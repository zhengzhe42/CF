#include <iostream>
#include <vector>
using namespace std;

int help(string s, string t){
	int len = s.size();
	for(int i=0; i<len; i++){
		string tmp = s.substr(i, len-i) + s.substr(0, i);
		if(tmp.compare(t)==0) return i;
	}
	return -1;
}

int main(){
	int num; vector<string> l;
	cin >> num;
	for(int i=0; i<num; i++){
		string t;
		cin >> t;
		l.push_back(t);
	}
	int res = INT_MAX;
	for(int i=0; i<num; i++){
		int count = 0;
		for(int j=0; j<num; j++){
			int t = help(l[j], l[i]);
			if(t==-1){
				cout << -1 << endl;
				return 0;
			}
			count += t;
		}
		res = min(res, count);
	}
	cout << res << endl;
	return 0;
}