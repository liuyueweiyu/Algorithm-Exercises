//

#include<iostream>

//这题容易越界= =ll范围...

//HYSBZ - 5106

// 1/11

#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long LL;
const LL N = 200010;
LL S, L, n;
LL hi[N], ai[N];

bool Check(LL mid) {
	LL sum = 0;
	for (int i = 0; i < n; i++){
		if (hi[i] + ai[i] * mid >= L)
			sum += hi[i] + ai[i] * mid;
		if (sum >= S)
			return true;
	}
	return false;
}

int main() {

	scanf("%lld %lld %lld", &n, &S, &L);
	for (int i = 0; i < n; i++)
		scanf("%lld", &hi[i]);
	for (LL i = 0; i < n; i++)
		scanf("%lld", &ai[i]);
	LL _start = 0, _final = 1e18, _middle = 0, _ans = 0;
	for (LL i = 0; i < n; i++)
		_final = min(_final, (max((S - hi[i]) / ai[i] + 1, (L - hi[i]) / ai[i] + 1)));       //取单棵树长到要求时的最小时间，即为上界
	while (_start <= _final){
		_middle = _start + ((_final - _start) >> 1);
		if (Check(_middle)) {
			_final = _middle - 1;
			_ans = _middle;
		}
		else
			_start = _middle + 1;
		
	}
	printf("%lld\n", _ans);
	return 0;
}
