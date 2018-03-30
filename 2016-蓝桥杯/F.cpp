#include <bits/stdc++.h>
using namespace std;

int a[13] = {0};
bool visit[13] = { false };
int _ans = 0;

void dfs(int step){
    if(step == 4 && a[0] + a[1] != a[2])
        return;
    if(step == 7 && a[3] - a[4] != a[5])
        return;
    if(step == 10 && a[6] * a[7] != a[8])
        return;
    if(step == 13){
        if(a[11] * a[10] == a[9])
            _ans++;
        return;
    }
    for(int i = 0;i<13;i++){
        if(!visit[i]){
            visit[i] = true;
            a[step-1] = i+1;
            dfs(step+1);
            a[step-1] = 0;
            visit[i] = false;
        }
    }
    return;

}


int main(){

    dfs(1);
    printf("%d",_ans);
    return 0;
}
