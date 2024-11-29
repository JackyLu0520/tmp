#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;
bitset<N>a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int t;scanf("%d",&t);
            a[i][j]=t;
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(a[i][k])
                a[i]|=a[k];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]?1:0);
        printf("\n");
    }
    return 0;
}