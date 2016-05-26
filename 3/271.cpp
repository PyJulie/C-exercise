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
