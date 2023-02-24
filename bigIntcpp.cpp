//Assignment 3
//M.umerfarooq
//CS_E
//21i-1184
//Question 3
#include "bigint.h"


char* stringToChar(string num)
{


		char* temp = new char[num.size() + 1];
		temp[num.size()] = '\0';
		for (int i = 0; i < num.size(); i++)
			temp[i] = num[i];
		return temp;


}
string charToString(char* temp)
{



			string out;
			for (int i = 0; temp[i]; i++)
				out = out + temp[i];
			return out;



}
void removeExtra(char* res, int i = 0)
{




	for (; res[i]; i++) {
		if (res[i] < '1' || res[i]>'9')
		{
			for (int j = i; res[j]; j++)
				res[j] = res[j + 1];
			i--;
		}
		else
			break;
	}
	if (res[i] == '\0')
	{
		res[0] = '0';
		res[1] = '\0';
	}





}
char* additionOfBigInteger(char* Num1, char* Num2) 
{




	int size1 = 0, size2 = 0, size, s = 0, carry = 0;
	bool first = false, second = false;
	for (int i = 0; Num1[i]; i++, size1++)
		if (Num1[i] < '0' || Num1[i]>'9')
			first = true;
	for (int i = 0; Num2[i]; i++, size2++)
		if (Num2[i] < '0' || Num2[i]>'9')
			second = true;
	if (first || second) {
		char* ret = new char[8] { "invalid" };
		return ret;
	}
	size = size1 > size2 ? size1 : size2;
	char* res = new char[size + 2];
	res[size + 1] = '\0';
	int k = size;
	for (int i = size1 - 1, j = size2 - 1; i >= 0 || j >= 0; i--, j--, k--)
	{
		if (j < 0)
			s = Num1[i] + carry - 48;
		else if (i < 0)
			s = Num2[j] + carry - 48;
		else
			s = Num1[i] + Num2[j] + carry - 96;
		carry = s / 10;
		s = s % 10;
		res[k] = char(s + 48);
		if (carry)
			res[k - 1] = char(carry + 48);
	}
	removeExtra(res);
	return res;
}
int takeborrow(char* n1, int i)
{


	int j = i - 1;
	if (n1[j] == '0')
		n1[j] = takeborrow(n1, j) + 48;
	n1[j]--;
	return 10;




}
char* subtractionOfBigInteger(char* Num1, char* Num2)
{


	char* n1 = Num1, * n2 = Num2;
	bool flag = 0;
	int size1 = 0, size2 = 0, size, s = 0, carry = 0;
	bool first = false, second = false;
	for (int i = 0; Num1[i]; i++, size1++)
		if (Num1[i] < '0' || Num1[i]>'9')
			first = true;
	for (int i = 0; Num2[i]; i++, size2++)
		if (Num2[i] < '0' || Num2[i]>'9')
			second = true;
	if (first || second) {
		char* ret = new char[8] { "invalid" };
		return ret;
	}
	size = size1 >= size2 ? size1 + 1 : size2 + 1;
	char* res = new char[size + 1];
	res[size] = '\0';
	if (size2 > size1)
		flag = false;
	else if (size1 > size2)
		flag = true;
	else
	{
		for (int i = 0; Num1[i] && Num2[i]; i++)
		{
			if (Num1[i] > Num2[i]) {
				flag = true; break;
			}
			if (Num2[i] > Num1[i]) {
				flag = false; break;
			}
		}
	}
	if (!flag)
	{
		n1 = Num2;
		n2 = Num1;
		int temp = size1;
		size1 = size2;
		size2 = temp;
	}
	int k = size - 1;
	for (int i = size1 - 1, j = size2 - 1; i >= 0 || j >= 0; i--, j--, k--)
	{
		if (j < 0)
			res[k] = n1[i];
		else if (n1[i] >= n2[j])
			res[k] = n1[i] - n2[j] + 48;
		else
		{
			int borrow = takeborrow(n1, i);
			res[k] = char(borrow + n1[i] - n2[j] + 48);
		}
	}
	int j = 0;
	if (!flag)
	{
		j++;
		res[0] = '-';
	}
	removeExtra(res, j);
	return res;



}
char* leftshift(char* n1, int s)
{


	int size1 = 0;
	for (int i = 0; n1[i]; i++, size1++);
	int size2 = s + size1;
	char* res = new char[size2 + 1];
	res[size2] = '\0';
	for (int i = 0; res[i]; i++)
	{
		if (i >= size1)
			res[i] = '0';
		else
			res[i] = n1[i];
	}

	return res;



}
char* multiplicationOfBigInteger(char* Num1, char* Num2) 

{



	int size1 = 0, size2 = 0, s = 0, carry = 0, size = 0;
	bool first = false, second = false;
	for (int i = 0; Num1[i]; i++, size1++)
		if (Num1[i] < '0' || Num1[i]>'9')
			first = true;
	for (int i = 0; Num2[i]; i++, size2++)
		if (Num2[i] < '0' || Num2[i]>'9')
			second = true;
	if (first || second) {
		char* ret = new char[8] { "invalid" };
		return ret;
	}
	size = size1 + size2;
	char* res = new char[size + 1];
	res[size] = '\0';
	res[size - 1] = '0';
	removeExtra(res);
	for (int i = size2 - 1; i >= 0; i--)
	{
		carry = 0;
		if (Num2[i] == '0')
			continue;
		char* temp = new char[size + 1];
		temp[size] = '\0';
		for (int j = size1 - 1, k = size - 1; j >= 0; j--, k--)
		{
			s = (Num2[i] - 48) * (Num1[j] - 48) + carry;
			carry = s / 10;
			s = s % 10;
			temp[k] = char(s + 48);
			if (carry)
				temp[k - 1] = char(carry + 48);
		}
		removeExtra(temp);
		char* sum = additionOfBigInteger(res, leftshift(temp, size2 - 1 - i));
		res = sum;
	}
	removeExtra(res);
	return res;



}
BigInt::BigInt(int val)
{

	if (val == 0)
		num = "0";
	while (val > 0)
	{
		num = char((val % 10) + 48) + num;
		val /= 10;
	}



}
BigInt::BigInt(const string& text)
{


	num = text;




}
BigInt::BigInt(const BigInt& copy) // copy constructor
{


	num = copy.num;




}
BigInt BigInt::operator+(const BigInt& val) const
{

	return BigInt(charToString(additionOfBigInteger(stringToChar(num), stringToChar(val.num))));




}
BigInt BigInt::operator+(int val) const
{


	return BigInt(charToString(additionOfBigInteger(stringToChar(num), stringToChar(BigInt(val).num))));



}
BigInt BigInt::operator-(const BigInt& val) const
{

	return BigInt(charToString(subtractionOfBigInteger(stringToChar(num), stringToChar(val.num))));


}
BigInt BigInt::operator-(int val) const
{

	return BigInt(charToString(subtractionOfBigInteger(stringToChar(num), stringToChar(BigInt(val).num))));

}
BigInt BigInt::operator*(const BigInt& val) const
{

	return BigInt(charToString(multiplicationOfBigInteger(stringToChar(num), stringToChar(val.num))));

}

BigInt BigInt::operator+=(const BigInt& rhs)
{

	*this = *this + rhs;
	return *this;

}
BigInt BigInt::operator-=(const BigInt& rhs)
{
	*this = *this - rhs;
	return *this;
}
BigInt BigInt::operator*=(const BigInt& rhs)
{
	*this = *this * rhs;
	return *this;
}

bool BigInt::operator==(const BigInt& val) const
{
	return this->num == val.num;
}

bool BigInt:: operator!=(const BigInt& val) const
{
	return this->num != val.num;
}
bool BigInt::operator<(const BigInt& val) const
{
	if (this->num.size() < val.num.size())
		return true;
	if (this->num.size() > val.num.size())
		return false;
	for (int i = 0; val.num[i]; i++)
		if (this->num[i] > val.num[i])
			return false;
	return true;
}
bool BigInt::operator<=(const BigInt& val) const
{
	return (*this == val || *this < val);
}
bool BigInt::operator>(const BigInt& val) const
{
	if (this->num.size() > val.num.size())
		return true;
	if (this->num.size() < val.num.size())
		return false;
	for (int i = 0; val.num[i]; i++)
		if (this->num[i] < val.num[i])
			return false;
	return true;
}
bool BigInt::operator>=(const BigInt& val) const
{
	return (*this == val || *this > val);
}
BigInt& BigInt::operator++()  
{
	*this = *this + 1;
	return *this;
}
BigInt BigInt::operator++(int)  
{
	BigInt temp(*this);
	*this = *this + 1;
	return temp;
}
BigInt& BigInt::operator--()  
{
	*this = *this - 1;
	return *this;
}
BigInt BigInt::operator--(int) 
{
	BigInt temp(*this);
	*this = *this - 1;
	return temp;
}
BigInt::operator string()   
{
	return this->num;
}
BigInt::~BigInt()
{
	num = "";
}// destructor
string BigInt::GetNum() const
{
	return num;
}
void BigInt::SetNum(string str)
{
	num = str;
}
ostream& operator<<(ostream& output, const BigInt& val) 
{
	output << val.GetNum();
	return output;
}
istream& operator>>(istream& input, BigInt& val) 
{
	string out = "";
	input >> out;
	val.SetNum(out);
	return input;
}