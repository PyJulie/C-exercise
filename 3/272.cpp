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
