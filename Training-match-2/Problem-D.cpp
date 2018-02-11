
//CodeForces 893B

//	1/2

#include <iostream>
using namespace std;

bool isPerfect(int number) {
	int x = number;
	int flag = 0;
	int i,k0 = 0, k1 = 0;
	int p[1000];
	if (number == 1)
	{
		return true;
	}
	for (i = 0;(number / 2 != 0)||(number % 2 != 0); i++)
	{
		*(p + i) = number % 2;
		number /= 2;
	}
	for ( i = 0;  ; i++)
	{
		if (*(p + i) != 0)
			break;
	}
	k0 = i;
	for (; ; i++) {
		if (*(p + i) != 1)
			break;
	}
	k1 = i - k0;
	for (; ; i++) {
		if (*(p + i) == 1) {
			flag = 1;
			break;
		}
	}
	if (k0==0)
	{
		return false;
	}
	int sss = ((2 << k0) - 1)*(2 << (k0 - 1));

	if (sss == x)
	{

		return true;
	}
	else
	{
		return false;
	}
	
}

int main() {
	int n;
	cin >> n;

	for (int i = n; i >= 1; i--)
	{
		if (n%i==0&&isPerfect(i))
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}
