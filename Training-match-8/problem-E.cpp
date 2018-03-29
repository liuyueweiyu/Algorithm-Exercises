
//	CodeForces-560B	1/3

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXNUMBER 100100
using namespace std;


int main()
{
	int a, b, a2, b2, a3, b3;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &a2, &b2);
	scanf("%d %d", &a3, &b3);

	int h1, w1, h2, w2, h3, w3, h4, w4;
	h1 = max(a2 + a3, max(b2, b3)); w1 = min(a2 + a3, max(b2, b3));
	h2 = max(a2 + b3, max(b2, a3)); w2 = min(a2 + b3, max(b2, a3));
	h3 = max(max(a2, a3), b2 + b3); w3 = min(max(a2, a3), b2 + b3);
	h4 = max(max(a2 ,b3), b2 + a3); w4 = min(max(a2 , b3), b2 + a3);
	int	h = max(a, b), w = min(a, b);
	if ((h >= h1 &&w >= w1) || (h >= h2&&w >= w2)|| (h >= h3&&w >= w3)|| (h >= h4&&w >= w4))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}