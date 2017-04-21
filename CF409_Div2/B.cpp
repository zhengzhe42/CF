#include <iostream>
#define scan(x) scanf("%s",&x)
using namespace std;

int main(){
	string a, z;
	cin >> a >> z;
	string res = "";
	for(int i=0; i<a.size(); i++){
		if(a[i]<z[i]){
			res = "-1";
			break;
		}
		else if(a[i]>z[i]){
			res = res+z[i];
		}
		else res = res+'z';
	}
	cout << res << endl;
	return 0;
}