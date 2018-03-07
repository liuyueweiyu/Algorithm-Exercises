
//HDU - 1711

//	1/1


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXNUMBER 1010
using namespace std;

int a[1000010];
int b[10010];

int _next[10010] = { 0 };

int search(int* s,int* p,int sLen,int pLen){
	int i = 0;
	int j = 0;
	_next[0] = -1;
	int k = -1;
	while (j < pLen - 1)
		if (k == -1 || p[j] == p[k])
			++k, ++j, _next[j] = k;
		else
			k = _next[k];
	j = 0;
	while (i < sLen && j < pLen)
	{   
		if (j == -1 || s[i] == p[j])
			i++,j++;
		else    
			j = _next[j];
	}
	if (j == pLen)
		return i - j + 1;
	else
		return -1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int xxx = 0; xxx < n; xxx++){
		int alen, blen;
		scanf("%d %d", &alen, &blen);
		for (int i = 0; i < alen; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < blen; i++)
			scanf("%d", &b[i]);

		cout << search(a, b, alen, blen) << endl;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(_next, 0, sizeof(_next));
	}
	return 0;
}