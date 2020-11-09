//////////////////////////////////////////////////////
/// Author : Kevin Balmores
/// Date : November 6, 2020
/// App : Payslip
/////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Payslip.h"
using namespace std;

int main()
{
    Payslip payslip("");
    char employee[99];
    double otHours, basicSalary;

    cout << " Employee Name: ";
    cin.getline(employee, 99);
    
    cout << " Basic Salary: Php ";
    cin >> basicSalary;
    
    cout << " Overtime Hours: ";
    cin >> otHours;

    payslip.setName(employee);
    payslip.setBasicSalary(basicSalary);
    payslip.setOThrs(otHours);
    payslip.determinePayGradeAndTaxRate(basicSalary);
    payslip.computePay(basicSalary, otHours);

    cout.imbue(locale(""));
    cout << endl;
    cout << "\t\t----------PAYSLIP----------" << endl;
    cout << " Employee Name\t: " << payslip.getName() << endl;
    cout << " Basic Salary\t: Php " << fixed << setprecision(2) 
        << payslip.getBasicSalary() << endl;
    cout << " Pay Grade\t: " << payslip.getPayGrade() << endl;
    cout << " No. of OT Hours: " << fixed << setprecision(1) 
        << payslip.getOThrs() << " hour(s)" << endl;
    cout << fixed << setprecision(2);
    cout << " OT Pay\t\t: Php "  << payslip.getOTpay() << endl;
    cout << " Gross Pay\t: Php " << payslip.getGrossPay() << endl;
    cout << " Withholding Tax: Php " << payslip.getWithholdingTax() << endl;
    cout << " Net Pay\t: Php " << payslip.getNetPay() << endl;
    cout << endl;
}

