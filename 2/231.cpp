#include <iostream>

using namespace std;

double getEarning(double salary,int absenceDays){
        return salary-absenceDays*salary/22;
}

double getEarning(double baseSalary,double salesSum,double rate){
        return baseSalary+salesSum*rate;
}

double getEarning(int workPieces,double wagePerpiece){
        return workPieces*wagePerpiece;
}

double getEarning(double hours,double wagePerHour){
        return hours*wagePerHour;
}
int main()
{
    int sel,AbsenceDays,WorkPieces;
    double Salary,BaseSalary,SalesSum,Rate,WagePerPiece,hours,wagePerHour;

    cout << "Please select..." << endl;
    cout << "1: Manager." << endl;
    cout << "2: Sales Man." << endl;
    cout << "3: Pieces Worker." << endl;
    cout << "4: Hour-Worker." << endl;
    cout << "Others: Quit" << endl;

    cin >> sel;

    switch(sel)
    {
    case 1:
        cin >> Salary>>AbsenceDays;
        cout << getEarning(Salary,AbsenceDays);
        break;
    case 2:
        cin >> BaseSalary>>SalesSum>>Rate;
        cout << getEarning(BaseSalary,SalesSum,Rate);
        break;
    case 3:
        cin >> WorkPieces>>WagePerPiece;
        cout << getEarning(WorkPieces,WagePerPiece);
        break;
    case 4:
        cin >> hours>>wagePerHour;
        cout << getEarning(hours,wagePerHour);
        break;
    default:
        break;
    }
    return 0;
}
