#include <iostream>
#include <cmath>
using namespace std;

float distance(float x1,float y1,float z1,float x2=0,float y2=0,float z2=0){
    float d1,d2;
    d1=sqrt(pow(x1,2)+pow(y1,2)+pow(z1,2));
    d2=sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
    cout<<d1<<endl;
    cout<<d2<<endl;

}
int main()
{
    float X1,Y1,Z1,X2,Y2,Z2;
    cin>>X1>>Y1>>Z1>>X2>>Y2>>Z2;
    distance(X1,Y1,Z1,X2,Y2,Z2);
    return 0;
}
/*
描述： 设计一个求空间两点距离的函数，要求第2个点的默认值为坐标原点。 
输入： 两个点的坐标。
 
输出： 输出第一个点与原点之间的距离及输入的两个点之间的距离。
 
输入样例： 1 1 1
5 5 5
 
输出样例： 1.73205
6.9282 
提示： 函数原型可设计如下：

float distance(float x1,float y1,float z1, float x2=0,float y2=0,float z2=0);
*/
