#pragma once
#include<iomanip>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class bigint
{
private:
	int v[5];
public:
	int SIZE = 5;
	bigint();
	bigint(int x0);
	bigint(int x0, int x1);
	bigint(int x0, int x1, int x2);
	bigint(int x0, int x1, int x2, int x3);
	bigint(int x0, int x1, int x2, int x3, int x4);
	friend istream& operator>>(istream& in, bigint& test);
	friend ostream& operator<<(ostream& out, bigint& test);
	bigint operator+(bigint test);
	bigint operator+(const int number);
	bigint operator-(bigint test);
	bigint operator-(const int number);
	bool operator==(bigint& test);
	bool operator!=(bigint& test);
	bool operator>(bigint& test);
	bool operator>=(bigint& test);
	bool operator<(bigint& test);
	bool operator<=(bigint& test);

};