
//HDU 2602	//一维解法

//	1/3

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXNUMBER 1010
using namespace std;

int v[MAXNUMBER], w[MAXNUMBER], m[MAXNUMBER];

int main()
{
	int xxx;
	scanf("%d", &xxx);
	for (int a = 0; a < xxx; a++)
	{

		int n, c;
		scanf("%d %d", &n, &c);
		for (int i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= n; i++)
			for (int j = c; j >= w[i]; j--)
				if (j >= w[i])
					m[j] = max(m[j], m[j - w[i]] + v[i]);


		cout << m[c] << endl;
	}

	return 0;
}
