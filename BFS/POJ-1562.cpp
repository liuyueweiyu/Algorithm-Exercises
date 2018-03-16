#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#define MAXNUMBER 101
using namespace std;

int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1} ,{1,1} ,{1,-1} ,{-1,1},{-1,-1} };
bool visit[MAXNUMBER][MAXNUMBER] = { false };
char map[MAXNUMBER][MAXNUMBER];

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
	int w, h, _start_x, _start_y, sum = 0, counter = 0;
	scanf("%d %d", &w, &h);
	while (w != 0 && h != 0){
		sum = 0;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < w; i++) {
			string a;
			cin >> a;
			for (int j = 0; j < h; j++)
				map[i][j] = a[j];
		}		
		queue<Node> q;
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++){
				if (!visit[i][j]&&map[i][j]=='@'){
					Node Vs(i, j);
					q.push(Vs);
					visit[i][j] = true;
					while (!q.empty())
					{
						Node Vm = q.front();
						q.pop();
						for (int a = 0; a < 8; a++) {
							int xxx = Vm.x + dir[a][0];
							int yyy = Vm.y + dir[a][1];
							if (xxx < 0 || yyy < 0 || xxx >= w || yyy >= h || visit[xxx][yyy] || map[xxx][yyy] == '*')
								continue;
							else {
								Node Vn(xxx, yyy);
								q.push(Vn);
								visit[xxx][yyy] = true;
							}

						}
					}
					sum++;
				}



			}
		printf("%d\n", sum);
		scanf("%d %d", &w, &h);
	}
	return 0;
}