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
