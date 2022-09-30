#include <stdio.h>

#define inf 100001

int main(){

    int n, m;
    scanf("%dx%d", &n, &m);

    char mat[n][m];
    int dist[n][m];

    int or_x, or_y;//origem
    int d_x, d_y;//destino

    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        scanf(" %c", &mat[i][j]);
        dist[i][j]=0;

        if(mat[i][j]=='o'){
            or_x=i;
            or_y=j;
        }else if(mat[i][j]=='d'){
            d_x=i;
            d_y=j;
        }
    }

    //CASO D adj O
    if((or_x-1==d_x&&or_y==d_y)||(or_x+1==d_x&&or_y==d_y)||(or_x==d_x&&or_y-1==d_y)||(or_x==d_x&&or_y+1==d_y)){
        printf("Apos correr 1 metros e quase desistir por causa da dist�ncia, Rebeka conseguiu escapar!\n");
        return 0;
    }


    int step=1;
    //distancia vertical
    for(int i=or_x-1;i>=0;i--){
        if(mat[i][or_y]=='#') break;
        else if(mat[i][or_y]=='_'){
            dist[i][or_y]+=step;
            step++;
        }
    }
    step=1;
    for(int i=or_x+1;i<n;i++){
        if(mat[i][or_y]=='#') break;
        else if(mat[i][or_y]=='_'){
            dist[i][or_y]+=step;
            step++;
        }
    }
    //distancia horizontal
    step=1;
    for(int i=or_y-1;i>=0;i--){
        if(mat[or_x][i]=='#') break;
        else if(mat[or_x][i]=='_'){
            dist[or_x][i]+=step;
            step++;
        }
    }
    step=1;
    for(int i=or_y+1;i<m;i++){
        if(mat[or_x][i]=='#') break;
        else if(mat[or_x][i]=='_'){
            dist[or_x][i]+=step;
            step++;
        }
    }

    //paredes
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(mat[i][j]=='#') dist[i][j]=inf;
    }  
    
    //outras casas
    int l[] = {-1, 1, 0, 0};
    int c[] = {0, 0, -1, 1};
    int t=n+m;
    while(t--){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==or_x&&j==or_y)) continue;
                for(int k=0;k<4;k++){
                    int lx=l[k]+i;
                    int cx=c[k]+j;

                    if(lx>=n||cx>=m||lx<0||cx<0||dist[lx][cx]==0||dist[i][j]==inf) continue;

                    //dist[i][j] = (dist[i][j] > dist[lx][cx]) ? dist[lx][cx] : dist[i][j];
                    if(dist[i][j]==0 && dist[lx][cx]!=inf){
                        dist[i][j] = dist[lx][cx] + 1;
                    }else{
                        dist[i][j] = (dist[i][j] > dist[lx][cx]+1) ? dist[lx][cx]+1 : dist[i][j];
                    }
                }
            }
        }
    }

    //print mat dist
    // printf("\n");
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++){
    //         printf("%d ", dist[i][j]);
    //     }
    //     printf("\n");
    // }

    int value=dist[d_x][d_y];
    if(value==0) printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    else printf("Apos correr %d metros e quase desistir por causa da dist�ncia, Rebeka conseguiu escapar!\n", value);

    return 0;
}