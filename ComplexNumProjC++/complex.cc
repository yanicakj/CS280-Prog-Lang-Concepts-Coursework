#include <iostream>
#include "complex.h"

complex::complex(int norm, int imag) : norm(norm), imag(imag) {}

complex complex::operator+(const complex &second) const {
    return complex(norm + second.norm, imag + second.imag);
}

complex complex::operator+(int n) const {
    return complex(norm + n, imag);
}

complex complex::operator-(const complex &second) const {
    return complex(norm - second.norm, imag - second.imag);
}

complex complex::operator-(int n) const {
    return complex(norm - n, imag);
}

complex complex::operator*(const complex &second) const {
    return complex((norm * second.norm)-(imag * second.imag), (norm * second.imag)+(imag * second.norm));
}

complex complex::operator*(int n) const {
    return complex(norm * n, imag * n);
}

complex complex::operator/(const complex &second) const {
    int den = ((second.norm*second.norm)+(second.imag*second.imag));
    return complex(((norm*second.norm) + (imag*second.imag))/den, ((imag*second.norm)-(norm*second.imag))/den);
}

complex complex::operator/(int n) const {
    return complex(norm / n, imag / n);
}

complex operator+(int n, const complex &second) {
    return second + n;
}

complex operator-(int n, const complex &second) {
    return complex(n) - second;
}

complex operator*(int n, const complex &second) {
    return second * n;
}

complex operator/(int n, const complex &second) {
    return complex(n) / second;
}

ostream &operator<<(ostream &out, const complex &second) {
    out << "(" << second.norm << " + " << second.imag << "i)";
    return out;
}
