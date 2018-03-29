#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include <time.h>

#define MAXNUMBER 11
using namespace std;

bool flag = false;

int w,h,sum ;

int s_x, s_y, d_x, d_y;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int a[MAXNUMBER];
char maps[8][8] = { 0 };
bool visit[8][8] = { false };

bool dfs(int x,int y,int step) {
	if (step > sum)
		return false;
	if (x == s_x && y == s_y) {
		flag = true;
		return true;
	}
	for (int i = 0; i < 4; i++){
		int xxx = dir[i][0] + x;
		int yyy = dir[i][1] + y;
		if (visit[xxx][yyy] || xxx >= w || xxx < 0 || yyy >= h || yyy < 0|| maps[xxx][yyy] == 'X')
			continue;
		visit[xxx][yyy] = true;
		dfs(xxx, yyy, step + 1);
		if (flag)
			return true;
		visit[xxx][yyy] = false;
	}
	if (flag)
		return true;
	else
		return false;
}

int main()
{
	scanf("%d %d %d", &w, &h, &sum);
	while (w != 0 && h != 0 && sum != 0){
		for (int i = 0; i < w; i++) {
			getchar();
			for (int j = 0; j < h; j++) {
				scanf("%c", &maps[i][j]);
				if (maps[i][j] == 'D')
					d_x = i, d_y = j;
				if (maps[i][j] == 'S')
					s_x = i, s_y = j;
			}
		}
		visit[d_x][d_y] = true;
		dfs(d_x,d_y,0);
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
		memset(visit, 0, sizeof(visit));
		flag = false;
		getchar();
		scanf("%d %d %d", &w, &h, &sum);
	}

	return 0;
}