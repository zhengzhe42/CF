#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct {
	int cost;
	int end;
}endStruct;
typedef struct {
	int cost;
	int duration;
	int start;
}startStruct;

int main(){
	int n, x, i, res;
	res = INT_MAX;
	unordered_map<int,vector<endStruct>> endMap;
	vector<startStruct> start;
	cin >> n >> x;
	for(i=0; i<n; i++){
		int l, r, c;
		cin >> l >> r >> c;
		int duration = r-l+1;
		endStruct e = {.cost=c, .end=r};
		startStruct s = {.cost=c, .duration=duration, .start=l};
		if(endMap.find(duration)==endMap.find()){
			vector<endStruct> t;
			endMap[duration] = t;
		}
		endMap[duration].push_back( e );
		start.push_back( s );
	}
	for(int i=0; i<n; i++){
		if(endMap.find(x-start[i].duration) != endMap.end()){
			vector<endStruct> e = endMap[x-start[i].duration];
			for(i=0; i<e.size(); i++){
				if(start[i].start<e.end && e.cost+start[i].cost<res){
					res = e.cost+start[i].cost;
				}
			}
		}
	}
	if(res==INT_MAX) return cout << "-1" << endl;
	else cout << res << endl;
	return 0;
}

#include<iostream>  
#include<cmath>  
#include<queue>  
#include<cstdio>  
#include<queue>  
#include<algorithm>  
#include<cstring>  
#include<string>  
#include<utility>
#include<map>
#include<stack>
#include<vector>
#define maxn 200005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const int mod = 1e9 + 7;
struct node{
	int index, mark, value, cost;
}p[maxn << 1];
bool cmp(node a, node b){
	return a.index < b.index || (a.index == b.index&&a.mark < b.mark);
}
int dp[maxn];
int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int number = 0;
	while (n--){
		int l, r, cost;
		scanf("%d%d%d", &l, &r, &cost);
		p[number].index = l;
		p[number + 1].index = r;
		p[number].mark = 0;
		p[number + 1].mark = 1;
		p[number].value = p[number + 1].value = r - l + 1;
		p[number].cost = p[number + 1].cost = cost;
		number += 2;
	}
	sort(p, p + number, cmp);
	memset(dp, inf, sizeof(dp));
	int ans = inf << 1;
	for (int i = 0; i < number; i++){
		if (p[i].mark)
			dp[p[i].value] = min(dp[p[i].value], p[i].cost);
		else{
			int value = x - p[i].value;
			if (value >= 0 && dp[value] != inf)
				ans = min(ans, dp[value] + p[i].cost);
		}
	}
	ans = ans == inf << 1 ? -1 : ans;
	printf("%d\n", ans);
}




#include<bits/stdc++.h>  
using namespace std;  
const int M=2e5+10;  
struct aa  
{  
    int u,v,w;  
} save1[M],save2[M];  
long long mincost[M];  
bool cmp1(const aa &a,const aa &b)  
{  
    return a.u<b.u;  
}  
bool cmp2(const aa &a,const aa &b)  
{  
    return a.v<b.v;  
}  
long long gmin(long long a,long long b)  
{  
return a>b?b:a;  
}  
int main()  
{  
    int n,x;  
    while(scanf("%d%d",&n,&x)!=EOF)  
    {  
        for(int i=0;i<M;i++)  
        mincost[i]=INT_MAX;  
        for(int i=0; i<n; i++)  
        {  
            scanf("%d%d%d",&save1[i].u,&save1[i].v,&save1[i].w);  
            save2[i]=save1[i];  
        }  
        sort(save1,save1+n,cmp1);  
        sort(save2,save2+n,cmp2);  
        int minn=INT_MAX;  
        int j=0;  
        for(int i=0; i<n; i++)  
        {  
            while(j<n&&save2[j].v<save1[i].u)  
            {  
                mincost[save2[j].v-save2[j].u+1]=gmin(mincost[save2[j].v-save2[j].u+1],save2[j].w);//ά����Сֵ  
                j++;  
            }  
            int k=x-(save1[i].v-save1[i].u+1);//�ҳ���Ӧʱ��  
            if(k>0&&minn>mincost[k]+save1[i].w)//������Сֵ  
                minn=mincost[k]+save1[i].w;  
        }  
        if(minn==INT_MAX)  
            printf("-1\n");  
        else  
            printf("%d\n",minn);  
    }  
}  