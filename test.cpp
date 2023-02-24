#include"pch.h"
#include <string.h>

#include"D:\programming\Assignment 3\Assignment 3\bigIntcpp.cpp"





// Q3: BigInt

TEST(BigInt, Constructors) {
	string expected1 = "119622220865480194561963161495657715064383733760000000000";
	string expected2 = "99999";
	BigInt a(expected1);
	BigInt b(99999);
	BigInt c(a);
	string s1 = (string)a;
	string s2 = (string)b;
	string s3 = (string)c;
	ASSERT_EQ(0, s1.compare(expected1));
	ASSERT_EQ(0, s2.compare(expected2));
	ASSERT_EQ(0, s3.compare(expected1));

}
TEST(BigInt, Addition) {
	string str = "9999999999999999999";
	BigInt a(str);
	BigInt b = a + 1;
	BigInt c;
	c = a + b;
	BigInt d(2);
	d += a;

	string s1 = (string)b; string expected1 = "10000000000000000000";
	string s2 = (string)c; string expected2 = "19999999999999999999";
	string s3 = (string)d; string expected3 = "10000000000000000001";

	ASSERT_EQ(0, s1.compare(expected1));
	ASSERT_EQ(0, s2.compare(expected2));
	ASSERT_EQ(0, s3.compare(expected3));


}

TEST(BigInt, Subtraction) {
	string str = "10000000000000000000";
	BigInt a(str);
	BigInt b = a - 1;
	BigInt c;
	c = a - b;
	BigInt d(2);
	a -= d;

	string s1 = (string)b; string expected1 = "9999999999999999999";
	string s2 = (string)c; string expected2 = "1";
	string s3 = (string)a; string expected3 = "9999999999999999998";

	ASSERT_EQ(0, s1.compare(expected1));
	ASSERT_EQ(0, s2.compare(expected2));
	ASSERT_EQ(0, s3.compare(expected3));

}
TEST(BigInt, Mul) {
	string str = "119622220865480194561963161495657715064383733760000000000";
	BigInt a(str);
	BigInt b;
	BigInt c = a * b;

	BigInt d(46);
	a *= d;

	string s1 = (string)c; string expected1 = "0";
	string s2 = (string)a; string expected2 = "5502622159812088949850305428800254892961651752960000000000";

	ASSERT_EQ(0, s1.compare(expected1));
	ASSERT_EQ(0, s2.compare(expected2));


}

TEST(BigInt, LogicalOperators) {
	string str1 = "119622220865480194561963161495657715064383733760000000000";
	string str2 = "5502622159812088949850305428800254892961651752960000000000";
	BigInt a(str1);
	BigInt c(str1);
	BigInt b(str2);

	ASSERT_EQ(true, a == c);
	ASSERT_EQ(false, a == b);
	ASSERT_EQ(true, a != b);
	ASSERT_EQ(true, a <= b);
	ASSERT_EQ(false, a >= b);
	ASSERT_EQ(false, a > b);
	ASSERT_EQ(true, a < b);


}

TEST(BigInt, UnaryOperators) {
	string str1 = "9999999999999999999";
	string str2 = "10000000000000000000";
	BigInt a(str1);
	BigInt c(str1);
	BigInt b(str2);
	a++;
	string s1 = (string)a; string expected1 = "10000000000000000000";
	ASSERT_EQ(0, s1.compare(expected1));

	--a;
	string s2 = (string)a; string expected2 = "9999999999999999999";
	ASSERT_EQ(0, s2.compare(expected2));

	++b;
	string s3 = (string)b; string expected3 = "10000000000000000001";
	ASSERT_EQ(0, s3.compare(expected3));

	b--;
	string s4 = (string)b; string expected4 = "10000000000000000000";
	ASSERT_EQ(0, s4.compare(expected4));



}
TEST(BigInt, InputOutput) {
	BigInt s1;
	cin >> s1;// input "2019" on terminal
	BigInt s2("2019");
	cout << s1;
	ASSERT_EQ(true, s2 == s1);

}



int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
