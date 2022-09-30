#include <bits/stdc++.h>

using namespace std;

#define cood pair<int,int>
#define x first
#define y second

vector<cood> path;

cood player;

int l[] = {1,-1,0,0};
int c[] = {0,0,-1,1};

int n, m;//tamanho da tela

int map[n][m];

vector<cood> findPath(cood pos){
    if(player.x == pos.x && player.y == pos.y) {
        return path;
    }
    for(int k=0;k<4;k++){
        int i = pos.x + l[k];
        int j = pos.x + c[k];

        if(i<0||j<0||i>=n||j>=m||map[i][j]) continue;//nao passar do limite da tela

        path.push_back({i, j});
        findPath({i, j});
        path.pop();
    }

}

int main(){

    return 0;
}