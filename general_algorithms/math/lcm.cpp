// Grant Williams -- Least Common Multiple
#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	      a = b;
	      b = tmp;
}

int gcd(int a, int b)
{
	if (b > a)
	{
		swap(a,b);
	}

	while( b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int lcm(int a,int b)
{
	int temp = gcd(a,b);

	return temp ? (a / temp * b) : 0;
}

int main()
{

	int a = 1989;
	int b = 1590;

	cout << lcm(a,b) << endl;

	return 0;
}