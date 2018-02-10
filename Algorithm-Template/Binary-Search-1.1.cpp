//二分
//1.1查找某个数的下标
//不存在返回-1

#include<string>
#include<queue>
#include<iostream>
using namespace std;


int main() {

	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = 2*i;
	int x;
	while (true)
	{
		int _start = 0, _final = 9, _middle = 4;
		cin >> x;
		while (_start <= _final)
		{
			if (a[_middle] == x) {
				cout << _middle << endl;
				return 0;
			}
			else if (a[_middle] > x)
				_final = _middle - 1;
			else
				_start = _middle + 1;

			//这种写法范围有可能会爆
			//_middle = ((_start + _final) >> 1); 2018.2.10
			_middle = _start + (_final - _start) >> 1;
		}

		cout << -1 << endl;
	}
	//system("PAUSE");
	return 0;
}

