
//	CodeForces-599A	1/1

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include <map>
#include<queue>
#define MAX_SIZE 101
#define MAXNUMBER 1e6+100
using namespace std;

int _map[3][2] = { {0,1}, {1,2} ,{0,2} };
//int all[];

int main() {

	int money[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", &money[i]);
	
	int sum[3];
	for (int i = 0; i < 3; i++)
		sum[i] = (money[_map[i][0]] + money[_map[i][1]]) * 2;
	int _max = 1e9;
	for (int i = 0; i < 3; i++)
		_max = min(_max, sum[i]);
	_max = min(_max, money[0] + money[1] + money[2]);
	printf("%d\n", _max);
	return 0;
}