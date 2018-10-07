#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>


using std::ostream;

struct complex {

    complex(int = 0, int = 1);

    complex operator+(const complex &) const;
    complex operator-(const complex &) const;
    complex operator*(const complex &) const;
    complex operator/(const complex &) const;

    complex operator+(int) const;
    complex operator-(int) const;
    complex operator*(int) const;
    complex operator/(int) const;

    friend complex operator+(int, const complex &);
    friend complex operator-(int, const complex &);
    friend complex operator*(int, const complex &);
    friend complex operator/(int, const complex &);

    friend ostream &operator<<(ostream &, const complex &);

private:
    int norm;
    int imag;
};

#endif /* complex_H */
