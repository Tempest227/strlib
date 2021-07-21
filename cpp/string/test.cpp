#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

//测试构造函数、拷贝构造、赋值运算、析构函数
void test1()
{
	hsy::string s("hsy");
	hsy::string s1(s);
	hsy::string s2("ysh");
	s = s2;
}

//测试增删查改
void test2()
{
	hsy::string s("hsy");
	//增
	s += 'b';
	s += "xxxxx";
	s += 'c';
	//删
	//s.clear();
	s.erase(0, 2);
	//查
	auto ret = s.find('c');
	auto ret1 = s.find("xx");
	//改
	s[1] = 'c';

}
std::ostream& operator<<(std::ostream& _cout, const hsy::string& s)
{
	_cout << s.c_str();
	return _cout;
}

std::istream& operator>>(std::istream& _cin, hsy::string& s)
{
	char* str = new char[s.size() + 1];
	_cin >> str;

	hsy::string tmp(str);
	s = tmp;

	return _cin;
}
int main()
{
	//test1();
	//test2();
	hsy::string s("hsy");
	//::operator<<(std::cout, s);
	//::operator>>(std::cin, s);
	return 0;
}