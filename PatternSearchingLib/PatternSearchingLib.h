#ifndef AISDTOMCZYKOWSKISEKULAWZORZECPON8_PATTERNSEARCHINGLIB_H
#define AISDTOMCZYKOWSKISEKULAWZORZECPON8_PATTERNSEARCHINGLIB_H
#endif //AISDTOMCZYKOWSKISEKULAWZORZECPON8_PATTERNSEARCHINGLIB_H

#include <iomanip>
#include <vector>


std::vector<int> Nsearch(std::string pat, std::string txt);

std::vector<int> KMPSearch(std::string pat, std::string txt);

std::vector<int> RKsearch(std::string pat, std::string txt, int q);

void computeLPSArray(std::string pat, int M, int lps[]);

