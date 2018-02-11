
//POJ - 1064
//	1/6
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
const int Max_Size = 100010;

int N, K;

double all[Max_Size];

bool Check(double mid) {
	int sum = 0;
	for (int i = 0; i < N; i++){
		sum += (int)(all[i] / mid);//(int) 的结合顺序
		if (sum >= K)
			return true;
	}
	return false;
}

int main() {
	double _start = 0, _middle, _final = 0;
	scanf_s("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf_s("%lf", &all[i]);
		_final = max(_final, all[i]);
	}
	for (int i = 0; i < 100; i++) {//通过循环强行控制二分次数,100次循环能达到1e-30的精度
		_middle =( _start + _final ) /2;
		if (!Check(_middle))
			_final = _middle;
		else
			_start = _middle;
	}
	
	printf("%.2lf\n", floor(_final * 100) / 100);//注意精度直接.2lf是四舍五入，floor(_final * 100) / 100先向下取整
	
	system("PAUSE");
	return 0;
}
