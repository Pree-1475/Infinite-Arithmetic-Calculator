#include "my_inf_arith.h"

using namespace std;
using namespace InfiniteArithmetic;

// Variable to store Remainder when division takes place
string remain;

/**
 * @brief Default Constructor where intnumber assigns to "0"
 * @return Integer
 */
Integer ::Integer()
{
	intnumber = "0";
}

/**
 * @brief Parameterised Constructor where private number intnumber
 *  is assigned to other_number
 * @param other_number
 * @return Integer
 */
Integer ::Integer(string other_number)
{
	intnumber = other_number;
}

/**
 * @brief Copy constructor which is used copy contents from one
 * string to the copy string
 * @param copy
 * @return Integer
 */
Integer ::Integer(const Integer &copy)
{
	intnumber = copy.intnumber;
}

/**
 * @brief Destructor which is used to delete the contents of the string
 * @return Integer
 */
Integer ::~Integer()
{
	intnumber = "";
}

/**
 * @brief Overloaded operator which is used to add two numbers which
 * is done through digit to digit approach
 * @param other_number
 * @return string
 */
string Integer ::operator+(const Integer &other_number)
{

	string n1 = this->intnumber;
	string n2 = other_number.intnumber;
	bool isNegative1 = false, isNegative2 = false;

	checkAndRemoveNegativeSign(n1, isNegative1);
	checkAndRemoveNegativeSign(n2, isNegative2);

	n1 = removeLeadingZeroes(n1);
	n2 = removeLeadingZeroes(n2);

	string result;
	int carry = 0;
	int sum = 0;

	if (isNegative1 == isNegative2)
	{
		reverse(n1.begin(), n1.end());
		reverse(n2.begin(), n2.end());

		int max_size = max(n1.size(), n2.size());

		for (int i = 0; i < max_size; i++)
		{
			int digit1 = 0, digit2 = 0;
			if (i < n1.size())
			{
				digit1 = n1[i] - '0';
			}

			if (i < n2.size())
			{
				digit2 = n2[i] - '0';
			}

			sum = carry + digit1 + digit2;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}

		if (carry)
		{
			result.push_back(carry + '0');
		}
	}

	if (isNegative1 != isNegative2)
	{
		Integer a(n1);
		Integer b(n2);
		string temp = a - b;
		if (isNegative1)
		{
			temp = "-" + temp;
		}
		reverse(temp.begin(), temp.end());
		result = temp;
	}

	bool isNegativeResult = false;

	if (isNegative1 && isNegative2)
	{
		isNegativeResult = true;
	}

	reverse(result.begin(), result.end());
	result = removeLeadingZeroes(result);
	if (isNegativeResult)
	{
		result = "-" + result;
	}

	if (result[0] == '-' && result[1] == '-')
	{
		result = result.substr(2);
	}

	if (result == "-0")
	{
		result = "0";
	}

	return result;
}

/**
 * @brief Overloaded Operator which subracts the two given strings
 * using digit to digit approach
 * @param other_number
 * @return string
 */

string Integer ::operator-(const Integer &other_number)
{
	string n1 = this->intnumber;
	string n2 = other_number.intnumber;
	bool isNegative1 = false, isNegative2 = false;

	checkAndRemoveNegativeSign(n1, isNegative1);
	checkAndRemoveNegativeSign(n2, isNegative2);

	int max_size = max(n1.size(), n2.size());

	if (n1.size() < max_size)
	{
		n1 = string(max_size - n1.size(), '0') + n1;
	}
	if (n2.size() < max_size)
	{
		n2 = string(max_size - n2.size(), '0') + n2;
	}

	bool Swapnumber = false;
	bool isNegativeResult = false;
	string result;
	if (n1 < n2 && (isNegative1 == isNegative2))
	{
		swap(n1, n2);
		Swapnumber = true;
	}

	if (isNegative1 == isNegative2)
	{
		reverse(n1.begin(), n1.end());
		reverse(n2.begin(), n2.end());

		int borrow = 0;
		int diff;
		for (int i = 0; i < max(n1.size(), n2.size()); i++)
		{

			int digit1 = 0, digit2 = 0;
			if (i < n1.size())
			{
				digit1 = n1[i] - '0';
			}
			if (i < n2.size())
			{
				digit2 = n2[i] - '0';
			}
			diff = digit1 - digit2 - borrow;

			if (diff < 0)
			{
				diff += 10;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}
			result.push_back(diff + '0');
		}
	}
	else
	{
		Integer p(n1);
		Integer q(n2);
		string temp = p + q;
		if (isNegative1)
		{
			temp = "-" + temp;
		}
		reverse(temp.begin(), temp.end());
		result = temp;
	}

	if (isNegative1 && isNegative2)
	{
		isNegativeResult = true;
	}

	reverse(result.begin(), result.end());

	result = removeLeadingZeroes(result);

	if (isNegativeResult)
	{
		result = "-" + result;
	}

	if (Swapnumber)
	{
		result = "-" + result;
	}

	if (result[0] == '-' && result[1] == '-')
	{
		result = result.substr(2);
	}

	if (result == "-0")
	{
		result = "0";
	}

	return result;
}

/**
 * @brief Non Parameterised Constructor where the private number
 * floatnumber is assigned to "0"
 * @return Float
 */
Float ::Float()
{
	floatnumber = "0.0";
}
/**
 * @brief Parameterised Constructor where the private number
 * floatnumber is assigned to other_number
 * @param other_number
 * @return Float
 */
Float ::Float(string s)
{
	floatnumber = s;
}
/**
 * @brief Copy Constructor where the private number floatnumber is
 * assigned to copy
 * @param copy
 * @return Float
 */
Float ::Float(const Float &copy)
{
	floatnumber = copy.floatnumber;
}

/**
 * @brief Destructor which destroys the allocated memory for the
 * object of respective class
 * @return Float
 */
Float ::~Float()
{
	floatnumber = "";
}
/**
 * @brief Overloaded operator which is used to add two numbers done through
 * overloaded + operator of Integer class
 * @param other_number
 * @return string
 */
string Float ::operator+(const Float &other_number)
{
	string n1 = floatnumber;
	string n2 = other_number.floatnumber;
	bool isNegative1 = false, isNegative2 = false;

	checkAndRemoveNegativeSign(n1, isNegative1);
	checkAndRemoveNegativeSign(n2, isNegative2);

	int nd;

	ftos(n1, n2, nd);

	Integer i1(n1);
	Integer i2(n2);

	string result;

	if (isNegative1 == isNegative2)
	{
		result = (i1 + i2);
	}
	else
	{
		result = (i1 - i2);
	}

	if (isNegative1)
	{
		result = "-" + result;
	}

	if (result[0] == '.')
	{
		result = result.substr(1);
	}

	int dot_position = result.size() - nd;
	result.insert(dot_position, ".");

	if (result.front() == '-' && result[1] == '-')
	{
		result = result.erase(0, 2);
	}

	result = removeTrailingZeroes(result);

	if (result.front() == '.')
	{
		result = "0" + result;
	}

	return result;
}

/**
 * @brief Overloaded operator which is used to subracts two numbers done through
 * overloaded - operator of Integer class
 * @param other_number
 * @return string
 */
string Float ::operator-(const Float &other_number)
{
	string n1 = this->floatnumber;
	string n2 = other_number.floatnumber;
	bool isNegative1 = false, isNegative2 = false;

	checkAndRemoveNegativeSign(n1, isNegative1);
	checkAndRemoveNegativeSign(n2, isNegative2);

	int nd;
	ftos(n1, n2, nd);
	bool isSwap = false;
	int max_size = max(n1.size(), n2.size());

	if (n1.size() < max_size)
	{
		n1 = string(max_size - n1.size(), '0') + n1;
	}
	if (n2.size() < max_size)
	{
		n2 = string(max_size - n2.size(), '0') + n2;
	}

	if ((n1 > n2) && (isNegative1 && isNegative2))
	{
		swap(n1, n2);
		isSwap = true;
	}

	Integer i1(n1);
	Integer i2(n2);

	string result;
	if (isNegative1 != isNegative2)
	{
		result = (i1 + i2);
	}
	else
	{
		result = (i1 - i2);
	}

	if ((isNegative1 != isNegative2) && isNegative1)
	{
		result = "-" + result;
	}

	if ((isNegative1 && isNegative2) && result.front() == '-' && !(isSwap))
	{
		result = result.substr(1);
	}

	int dot_position = result.size() - nd;
	result.insert(dot_position, ".");

	if (result.front() == '-' && result[1] == '-')
	{
		result = result.erase(0, 2);
	}

	// result = removeTrailingZeroes(result);

	if (result.front() == '.')
	{
		result = "0" + result;
	}

	return result;
}
/**
 * @brief Overloaded operator which is used to multiply two
 * numbers done through traditional way of multiplying tho numbers
 * @param s
 * @return string
 */
string Integer ::operator*(const Integer &s)
{
	string num1 = this->intnumber;
	string num2 = s.intnumber;
	bool isNegative1, isNegative2;

	checkAndRemoveNegativeSign(num1, isNegative1);
	checkAndRemoveNegativeSign(num2, isNegative2);

	int size1 = num1.size();
	int size2 = num2.size();

	if (num1 == "0" || num2 == "0")
	{
		return "0";
	}

	if (num1.size() == 0 || num2.size() == 0)
	{
		return "0";
	}

	vector<int> result(num1.size() + num2.size(), 0);

	for (int i = size1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';
		for (int j = size2 - 1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';
			int sum = n1 * n2 + result[i + j + 1] + carry;

			carry = sum / 10;

			result[i + j + 1] = sum % 10;
		}
		result[i] += carry;
	}
	int i = 0;
	while (i < result.size() && result[i] == 0)
	{
		i++;
	}

	if (i == -1)
	{
		return "0";
	}

	string str = "";

	while (i < result.size())
	{
		str += to_string(result[i++]);
	}

	str = removeLeadingZeroes(str);

	if (isNegative1 != isNegative2)
	{
		str = "-" + str;
	}

	return str;
}
/**
 * @brief Overloaded operator which is used to multiply
 * two numbers done through * of Integer class
 * @param s
 * @return string
 */
string Float ::operator*(const Float &s)
{
	string n1 = this->floatnumber;
	string n2 = s.floatnumber;
	bool isNegative1, isNegative2;

	checkAndRemoveNegativeSign(n1, isNegative1);
	checkAndRemoveNegativeSign(n2, isNegative2);

	n1 = removeTrailingZeroes(n1);
	n2 = removeTrailingZeroes(n2);
	int n1d = 0, n2d = 0, nd;
	int decimalPos1 = n1.find('.');
	int decimalPos2 = n2.find('.');

	if (decimalPos1 != std::string::npos)
	{
		n1d = n1.length() - decimalPos1 - 1;
	}

	if (decimalPos2 != std::string::npos)
	{
		n2d = n2.length() - decimalPos2 - 1;
	}

	ftos(n1, n2, nd);

	nd = n1d + n2d;

	Integer i1(n1);
	Integer i2(n2);

	string result;

	result = i1 * i2;

	if (isNegative1 != isNegative2)
	{
		result = "-" + result;
	}

	int dot_position = result.size() - nd;
	result.insert(result.begin() + dot_position, '.');

	result = removeTrailingZeroes(result);

	return result;
}
/**
 * @brief Overloaded operator which is used to divide two number through
 * long Divison method
 * @param s
 * @return string
 */
string Integer ::operator/(const Integer &s)
{
	string n1 = this->intnumber;
	string n2 = s.intnumber;
	bool isNegative1, isNegative2;
	checkAndRemoveNegativeSign(n1, isNegative1);
	checkAndRemoveNegativeSign(n2, isNegative2);

	string result = "";
	int ZeroBalance = 0;
	int preivousDifference = 0;
	if (!CheckDivison(n1, n2))
	{
		remain = n1;
		return "0";
	}
	if (HaveAllZeroes(n2))
	{
		return "Divison by Zero error";
	}

	if (HaveAllZeroes(n1))
	{
		return "0";
	}
	while (!HaveAllZeroes(n1))
	{
		string dividend = "";
		while (!CheckDivison(dividend, n2))
		{
			dividend.push_back(n1[0]);
			n1.erase(0, 1);
		}
		ZeroBalance = dividend.size() - preivousDifference;
		ZeroBalance--;
		result.append(ZeroBalance,'0');
		Integer a(dividend);
		Integer b(n2);
		string difference = "";
		int i;

		for (i = 0; i <= 10; i++)
		{
			Integer loop(to_string(i));
			string temp = loop * b;
			Integer Temp(temp);
			difference = a - Temp;
			if (!difference.empty() && difference.front() == '-' )
			{
				i--;
				Integer differenceInt(difference);
				difference = differenceInt + b;
				n1 = difference + n1;
				break;
			}
			preivousDifference = difference.size();
			if (HaveAllZeroes(difference))
			{
				preivousDifference = 0;
				break;
			}
		}
		result.push_back(i + '0');
		if (HaveAllZeroes(n1))
		{
			result = result + n1;
		}
		if (!CheckDivison(n1, n2))
		{
			remain = n1;
			break;
		}
		else
		{
			continue;
		}
	}

	if ((preivousDifference == 0) && (!CheckDivison(n1, n2)))
	{
		result.append(n1.size(),'0');
	}
	if (isNegative1 != isNegative2)
	{
		result = "-" + result;
	}
	else
	{
	}

	result = removeLeadingZeroes(result);

	return result;
}
/**
 * @brief Oveloaded Operator which divides two numbers using the
 * above the / of Integer class and Remainder
 * @param s
 * @return string
 */
string Float::operator/(const Float &s)
{

	string n1 = this->floatnumber;
	string n2 = s.floatnumber;
	string result = "";

	bool isNegative1, isNegative2;
	checkAndRemoveNegativeSign(n1, isNegative1);
	checkAndRemoveNegativeSign(n2, isNegative2);

	int no_use;
	ftos(n1, n2, no_use);

	if (HaveAllZeroes(n1))
	{
		return "Division by zero error";
	}
	if (HaveAllZeroes(n2))
	{
		return "0";
	}

	Integer a(n1);
	Integer b(n2);

	result = a / b;
	if (remain == "0")
	{
		result = result + ".0";
		return result;
	}
	else
	{
		result = result + ".";
	}
	int size = result.size();
	string temp = remain;
	int DecimalPrecision = 0;
	while (DecimalPrecision < 999)
	{
		int zeroes = -1;
		while (!CheckDivison(temp, n1))
		{
			temp = temp + "0";
			zeroes++;
		}
		for (int i = 0; i < zeroes; i++)
		{
			result = result + "0";
		}
		Integer tempInt(temp);
		string tempResult = tempInt / b;
		result = result + tempResult;
		temp = remain;
		DecimalPrecision++;
	}

	if (isNegative1 != isNegative2)
	{
		result = "-" + result;
	}
	
	result = removeTrailingZeroes(result);
	return result;
}

