//  1/2

#include <bits/stdc++.h>
#define MAXNUMBER 21
using namespace std;

int n, counter = 0;

int prime_number[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

int a[MAXNUMBER];
bool visit[MAXNUMBER] = { false };

bool isPrime(int a,int b){
    int s = a+b;
    for(int i = 0;i<12;i++)
        if(s == prime_number[i])
            return true;
    return false;
}

void dfs(int step) {
    if(step == n && isPrime(a[0],a[n-1])){
        for(int i=0;i<n;i++)
            if(i != n-1)
                printf("%d ",a[i]);
            else
                printf("%d",a[i]);
        printf("\n");
    }
    for(int i = 1;i<n;i++){
        if(!visit[i]&&isPrime(a[step-1],i+1)){
            a[step] = i+1;
            visit[i] = true;
            dfs(step+1);
            visit[i] = false;
        }
    }
    return;
}

int main()
{

    int i = 0;
	while(scanf("%d",&n)!=EOF)
	{
	    a[0] = 1;
	    printf("Case %d:\n",++i);
		dfs(1);
        printf("\n");
	}
	return 0;
}
