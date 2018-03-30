
//	HDU-2141

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int  MAXSIZE = 10020;
int a[502], b[502], c[502], ans[1010];
int L, M, N, S;
int sum[502];
bool check(int x) {
	int _start = 0, _final = L*N - 1, _middle;

	while (_start <= _final)
	{
		_middle = (_final - _start) >> 1 + _start;
		if (sum[_middle] == x)
			return true;
		else if (sum[_middle] > x)
			_final = _middle - 1;
		else
			_start = _start + 1;
	}

    return false;
}


int main() {
	int couter = 0;
	while (scanf("%d %d %d", &L, &N, &M) != EOF)
	{
		int numebre = 0;
		for (int i = 0; i < L; i++)
			scanf("%d",&a[i]);
		for (int i= 0; i < N; i++)
			scanf("%d",&b[i]);
		for (int i = 0; i < M; i++)
			scanf("%d",&c[i]);
		scanf("%d", &S);
		for (int i = 0; i < S; i++)
			scanf("%d",&ans[i]);
		printf("Case %d:\n", ++couter);
		for (int i = 0; i < L; i++)
			for (int k = 0; k < N; k++)
				sum[numebre++] = a[i] + b[k];
        int ab = L*N -1;
		sort(sum, sum + ab +1);
		sort(c, c + M);
		for (int i = 0; i < S; i++)
		{
			bool flag = false;
            if(sum[0] + c[0] > ans[i] || sum[ab] + c[M-1] < ans[i]){
                printf("NO\n");
                continue;
            }

			for (int j = 0; j < M; j++) {
				if (check(ans[i] - c[j]))
					j = M, flag = true;
			}
			if (flag)
				printf("YES\n");
			else
				printf("NO\n");
		}


	}


	return 0;
}
