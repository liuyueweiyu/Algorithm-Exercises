
//CodeForces 893A

//	1/1

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n ;
	int com = 3,flag = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x+com == 6)
			flag++;
		else
			com = 6 + x - com;
	}
	if (flag!=0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}
