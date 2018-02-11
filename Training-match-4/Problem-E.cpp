//HDU - 6015

//	1/1

#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#define MAX_SIZE 1000
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int m, sum = 0;
		multimap<string, int> muti;
		scanf("%d", &m);
		for (int k = 0; k < m; k++) {
			string x;
			int y;
			cin >> x >> y;
			muti.insert(pair<string, int >(x, y));
		}
		multimap <string, int>::iterator map_it;
		for (map_it = muti.begin(); map_it != muti.end(); map_it = muti.upper_bound(map_it->first)) {
			multimap<string, int>::iterator _iterator = muti.find(map_it->first);
			if (muti.count(map_it->first)<2){
				for (int i = 0; i < muti.count(map_it->first); i++, _iterator++)
					sum += _iterator->second;
			}
			else{
				int upper1, upper2;
				upper1 = _iterator->second;
				_iterator++;
				upper2 = _iterator->second;
				_iterator++;
				for (int i = 2; i < muti.count(map_it->first); i++, _iterator++) {
					if (upper1 < _iterator->second)
						swap(upper1, _iterator->second);
					if (upper2 < _iterator->second)
						swap(upper2, _iterator->second);
				}
				sum += upper1 + upper2;
			}

		
		}
		printf("%d\n", sum);
	}

	return 0;
}