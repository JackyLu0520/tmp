#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m,s;
int head[N],nxt[M],ver[M],ew[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],vis[N];
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
>q;
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.emplace(0,s);dis[s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.emplace(dis[v],v);
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
}