from __future__ import division

class complex:
    def __init__(self, norm = 0, imag = 0):
        self.norm = norm
        self.imag = imag
        
    def __add__(self, other):
        if isinstance(other, int):
            return complex(self.norm + other, self.imag)
        elif isinstance(other, complex):
            return complex(self.norm + other.norm, self.imag + other.imag)
        else:
            raise TypeError

    def __sub__(self, other):
        if isinstance(other, int):
            return complex(self.norm - other, self.imag)
        elif isinstance(other, complex):
            return complex(self.norm - other.norm, self.imag - other.imag)
        else:
            raise TypeError
        
    def __mul__(self, other):
        if isinstance(other, int):
            return complex(self.norm * other, self.imag * other)
        elif isinstance(other, complex):
            # ac - bd, ad + bc
            return complex((self.norm * other.norm)-(self.imag * other.imag), (self.norm * other.imag) + (self.imag * other.norm))
        else:
            raise TypeError
            
    def __truediv__(self, other):
        if isinstance(other, int):
            return complex(round(self.norm / other, 1), round(self.imag / other, 1))
        elif isinstance(other, complex):
            den = ((other.norm * other.norm) + (other.imag * other.imag))
            firstnum = ((self.norm * other.norm) + (self.imag * other.imag))
            secnum = ((self.imag * other.norm) - (self.norm * other.imag))
            return complex(round(firstnum / den, 1), round(secnum / den, 1))
        else:
            raise TypeError
            
    def __floordiv__(self, other):
        if isinstance(other, int):
            return complex(round(self.norm / other, 1), round(self.imag / other, 1))
        elif isinstance(other, complex):
            den = ((other.norm * other.norm) + (other.imag * other.imag))
            firstnum = ((self.norm * other.norm) + (self.imag * other.imag))
            secnum = ((self.imag * other.norm) - (self.norm * other.imag))
            return complex(round(firstnum / den, 1), round(secnum / den, 1))
        else:
            raise TypeError
            
    
    def __div__(self, other):
        if isinstance(other, int):
            return complex(round(self.norm / other, 1), round(self.imag / other, 1))
        elif isinstance(other, complex):
            den = ((other.norm * other.norm) + (other.imag * other.imag))
            firstnum = ((self.norm * other.norm) + (self.imag * other.imag))
            secnum = ((self.imag * other.norm) - (self.norm * other.imag))
            return complex(round(firstnum / den, 1), round(secnum / den, 1))
        else:
            raise TypeError
            
    def __radd__(self, other):
        return self + other
    
    def __rsub__(self, other):
        return complex(other) - self
        
    def __rmul__(self, other):
        return self * other
        
    def __rtruediv__(self, other):
        return complex(other) / self
        
    def __rfloordiv__(self, other):
        return complex(other) / self
        
    def __rdiv__(self, other):
        return complex(other) / self
            
    def __float__(self):
        return float(self.norm) / self.imag

    def __int__(self):
        return self.norm / self.imag
    
    def __str__(self):
        return '(' + str(self.norm) + ' + ' + str(self.imag) + "i)"



if __name__ == '__main__':
    
    a = complex(1, 2)
    b = complex(1, 3)
    
    i = 5
    
    print('%s + %s = %s' % (a, b, a + b))
    print('%s - %s = %s' % (a, b, a - b))
    print('%s * %s = %s' % (a, b, a * b))
    print('%s / %s = %s' % (a, b, a  /b))

    print('%s + %i = %s' % (a, i, a + i))
    print('%s - %i = %s' % (a, i, a - i))
    print('%s * %i = %s' % (a, i, a * i))
    print('%s / %i = %s' % (a, i, a / i))

    print('%i + %s = %s' % (i, a, i + a))
    print('%i - %s = %s' % (i, a, i - a))
    print('%i * %s = %s' % (i, a, i * a))
    print('%i / %s = %s' % (i, a, i / a))

