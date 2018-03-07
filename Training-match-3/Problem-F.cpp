
//Five Dimensional Points

//	1/5

//暴力11以上可能超时，但是需要注意11以上不存在good
//n为1的时候输出1....不是0......

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#define MAX_SIZE 1010
using namespace std;

int n, d, goodcounter = 0;
class Point
{
public:
	Point() {};
	void setPoint(int x1, int x2, int x3, int x4, int x5) {
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->x4 = x4;
		this->x5 = x5;
		isGood = false;
		goodnumber = 0;
	}
	int x1;
	int x2;
	int x3;
	int x4;
	int x5;
	bool isGood;
	int goodnumber;
	int operator* (Point& p) {
		return x1*p.x1 + x2*p.x2 + x3*p.x3 + x4*p.x4 + x5*p.x5;
	}
};

Point all[MAX_SIZE];
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x1, x2, x3, x4, x5;
		scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5);
		all[i].setPoint(x1, x2, x3, x4, x5);
	}
	if (n == 1){
		printf("1\n1\n");
		return 0;
	}
	if (n > 11){
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			else
				for (int k = j + 1; k < n; k++) {
					if (i == k)
						continue;
					else
					{
						Point p1, p2;
						p1.setPoint(all[j].x1 - all[i].x1, all[j].x2 - all[i].x2, all[j].x3 - all[i].x3, all[j].x4 - all[i].x4, all[j].x5 - all[i].x5);
						p2.setPoint(all[k].x1 - all[i].x1, all[k].x2 - all[i].x2, all[k].x3 - all[i].x3, all[k].x4 - all[i].x4, all[k].x5 - all[i].x5);
						int a = p1*p2;
						if (a > 0){
							flag = 1;
							j = n+1;
							break;
						}
							
					}
				}

		}
		if(flag == 0)
			all[i].isGood = true,goodcounter++;
	}
		
	printf("%d\n", goodcounter);
	for (int i = 0; i < n; i++)
		if (all[i].isGood)
			printf("%d\n", i + 1);
	return 0;
}