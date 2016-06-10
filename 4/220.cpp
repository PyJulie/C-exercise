#include <iostream>
#include <cmath>
using namespace std;
class Point{
public:
    double X;
    double Y;
    Point(double x=0, double y=0):X(x),Y(y){}
};
class Line{
private:
    Point ptStart;
    Point ptEnd;

public:
    Line(const Point &Start, const Point &End):ptStart(Start),ptEnd(End){}
    double Length(){
        double len;
        len = sqrt(pow(ptEnd.X-ptStart.X,2) + pow(ptEnd.Y-ptStart.Y,2));
        return len;
    }
};
class Triangle{
public:
    Triangle(const Point &p1, const Point &p2, const Point &p3):ptA(p1),ptB(p2),ptC(p3){}
    double Perimeter(){
    Line lab(ptA,ptB), lbc(ptB,ptC), lca(ptC,ptA);
    return lab.Length()+lbc.Length()+lca.Length();
}
    double Area(){
        Line lab(ptA,ptB), lbc(ptB,ptC), lca(ptC,ptA);
        double a = lab.Length();
        double b = lbc.Length();
        double c = lca.Length();
        double p = 0.5*(a+b+c);
    return sqrt(p*(p-a)*(p-b)*(p-c));
    }
private:
    Point ptA;
    Point ptB;
    Point ptC;
};

int main()
{

    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    Triangle t(Point(x1,y1),Point(x2,y2),Point(x3,y3));
    cout << t.Perimeter() << " " << t.Area() << endl;
    return 0;
}
/*
描述： 设计用于表示点、线和三角形的类：Point、Line和Triangle，要求如下：

（1）Point类中包含两个用于表示点的X和Y坐标分量的公有数据成员，能够根据指定的X和Y坐标构建点对象。

（2）Line类中包含两个用于表示线段端点的私有对象成员，能够根据指定的两点构造线段对象（要求构造函数的参数为常引用），具有计算线段长度的公有成员函数。

（3）Triangle类中包含三个用于表示三角顶点的私有对象成员，能够根据指定的三点构造三角形对象（要求构造函数的参数为常引用），具有计算三角形周长和面积的公有成员函数。

 

在main函数中：

根据输入的三个点的坐标构建三角形对象，并输出的三角形的周长和面积。
 
输入： 依次输入三个点的坐标:x1,y1,x2,y2,x3,y3
 
输出： 输出三个点所构成的三角形的周长和面积 
输入样例： 0 0 3 0 0 4 
输出样例： 12 6
*/
