#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> list;
	int max1=INT_MIN, min1=INT_MAX, max2=INT_MIN, min2=INT_MAX;

	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		list.push_back(t);
		if(i%2==0){
			max1 = max(max1, t);
			min1 = min(min1, t);
		}
		else{
			max2 = max(max2, t);
			min2 = min(min2, t);
		}
	}
	int res = max(abs(max1-min2), abs(max2-min1));
	cout << res << endl;
	
	return 0;
}