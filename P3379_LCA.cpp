#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,L=21;
int n,m,s;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int fa[N][L],depth[N];
void dfs(int u,int p){
    fa[u][0]=p;depth[u]=depth[p]+1;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v!=p)
            dfs(v,u);
    }
}
int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1) u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(s,0);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        printf("%d\n",lca(u,v));
    }
    return 0;
}