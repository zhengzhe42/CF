#include <iostream>
#include <vector>

using namespace std;

int main(){
	string s;
	cin >> s;
	if(s.size()<2){
		cout << 0;
		return 0;
	}
	bool flag = true;
	vector<int> dp(s.size()+1, 0);
	for(int i=1; i<s.size(); i++){
		if(s[i-1]=='V' && s[i]=='K') dp[i+1] = max(dp[i-1]+1, dp[i]);
		else if(s[i-1] == s[i] && flag){
			dp[i+1] = max(dp[i-1], dp[i]);
			if(s[i]=='V'){
				if(i==s.size()-1 || s[i+1]=='V') flag = false;
			}
			else{
				if(i-1==0 || s[i-2]=='K') flag = false;
			}
		}
		else dp[i+1] = max(dp[i-1], dp[i]);
	}
	int res = max(dp[s.size()-1], dp[s.size()]);
	res = flag ? res : res+1;
	cout << res << endl;
	return 0;
}