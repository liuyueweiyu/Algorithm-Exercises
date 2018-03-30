#include <cstdio>
#include <queue>
using namespace std;

int maps[3][4] = { 0 };
bool visit[3][4] = { false };
int _ans = 0;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

struct Node {
	int x;
	int y;
};

bool check() {
	int i, j, flag = 0;
	for (i = 0; i<3; i++)
		for (j = 0; j<4; j++) {
			if (maps[i][j] != 0) {
				queue<Node> q;
				Node n;
				visit[i][j] = true;
				n.x = i;
				n.y = j;
				q.push(n);
				while (!q.empty()) {
					Node nnn = q.front();
					q.pop();
					flag++;
					for (int k = 0; k<4; k++) {
						int xxx = nnn.x + dir[k][0];
						int yyy = nnn.y + dir[k][1];
						if (xxx<0 || xxx >= 3 || yyy<0 || yyy >= 4 || visit[xxx][yyy] || maps[xxx][yyy] == 0)
							continue;
						else {
							Node new_n;
							visit[xxx][yyy] = true;
							new_n.x = xxx;
							new_n.y = yyy;
							q.push(new_n);
						}
					}
				}
				memset(visit, 0, sizeof(visit));
				if (flag == 5)
					return true;
				else
					return false;
			}

		}
	return false;

}

void dfs(int step) {
	if (step == 6) {
		if (check())
			_ans++;
		return;
	}
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<4; j++) {
			if (maps[i][j] == 0) {
				maps[i][j] = 1;
				dfs(step + 1);
				maps[i][j] = 0;
			}
		}
	}
}

int main() {
	dfs(1);
	printf("%d\n", _ans/120);
	system("PAUSE");


	return 0;
}
