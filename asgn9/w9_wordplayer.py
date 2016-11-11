#!/usr/bin/env python3.5
# AUTHOR alex alxndr@bu.edu

import sys
import itertools
import math


def nCr(n, r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)


def issubstr(small, large):
    charlist = list(large)
    for c in list(small):
        if(c in charlist):
            charlist.remove(c)
        else:
            return 0
    return 1


def main():
    filename = sys.argv[1]
    wordlist = dict()
    f = open(filename)

    for w in f.read().split():
        s = ''.join(sorted(w))
        wordlist.setdefault(len(s), {}).setdefault(s, []).append(w)

    while(1):
        inputstr = input()
        searchstr, length = inputstr.split()
        length = int(length)
        if(length == 0):
            break
        searchlist = sorted(searchstr)
        if(len(searchlist) < length):
            print('.')
            continue
        wordsfound = set()
        if(wordlist.get(length)):
            if(nCr(len(searchlist), length) > len(wordlist[length])):
                for w in wordlist[length]:
                    if(issubstr(w, searchlist)):
                        for n in wordlist[length][w]:
                            wordsfound.add(n)
            else:
                combinations = list()
                for x in set(itertools.combinations(searchlist, length)):
                    combinations.append(x)
                for c in combinations:
                    w = ''.join(c)
                    if(w in wordlist[length]):
                        for n in wordlist[length][w]:
                            wordsfound.add(n)

        for n in sorted(wordsfound):
            print(n)
        print('.')
    return 0

if __name__ == "__main__":
    main()
