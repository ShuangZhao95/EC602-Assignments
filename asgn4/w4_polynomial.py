# AUTHOR James Michael Clifford jcliff@bu.edu
# AUTHOR Jingwei Zhang jyz5257@bu.edu
# AUTHOR Alexander Oleinik alxndr@bu.edu
# AUTHOR Alejandro Aparicio aaparici@bu.edu

#Better polynomial with negative exponent support
# http://128.197.128.203:60216/static/content/assignment_4_modeling.html


class Polynomial():
    'Polynomial class with support for negative numbers'
    def __init__(self, seq=None):
        # Constructor - seq are coefficients ordered by exponent - high to low
        self.poly = dict()
        if seq != None :
            inc = 0
            for c in reversed(seq):
                self[inc] = c
                inc = inc + 1
    
    def __getitem__(self,index):
        if index in self.poly :
            return self.poly[index]
        else :
            return 0

    def __setitem__(self, key, value):
        if value == 0 :
            try:
                del self.poly[key]
            except KeyError:
                pass
        else:
            self.poly[key]=value

    def __str__(self):
        return str(self.poly)

    def __add__(self, other):
        s = Polynomial()
        for i in self.poly:
            s[i] = self[i]
        for j in other.poly:
            s[j] = s[j] + other[j]
        return s;

    def __sub__(self, other):
        s = Polynomial()
        for i in self.poly:
            s[i] = self[i]
        for j in other.poly:
            s[j] = s[j] - other[j]
        return s;
        
    def __mul__(self, other):
        s = Polynomial()
        for i in self.poly:
            for j in other.poly:
                s[i+j] += self[i] * other[j]
        return s;
    
    def __eq__(self, other):
        return self.poly == other.poly;

    def eval(self, x):
        s = 0
        for i in self.poly:
            s = s + self[i] * x**i
        return s

    def deriv(self):
        s = Polynomial()
        for i in self.poly:
            s[i-1] = self[i]*i
        return s

    __repr__ = __str__
        
def main():
    pass

if __name__=="__main__":
    main()
