#include <iostream>
#include <string>

const int minutes = 60;
using namespace std;

int help(string h, string m){
	string rh=h;
	swap(rh[0], rh[1]);
	if(rh.compare(m)==0) return 0;
	int hh = stoi(h)%24, mm = stoi(m), rhh = stoi(rh), res = 0;
	while( rhh<mm || rhh>59 ){
		res += minutes-mm;
		hh = (hh+1)%24;
		mm = 0;
		rh = to_string(hh);
		//cout << rh <<" "<< rh.size() << endl;
		if(rh.size()==1){
		    rh += "0";
		}
		else{
		    swap(rh[0], rh[1]);
		}
		rhh = stoi(rh);
	}
	res += rhh-mm;
	return res;
}

int main(){
	string s;
	cin >> s;
	cout << help(s.substr(0,2), s.substr(3,2)) << endl;
	return 0;
}