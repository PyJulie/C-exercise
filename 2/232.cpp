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
