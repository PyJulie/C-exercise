#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct Iformation{
    int ID;
    string GBE;
} information[1000];

int main()
{
    string File1;
    string File2;
    int i = 0;
    string id;
    int Id;
    Iformation exchange;

    cin >> File1 >> File2;
    ifstream in(File1.c_str());
    ofstream out(File2.c_str());
    if(in.fail()||out.fail()){
        cout << "Error: can't open the file!" << endl;
        return 0;
    }

    while(!in.eof()){
        getline(in,id,',');
        Id = atoi(id.c_str());
        information[i].ID = Id;
        getline(in,information[i].GBE);
        i++;
    }

    for(int j = 0; j < i - 1; j++ ){
        for(int k = 0; k < i - 1 - j; k++){
            if(information[k].ID > information[k+1].ID){
                exchange =  information[k];
                information[k] = information[k+1];
                information[k+1] = exchange;
            }
        }
    }

    Iformation save = information[0];
    out << save.ID << ',' <<  save.GBE << endl;
    cout << save.ID << ',' <<  save.GBE << endl;

    for(int j = 1; j < i ; j++ ){
        if(save.ID == information[j].ID){
            ;
        }
        else{
            save = information[j];
            out << save.ID << ',' <<  save.GBE << endl;
            cout << save.ID << ',' <<  save.GBE << endl;
        }
    }

    return 0;
}
/*
描述： 源数据文件（文本格式）中包含有每个学生的记录：ID(身份识别号)、 Gender(性别)、 Birthday(生日)和EnrollmentDate(入学时间)，字段之间以半角逗号分隔，记录之间以换行符分隔。要求从源数据文件中读取学生记录并删除重复记录，然后根据ID大小对所有记录按从小到大排序，将排序后的记录保存到目标文件中并同时输出到屏幕上。
 
输入： 键盘输入源文件和目标文件的文件名
 
输出： 将处理后的学生记录输出到目标文件和屏幕 
输入样例： 源数据文件和目标数据文件名：

SrcData.txt

DstData.txt

源数据文件内容：

10001,F,1987/4/1,2006/9/1
10005,F,1989/11/30,2008/9/1
10005,F,1989/11/30,2008/9/1
10006,M,1986/3/14,2005/9/1
10002,M,1988/5/5,2006/9/1
10003,M,1985/8/13,2005/4/1
10004,M,1985/12/15,2006/4/1
10003,M,1985/8/13,2005/4/1

 
 
输出样例： 目标文件和屏幕打印的内容：

10001,F,1987/4/1,2006/9/1
10002,M,1988/5/5,2006/9/1
10003,M,1985/8/13,2005/4/1
10004,M,1985/12/15,2006/4/1
10005,F,1989/11/30,2008/9/1
10006,M,1986/3/14,2005/9/1
*/
