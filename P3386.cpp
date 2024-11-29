#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,e;
int match[N];
vector<int>a[N];
int cnt=0;
int vis[N];
bool dfs(int u){
    for(int v:a[u])
        if(!vis[v]){
            vis[v]=1;
            if(!match[v]||dfs(match[v])){
                match[v]=u;
                return 1;
            }
        }
    return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&e);
    for(int i=1;i<=e;i++){
        int u,v;scanf("%d%d",&u,&v);
        a[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        cnt+=dfs(i);
    }
    printf("%d",cnt);
    return 0;
}