
//CodeForces - 60B

//	1/3

#include<string>
#include<queue>
#include<iostream>
using namespace std;

bool box[10][10][10] = { false };
int dir[6][3] = { { 0,0,1 },{ 0,0,-1 },{ 0,-1,0 },{ 0,1,0 },{ 1,0,0 },{ -1,0,0 } };
bool visit[10][10][10] = { false };
class Node
{
public:
	Node(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	int x;
	int y;
	int z;
private:

};

int main() {
	int h, w, l, i = 0;
	int oks, jsd;
	cin >> h >> w >> l;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			for (int k = 0; k < l; k++) {
				char x;
				cin >> x;
				if (x == '.')
				{
					box[i][j][k] = true;
					//number++;
				}
			}
	cin >> oks >> jsd;

	queue<Node> Q;
	Node Vs(0, oks - 1, jsd - 1);
	visit[0][oks - 1][jsd - 1] = true;
	Q.push(Vs);
	for (i = 0; !Q.empty(); i++ ) {
		Node v = Q.front();
		Q.pop();
		for (int a = 0; a < 6; a++) {
			int x = v.x + dir[a][0];
			int y = v.y + dir[a][1];
			int z = v.z + dir[a][2];
			if (x >= 0 && x < h&&y >= 0 && y < w&&z >= 0 && z < l&&box[x][y][z] && !visit[x][y][z]) {
				
				Node mmmm(x, y, z);
				visit[x][y][z] = true;
				Q.push(mmmm);
			}

		}
	}

	cout << i << endl;
	return 0;
}
