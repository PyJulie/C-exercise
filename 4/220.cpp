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
