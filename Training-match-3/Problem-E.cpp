
//CodeForces-787A

//	1/2

//暴力出奇迹(雾)

#include<cstdio>
#include<iostream>
#define MAX_SIZE 101
#define MAXNUMBER 1e6+100
using namespace std;


int main() {
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	for (int i = 0; i < MAXNUMBER; i++) {
		int t = b + i*a;
		if (t - d >= 0 && (t - d) % c == 0) {
			printf("%d\n", t);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}