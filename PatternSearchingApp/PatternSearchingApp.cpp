#include <iomanip>
#include <PatternSearchingLib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cstring>

using namespace std::chrono;

void readPanTadeusz(std::vector<std::string> &searchPatterns, int const& n){
    std::fstream file;
    std::string filename = "C:/Users/wojte/CLionProjects/aisdtomczykowskisekulawzorzecpon8/pan-tadeusz.txt", word;
    file.open(filename.c_str());
    int count = n;
    while (file >> word && count)
    {
        searchPatterns.push_back(word);
        count--;
    }
}

int main(){
    std::vector<int> lengths = {100, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};


    std::ifstream file("C:/Users/wojte/CLionProjects/aisdtomczykowskisekulawzorzecpon8/str.txt");
    std::string str((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

    std::string fileStr = str.c_str();
    long long sumRk = 0;
    long long sumKMP = 0;
    long long sumN = 0;
    for(auto len : lengths) {
        sumRk = 0;
        sumKMP = 0;
        sumN = 0;
        std::vector<std::string> searchPatterns;
        readPanTadeusz(searchPatterns, len);

        for (auto word: searchPatterns) {
            auto start = high_resolution_clock::now();
            RKsearch(word, fileStr, 101);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            sumRk += duration.count();

            start = high_resolution_clock::now();
            KMPSearch(word, fileStr);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            sumKMP += duration.count();

            start = high_resolution_clock::now();
            Nsearch(word, fileStr);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            sumN += duration.count();
        }
        std::cout << sumRk/len << ";" << sumKMP/len << ";" << sumN/len << std::endl;
    }

    return 0;
}