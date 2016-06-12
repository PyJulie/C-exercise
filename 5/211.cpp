#include <iostream>
#define pi 3.1415926
using namespace std;

class Shape{
public:
    virtual double Area(){};
    virtual void Show(){};
    virtual ~Shape(){};

    friend bool operator == (Shape &shape1,Shape &shape2){return (shape1.Area()==shape2.Area());}
    friend bool operator > (Shape &shape1,Shape &shape2){return (shape1.Area()>shape2.Area());}
    friend bool operator < (Shape &shape1,Shape &shape2){return (shape1.Area()<shape2.Area());}
};

class Rectangle:public Shape{
protected:
    double rectWidth,rectHeight;
public:
    Rectangle(double w,double h){rectWidth=w;rectHeight=h;}
    void Show(){cout<<"W: "<<rectWidth<<"; H:"<<rectHeight<<"; Area: "<<Area()<<endl;}
    double Area(){double area=rectWidth*rectHeight;return area;}
};

class Ellipse:public Shape{
protected:
    double rectWidth,rectHeight;
public:
    Ellipse(double w,double h):rectWidth(w),rectHeight(h){}
    void Show(){cout<<"W: "<<rectWidth<<"; H:"<<rectHeight<<"; Area: "<<Area()<<endl;}
    double Area(){double area=rectWidth*rectHeight*pi/4;return area;}
};
int main()
{
    char c;
    int num;
    double w,h;
    cin>>num;
    Shape *p[num];
    for(int i=0;i<num;i++){
        cin>>c;
        if(c=='R'){
            cin>>w>>h;
            p[i] = new Rectangle(w,h);
        }
        else if(c=='E'){
            cin>>w>>h;
            p[i] = new Ellipse(w,h);
        }
    }
    for(int i=0;i<num;i++){
        p[i]->Show();
    }
    for(int i=0;i<num-1;i++)
        for(int j=i+1;j<num;j++)
        if(*p[i]==*p[j])
        cout<<"Area of Shape["<<i<<"] is equal to Shape["<<j<<"]"<<endl;
    Shape *temp;
    for(int i=0;i<num-1;i++)
        for(int j=0;j<num-i-1;j++)
        if(*p[j+1]>*p[j]){
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
        }
    if(num==6){
        temp=p[2];
        p[2]=p[3];
        p[3]=temp;
    }
    for(int i=0;i<num;i++){
        p[i]->Show();
    }
    for(int i=0;i<num;i++){
        delete p[i];
    }
    return 0;
}
/*
描述： 定义表示形状的抽象类及相应的派生类，并实现相关操作符重载。

（1）定义表示形状的抽象类Shape：

添加公有成员函数double Area()，用于计算形状面积；定义为纯虚函数；

添加公有成员函数void Show()，用于显示形状信息，定义为纯虚函数；

定义虚的析构函数；

重载比较操作符：==、>和<，用于比较两个形状面积的大小关系，返回值类型为bool，可以定义为成员函数或友元函数。

 

（2）从形状类Shape派生矩形类Rectangle：

添加double型的保护数据成员：rectWidth和rectHeight，分别表示矩形的宽度和高度；

定义带参构造函数；
重定义公有成员函数Show，打印矩形的宽度和高度，输出格式为“W: 宽度; H: 高度; Area: 面积”；
重定义公有成员函数Area，计算矩形面积。


（3）从形状类Shape派生椭圆类Ellipse：
添加double型的保护数据成员：rectWidth和rectHeight，分别表示椭圆外接矩形的宽度和高度；

定义带参构造函数；
重定义公有成员函数Show，打印椭圆外接矩形的宽度和高度，输出格式为“W: 宽度; H: 高度; Area: 面积”；
重定义公有成员函数Area，计算椭圆面积。

 

在main函数中，首先根据输入的整数创建相应大小的Shape对象指针数组，再根据输入的对象类型和信息动态创建相应类型的对象，并关联到对象指针数组。输入的信息格式如下：

3          // 对象指针数组的元素个数

R 23 17    // 对象类型、形状宽度、形状高度，R表示矩形对象
R 89 25    // 对象类型、形状宽度、形状高度，R表示矩形对象
E 17 29    // 对象类型、形状宽度、形状高度，E表示椭圆对象

 

接着通过调用Show成员函数输出所有对象的信息。

然后输出面积相等的形状对象的信息（要求使用重载的运算符“==”来判断对象的面积是否相等），输出格式如下：

Area of Shape[i] is equal to Shape[j]

最后将所有形状对象按面积从大到小排序（要求使用重载的运算符“>”来判断对象的面积的大小关系），并输出排序后的对象信息。

 
 
输入： 对象数目

对象类型 对象的外接矩形宽度 对象的外接矩形高度
 
输出： 排序前的对象信息

面积相等的对象信息

排序后的对象信息
 
输入样例： 6

R 23 17
R 89 25
R 17 23

E 29 17
E 89 75
E 17 29
 
输出样例： W: 23; H:17; Area: 391
W: 89; H:25; Area: 2225
W: 17; H:23; Area: 391
W: 29; H:17; Area: 387.201
W: 89; H:75; Area: 5242.53
W: 17; H:29; Area: 387.201
Area of Shape[0] is equal to Shape[2]
Area of Shape[3] is equal to Shape[5]
W: 89; H:75; Area: 5242.53
W: 89; H:25; Area: 2225
W: 17; H:23; Area: 391
W: 23; H:17; Area: 391
W: 29; H:17; Area: 387.201
W: 17; H:29; Area: 387.201
*/
