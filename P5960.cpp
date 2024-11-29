#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=5e3+10;
int n,m;
int head[N],nxt[M+N],ver[M+N],ew[M+N],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],inq[N],cnt[N];
queue<int>q;
bool spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    q.push(s);dis[s]=0;inq[s]=1;cnt[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){q.push(v);inq[v]=1;cnt[v]++;}
                if(cnt[v]>n)    return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(v,u,w);
    }
    for(int i=1;i<=n;i++)
        add(n+1,i,0);
    if(spfa(n+1))   printf("NO\n");
    else{
        for(int i=1;i<=n;i++)
            printf("%d ",dis[i]);
        printf("\n");
    }
    return 0;
}