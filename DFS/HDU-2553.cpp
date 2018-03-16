

#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include <time.h>
#define MAXNUMBER 11
using namespace std;

int n, counter = 0;

int a[MAXNUMBER];

bool check(int x, int y) {			//判断在x行，y列可以放置"queen"
	for (int i = 0; i < x; i++)			
		if (a[i] == y || a[i] - i == y - x || a[i] + i == y + x)
			return false;
	return true;

}

void dfs(int step) {	
	if (step == n - 1) 				//最后一行可以放置即数目+1，递归结束
		for (int i = 0; i < n; i++) 
			if (check(step, i)) {	
				counter++;
				return;
			}
	for (int i = 0; i<n; i++) {		//dfs搜索
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
		dfs(0);					//从第一层开始搜索
		printf("%d\n", counter);
		counter = 0;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
	}
	return 0;
}