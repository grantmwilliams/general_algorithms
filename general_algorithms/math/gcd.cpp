//GCD(m,n)
#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	      a = b;
	      b = tmp;
}

void gcd(int a, int b)
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

	cout << a << endl;

}

int main()
{

	int a = 1989;
	int b = 1590;

	gcd(a,b);

	return 0;
}