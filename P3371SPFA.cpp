#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=5e5+10;
int n,m,s;
int head[N],nxt[M],ver[M],ew[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],inq[N];
queue<int>q;
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    q.emplace(s);dis[s]=0;inq[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]) q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]==0x3f3f3f3f?2147483647:dis[i]);
    return 0;
}