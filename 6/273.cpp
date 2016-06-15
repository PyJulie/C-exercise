#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
    string file1;
    string file2;
    string text;
    int line=1;
    cin >> file1 >> file2;
    ifstream in(file1.c_str());
    ofstream out(file2.c_str());

    if(in.fail()||out.fail())
    {
        return 0;
    }


    while(!in.eof())
    {
        getline(in,text);
        cout <<setw(4) << setfill('0') << line << ' ' << text << endl;
        out <<setw(4) << setfill('0') << line << ' ' << text << endl;
        line++;
    }

    return 0;
}
/*
描述： 逐行读取源文件的文本，在每行文本前加上行号，保存到目标文件并同时输出到屏幕。
 
输入： 键盘输入源文件和目标文件的文件名 
输出： 将添加行号后的文本输出到目标文件和屏幕 
输入样例： 源文件和目标文件名：

SrcData.txt

DstData.txt

源文件内容：

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}




 
输出样例： 目标文件及屏幕输出结果：

0001 #include <iostream>
0002 
0003 using namespace std;
0004 
0005 int main()
0006 {
0007     cout << "Hello world!" << endl;
0008     return 0;
0009 }


 
提示： 本机测试时，可在项目的当前路径下建立一个名为SrcData.txt的源文本文件。

利用getline函数读取行数据；利用setfill和setw格式控制符设置输出格式。
*/
