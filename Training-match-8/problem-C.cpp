
//CodeForces-567A	1/2

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXNUMBER 100100
using namespace std;

int a[MAXNUMBER];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	cout << a[1] - a[0] << " " << a[n - 1] - a[0] << endl;
	for (int i = 1; i < n-1; i++){
		cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << " " << max(a[i] - a[0], a[n - 1] - a[i]) << endl;
	}
	cout << a[n - 1] - a[n - 2] << " " << a[n - 1] - a[0] << endl;
	return 0;
}