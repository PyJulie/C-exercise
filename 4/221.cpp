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
