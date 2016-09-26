# http://128.197.128.203:60216/static/content/assignment_4_modeling.html


class Polynomial():
    'Polynomial class with support for negative numbers'
    def __init__(self, seq):
        # Constructor - seq are coefficients ordered by exponent - high to low
        self.poly = dict()
        inc = 0
        for c in reversed(seq):
            self[inc] = c
            inc = inc + 1
    
    def __getitem__(self,index):
        return self.poly[index]

    def __setitem__(self, key, value):
        self.poly[key]=value

    def __str__(self):
        return str(self.poly)



def main():
    pass

if __name__=="__main__":
    main()
