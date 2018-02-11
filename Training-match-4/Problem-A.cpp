
//CodeForces-811A

//	1/2

#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 1; a>=0&&b>=0; i++)
	{
		if (i%2!=0)
			a -= i;
		else
			b -= i;

	}
	if (b < 0)
		cout << "Valera" << endl;
	if (a < 0)
		cout << "Vladik" << endl;

	return 0;
}