
//CodeForces 231A
//	1/2
#include<iostream>
using namespace std;

int main() {

	int N = 0;
	
	
	cin >> N;
	int *x = new int[N]();
	int a, b, c, counter = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		if (a + b + c >= 2)
			counter++;
	}
	cout << counter << endl;
	return 0;
}