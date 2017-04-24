#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int l=0, r=0;
	unordered_set<int> set;
	while(true){
		int t1 = b + a*l;
		int t2 = d + c*r;
		if(t1==t2){
			cout << t1 << endl;
			return 0;
		}
		int diff = t1 - t2;
		if(set.find(diff)!=set.end()){
			cout << -1 << endl;
			return 0;
		}
		set.insert(diff);
		if(t1<t2) l++;
		else r++;
	}
	return 0;
}