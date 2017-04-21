#include<bits/stdc++.h>
#define PI acos(-1)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define MX 300005
#define MXX 1000005
#define  s second
#define f first
#define mod 1000000007
#define inf 1000000000
//int ex[]={1,-1,0,0};
//int wye[]={0,0,1,-1};
using namespace std;
int p[MX],col[MX],cur[MX],n,k,d,a[MX],b[MX];
vector<int>vt[MX];
int dfs(int node,int par)
{
    int tmp,siz=vt[node].size(),lol=cur[node],tpp;
    if(p[node]) lol=0,cur[node]=0,col[node]=node;
    if(lol>cur[par]+1) cur[node]=cur[par]+1,col[node]=col[par],lol=cur[par]+1;
    for(int i=0;i<siz;i++){
        tmp=vt[node][i];
        if(tmp==par){
            continue;
        }
        tpp=dfs(tmp,node)+1;
        if(lol>tpp) lol=tpp,cur[node]=tpp,col[node]=col[tmp];
    }
    //cout<<node<<" "<<col[node]<<" "<<cur[node]<<endl;
    return lol;
}
int main()
{
    fast();
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1,x;i<=k;i++){
        scanf("%d",&x);
        p[x]=1;
    }
    cur[1]=inf,cur[0]=inf;
    for(int i=1;i<n;i++){
        cur[i+1]=inf;
        scanf("%d%d",&a[i],&b[i]);
        vt[a[i]].push_back(b[i]);
        vt[b[i]].push_back(a[i]);
    }
    dfs(1,0);
   // for(int i=1;i<=n;i++) printf("%d ",col[i]);
   // printf("\n");
    dfs(1,0);
    //for(int i=1;i<=n;i++) printf("%d ",col[i]);
     for(int i=1;i<n;i++) if(col[a[i]]!=col[b[i]]) vt[0].push_back(i);
    n=vt[0].size();
    printf("%d\n",n);
    for(int i=0;i<n;i++) printf("%d ",vt[0][i]);
    return 0;
}