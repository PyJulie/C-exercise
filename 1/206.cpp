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
/*
描述： 输入一个二维矩阵，找出其中所有鞍点。如果矩阵有鞍点，则输出鞍点的信息：行号、列号、值；
如果没有鞍点，则输出“Not found！”。

所谓“鞍点”，是指满足以下条件的矩阵中的一个数：在它所在的行上最小、所在列上最大。 该题中假设矩阵中任意两个数互不相等。
 
输入： 输入数据有多行：

第一行是矩阵的行数m和列数n 
从第二行起共包含m行，每行包含n个数，为矩阵的一行数据
 
输出：    如果矩阵有鞍点，输出鞍点的信息，包括：所在行、所在列、值
   如果没有鞍点，输出Not found！ 
输入样例： 3 4
11 23 56 47
12 45 66 90
16 77 34 18 
输出样例： 2016 
提示： 1、要求用动态内存分配来完成，可用new和delete实现；

2、屏幕输出只有2 0 16（加回车换行），不能有其它信息。
*/
