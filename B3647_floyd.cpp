#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,dis[N][N];
int main(){
    scanf("%d%d",&n,&m);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=dis[u][v];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",dis[i][j]);
        printf("\n");
    }
    return 0;
}