
//CodeForces-560A	1/1

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXNUMBER 100100
using namespace std;

int main()
{
	int n, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int xxx;
		scanf("%d", &xxx);
		if (xxx == 1)
			flag = 1;
	}
	if (flag == 1)
		cout << -1 << endl;
	else
		cout << 1 << endl;
	return 0;
}