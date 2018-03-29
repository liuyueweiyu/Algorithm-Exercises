
//	HDU-1995	1/1

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include <map>
#include<queue>
#include<cmath>

#define MAXNUMBER 4000000
#define LL long long
using namespace std;


int main() {

	int n, m, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		
		scanf("%d %d", &m,&x);
		//LL a = 1 << (m - x);
		LL a = pow(2, m - x);
		
		cout << a << endl; 
	}

	


	return 0;
}