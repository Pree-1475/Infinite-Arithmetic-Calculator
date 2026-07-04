#include"my_inf_arith.h"

using namespace InfiniteArithmetic;

int main(int no,char *arg[])
{
	string filename = arg[0];
	string type = arg[1];
	string oper = arg[2];
	string s1 = arg[3];
	string s2 = arg[4];

	string result;

	int o = 0;
	if (oper == "add")
	{
		o = 1;
	}
	if (oper == "sub")
	{
		o = 2;
	}
	if (oper == "mul")
	{
		o = 3;
	}
	if (oper == "div")
	{
		o = 4;
	}
	if (type == "int")
	{
		Integer a(s1);
		Integer b(s2);
		switch (o)
		{
		case 1:
			result = a + b;
			break;
		case 2:
			result = a - b;
			break;
		case 3:
			result = a * b;
			break;
		case 4:
			result = a / b;
			break;
		}
	}

	else if (type == "float")
	{
		InfiniteArithmetic::Float a(s1);
		InfiniteArithmetic::Float b(s2);
		switch (o)
		{
		case 1:
			result = a + b;
			break;
		case 2:
			result = a - b;
			break;
		case 3:
			result = a * b;
			break;
		case 4:
			result = a / b;
			break;
		}
	}

	cout << result << endl;
	return 0;
}
