#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	int lenS, lenT, i, j;
	string s, t;
	cin >> lenS >> lenT >> s >> t;
	vector<int> res;
	int size = 1e7;						// Attention
	for(i=0; i<=lenT-lenS; i++){
		vector<int> temp;
		for(j=i; j<lenS+i; j++){
			if(t[j]!=s[j-i]) temp.push_back(j-i+1);
		}
		if(temp.size()<size){
			res = temp;					// Attention vector a = b
			size = temp.size();
		}
	}
	cout << res.size() << endl;
	for(i=0; i<res.size(); i++) cout << res[i] << " ";
	return 0;
}