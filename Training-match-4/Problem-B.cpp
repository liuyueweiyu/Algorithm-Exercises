
//CodeForces-811B

//	1/2

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#define MAX_SIZE 10010
using namespace std;


int n,m;

int all[MAX_SIZE];
int copy_all[MAX_SIZE];
int main() {
	int x;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++)
		scanf("%d", &all[i]);
	for (int i = 0; i < m; i++)
	{
		int _start, _final, _like;
		scanf("%d %d %d", &_start, &_final, &_like);
		if (_like<_start || _like > _final) {
			printf("Yes\n");
			continue;
		}
		int xxxx = all[_like - 1];
		int k, counter = 0;
		for (k = _start - 1; k < _final; k++)
			if (all[k] < xxxx)
				counter++;

		if (counter == _like -  _start)
			printf("Yes\n");
		else
			printf("No\n");		
	}
	return 0;
}