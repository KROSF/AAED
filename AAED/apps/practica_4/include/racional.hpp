#ifndef RACIONAL_HPP
#define RACIONAL_HPP
class Racional{
public:
    Racional(long n = 0, long d = 1);
    long num() const { return n_; }
    long den() const { return d_; }
    friend Racional inv(const Racional& r);
    Racional operator + () const;
    Racional operator - () const;
    Racional& operator+=(const Racional&);
    Racional& operator-=(const Racional&);
    Racional& operator*=(const Racional&);
    Racional& operator/=(const Racional&);
private:
    long n_,d_;
    static long mcd(long, long);
    static long mcm(long, long);
};

Racional operator + (const Racional& r, const Racional& s);
Racional operator - (const Racional& r, const Racional& s);
Racional operator * (const Racional& r, const Racional& s);
Racional operator / (const Racional& r, const Racional& s);
bool operator == (const Racional& r, const Racional& s);
bool operator != (const Racional& r, const Racional& s);
bool operator <= (const Racional& r, const Racional& s);
bool operator >= (const Racional& r, const Racional& s);
bool operator < (const Racional& r, const Racional& s);
bool operator > (const Racional& r, const Racional& s);

#endif
