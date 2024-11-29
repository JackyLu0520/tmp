#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10,M=3e3+10;
int n,m;
int head[N],nxt[2*M],ver[2*M],ew[2*M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],inq[N],cnt[N];
queue<int>q;
bool spfa(){
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    q.push(1);dis[1]=0;cnt[1]=1;inq[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]) q.push(v),cnt[v]++,inq[v]=1;
                if(cnt[v]>n-1)  return 1;
            }
        }
    }
    return 0;
}
int main(){
    int _;scanf("%d",&_);
    while(_--){
        scanf("%d%d",&n,&m);
        tot=1;
        memset(head,0,sizeof(head));
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            if(w>=0)    add(v,u,w);
        }
        printf(spfa()?"YES\n":"NO\n");
    }
    return 0;
}