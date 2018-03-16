

#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include <time.h>
#define MAXNUMBER 11
using namespace std;

int n, counter = 0;

int a[MAXNUMBER];

bool check(int x, int y) {
	for (int i = 0; i < x; i++)
		if (a[i] == y || a[i] - i == y - x || a[i] + i == y + x)
			return false;
	return true;

}

void dfs(int step) {
	if (step == n - 1) 
		for (int i = 0; i < n; i++) 
			if (check(step, i)) {
				counter++;
				return;
			}
	for (int i = 0; i<n; i++) {
		if (check(step, i) ){
			a[step] = i;
			dfs(step + 1);
			a[step] = 0;
		}			
	}
	return;
}

int main()
{
	scanf("%d", &n);
	while (n != 0)
	{
		dfs(0);
		printf("%d\n", counter);
		counter = 0;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
	}
	return 0;
}