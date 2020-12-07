#include <iostream>
#include <iomanip>
#include "employee_dam.h"

using namespace std;

class Manager : public Employee{
    public:
        Manager();
        Manager(double sal, double pen, double medical, float tax, double allow);
        void Display();
        double calcGrossPay();
        double calcTax();


    private:
        double allowance;
};

Manager::Manager(double sal, double pen, double medical, float tax, double allow):Employee(sal, pen, medical, tax){
    allowance = allow;
}

void Manager::Display(){

    cout << "Basic Salary: \t\tR " << getSalary() << endl;
    cout << "Pension Amount: \tR " << getPension() << endl;
    cout << "Medical Aid Amount: \tR " << getMedicalAid() << endl;
    cout << "Allowance: \t\tR " << allowance << endl;
    cout << "%Tax Paid: \t\t" << getTaxPercentage() << "%" << endl;
}

double Manager::calcGrossPay(){
    return (getPension() + getMedicalAid() + getSalary() + allowance);
}

double Manager::calcTax(){
    return (calcGrossPay()*getTaxPercentage());
}
