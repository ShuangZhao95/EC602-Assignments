// AUTHOR alex alxndr@bu.edu
/*  Copyright 2016 Alejandro, Alex, James, Jingwei */
#include <stdlib.h>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#define strsort(a) std::sort(a.begin(), a.end())
#define nCm(n, m) std::tgamma(n+1)/(std::tgamma(m+1)*std::tgamma(n-m+1))
#define CONT {std::cout << "." << std::endl; continue;}
std::unordered_map<int, std::unordered_map<std::string, \
        std::set<std::string> > > dictionary;
std::set<std::string> wordset;

int list_matches(std::string s) {
    for (auto const& i : dictionary[s.length()][s])
        wordset.insert(i);
}
int strcontains(std::string large, std::string small) {
    for (auto i : small) {
        int pos = large.find_first_of(i);
        if (pos != std::string::npos)
            large.erase(pos, 1);
        else
            return 0;
    }
    return 1;
}
int dict_search(std::string s, int l) {
    for (auto i : dictionary[l]) {
          if (strcontains(s, i.first)) {
            for (auto j : i.second)
                wordset.insert(j);
          }
    }
}

int strcomb(std::string s, int m, int n, std::string t) {
    if (n == 0) {
        list_matches(t);
        return 0;
    }
    for (int i= m;  i<= s.length()-n; i++) {
        std::string q = t;
        q.push_back(s[i]);
        strcomb(s, i+1, n-1, q);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    std::ifstream infile(argv[1]);
    std::string word;
    while (infile >> word) {
        std::string sortedword = word;
        strsort(sortedword);
        dictionary[word.length()][sortedword].insert(word);
    }
    std::string searchstr;
    int length;
    while (std::cin >> searchstr >> length) {
        if (!length) return 0;
        wordset.clear();
        strsort(searchstr);
        if (searchstr.length() < length) CONT;
        if (nCm(searchstr.length(), length) < \
                dictionary[searchstr.length()].size())
            strcomb(searchstr, 0, length, "");
        else
            dict_search(searchstr, length);
        for (auto &i : wordset)
            std::cout << i << std::endl;
        CONT;
    }
}

