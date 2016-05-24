#include <iostream>

using namespace std;

int main()
{
    int **p;
    int m,n,flag=1,getad=0;
    cin>>m>>n;
    p = new (int*[m]);
    for(int i=0;i<m;i++)
        p[i] = new int[n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        cin>>p[i][j];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            flag=1;
            for(int r=0;r<m;r++)
                if(p[i][j]<p[r][j]){
                    flag=0;
                    break;
                }
            if(flag==1)
            for(int l=0;l<n;l++)
                if(p[i][j]>p[i][l]){
                    flag=0;
                    break;
                }
            if(flag==1){cout<<i<<" "<<j<<" "<<p[i][j]<<endl;getad=1;}

        }
    for (int i=0; i<n; i++)
        if (p[i]){
            delete p[i];
            p[i]=NULL;
        }
    delete []p;
    p=NULL;

    if(!getad)
        cout<<"Not found!"<<endl;
}
