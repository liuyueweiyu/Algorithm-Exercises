
//	CodeForces-791A		1/1

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#define MAX_SIZE 101
#define MAXNUMBER 1e6+100
using namespace std;


int main() {
	int a, b,i;
	scanf("%d %d", &a, &b);

	if (a == b) {
		printf("1\n");
		return 0;
	}

	for ( i = 0; a <= b; i++){
		a *= 3;
		b *= 2;
	}
	printf("%d\n", i);
	return 0;
}