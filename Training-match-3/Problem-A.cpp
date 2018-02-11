
//CodeForces-82A

//	1/3

#include<string>
#include<queue>
#include<iostream>
using namespace std;



int main() {
	int n, i,sum =0;

		cin >> n;
		string q[5] = { "Sheldon" ,"Leonard" ,"Penny","Rajesh","Howard" };

		for (i = 0;; i++)
			if ((sum += (1 << i) * 5) > n -1)
				break;
		//cout << i << endl;
		int mark = i;
		// i 组
		for (i = 0,sum = 0;i < mark; i++)
			sum += (1 << i) * 5;
		sum = n - sum;
		int mul = (1 << mark);

		for  (i = 0; mul*i < sum; i++);
		cout << q[i-1] << endl;
		//cout << sum << endl;
	

	return 0;
}

