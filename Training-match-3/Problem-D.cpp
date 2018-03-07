
//HYSBZ 1800

//	1/8

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#define MAX_SIZE 21
using namespace std;

int n, d;
int all[MAX_SIZE];

bool Check(int index) {
	int s = 0;
	for (int i = index; i < n; i++) {
		if ((s += all[i]) == d)
			return true;
	}
	return false;
}

int main() {
	int sum = 0, counter = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &all[i]);
		sum += all[i];
	}
	if (n < 4 || sum % 2 != 0) {
		printf("0\n");
		return 0;
	}
	d = sum / 2;
	for (int i = 1; i < n; i++)
		if (Check(i))
			counter++;
	printf("%d\n", (counter - 1)*(counter - 0) / 2);

	return 0;
}