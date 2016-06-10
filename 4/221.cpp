#include <iostream>
#include <string>
using namespace std;

class StudentRecord{
public:
    string stuName;
    int stuNo;

    void print(){
        cout<<"Name: "<<stuName<<", Number: "<<stuNo<<endl;
    }
};
class StudentNode{
public:
    StudentRecord data;
    StudentNode *next;
    StudentNode(){
        next = NULL;
    }
};

class LinkedList{
protected:
    StudentNode *first;
public:
    LinkedList(){first = NULL;}
    void HeadInsert(){
        string name;
        int no;
        cin>>name>>no;
        if(first == NULL){
            StudentNode *newNode = new StudentNode();
            newNode->data.stuName = name;
            newNode->data.stuNo = no;
            first = newNode;
            newNode->next = NULL;
        }
        else{
            StudentNode *newNode = new StudentNode();
            newNode->data.stuName = name;
            newNode->data.stuNo = no;
            newNode->next = first;
            first = newNode;
        }
    }

    void LastInsert(){
        string name;
        int no;
        cin>>name>>no;
        if(first == NULL){
            StudentNode *newNode = new StudentNode();
            newNode->data.stuName = name;
            newNode->data.stuNo = no;
            first = newNode;
            newNode->next = NULL;
        }
        else{
            StudentNode *current = first;
        while((current->next)!=NULL){
            current = current->next;
        }
        StudentNode *newNode = new StudentNode();
        newNode->data.stuName = name;
        newNode->data.stuNo = no;
        newNode->next = NULL;
        current->next = newNode;
        }

    }

    bool HeadDelete(){
        if(first != NULL){
            StudentNode *del = first;
        if((first->next)!=NULL){
            cout<<"Name: "<<first->data.stuName<<", Number: "<<first->data.stuNo<<endl;
            first = first->next;
            delete del;
            return true;
        }
        else{
            cout<<"Name: "<<first->data.stuName<<", Number: "<<first->data.stuNo<<endl;
            delete del;
            first = NULL;
            return true;
        }
        return false;
        }
        else
            return false;

    }

    bool LastDelete(){
        if(first->next != NULL){
            StudentNode *current = first;
        if((first->next)!=NULL){
            while((current->next->next)!=NULL){
            current = current->next;
            }
            StudentNode *del = current->next;
            current->next = NULL;
            cout<<"Name: "<<current->data.stuName<<", Number: "<<current->data.stuNo<<endl;
            delete del;
            return true;
        }
        else{
            cout<<"Name: "<<first->data.stuName<<", Number: "<<first->data.stuNo<<endl;
            delete current;
            first = NULL;
            return true;
        }
        return false;
        }
        else
            return false;

    }

    void Traverse(){
        StudentNode *current = first;
        while(current->next!=NULL){
            cout<<current->data.stuName<<current->data.stuNo<<endl;
            current= current->next;
        }
    }
};
class LinkedStack:public LinkedList{
public:
    void Push(){
        LinkedList::HeadInsert();
    }

    void Pop(){
        if(LinkedList::HeadDelete())
            return;
        else
            cout<<"Stack is empty!"<<endl;
    }
};
class LinkedQueue:public LinkedList{
public:
    void EnQueue(){
        LinkedList::LastInsert();
    }

    void DeQueue(){
        if(LinkedList::HeadDelete())
            return;
        else
            cout<<"Queue is empty!"<<endl;
    }

};
int main(){
    LinkedQueue que;
    LinkedStack sta;
    string c;
    cin>>c;
    while(c!="Exit"){
        if(c == "Push")
            sta.Push();
        else if(c == "Pop")
            sta.Pop();
        else if(c == "EnQueue")
            que.EnQueue();
        else if(c == "DeQueue")
            que.DeQueue();
        else
            cout<<"Input error!"<<endl;
        cin>>c;
    }
}
/*
描述： 设计单链表类，并基于单链表类实现栈类和队列类：

（1）设计学生信息类StudentRecord，要求包含公有数据成员：string stuName和int stuNo，设计用于输出学生信息的公有成员函数：void print，输出格式为：Name: stuName, Number: stuNo。

（2）设计学生链表的结点类StudentNode，要求包含公有数据成员：StudentRecord data和StudentNode *next。

（3）设计学生链表类LinkedList，要求定义头插入、头删除、尾插入、遍历等公有成员函数

。

（4）由LinkedList派生LinkedStack类，基于单链表类的功能实现压栈和出栈的成员函数：void Push(StudentRecord record)和bool Pop(StudentRecord &record)。

（5）由LinkedList派生LinkedQueue类，基于单链表类的功能实现入队和出队的成员函数：void EnQueue(StudentRecord record)和bool DeQueue(StudentRecord &record)。

 

在main函数中：

定义一个LinkedQueue类的对象queue和一个LinkedStack类的对象stack，并根据用户的输入分别对queue和stack作出相应的操作。若为"Push",则压栈；若为"EnQueue",则入队；若为"Pop",则出栈；若为"DeQueue",则出队；若为"Exit"，则退出；若为其它，则给出提示信息"Input error!"。入栈和入队时，输入学生姓名和学号。出栈和出队时，若非空，则输出被删除的学生信息；若栈空，则输出Stack is empty!"；若队空，则输出"Queue is empty!"。
 
输入： 操作名；

学生姓名，学号。 
 
输出： 删除的信息；提示信息。
 
输入样例： Push
ZhangSan 200905
Push
LiSi 200906
EnQueue
WangWu 200907
Pop
exit
Exit
 
输出样例： Name: LiSi, Number: 200906
Input error!
*/
