#!/usr/bin/env python3.5
import sys
import itertools
def main():
    fn = sys.argv[1]
    word = sys.argv[2]
    l = int(sys.argv[3])
    wordlist = dict()
    f = open(fn)
    
    for w in f.read().split():
        s = ''.join(sorted(w))
        wordlist.setdefault(s,[]).append(w)

    l = ''.join(sorted(set(word.lower())))
    wl = list(l)
    combs = [ list(x) for x in itertools.combinations(wl, int(sys.argv[3]))]
    words = list()
    for c in combs:
        w = ''.join(c)
        if(w in wordlist):
            wordlist[w]
            for n in wordlist[w]:
                words.append(n)
    for n in sorted(words) :
        print(n)
if __name__ == "__main__":
    main()
