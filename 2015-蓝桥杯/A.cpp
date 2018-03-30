#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,j;
    for(i = 1;i<100;i++)
        for(j = 1;j<100;j++){
            if(i*j==(i+j)*6&&abs(i-j)<=8){
                printf("%d %d",i,j);
                i = 100;
                j =100;
            }
        }
	return 0;
}
