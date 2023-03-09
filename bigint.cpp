#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
#include"bigint.h"
using namespace std;

bigint::bigint()
{
	//Default constructor
	int i = 0;
	while (i < SIZE)
	{
		v[i] = 0;
		i++;
	}
	//sets the value equal to zero
}
bigint::bigint(int x0)
{
	//sets the value to be x0	

	this->v[0] = x0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[4] = 0;
}

bigint::bigint(int x0, int x1)
{

	//set the value to be x1*10^9 + x0
	this->v[0] = x0;
	this->v[1] = x1;
	v[2] = 0;
	v[3] = 0;
	v[4] = 0;

}
bigint::bigint(int x0, int x1, int x2)
{

	// set the value to be x2 * 10^18 + x1 * 10^9 + x0
	this->v[0] = x0;
	this->v[1] = x1;
	this->v[2] = x2;
	v[3] = 0;
	v[4] = 0;

}
bigint::bigint(int x0, int x1, int x2, int x3)
{

	// set the value to be x3 * 10^27 + x2 * 10^18 + x1 * 10^9 + x0
	this->v[0] = x0;
	this->v[1] = x1;
	this->v[2] = x2;
	this->v[3] = x3;
	v[4] = 0;

}
bigint::bigint(int x0, int x1, int x2, int x3, int x4)
{
	
	// set the value to be  x4 * 10^36 +  x3 * 10^27 + x2 * 10^18 + x1 * 10^9 + x0
	this->v[0] = x0;
	this->v[1] = x1;
	this->v[2] = x2;
	this->v[3] = x3;
	this->v[4] = x4;

}
ostream& operator<<(ostream& out, bigint& test)
{
	for (int i = 4; i >= 0; i--)
	{
		if (i != (4))
		{
			cout << setfill('0') << setw(9) << test.v[i];
		}
		else
		{
			cout << test.v[i];
		}
	}

	return out;

}
istream& operator>>(istream& in, bigint& test)
{
	char array[45];
	int memory = 0, j = 0, POW = 0;
	for (int i = 0; i < 5; i++)
	{
		test.v[i] = 0;//INITIALIZED TO ZERO 
	}
	cout << "Enter the number: ";
	in.getline(array, 45, '\n');//input is taken by the user
	for (int i = (strlen(array) - 1); i >= 0; i--)
	{
		memory = (array[i] - 48);
		if (POW > 8)//9 digits can be stored in an integer 
			POW = 0;
		memory = memory * (pow(10, POW));
		POW++;//power is incremented
		test.v[j] += memory;
		if (POW == 9)
			j++;
	}
	return in;
	//the input is returned
}
bigint bigint::operator+(bigint test)
{
	bigint newobject;
	int i = 0;
	//made an object
	int j = 0;
	for (; i < SIZE; i++)
	{
		if ((this->v[i] + test.v[i]) <= 999999999)//setting the condition to be smaller than 10 digit number
		{
			newobject.v[j] = test.v[i] + this->v[i];
			j++;
		}
		else
		{
			newobject.v[j] = (test.v[i] + this->v[i]) - (1 * pow(10, 9));
			j++;
			for (int k = i + 1; k < SIZE; k++)
			{
				if (test.v[k] < 999999999)
				{
					test.v[k]++;
					break;
				}
				else if (this->v[k] < 999999999)
				{
					this->v[k]++;
					break;
				}
			}
		}
	}
	return newobject;//the object is returned

}
bigint bigint::operator+(const int number)
{
	bigint newobj(number);//made a new object
	newobj = (*this) + newobj;//integer number is added to the object
	return newobj;//new incremented object is returned
}
bigint bigint::operator-(bigint test)
{
	bigint new1;
	int j = 0, i = 0;
	for (; i < SIZE; i++)
	{
		if ((this->v[i] - test.v[i]) >= 0)
		{
			new1.v[j] = this->v[i] - test.v[i];
			j++;
		}
		else
		{
			new1.v[j] = ((this->v[i] + (1 * pow(10, 9))) - test.v[i]);
			j++;
			for (int k = i + 1; k < SIZE; k++)
			{
				if (this->v[k] > 0)
				{
					this->v[k]--;
					for (int l = k - 1; l > i; l--)
					{
						this->v[l] += (1 * pow(10, 9));
						this->v[l]--;//decrmented the integer
					}
					break;
				}
			}
		}
	}
	return new1;//the new object is returned
}
bigint bigint::operator-(const int number)
{
	bigint newobj1(number);//made a new object
	newobj1 = (*this) - newobj1;//integer number is subtracted from the object
	return newobj1;//new decremented object is returned
}
bool bigint::operator==(bigint& test)
{
	bool condition;
	int i = 0;
	while (i < SIZE)
	{
		if (this->v[i] == test.v[i])//if array is equal to input array condition is satisfied
		{
			condition = true;
		}
		else
		{
			condition = false;
			return condition;
		}
		i++;
	}
	return condition;
}

bool bigint::operator!=(bigint& test)
{
	bool condition;
	int i = 0;
	while (i < SIZE)
	{
		if (this->v[i] == test.v[i])//if array is not equal to input array the condition is false
		{
			condition = false;
		}
		else
		{
			condition = true;
			return condition;
		}
		i++;
	}
	return condition;
}
bool bigint::operator>(bigint& test)
{
	int initial1 = 0;
	int initial2 = 0;
	//we have set up the initial point 
	for (int i = (SIZE - 1); i >= 0; i--)
	{
		if (test.v[i] != 0)
		{
			initial1 = i;//IT IS SET EQUAL TO i
			break;
		}
	}
	//I IS DECREMENTED
	for (int j = (SIZE - 1); j >= 0; j--)
	{
		if (this->v[j] != 0)
		{
			initial2 = j;//It is set equal to j
			break;
		}
	}
	if (initial1 > initial2)//if first array is larger than the other
		return 0;
	else if (initial2 > initial1)//if second array is larger than the first
		return 1;
	else if (initial1 == initial2)//if both are equal
	{
		bool condition = 0;
		int j = initial2;
		for (; j >= 0; j--)//j is decremented
		{
			if (this->v[j] > test.v[j])
			{
				condition = 1;
				return condition;
			}
			else if (this->v[j] < test.v[j])
			{
				condition = 0;
				return condition;
			}
		}
		return condition;//the condition is returned whatever it is
	}
}
bool bigint::operator>=(bigint& test)
{
	if (*this > test || *this == test)//if equal or greater than the object condition is satisfied in both ways
		return 1;
	else
		return 0;
}
bool bigint::operator<(bigint& test)
{
	if (*this > test || *this == test)//if equal or greater than the object condition is not satisfied in both ways
		return 0;
	else
		return 1;
}

bool bigint::operator<=(bigint& test)
{
	if (*this < test || *this == test)//if equal or less than the objet than the condition is satisfied in both ways
		return 1;
	else
		return 0;
}

