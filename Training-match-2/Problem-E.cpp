#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int  MAXSIZE = 10020;
int values[MAXSIZE];

struct Node
{
	int values;
	int parents;
}nodes[MAXSIZE];

int find(int i) {
	if (nodes[i].parents != -1)
		find(nodes[i].parents);
	return i;
}

int main() {
	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nodes[i].values;
		nodes[i].parents = -1;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b;
		a--, b--;
		c = max(a, b);
		int pa = find(min(a, b));
		if (pa != c)
			nodes[pa].parents = c;
	}
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (nodes[i].parents != -2)
		{
			if (nodes[i].parents != -1) {
				int _min;
				_min = nodes[i].values;
				int r = i;
				while (nodes[r].parents != -1)
				{
					_min = min(_min, nodes[nodes[r].parents].values);
					int xxx = nodes[r].parents;
					nodes[r].parents = -2;
					r = xxx;
				}
				_min = min(_min, nodes[r].values);
				nodes[r].parents = -2;
				sum += _min;
			}
			else
				sum += nodes[i].values;
		}
	}
	cout << sum << endl;
	system("PAUSE");
	return 0;
}