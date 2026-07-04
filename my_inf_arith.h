#include <bits/stdc++.h>

using namespace std;

namespace InfiniteArithmetic
{
	class Integer
	{
	public:
		Integer();
		Integer(string other_number);
		Integer(const Integer &copy);
		~Integer();

		void parse(const string &s);
		string operator+(const Integer &s);
		string operator-(const Integer &s);
		string operator*(const Integer &s);
		string operator/(const Integer &s);

	private:
		string intnumber;
	};

	class Float
	{
	public:
		Float();
		Float(string s);
		Float(const Float &copy);
		~Float();

		void parse(const string &s);
		string operator+(const Float &s);
		string operator-(const Float &s);
		string operator*(const Float &s);
		string operator/(const Float &s);

	private:
		string floatnumber;
	};

	void checkAndRemoveNegativeSign(string &number, bool &isNegative);
	string removeLeadingZeroes(const string &n);
	string removeTrailingZeroes(const string &n);
	void ftos(string &n1, string &n2, int &nd);
	int getIntValue(const string &str);
	bool CheckDivison(const string &num1, const string &num2);
	bool HaveAllZeroes(string &s);

}
