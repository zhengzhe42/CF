#include <iostream>
#include <unordered_set>
#define ll long long

using namespace std;

int main(){
    unordered_set<ll> bad, added;
    int b1, q, l1, m;
    cin >> b1 >> q >> l1 >> m;
    for(int j=0; j<m; j++){
        int t;
        cin >> t;
        bad.insert(t);
    }
    ll b = (ll)b1;
    ll l = (ll)l1;
    int count = 0;
    while(abs(b) <= l && added.find(b)==added.end()){
        added.insert(b);
        if(bad.find(b)==bad.end()){
            count++;
        }
        b *= q;
    }
    if(abs(b)<=l){
        if(bad.find(b) == bad.end()) cout << "inf" << endl;
        else{
            if(q==-1 && count>0) cout << "inf" << endl;
            else cout << count << endl;
        }
        return 0;
    }
    cout << count << endl;
    return 0;
}