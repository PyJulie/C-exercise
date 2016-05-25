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
