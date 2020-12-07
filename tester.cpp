using namespace std;
#include "newSeven.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Manager : public Employee

{
public:
    //default constructor
    Manager();

        //overloaded constructor
    Manager(double theSalary, double thePension, double theMedicalAid, float theTaxPercentage, double theAllowance);

    //function to display salary details
    void Display();

    //function to get entertainment allowance amount
    double getAllowance();

    //overridden function to calculate the tax
    double calcTax(double grossPay, double deductions, double allowance);

    //overridden function to calculate the gross pay
    double calcGrossPay();



private:
    //entertainment allowance
    double Allowance;
};

//overloaded constrcutor
Manager::Manager(double theSalary, double thePension, double theMedicalAid, float theTaxPercentage, double theAllowance):Employee(theSalary, thePension, theMedicalAid, theTaxPercentage)
{
    Allowance = theAllowance;
}
//accessor for entertainment allowance
double Manager::getAllowance()
{
    return Allowance;
}

//function to display salary details
void Manager::Display()
{
    cout<<"\nThe details of the manager's salary are the following: ";


    cout << "basic salary: R" << getBasicSalary() << endl;
    cout << "pension amount: R" << getPension() << endl;
    cout << "medical aid amount: R" << getMedicalAid() << endl;
    cout << "Allowance: R" << Allowance << endl;
    cout << "% tax paid: " << getTaxPercentage();

}

double Manager::calcTax(double grossPay, double deductions, double allowance)
{
      float taxP = getTaxPercentage();
    double taxAmount = taxP*(grossPay-deductions);

        return taxAmount;
}

    //function to calculate gross pay
double Manager::calcGrossPay()
    {
        //get the values
        double theBasicSalary = getBasicSalary();
        double thePension = getPension();
        double theMed= getMedicalAid();
        double theAllowance = getAllowance();

        //calculate gross salary
        double grossPay = theBasicSalary+thePension+theMed+theAllowance;

        return grossPay;

    }

int main()
{
    //instantiate an object of type Manager
    Manager manager(60560, 5500, 2800, 0.14, 3100);

    manager.Display();

    double currentGrossPay = manager.calcGrossPay();
    cout <<endl<<"Current gross pay: "<<currentGrossPay;

    double currentDeductions = manager.Employee::calcDeductions(manager);
    cout<<"\nDeductions: "<<currentDeductions;

    double currentAllowance = manager.getAllowance();

    double currentTaxAmount = manager.calcTax(currentGrossPay, currentDeductions, currentAllowance);
    cout<<endl<<"tax: "<<currentTaxAmount;

    double netSalary = currentGrossPay - currentTaxAmount - currentDeductions;

   cout <<"\nNetSalary after medical aid, pension and tax has been paid: "<<netSalary;



}

