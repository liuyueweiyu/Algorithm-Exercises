#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i,j,k,l;
        for(i = 0;i<2500;i++){
            for(j = i;j<2500;j++){
                for(k = j;k<2500;k++){
                    for(l = k;l<2500;l++){
                        if(i*i+j*j+k*k+l*l==n)
                            printf("%d %d %d %d\n",i,j,k,l),i=2500,j=2500,k=2500,l=2500;
                        if(i*i+j*j+k*k+l*l>n)
                            l = 2500;
                    }
                    if(i*i+j*j+k*k>n)
                        k = 2500;
                }
                if(i*i+j*j>n)
                    j =2500;
            }

        }

    }


    return 0;
}
