#include<bits/stdc++.h>
typedef long long lnt;
const int inf = -2e9;
int m1=inf,m2=inf;
int a[300010],t1[300010],t2[300010];
int main(){
    int n,k;
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
        scanf("%d",&a[k]);
        if(a[k]>m1){
            m2=m1;
            m1=a[k];
        }
        else if(a[k]>m2){
            m2=a[k];
        }
    }
    int x=0,y=0;
    for(int k=1;k<=n;k++){
        if(m1==a[k]) x++;
        if(m2==a[k]) y++;
    }
    for(int k=1;k<n;k++){
        int p,q;
        scanf("%d%d",&p,&q);
        if(a[p]==m1) t1[q]++;
        if(a[p]==m2) t2[q]++;
        if(a[q]==m1) t1[p]++;
        if(a[q]==m2) t2[p]++;
    }
    int ans=2e9;
    for(int k=1;k<=n;k++){
        int tmp=a[k];
        if(t1[k]>0) tmp=std::max(tmp,m1+1);
        if(t2[k]>0) tmp=std::max(tmp,m2+1);
        if(a[k]==m1) t1[k]++;
        if(a[k]==m2) t2[k]++;
        if(t1[k]<x) tmp=std::max(tmp,m1+2);
        if(t2[k]<y) tmp=std::max(tmp,m2+2);
        if(tmp<ans) ans=tmp;
    }
    printf("%d\n",ans);
}