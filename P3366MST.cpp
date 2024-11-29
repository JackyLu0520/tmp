#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=2e5+10;
int n,m;
struct edge{
    int u,v,w;
    inline bool operator<(const edge& a)const{
        return w<a.w;
    }
}e[M];
struct dsu{
    int fa[N];
    dsu(int n){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
int ans=0,cnt;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+m+1);
    dsu d(n);
    cnt=n;
    for(int i=1;i<=m&&cnt>1;i++)
        if(d.query(e[i].u)!=d.query(e[i].v)){
            d.merge(e[i].u,e[i].v);
            ans+=e[i].w;
            cnt--;
        }
    if(cnt==1)  printf("%d",ans);
    else        printf("orz");
    return 0;
}