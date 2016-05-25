#include <iostream>

using namespace std;
template<class T>

void Swap(T& a,T& b){
        T temp;
        temp=a;
        a=b;
        b=temp;
}

int main()
{
    int a,b;
    char c,d;
    cin>>a>>b;
    cin>>c>>d;
    Swap(a,b);
    Swap(c,d);
    cout<<a<<" "<<b<<endl;
    cout<<c<<" "<<d<<endl;
    return 0;
}
