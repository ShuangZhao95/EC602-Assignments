#!/usr/bin/env python3.5

# 1. Load the file into a dictionary of lists using this procedure:
#   a. Read a word "cat"
#   b. Sort the letters of the word "act" 
#   c. To the list at key "act" append "cat"
# 2. Find all n letter combinations of string s in the dictionary (n=3, s=tacks)
#   a. Sort the string "ackst"
#   b. Generate a list of all 3 letter ordered combinations from the sorted string
#       [ack, acs, act ...]
#   c. Access the list at each key matching each of the combinations and append it 
#       to the final word set
# 3. Spit out the final word set

import sys
import itertools

def nCr(n,r):
        f = math.factorial
        return f(n) / f(r) / f(n-r)

def main():
    filename = sys.argv[1]
    
    wordlist = dict()
    f = open(filename)

    for w in f.read().split():
        s = ''.join(sorted(w))
        wordlist.setdefault(s,[]).append(w)

    while(1):
        inputstr = input()
        searchstr, length = inputstr.split()
        print("got input")
        length = int(length)
        if(length == 0):
            break
        searchlist = sorted(searchstr)
        print("making combinations")
        combinations = [ set(x) for x in itertools.combinations(searchlist, length)]
        print(combinations)
        print("searching")
        wordsfound = set()
        for c in combinations:
            w = ''.join(c)
            if(w in wordlist):
                wordlist[w]
                for n in wordlist[w]:
                    wordsfound.add(n)

        for n in sorted(wordsfound) :
            print(n)
        print('.')

if __name__ == "__main__":
    main()
