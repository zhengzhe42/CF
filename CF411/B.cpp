#include <iostream>

using namespace std;

int main(){
	int len;
	cin >> len;
	string res = "";
	while(len>=3){
		res += "aab";
		len -= 3;
	}
	if(len==1) res += "a";
	else if(len==2) res += "aa";
	cout << res << endl;
	return 1;
}