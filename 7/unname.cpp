#include <iostream>
#include <map>
#include <string>
using namespace std;
class friends{
public:
    string name;
    string number;
    int age;
    friends():name(""),number(""),age(0){}
    friends(string name1,string number1,int age1):name(name1),number(number1),age(age1){}
    friend ostream &operator <<(ostream &out,friends &a){
        out<<a.name<<" "<<a.number<<" "<<a.age;
        return out;
    }
};
int main()
{
    multimap<string,friends> f1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name1,name,number;
        int age;
        cin>>name1>>name>>number;
        cin>>age;
        friends friend1(name,number,age);
        f1.insert(pair<string,friends>(name1,friend1));
    }
    int n1;
    cin>>n1;
    multimap<string,friends>::iterator i1,i2;
    multimap<string,friends> sf;
    for(int i=0;i<n1;i++){
        pair<multimap<string,friends>::iterator,multimap<string,friends>::iterator > ret;
        string name2;
        cin>>name2;
        ret=f1.equal_range(name2);
        if(i==0){
            for(i1=ret.first;i1!=ret.second;i1++){
                friends f2;
                f2.name=i1->second.name;
                f2.age=i1->second.age;
                f2.number=1;
                sf.insert(pair<string,friends>(i1->second.number,f2));
            }
        }
        else{
            for(i1=ret.first; i1 != ret.second; i1++){
                pair<multimap<string,friends> :: iterator,
                multimap<string,friends>::iterator>record;
                record=sf.equal_range(i1->second.number);
                for(i2=record.first;i2!=record.second;i2++){
                    if(i2->second.name==i1->second.name&&i2->second.age==i1->.second.age)
                        i2->second.number++;
                }
            }
        }
    }
    return 0;
}

