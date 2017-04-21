#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k , res = 0, count=0;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        res += t/k;
        if(t%k == 0) continue;
        count++;
    }
    res += count;
    if(res%2==0) res = res/2;
    else res = res/2+1;
    cout << res <<endl;
    return 0;
}