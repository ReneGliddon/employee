#include <iostream>

using namespace std;

class Employee{
    public:
        Employee();
        Employee(double sal, double pen, double medical, float tax);
        double getSalary();
        double getPension();
        double getMedicalAid();
        float getTaxPercentage();

        double calcTax();
        double calcGrossPay();
        double calcDeductions();

    private:
        double salary;
        double pension;
        double medicalAid;
        float taxPercentage;
};

Employee::Employee(double sal, double pen, double medical, float tax){
    salary = sal;
    pension = pen;
    medicalAid = medical;
    taxPercentage = tax;
}

double Employee::getSalary(){
    return salary;
}

double Employee::getPension(){
    return pension;
}

double Employee::getMedicalAid(){
    return medicalAid;
}
float Employee::getTaxPercentage(){
    return taxPercentage;
}

double Employee::calcGrossPay(){
    return (salary + pension + medicalAid);
}

double Employee::calcTax(){
    return (calcGrossPay()*taxPercentage);
}

double Employee::calcDeductions(){
    return ((pension*2) + (medicalAid*2));
}
