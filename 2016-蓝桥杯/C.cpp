#include <bits/stdc++.h>
using namespace std;

int dir[8][2] = {{1,1},{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1}};
int maps[3][4] = {0};
int _ans = 0;
bool visit[3][4] = { false };

bool check(int x,int y,int n){
    for(int i = 0;i<8;i++){
        int xxx = x+dir[i][0];
        int yyy = y + dir[i][1];
        if(xxx<0||xxx>=3||yyy<0||yyy>=4)
            continue;
        else{
            if(maps[xxx][yyy]!=0&&abs(maps[xxx][yyy] - n)==1)
                return false;
        }
    }
    return true;
}

void dfs(int step){
    if(step==10){
        int i,j,flag = 0;
        for(i = 0;i < 3;i++){
            for(j = 0;j<4;j++){
                if(maps[i][j]>=0&&!visit[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(check(i,j,step))
            _ans++;
        else
            return;
    }
    for(int i = 0;i < 3;i++){
        for(int j = 0;j<4;j++){
            if(maps[i][j]>=0&&!visit[i][j]&&check(i,j,step)){
                maps[i][j] = step;
                visit[i][j] = true;
                dfs(step+1);
                maps[i][j] = 0;
                visit[i][j] = false;
            }
        }
    }
    return;

}


int main(){
    maps[0][0] = -1;
    maps[2][3] = -1;
    visit[0][0] = true;
    visit[2][3] = true;

    dfs(1);
    printf("%d\n",_ans);

    return 0;
}
