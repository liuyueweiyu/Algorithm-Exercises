#include <bits/stdc++.h>
using namespace std;

int main(){
    int couter = 0,i,j,year;
    for(i = 1;i<100;i++){
        couter = 0;
        year = i;
        for(j=i;j<100;j++){
            couter+=j;
            if(couter == 236){
                i = 100;
                break;
            }
            else if(couter >236)
                break;
        }
    }
    printf("%d\n",year);
    return 0;
}
