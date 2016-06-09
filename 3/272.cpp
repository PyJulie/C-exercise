#include <iostream>

using namespace std;

class Array{
private:
    int m;
    int *p;
public:

    Array(){
    m=5;
    p = new int[m];
    for(int i=0;i<m;i++)
        p[i]=(i+1);
    }

    Array(int om){
    m=om;
    p=new int[m];
    for(int i=0;i<m;i++)
        p[i]=0;
    }

    Array(const Array& a){
    m=a.m;
    p=new int[a.m];
    for(int i=0;i<m;i++)
        p[i]=a.p[i];
    }

    int Find(int i,int x){
    if(i>=m){
        cout<<"out of boundary"<<endl;
        return 0;
    }


    p[i]=x;
    return 1;
    }

    int Size(){
    return m;
    }

    int Traverse(){
    for(int i=0;i<m-1;i++)
        cout<<p[i]<<" ";
    cout<<p[m-1]<<endl;
    }

};
int main()
{
    int n;
    int i,x;
    cin>>n;
    cin>>i>>x;
    Array a1;
    Array a2(n);
    a1.Traverse();
    a2.Traverse();
    a1.Find(i,x);
    Array a3(a1);
    a1.Traverse();
    a3.Traverse();
    return 0;
}
/*
描述： 设计并实现一个动态整型数组类Vect，要求：

（1）实现构造函数重载，可以根据指定的元素个数动态创建初始值为0的整型数组，或根据指定的内置整型数组动态创建整型数组。

（2）设计拷贝构造函数和析构函数，注意使用深拷贝。

（3）设计存取指定位置的数组元素的公有成员函数，并进行下标越界，若越界则输出“out of boundary”。

（4）设计获取数组元素个数的公有成员函数。

（5）设计用于输出数组元素的公有成员函数，元素之间以空格分隔，最后以换行符结束。

 

在main函数中按以下顺序操作：

（1）根据内置的静态整型数组{1,2,3,4,5}构造数组对象v1，根据输入的整型数构造数组对象v2。

（2）调用Vect的成员函数依次输出v1和v2的所有元素。

（3）输入指定的下标及对应的整型数，设置数组对象v1的指定元素。

（4）根据数组对象v1拷贝构造数组对象v3。

（5）调用Vect的成员函数依次输出v1和v3的所有元素。
 
输入： 用于构建数组对象v2的元素个数

用于设置数组对象v1的指定下标及元素值

 
 
输出： 数组对象v1和v2的所有元素

数组对象v1和v3的所有元素
 
输入样例： 10

6 6

 
 
输出样例： 1 2 3 4 5
0 0 0 0 0 0 0 0 0 0
out of boundary
1 2 3 4 5
1 2 3 4 5
*/
