#include "stdafx.h"
#include "iostream"

using namespace std;

const int MAX_DOUBLE_BIT = 64;
const long long X1 = 0X8000000000000000;
const int MAX_SHORT_BIT = 32;

void binaryLongLong(const long long &);
void binaryShort(const short );

union DoubleBit
{
	double a;
	long long b;
};

int main()
{
	int i, j = 10;
	
	DoubleBit a;
	cout << "Enter number for task" << endl;
	cin >> a.a;
	cout << "Double:" << endl << "	Binary:" << endl << "		";
	binaryLongLong(a.b);
	cout << endl << "	Hex :" << endl << "		";
	cout << hex << a.b << endl;
	cout << "Short: " << endl;
	cout << "	Binary:" << endl << "		";
	binaryShort(short(a.a));
	cout << endl << "	Hex :" << endl << "		";
	cout << hex << short(a.a) << endl;
	system("pause");
	
	unsigned short int numb, count;
	bool f = true;
	
	cout << "Enter number hightest register" << endl;
	do
	{
		cin >> numb;
		if (f && ((numb > MAX_DOUBLE_BIT) || (numb < 1)))
		{
			cout << "hightest register must be between 65 and 0;" << endl;
			f = false;
		}
	} while ((numb > MAX_DOUBLE_BIT) || (numb < 1));
	f = true;
	cout << "Enter number count of register" << endl;
	do
	{
		cin >> count;
		if (f && (((numb - count) > MAX_DOUBLE_BIT) || ((numb - count) < 0)))
		{
			cout << "count must be between " << int(numb) << " and 0 inclusive;" << endl;
			f = false;
		}
	} while (((numb - count) > MAX_DOUBLE_BIT) || ((numb - count) < 0));

	long long mask = ((X1 >> (count)) ^ ((numb == 64) ? 0 : X1)) >> (MAX_DOUBLE_BIT - numb - 1);
	DoubleBit ans;
	ans.b = a.b ^ mask;
	cout << endl << "Answer:" << endl;
	binaryLongLong(ans.b);
	cout << endl << "Initial data:" << endl;
	binaryLongLong(a.b);
	cout << endl << "Mask for task:" << endl;
	binaryLongLong(mask);
	cout << endl;

	cout << endl << ans.a;
	system("pause");
    return 0;
}

void binaryLongLong(const long long &input)
{
	long long c;
	c = input;
	for (int i = MAX_DOUBLE_BIT; i > 0; --i)
	{
		cout << ((c >> (i - 1)) & 1);
	}
}

void binaryShort(const short input)
{
	short c;
	c = input;
	for (int i = MAX_SHORT_BIT; i > 0; --i)
	{
		cout << ((c >> (i - 1)) & 1);
	}
}
