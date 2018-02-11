
//CodeForces-847G

//	1/9

#include<cstdio>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

char all[1001][1001];
int main() {

	int n;
	scanf("%d", &n);
	
	int maxss = 0;
	int counter[10] = { 0 };
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < 7; j++)
		{
			scanf("%c", &all[i][j]);
			counter[j] += all[i][j] - 48;
			if (i == n - 1 && counter[j] > maxss)
				maxss = counter[j];
		}

	}

	printf("%d\n", maxss);

	return 0;
}