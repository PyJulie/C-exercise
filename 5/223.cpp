#include <iostream>
#include <string>
using namespace std;

class Rational{
private:

    int iUp;
    int iDown;

public:
    void Reduce();
    int Gcd(int&,int&);
    Rational(int up = 0, int down = 1);
    Rational& operator-();
    Rational& operator=(const Rational& r);
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);
    friend Rational operator+(const Rational &l, const Rational &r);
    friend Rational operator-(const Rational &l, const Rational &r);
    friend Rational operator*(const Rational &l, const Rational &r);
    friend Rational operator/(const Rational &l, const Rational &r);
    friend bool operator==(const Rational &l, const Rational &r);
    friend bool operator<(const Rational &l, const Rational &r);
    friend bool operator>(const Rational &l, const Rational &r);
    friend bool operator<=(const Rational &l, const Rational &r);
    friend bool operator>=(const Rational &l, const Rational &r);
    friend ostream& operator<<(ostream& os, const Rational& rat);
    friend istream& operator>>(istream& is, Rational& rat);
};

Rational::Rational(int up, int down):iUp(up),iDown(down){
    Reduce();
}
int Rational::Gcd(int &iUp,int &iDown){
    int m, n, r, s = 1;
    if(iUp != 0 && iDown != 0){
        if(iDown < 0){
            s = -s;
            iDown = -iDown;
        }
        if(iUp < 0){
            s = -s;
            iUp = -iUp;
        }
        m = iUp;
        n = iDown;
        while(n != 0){
            r = m % n;
            m = n;
            n = r;
        }
        if(m != 0){
            iUp = s * iUp / m;
            iDown = iDown / m;
        }
    }
    else{
        iUp = 0;
        iDown = 1;
    }
}
void Rational::Reduce(){
    Gcd(iUp,iDown);
}
Rational& Rational::operator-(){
    if(iDown<0)
        iDown=-iDown;
    else
        iUp=-iUp;
    return *this;
}
Rational& Rational::operator=(const Rational& r){
    if(this != &r){
        iUp = r.iUp;
        iDown = r.iDown;
    }

    return *this;
}
Rational& Rational::operator++(){
    iUp += iDown;
    Reduce();
    return *this;
}

Rational Rational::operator++(int){
    Rational t = *this;
    iUp += iDown;
    Reduce();
    return t;
}
Rational& Rational::operator--(){
    iUp -= iDown;
    Reduce();
    return *this;
}

Rational Rational::operator--(int){
    Rational t = *this;
    iUp -= iDown;
    Reduce();
    return t;
}

Rational operator+(const Rational &l, const Rational &r){
    int m = l.iUp * r.iDown + l.iDown * r.iUp;
    int n = l.iDown * r.iDown;
    Rational t(m, n);
    return t;
}

Rational operator-(const Rational &l, const Rational &r){
    int m = l.iUp * r.iDown - l.iDown * r.iUp;
    int n = l.iDown * r.iDown;
    Rational t(m, n);
    return t;
}

Rational operator*(const Rational &l, const Rational &r){
    int m = l.iUp * r.iUp;
    int n = l.iDown * r.iDown;
    Rational t(m, n);
    return t;
}
Rational operator/(const Rational &l, const Rational &r){
    int m = l.iUp * r.iDown;
    int n = l.iDown * r.iUp;
    Rational t(m, n);
    return t;
}
bool operator==(const Rational& l, const Rational& r){
    return (l.iUp * r.iDown) == (l.iDown * r.iUp);
}

bool operator<(const Rational& l, const Rational& r){
    return (l.iUp * r.iDown) < (l.iDown * r.iUp);
}

bool operator>(const Rational& l, const Rational& r){
    return (l.iUp * r.iDown) > (l.iDown * r.iUp);
}

bool operator<=(const Rational& l, const Rational& r){
    return (l.iUp * r.iDown) <= (l.iDown * r.iUp);
}

bool operator>=(const Rational& l, const Rational& r){
    return (l.iUp * r.iDown) >= (l.iDown * r.iUp);
}

ostream& operator<<(ostream& os, const Rational& rat){
    if(rat.iDown == 1)
        os << rat.iUp;
    else if(rat.iUp%rat.iDown==0)
        os << rat.iUp/rat.iDown ;
    else
        os << rat.iUp << "/" << rat.iDown;

    return os;
}
istream& operator>>(istream& is, Rational& rat){
    is >> rat.iUp >> rat.iDown;

    return is;
}

int main()
{
    Rational a, b;
    cin >> a;
    cin >> b;
    Rational c = a + b;
    Rational d = a - b;
    Rational e = a * b;
    Rational f = a / b;
    Rational g = -a;
    -a;
    Rational h = ++a;
    Rational i = --a;
    Rational j = a++;
    Rational k = a--;
    cout << "a+b: " << c << endl;
    cout << "a-b: " << d << endl;
    cout << "a*b: " << e << endl;
    cout << "a/b: " << f << endl;
    cout << "-a: " << g << endl;
    cout << "++a: " << h << endl;
    cout << "--a: " << i << endl;
    cout << "a++: " << j << endl;
    cout << "a--: " << k << endl;
    cout << "a<b: " << boolalpha << (a<b) << endl;
    cout << "a<=b: " << boolalpha << (a<=b) << endl;
    cout << "a>b: " << boolalpha << (a>b) << endl;
    cout << "a>=b: " << boolalpha << (a>=b) << endl;

    return 0;
}
