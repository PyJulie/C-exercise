#include <iostream>
#include <string>
using namespace std;

class Person{
private:
    string Name;
public:
    string Gender;
    int Age;

    void Changename(){
        const string s="郑八";
        Name.assign(s);
    }
    string ShowName(){
        return Name;
    }
    Person(){
        Name="郑七";
        Age=22;
        Gender="男";
        cout<<"Person"<<Name<<"constructed"<<endl;
        }
    ~Person(){cout<<"Person"<<Name<<"destructed"<<endl;}
};

class StudentRecord:public virtual Person{
private:
    int Score;
public:
    string Number;
    string ClassName;
    int TotalCount;


    StudentRecord(){
        Score=89;
        Number="2010123";
        ClassName="软20101";
        TotalCount=1;
        cout<<"Student"<<Person::ShowName()<<"constructed"<<endl;
    }
    int ShowScore(){
        return Score;
    }
    ~StudentRecord(){cout<<"Student"<<Person::ShowName()<<"destructed"<<endl;}
};

class TeacherRecord:public virtual Person{
private:
    int Year;
public:
    string CollegeName;
    string DepartmentName;


    TeacherRecord(){
        Year=1;
        CollegeName="信息";
        DepartmentName="软件";
        cout<<"Teacher"<<Person::ShowName()<<"constructed"<<endl;
    }

    int ShowYear(){
        return Year;
    }
    string ShowName(){
        return Person::ShowName();
    }

    ~TeacherRecord(){cout<<"Teacher"<<Person::ShowName()<<"destructed"<<endl;}
};

class TeachingAssistant:public virtual StudentRecord,public virtual TeacherRecord{
public:
    string LectureName;


    TeachingAssistant(){
        LectureName="数据结构";
        cout<<"TeachingAssistant"<<Person::ShowName()<<"constructed"<<endl;
    }

    ~TeachingAssistant(){cout<<"TeachingAssistant"<<Person::ShowName()<<"destructed"<<endl;}


    void Show(){
    cout<<"Name:"<<StudentRecord::ShowName()<<" "
        <<"Gender:"<<StudentRecord::Gender<<" "
        <<"Age:"<<StudentRecord::Age<<" "
        <<"Number:"<<Number<<" "
        <<"ClassName:"<<ClassName<<" "
        <<"TotalCount:"<<TotalCount<<" "
        <<"Score:"<<StudentRecord::ShowScore()<<" "
        <<"CollegeName:"<<CollegeName<<" "
        <<"DepartmentName:"<<DepartmentName<<" "
        <<"Year:"<<TeacherRecord::ShowYear()<<" "
        <<"LectureName:"<<LectureName<<endl;
    }
};
int main()
{
    TeachingAssistant stu;
    stu.Show();
    stu.Changename();
    stu.Show();
    return 0;
}
/*
描述： (1)定义人员类Person:
公有成员：姓名（Name）；
保护成员：性别（Gender），年龄（Age）；

构造函数和析构函数

(2) 从人员类Person派生学生记录类StudentRecord：
添加公有成员：学号（Number），班级（ClassName），
添加静态公有成员：学生总人数（TotalCount）；
添加保护成员：平均成绩（Score）；
实现构造函数和析构函数。
(3) 从人员类Person派生教师记录类TeacherRecord：
添加公有成员：学院（CollegeName），系（DepartmentName）；
添加保护成员：教龄（Year）；
实现构造函数和析构函数。


(4)从学生记录类StudentRecord和教师记录类TeacherRecord派生学生助教类TeachingAssistant：
添加公有成员：辅导课程（LectureName）；
实现公有函数：显示人员信息（Show），屏幕打印 姓名，性别，年龄，学号，班级，学生总人数，平均成绩，学院，系，教龄，辅导课程。
实现构造函数和析构函数。为检验类间结构设计是否正确，设计函数void SetName(String name)实现更改一名助教的姓名的功能。

创建一个助教类的对象

助教
姓名 性别 年龄 学号 班级 平均成绩 学院 系 教龄 辅导课程
郑七 男 22 2010123 软20101 89         信息 软件    1 数据结构
显示其信息。

调用更改姓名的函数，更改其姓名为“郑八”，并再次显示其信息。

 
输入： 无
 
输出： 显示构造的信息和更改前和更改后的助教信息 
输入样例： 无 
输出样例： Person郑七constructed
Student郑七constructed
teacher郑七constructed
teachingassistant郑七constructed
Name:郑七 Gender:男 Age:22 Number:2010123 ClassName:软20101 TotalCount:1 Score:8
9 CollegeName:信息 DepartmentName:软件 Year:1 LectureName:数据结构
Name:郑八 Gender:男 Age:22 Number:2010123 ClassName:软20101 TotalCount:1 Score:8
9 CollegeName:信息 DepartmentName:软件 Year:1 LectureName:数据结构
teachingassistant郑八destructed
teacher郑八destructed
Student郑八destructed
Person郑八destructed
 
提示： 各类的构造函数和析构函数都有输出。

调用公有函数Show,以分别显示各个记录的人员信息。

在派生助教类时，使用虚基类。
*/
