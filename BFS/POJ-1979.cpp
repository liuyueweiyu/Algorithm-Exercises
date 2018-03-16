#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXNUMBER 21
#define scanf scanf_s
using namespace std;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };


class Node{
public:
	Node(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x;
	int y;
};

int main()
{
	int w, h, _start_x, _start_y, sum = 0;
	scanf("%d %d", &w, &h);
	while (w != 0 && h != 0){
		sum = 0;
		bool visit[MAXNUMBER][MAXNUMBER] = { false };
		char map[MAXNUMBER][MAXNUMBER];
		for (int i = 0; i < h; i++) {
			getchar();
			for (int j = 0; j < w; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@')
					_start_x = i, _start_y = j, visit[i][j] = true;
			}
		}		
		queue<Node> q;
		Node n(_start_x, _start_y);
		q.push(n);
		while (!q.empty()){
			Node ns = q.front();
			q.pop();
			sum++;
			for (int i = 0; i < 4; i++){
				int xxx = ns.x + dir[i][0];
				int yyy = ns.y + dir[i][1];
				if (xxx < 0 || yyy < 0 || xxx >= h || yyy >= w)
					continue;
				if (!visit[xxx][yyy] && map[xxx][yyy] == '.') {
					Node Vn(xxx, yyy);
					q.push(Vn);
					visit[xxx][yyy] = true;
				}
			}
		}
		printf("%d\n", sum);
		scanf("%d %d", &w, &h);
	}
	system("PAUSE");
	return 0;
}
