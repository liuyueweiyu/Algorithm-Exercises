#include <iostream>
#include <cstdio>

//HDU-2602	1/3	二维数组解法

#include <cstring>
#include <algorithm>
#define scanf scanf_s;
using namespace std;
const int  MAXSIZE = 1020;

int volumes[MAXSIZE], values[MAXSIZE];
int bags[MAXSIZE][MAXSIZE];

int main() {
	int n = 0;
	cin >> n;
	while (n--)
	{
		int _size = 0, _volume = 0, i, j;
		cin >> _size >> _volume;
		for (i = 1; i <= _size; i++)
			cin >> values[i];
		for (i = 1; i <= _size; i++)
			cin >> volumes[i];
		memset(bags, 0, sizeof(bags));

		for (i = 1; i <= _size; i++)			//bags[i][j]表示i块且体积不大于j的最大价值
			for (j = 0; j <= _volume; j++) {
				if (volumes[i] > j)
					bags[i][j] = bags[i - 1][j];	//放不下第i块骨头
				else
					bags[i][j] = max(bags[i - 1][j], bags[i - 1][j - volumes[i]] + values[i]);
			}

		cout << bags[_size][_volume] << endl;

	}

	return 0;
}