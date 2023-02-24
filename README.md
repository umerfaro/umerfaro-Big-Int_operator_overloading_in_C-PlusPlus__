# umerfaro-Big-Int_operator_overloading_in_C++__

BigInt class is used for the mathematical operations that involve very big integer calculations that are outside the limit of all available primitive data types. For example, factorial of 100 contains 158 digits in it so we can’t store it in any primitive data type available. We can store as large Integer as we want in it. 
Your goal is to overload the operators for a generic “BigInt” class. You will need to write two files (BigInt.h and BigInt.cpp). Your implemented class must fully provide the definitions of following class (interface) functions .

class BigInt
{
//think about the private data members
public:
BigInt(int val = 0);
BigInt(const string& text);
BigInt(const BigInt& copy); // copy constructor

// Binary Operators
// Arithmetic Operators
BigInt operator+(const BigInt& val) const;
BigInt operator+(int val) const;
BigInt operator-(const BigInt& val) const;
BigInt operator-(int val) const;
BigInt operator*(const BigInt& val) const;
// Compound Assignment Operators
BigInt operator+=(const BigInt& rhs);
BigInt operator-=(const BigInt& rhs);
BigInt operator*=(const BigInt& rhs);
// Logical Operators
bool operator==(const BigInt& val) const;
bool operator!=(const BigInt& val) const;
bool operator<(const BigInt& val) const;
bool operator<=(const BigInt& val) const;
bool operator>(const BigInt& val) const;
bool operator>=(const BigInt& val) const;

// Unary Operators
BigInt& operator++();  // Pre-increment Operator
BigInt operator++(int);  // Post-increment Operator
BigInt& operator--();  // Pre-decrement Operator
BigInt operator--( int ); // Post-decrement Operator

//Conversion Operator
operator string();    // return value of the BigInt as string
~BigInt(); // destructor
};

ostream& operator<<(ostream& output, const BigInt& val); // outputs the BigInt
istream& operator>>(istream& input, BigInt& val); // inputs the BigInt
