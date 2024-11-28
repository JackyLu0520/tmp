#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;
int head[N],nxt[N*N],ver[N*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ind[N];
queue<int>q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int j;
        while(1){
            scanf("%d",&j);
            if(j==0)    break;
            add(i,j);
            ind[j]++;
        }
    }
    for(int i=1;i<=n;i++)
        if(!ind[i])
            q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        printf("%d ",u);
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            ind[v]--;
            if(!ind[v])q.push(v);
        }
    }
    return 0;
}