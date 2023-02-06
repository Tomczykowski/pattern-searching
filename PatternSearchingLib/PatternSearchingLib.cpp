#include "PatternSearchingLib.h"
#include "string"
#include "stdio.h"
#include "cstring"
#include "iostream"
#define d 256


std::vector<int> Nsearch(std::string pat, std::string txt)
{

    std::vector<int> index;
    int M = pat.length();
    int N = txt.length();

    if(M == 0 || N == 0 || M > N)
        throw std::logic_error("Incorrect action");

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M)
            index.push_back(i);
    }
    return index;
}

void computeLPSArray(std::string pat, int M, int lps[])
{
    int j = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[j]) {
            ++j;
            lps[i] = j;
            ++i;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}

std::vector<int> KMPSearch(std::string pat, std::string txt)
{
    std::vector<int> index;
    int M = pat.length();
    int N = txt.length();

    if(M == 0 || N == 0 || M > N)
        throw std::logic_error("Incorrect action");


    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            index.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }
    return index;
}

std::vector<int> RKsearch(std::string pat, std::string txt, int q)
{
    std::vector<int> index;
    int M = pat.length();
    int N = txt.length();

    if(M == 0 || N == 0 || M > N)
        throw std::logic_error("Lenght");

    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;


    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;


    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }


    for (i = 0; i <= N - M; i++)
    {

        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)
                index.push_back(i);

        }

        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0)
                t = (t + q);
        }
    }
    return index;
}
