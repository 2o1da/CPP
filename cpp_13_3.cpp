#include "cpp_13_3.h"

#include <iostream>
#include <string>
using namespace std;

typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string& s, long an, double bal)
{
	fullName = s;
	accctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "���̳ʽ� �Ա��� ������ �ʽ��ϴ�.\n"
		"�׷��� �Ա��� ��ҵǾ����ϴ�.\n";
	else
		balance += amt;
}

void Brass::WithDraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "���̳ʽ� ������ ������ �ʽ��ϴ�.\n"
		"�׷��� ������ ��ҵǾ����ϴ�.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "������ �䱸�� �ݾ�:" << amt
		<< "�� ���� �ܾ��� �ʰ��մϴ�.\n"
		<< "�׷��� ������ ��ҵǾ����ϴ�.\n";

	restore(initialState, prec);
}

double Brass::Balance()const
{
	return balance;
}

void Brass::ViewAcct()const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	cout << "���̸�:" << fullName << endl;
	cout << "���¹�ȣ:" << accctNum << endl;
	cout << "�����ܾ�:" << balance << endl;
	restore(initialState, prec);
}

BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r) :Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct()const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "���� ��� �ѵ���:$" << maxLoan << endl;
	cout << "��ȯ�� ������:$" << owesBank << endl;
	cout.precision(3);
	cout << "���� ��� ������:" << 100 * rate << "%\n";
}

void BrassPlus::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	
	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "���� ��� �ѵ���:$" << advance << endl;
		cout << "���� ��� ����:$" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "���� ��� �ѵ��� �ʰ��Ǿ� �ŷ��� ��ҵǾ����ϴ�.\n";
	restore(initialState, prec);
}

format setFormat()
{
	return cout.setf(ios_base::fixed, ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, ios_base::floatfield);
	cout.precision(p);
}