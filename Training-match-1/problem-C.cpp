
//CodeForces 155A

// 1/1

#include<iostream>
using namespace std;

int main() {

	int N = 0;
	
	
	cin >> N;
	int a;
	cin >> a;
	int max_number = a, min_nunmber = a;
	int counter = 0;
	for (int i = 0; i < N-1; i++)
	{
		cin >> a;
		if (a > max_number)
		{
			counter++;
			max_number = a;
		}
		if (a < min_nunmber)
		{
			counter++;
			min_nunmber = a;
		}
	}
	cout << counter << endl;
	return 0;
}