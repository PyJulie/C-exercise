#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
    string file1;
    string file2;
    string text;
    int line=1;
    cin >> file1 >> file2;
    ifstream in(file1.c_str());
    ofstream out(file2.c_str());

    if(in.fail()||out.fail())
    {
        return 0;
    }


    while(!in.eof())
    {
        getline(in,text);
        cout <<setw(4) << setfill('0') << line << ' ' << text << endl;
        out <<setw(4) << setfill('0') << line << ' ' << text << endl;
        line++;
    }

    return 0;
}
