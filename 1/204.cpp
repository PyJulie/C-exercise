#include <iostream>

using namespace std;
int main(){
char name[10];
cin>>name;
cout<<"Hello, "<<name<<"!"<<endl;
return 0;
}
/*描述：     编写一个简单的控制台应用程序，先输入姓名，如“John”，再输出问候语，如“Hello, John!”。 
输入： John
 
输出： Hello, John! 
输入样例： John
 
输出样例： Hello,John!
 
提示： 1、使用string类定义字符串对象，需包含头文件<string>；

2、使用cin和提取符>>从键盘输入数据，使用cout和插入符<<输出结果到屏幕，需包含头文件<iostream>；

3、注意使用名称空间std。*/
