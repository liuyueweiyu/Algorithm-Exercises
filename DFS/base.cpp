#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#define MAXNUMBER 101
#define scanf scanf_s
using namespace std;

int a[3];
bool visit[3] = { false };

void dfs(int step) {
	if (step == 3) {                    //结束条件
		for (int i = 0; i < 3; i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < 3; i++) {       //遍历下一个节点
		if (!visit[i]) {                //判断是否遍历已经遍历过的节点
			a[step] = i;
			visit[i] = true;            //设置节点为遍历过
			dfs(step + 1);
			visit[i] = false;           //遍历后将该节点设置为未遍历过
		}
		
	}
}

int main()
{
	dfs(0);
	
	system("PAUSE");
	return 0;
}
