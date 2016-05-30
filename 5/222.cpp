#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Person{
protected:
    string szName;
public:
    Person(string name):szName(name){}
    virtual void Print(){cout<<"Person "<<szName<<endl;}
    virtual ~Person(){}
};

class Student:public Person{
protected:
    int iNumber;
public:
    Student(string name,int number):Person(name),iNumber(number){}
    void Print(){cout<<"Student "<<szName<<" "<<iNumber<<endl;}
    virtual ~Student(){}
};

class Teacher:public Person{
protected:
    int iYear;
public:
    Teacher(string name,int year):Person(name),iYear(year){}
    void Print(){cout<<"Teacher "<<szName<<" "<<iYear<<endl;}
    virtual ~Teacher(){}
};

class Graduate:public Student{
protected:
    string szResearch;
public:
    Graduate(string name,int number,string research):Student(name,number),szResearch(research){}
    void Print(){cout<<"Graduate "<<szName<<" "<<iNumber<<" "<<szResearch<<endl;}
    virtual ~Graduate(){}
};
int main()
{
    int num;
    string option1,name,research,option2;
    int number,year;
    cin>>num;
    Person *p[num];
    for(int i=0;i<num;i++){
        cin>>option1;
        if(option1=="Person"){
            cin>>name;
            p[i] = new Person(name);
        }
        else if(option1=="Student"){
            cin>>name>>number;
            p[i] = new Student(name,number);
        }
        else if(option1=="Teacher"){
            cin>>name>>year;
            p[i] = new Teacher(name,year);
        }
        else if(option1=="Graduate"){
            cin>>name>>number>>research;
            p[i] = new Graduate(name,number,research);
        }
    }
    cin>>option2;
    while(option2!="exit"){
        int n=atoi(option2.c_str());
        p[n]->Print();
        cin>>option2;
    }
    for(int i=0;i<num;i++)
        delete p[i];

    return 0;
}
