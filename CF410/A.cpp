#include <iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	int l=0, r=s.size()-1, count=0;
	while(l<r){
		if(s.at(l)!=s.at(r)){
			if(count>0){
				cout << "NO" << endl;
				return 0;
			}
			count++;
		}
		l++; r--;
	}

	if(count==1 || l==r) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
<<<<<<< HEAD

	
=======
>>>>>>> 0d12ef986e58e249182b75f961b5ad6b099506cf
}