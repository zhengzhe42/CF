#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

#define scan(x) scanf("%d",&x);

int main(){
	int n, k, d;
	scan(n); scan(k); scan(d);
	int res = 0;
	unordered_map<int,vector<int>> M;
	queue<int> Q;
	bool visited[300010];
	vector<pair<int,int>> road;
	for(int i=0; i<k; i++){
		int a; scan(a);
		Q.push(a);
		visited[a]=true;
	}
	for(int i=1; i<n; i++){
		int a, b;
		scan(a); scan(b);
		pair<int,int> temp(a,b);
		road.push_back(temp);
		M[a].push_back(road.size()-1);
		M[b].push_back(road.size()-1);
	}
	int count=0;
	int level=1;
	while(!Q.empty()){
		if(count==n) break;
		int t = Q.front();
		Q.pop();
		count++;
		vector<int> temp(M[t]);
		for(auto v : temp){
			pair<int,int> p (road[v]);
			if(p.first==t){
				if(visited[p.second]) res++;
				else{
					Q.push(p.second);
					visited[p.second];
					count++;
					road[v].first=400000;
				}
			}
			else{
				if(visited[p.first]) res++;
				else{
					Q.push(p.first);
					visited[p.first];
					count++;
					road[v].first = 400000;
				}
			}
		}
	}
	printf("%d\n", road.size()-res);
	for(int i=0; i<road.size(); i++){
		if(road[i].first==400000) continue;
		printf("%d ", i);
	}
	return 0;
}