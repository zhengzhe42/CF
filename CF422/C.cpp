#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 200005											// using define

using namespace std;

struct node{												// create struct
	int start; int end; int cost;
}node1[maxn], node2[maxn];

vector<long long> mincost(maxn, INT_MAX);

bool compare1(const node &n1, const node &n2){				// compare function 
	return n1.start <n2.start;
}
bool compare2(const node &n1, const node &n2){
	return n1.end < n2.end;
}

int compares(long long a, long long b){						// min function by long long
	return a<b ? a : b;
}

int main(){
	int n, x, i, j, res;
	res = INT_MAX;
	cin >> n >> x;
	for(i=0; i<n; i++){
		cin >> node1[i].start >> node1[i].end >> node1[i].cost;
		node2[i] = node1[i];
	}
	sort(node1, node1+n, compare1);							// sort using customized compare
	sort(node2, node2+n, compare2);
	j=0;
	for(i=0; i<n; i++){
		while(j<n && node2[j].end<node1[i].start){
			mincost[node2[j].end-node2[j].start+1] = compares(mincost[node2[j].end-node2[j].start+1], node2[j].cost);
			j++;
		}
		int k = x - (node1[i].end-node1[i].start+1);
		if(k>0 && res > mincost[k]+node1[i].cost ) res = mincost[k]+node1[i].cost;
	}

	if(res==INT_MAX) cout << "-1" << endl;
	else cout << res << endl;

	return 0;
}