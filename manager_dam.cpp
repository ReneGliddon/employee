
#include <iostream>
#include "manager_dam.h"

using namespace std;

int main(){

    Manager jeff(60560, 5500, 2800, 0.14, 3100);

    jeff.Display();

    cout << "\nSalary Deduction: \tR " << jeff.calcDeductions() << endl;
    cout << "Payable Tax: \t\tR " << jeff.calcTax() << endl;
    cout << "Net Salary: \t\tR " << jeff.calcGrossPay() - jeff.calcTax() - jeff.calcDeductions() << endl;

    return 0;
}
