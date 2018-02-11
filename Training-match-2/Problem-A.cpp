
//CodeForces-327A

//	1/1

//暴力过的...

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>

#define MAXSIZE 101

using namespace std;

int n;
int all[MAXSIZE];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &all[i]);
	int max_counter = 0;

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			int counter = 0;
			for (int k = i; k <= j; k++) 
				all[k] = 1 - all[k];
			for (int k = 0; k < n; k++)
				if (all[k] == 1)
					counter++;
			for (int k = i; k <= j; k++)
				all[k] = 1 - all[k];
			if (counter > max_counter)
				max_counter = counter;

		}
			
	printf("%d\n", max_counter);

	return 0;
}