#include <iostream>

using namespace std;

long long pow (long long x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (!(n&1))
		return pow(x * x, n / 2);
	else
		return pow(x * x, n /2) * x;
}

int main()
{
	long long x = 2;
	int n = 32;

	cout << pow(x,n) << endl;

}