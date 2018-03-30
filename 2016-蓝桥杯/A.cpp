#include <bits/stdc++.h>
using namespace std;

int main(){
    int couter = 0;
    for(int i = 27;i<100;i++){
        int a = (i%10)*10 + i/10;
        if(i-a==27)
            couter++;
    }
    printf("%d\n",couter);
    return 0;
}
