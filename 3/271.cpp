#include <iostream>

using namespace std;
class Cyklinder{
private:
    double height;
    double radius;
public:
    const double pi=3.1415926;

    double GetPi(){
    return pi;
    }

    void SetRadius(double r){
        radius=r;
    }

    void SetHeight(double h){
        height=h;
    }

    double GetRadius(){
        return radius;
    }

    double GetHeight(){
        return height;
    }

    double Volume(){
        return radius*radius*pi*height;
    }

    double Area(){
        return 2*pi*radius*height + 2*radius*radius*pi;
    }
};
int main()
{
    double h,r;
    cin>>h>>r;
    Cyklinder c1;
    c1.SetHeight(h);
    c1.SetRadius(r);
    cout<<"pi="<<c1.GetPi()<<", ";
    cout<<"height="<<c1.GetHeight()<<", ";
    cout<<"radius="<<c1.GetRadius()<<":";
    cout<<"volume="<<c1.Volume()<<", ";
    cout<<"area="<<c1.Area()<<endl;
    return 0;
}
/*
描述： 设计并实现一个圆柱类Cylinder，要求：

（1）设计两个double型的私有数据成员：高度height和底圆半径radius。

（2）设计一个double型的公有静态常量数据成员pi（其值初始化为3.1415926），以及一个获取该常量的公有静态成员函数GetPI。

（3）在构造函数的初始化列表中初始化高度height和底圆半径radius。

（4）设计用于获取半径的成员函数GetRadius、获取高度的成员函数GetHeight、设置半径的成员函数SetRadius、设置高度的成员函数SetHeight。

（5）设计用于计算圆柱体积的成员函数Volume()、计算圆柱表面积的成员函数Area。

 

在main函数中：

根据输入的高度和半径构造圆柱对象，并输出圆柱的基本信息、体积和表面积。
 
输入： 圆柱的高度和底圆半径
 
输出： 圆周率pi、圆柱高度、底圆半径、圆柱的体积和表面积 
输入样例： 2.0 1.0 
输出样例： pi=3.14159, height=2, radius=1:volume=6.28319, area=18.8496
*/
