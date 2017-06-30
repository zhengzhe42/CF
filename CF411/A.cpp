#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int res=0, temp=0, i=2;
	while(i<=a){
		int count =0;
		if(i>b) break;
		for(int j=a; j<=b; j++){
			if(j%i==0) count++;
		}
		if(count>=temp){
			temp = count;
			res = i;
		}
		i++;
	}
	cout << res << endl;
	return 1;
}