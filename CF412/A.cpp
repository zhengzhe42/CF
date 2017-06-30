#include <iostream>
#include <vector>

using namespace std;

int main(){
	//vector<pair<int,int>> v;
	int len, pre=INT_MAX, res=2;
	cin >> len;
	for(int i=0; i<len; i++){
		int a, b;
		cin >> a >> b;
		if(a!=b){
			res=1;
		}
		else{
			if(res==1) continue;
			if(pre<a){
				res=0;
			}
			pre = min(pre, a);
		}
	}
	if(res==0) cout << "unrated" << endl;
	else if(res==1) cout << "rated" << endl;
	else cout << "maybe" << endl;

	return 1;
}