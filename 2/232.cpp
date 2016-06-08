#include <iostream>

using namespace std;

void Math(float a,float b,float &sum,float &sub,float &pro){
        sum=a+b;
        sub=a-b;
        pro=a*b;
}
int main()
{
    float A,B,Sum,Sub,Pro;
    cin>>A>>B;
    Math(A,B,Sum,Sub,Pro);
    cout << Sum<<" "<< Sub<<" "<<Pro<< endl;
    return 0;
}
/*
描述： 设计一个函数，将两个浮点数传入，然后通过引用把其和、差、积传出。

函数原型如下：void Math(float a,float b,float &sum,float &sub,float &pro);
 
输入： 输入两个浮点数 
输出： 输出两个浮点数的和、差、积。 
输入样例： 6.5 2.3
 
输出样例： 8.8 4.2 14.95
*/
