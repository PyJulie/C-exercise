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
/*
描述：     建立一个链表，每个节点包括学生的学号、姓名、性别、年龄。先输入5个学生的数据，再输入一个年龄，如果链表中有年龄等于此年龄的记录，则删除所有年龄等于此年龄的记录，否则在链表的最后增加一个新节点，学号为180姓名为"aaa"，性别为"male"。。 
输入：     创建链表时输入5个职工的职工号和工资，学号为大于100且小于200的整数，姓名为长度小于20的字符串，性别为长度小于10的字符串，年龄为大于等于0且小于200的整数。 
输出： 按顺序输出链表中的所有数据，每个数据占一行。 
输入样例： 101 zhangsan male 30
103 lisi female 18
105 wangwu male 25
107 maliu male 28
109 niuqi female 22
28 
输出样例： 101
zhangsan
male
30
103
lisi
female
18
105
wangwu
male
25
109
niuqi
female
22
*/
