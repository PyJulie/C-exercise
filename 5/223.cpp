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
/*
描述： 定义有理数类（分母不为0的分数，分子分母均为整数）Rational，实现相应操作符的重载。

（1）定义私有数据成员：分子int iUp; 分母 int iDown。

（2）定义私有成员函数：void Reduce() 和 int Gcd(int l, int r)，分别用于有理数的约简和求两个整数的最大公约数。其中，在约简时需要求取分子与分母的最大公约数。

（3）定义构造函数，在构造函数体内可调用Reduce对有理数进行约简。

（4）将负号-和赋值运算符=重载为公有成员函数，分别用于求有理数的负数和赋值。

（5）将前置++、前置--、后置++、后置--重载为公有成员函数，实现有理数自增1或自减1。

（6）将+、-、*、/重载为友员函数，实现有理数的加减乘除。

（7）将<、<=、>、>=重载为友员函数，实现有理数的大小关系比较。

（8）重载流插入符<<和流提取符>>，分别用于有理数的输出和输入。其中，输出格式为“分子/分母”，若为整数，则直接输出整数。

 

在main函数中，根据输入的分子和分母定义两个有理数对象a和b。再定义几个有理数对象分别用于表示a和b的加、减、乘、除、前置自增a、前置自减a、后置自增a、后置自减a，并依次各个对象的结果。最后依次用<、<=、>、>=比较a和b的大小关系，并依次输出比较结果（true或false）。
 
输入： 两个有理数a和b的的分子和分母
 
输出： 有理数a和b的加、减、乘、除以及前置自增a、前置自减a、后置自增a、后置自减a

有理数a和b的<、<=、>、>=的结果
 
输入样例： 4 3

3 2
 
输出样例： a+b: 17/6
a-b: -1/6
a*b: 2
a/b: 8/9
-a: -4/3
++a: 7/3
--a: 4/3
a++: 4/3
a--: 7/3
a<b: true
a<=b: true
a>b: false
a>=b: false
*/
