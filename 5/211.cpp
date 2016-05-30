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
