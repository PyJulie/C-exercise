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
/*
描述：     设计一个函数模板，实现两个同类型数据的交换。

    将设计好的函数模板分别实例化为两个整型数交换、两个字符交换的模板函数，调用这些函数并输出运行结果。
 
输入： 分别输入两个整型数和两个字符
 
输出： 分别输出两个整型数和两个字符交换的结果 
输入样例： 5 9 
输出样例： 9 5
*/
