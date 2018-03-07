#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include <map>
#include<queue>
#define scanf scanf_s
#define MAX_SIZE 101
#define MAXNUMBER 4000000
using namespace std;


string mutiBig(string x, string y) {
	char _ans[1000] = { 0 };
	if (x == "0" || y == "0")
		return "0";
	for (int i = 0; i < x.length(); i++)
		for (int j = 0; j < y.length(); j++) {
			_ans[i + j] = (x[i])*(y[j] ) + _ans[i + j];
			if (_ans[i + j] >= 10)
				_ans[i + j + 1] += 1, _ans[i + j] = _ans[i + j] % 10;
		}
			
	return _ans;
}

string addBig(string x, string y) {
	char _ans[1000] = { 0 };
	int counter = min(x.length(), y.length());
	int anotger_ = max(x.length(), y.length());
	for (int i = 0; i < counter; i++){
		_ans[i] = x[i] + y[i];
		if (_ans[i] >= 10)
			_ans[i + 1]++, _ans[i] %= 10;
	}
	string a = x.length() > y.length() ? x : y;
	for (int i = counter; i < anotger_; i++){
		_ans[i] += a[i];
		if (_ans[i] >= 10)
			_ans[i + 1]++, _ans[i] %= 10;
	}
	return _ans;
}

string subOneBig(string x) {     
	int moutner = x.length();
	for (int i = 0; i < moutner; i++)
		if (x[i] < 0)
			x[i] += 10, x[i + 1]--;
		else if (x[i] == 0)
			x[i] += 9, x[i + 1]--;
		else
			x[i]--;
	return x;
}

int n;
string all[20];
int main() {

	system("PAUSE");
	return 0;
}