
//CodeForces 472A

//	1/1

#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int number);
int main() {
	int n, i;
	cin >> n ;
	int flag = 0;
	for (i = 4; i <= n/2+1; i++)
	{
		if (isPrime(i)&&isPrime(n-i))
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << i << " " << n - i << endl;
	}
	return 0;
}

bool isPrime(int number) {
	int lengths = (int)sqrt(number) + 1;
	int flag = 0;
	for (int i = 2; i <lengths; i++)
	{
		if (number%i == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag == 1 ? true : false;
}
