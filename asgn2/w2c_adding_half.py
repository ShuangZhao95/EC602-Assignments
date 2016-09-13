# w2c_addinghalf.py

#     00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
#  sign |  exponent    |       fraction                parts of half
#  ---------------------------------------------------
#    |     1     |     2     |     3     |     4     | nibbles(4 bits)
#     00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
#
# Breakdown of each nibble:
# Nibble 1: 1st bit is sign, next 3 bits are bits 3,4,5 of the exponent
# Nibble 2: First two bits are bits 1 and 2 of exponent. Last two bits are bits 9 and 10 of fraction
# Nibble 3: Bits are 5,6,7,8 of fraction
# Nibble 4: Bits are 1,2,3,4 of fraction

from math import inf
def number_from_half(s : str):
    """return the number represented by s, a binary16 stored as a 4-character hex number"""
    i = int(s, 16)
    sign = ((i & 0xF000) >> 15 )

    # Combine last two bits of nibble 1 and first two of nibble 2 to form the exponent
    exponent = (((( i & 0xF000 ) >> 12 ) & 0b0111 ) << 2 ) + (( i & 0x0F00 ) >> 10 ) 
    
    
    # Combine last two bits of nibble 1 and first two of nibble 2 to form the exponent
    fraction = (((( i & 0x0F00 ) >> 8 ) & 0b0011 ) << 8 ) + ( i & 0x00FF )

    if exponent == 0  :
        num = (-1)**sign * 2**(-14) * (fraction * (0b10)**(-10))
    elif exponent == 0b11111 :
        return "inf"
    else :
        num = (-1)**sign * 2**(exponent - 15) * (1+fraction * (0b10)**(-10))
        
    return num
def main():
    """add all binary16 numbers from standard input until a non-number is entered, then print the total.
    Numbers are represented in 4-character hex string format, one per line"""

    # hint1: use int(input(),16)
    # hint2: use try: except: to halt
    sum = 0
    while 1 == 1:
        try:
            num = number_from_half(input())
            sum += num
        except:
            print(sum)
            return

if __name__ == '__main__':
    main()
