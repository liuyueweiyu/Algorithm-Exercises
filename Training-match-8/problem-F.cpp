
//	CodeForces-560C	1/1

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXNUMBER 1010
using namespace std;

int boeder[6];

int main()
{
	for (int i = 0; i < 6; i++)
		scanf("%d", &boeder[i]);
	int sum = boeder[0] + boeder[1] + boeder[2];
	sum = sum*sum;
	for (int i = 0; i < 6; i+=2)
		sum -= boeder[i] * boeder[i];
	cout << sum << endl;

	return 0;
}