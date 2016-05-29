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
