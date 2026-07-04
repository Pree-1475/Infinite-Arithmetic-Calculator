#include "my_inf_arith.h"

/**
 * @brief Functions which checks if the number is negative and remove
 * negative sign from the number
 * @param number 
 * @param isNegative 
 */
void InfiniteArithmetic ::checkAndRemoveNegativeSign(string &number, bool &isNegative)
{
    if ((!number.empty()) && (number.front()) == '-')
    {
        isNegative = true;
        number = number.substr(isNegative);
    }
}

/**
 * @brief Function which removes Leading Zeroes from a number
 * @param n 
 * @return string 
 */
string InfiniteArithmetic ::removeLeadingZeroes(const string &n)
{
    int start = 0;
    while (start < n.length() && n[start] == '0')
    {
        start++;
    }
    if (start == n.length())
    {
        return "0";
    }

    return n.substr(start);
}

/**
 * @brief Function which removes Trailing Zeroes from a number
 * @param n 
 * @return string 
 */
string InfiniteArithmetic ::removeTrailingZeroes(const string &n)
{
    string temp = n;

    int decimal_place = temp.find('.');

    if (decimal_place == string ::npos)
    {
        return temp;
    }

    int lastNonZero = temp.find_last_not_of('0');
    if (lastNonZero != string ::npos && lastNonZero > decimal_place)
    {
        temp.erase(lastNonZero + 1);
    }
    else if (lastNonZero == decimal_place)
    {
        temp.erase(decimal_place);
    }
    else
    {
        temp = "0";
    }

    if (temp.back() == '.')
    {
        temp.pop_back();
    }

    if (temp.front() == '-' && (temp.length() == 1) || (temp.length() > 1 && temp[1] == '.'))
    {
        temp.insert(1, "0");
    }

    return temp;
}

/**
 * @brief Function which converts a float string to Integer string by 
 * removing decimal point
 * @param n1 
 * @param n2 
 * @param nd 
 */
void InfiniteArithmetic ::ftos(string &n1, string &n2, int &nd)
{
    int n1i = n1.find('.');
    int n2i = n2.find('.');

    int n1d, n2d;

    if (n1i == string ::npos)
    {
        n1d = 0;
    }
    else
    {
        n1d = n1.size() - (n1i + 1);
    }

    if (n2i == string ::npos)
    {
        n2d = 0;
    }
    else
    {
        n2d = n2.size() - (n2i + 1);
    }

    nd = max(n1d, n2d);

    if (n1i != string ::npos)
    {
        n1 += string(nd - n1d, '0');
        n1.erase(n1i, 1);
    }

    if (n2i != string ::npos)
    {
        n2 += string(nd - n2d, '0');
        n2.erase(n2i, 1);
    }
}

/**
 * @brief Function which return the integer value of 
 * corresponding charcater value
 * 
 * @param str 
 * @return int 
 */
int InfiniteArithmetic ::getIntValue(const string &str)
{
    int value = 0;
    for (char c : str)
        value = value * 10 + (c - '0');
    return value;
}

/**
 * @brief Function which checks if the numbers are eliglible for divison
 * @param num1 
 * @param num2 
 * @return true 
 * @return false 
 */
bool InfiniteArithmetic ::CheckDivison(const string &num1, const string &num2)
{
	int len1 = num1.length();
	int len2 = num2.length();

	if (len1 < len2)
		return false;
	else if (len1 > len2)
		return true;

	for (int i = 0; i < len1; i++)
	{
		if (num1[i] < num2[i])
			return false;
		else if (num1[i] > num2[i])
			return true;
	}

	return true;
}
/**
 * @brief Function which checks if the given string have 
 * Zeroes in all its places
 * @param s 
 * @return true 
 * @return false 
 */
bool InfiniteArithmetic ::HaveAllZeroes(string &s)
{
	bool temp = (s.find_first_not_of('0') == string ::npos);
	return temp;
}
