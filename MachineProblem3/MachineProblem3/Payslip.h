#include <string>

#define SSS 500.00
#define PagIbig 200.00
#define Philhealth 100.00

using namespace std;

class Payslip
{
private:
	string mName;
	char mPayGrade;
	double mBasicSalary, mOThrs, mOTpay, mGrossPay, mNetPay, 
		mWithholdingTax, mTaxRate;
public:
	Payslip(string _name) {}

	void setName(string _name) { this->mName = _name; }
	void setBasicSalary(double _basicSalary) { 
		this->mBasicSalary = _basicSalary; 
	}
	void setOThrs(double _otHrs) { this->mOThrs = _otHrs; }

	string getName() { return mName; }
	char getPayGrade() { return mPayGrade; }
	double getBasicSalary() { return mBasicSalary; }
	double getOThrs() { return mOThrs; }
	double getOTpay() { return mOTpay; }
	double getGrossPay() { return mGrossPay; }
	double getNetPay() { return mNetPay; }
	double getWithholdingTax() { return mWithholdingTax; }

	void determinePayGradeAndTaxRate(double _basicSalary);
	void computePay(double _basicSalary, double _otHrs);
};

void Payslip::determinePayGradeAndTaxRate(double _basicSalary) {
	if (!cin) {
		cin.clear();
		cin.ignore();
		mPayGrade = ' ';
		mTaxRate = 0;
	}
	else if (_basicSalary > 9999 && _basicSalary < 14999) { // 10,000 to 15,000
		mPayGrade = 'A';
		mTaxRate = 0.10;
	}
	else if (_basicSalary > 14999 && _basicSalary < 19999) { // 15,000 to 20,000
		mPayGrade = 'B';
		mTaxRate = 0.10;
	}
	else if (_basicSalary > 19999 && _basicSalary < 24999) { // 20,000 to 25,000
		mPayGrade = 'A';
		mTaxRate = 0.15;
	}
	else if (_basicSalary > 24999 && _basicSalary < 29999) { // 25,000 to 30,000
		mPayGrade = 'B';
		mTaxRate = 0.15;
	}
	else if (_basicSalary > 29999 && _basicSalary < 34999) { // 30,000 to 35,000
		mPayGrade = 'A';
		mTaxRate = 0.20;
	}
	else if (_basicSalary > 34999 && _basicSalary < 39999) { // 35,000 to 40,000
		mPayGrade = 'B';
		mTaxRate = 0.20;
	}
	else if (_basicSalary > 39999 && _basicSalary < 44999) { // 40,000 to 45,000
		mPayGrade = 'A';
		mTaxRate = 0.25;
	}
	else if (_basicSalary > 44999 && _basicSalary < 49999) { // 45,000 to 50,000
		mPayGrade = 'B';
		mTaxRate = 0.25;
	}
	else if (_basicSalary > 49999 && _basicSalary < 54999) { // 50,000 to 55,000
		mPayGrade = 'A';
		mTaxRate = 0.30;
	}
	else if (_basicSalary > 54999) { // 55,000 & up
		mPayGrade = 'B';
		mTaxRate = 0.30;
	}
	else if (_basicSalary < 10000) {
		mPayGrade = ' ';
		mTaxRate = 0;
		cout << "Your salary is below the minimum range. Please ask for a raise to your Manager." 
			<< endl;
	}
}

void Payslip::computePay(double _basicSalary, double _otHrs) {
	/*Gross pay = basic salary + OT pay
		OT pay = no.of OT hours * 1 % of basic salary
		Net pay = gross pay – withholding tax – fixed values
		Withholding tax = gross pay * tax rate
		6.	The following are fixed values:
SSS = 500.00
Pag-ibig = 200.00
Philhealth = 100.00
*/
	if (!cin) {
		cin.clear();
		cin.ignore();
	}
	else if (_otHrs < 1 || _basicSalary <= 9999) {
		mOThrs = 0;
		mOTpay = 0;
		mGrossPay = 0;
		mWithholdingTax = 0;
		mNetPay = 0;
	}
	else {
		mOTpay = _otHrs * (_basicSalary * 0.01);
		mGrossPay = _basicSalary + mOTpay;
		mWithholdingTax = mGrossPay * mTaxRate;
		mNetPay = mGrossPay - mWithholdingTax - SSS - PagIbig - Philhealth;
	}
		
}

