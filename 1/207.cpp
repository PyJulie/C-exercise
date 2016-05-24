#include <iostream>
#include <string>
using namespace std;
class Student{
public:
    int number;
    string name;
    string sex;
    int age;
    Student *next;
};
int main()
{
    int no,flag=0,i=0;
    Student *p=NULL;
    Student *current=NULL;
    Student *rear=NULL;
    Student *node=NULL;
    Student *head=NULL;
    for(int i=0; i<5; i++)
    {
        node=new Student;
        cin>>node->number;
        cin>>node->name;
        cin>>node->sex;
        cin>>node->age;
        if(head==NULL)
            head=node;
        else
            p->next=node;
        p=node;
        if(i==4)
        {
            p->next=NULL;
            rear=p;
        }
    }

    p=head;

    cin>>no;
    while(p!=NULL){

        if(p->age==no)
            {
                flag=1;
                break;
            }
            p=p->next;
            i++;
    }
    current=head;
    while(--i && flag==1 && current!=NULL){
        current=current->next;}
    if(flag){
    Student *delnow = current->next;
    current->next = delnow->next;
    delete delnow;}

if(!flag){
        Student *laststudent = new Student;
        rear->next=laststudent;
        rear=laststudent;
        laststudent->age=no;
        laststudent->number=180;
        laststudent->name="aaa";
        laststudent->sex="male";
        laststudent->next=NULL;
    }
    p=head;
    while(p!=NULL)
    {
        cout<<p->number<<endl;
        cout<<p->name<<endl;
        cout<<p->sex<<endl;
        cout<<p->age<<endl;
        p=p->next;
    }
//销毁链表
    Student *q;
    p=head;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        delete q;
    }
    return 0;
}
