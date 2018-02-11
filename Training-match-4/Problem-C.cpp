
//POJ-2386

//	1/3

#include<iostream>
#include<queue>
using namespace std;
const int MAX_SIZE = 111;


char map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE] = { false };
int dir[8][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 },{-1,-1},{-1,1},{1,-1},{1,1} };

class Node
{
public:
	int x;
	int y;
	Node(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Node() {}
};


int main() {
	int N, M, number = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	if (N == 1 && M == 1 && map[0][0] == 'W')
	{
		cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {

			if (!visit[i][j] && map[i][j] == 'W')
			{
				int counter = 0;
				queue<Node> Q;
				Node n(i, j);
				Q.push(n);
				visit[i][j] = true;
				for (; !Q.empty(); )
				{
					Node oldN = Q.front();
					Q.pop();
					counter++;
					for (int a = 0; a < 8; a++)
					{
						int x = oldN.x + dir[a][0];
						int y = oldN.y + dir[a][1];
						if (x >= 0 && x < N&&y >= 0 && y < M && map[x][y] == 'W' && !visit[x][y])
						{
							Node Nes(x, y);
							Q.push(Nes);
							visit[x][y] = true;
						}
					}
				}

				if (counter >= 1)
					number++;
			}

		}
	cout << number << endl;


	return 0;
}