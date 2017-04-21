#include <iostream>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    int a[n][2];
    long long sum = 0;
    for(int i=0; i<n; i++){
        int t1, t2;
        cin >> t1 >> t2;
        a[i][0] = t1;
        a[i][1] = t2;
        sum += a[i][0];
    }
    if(sum<=p){
        cout << "-1" << endl;
        return 0;
    }
    double l = 0, r = 1e18, answer = 0;
    while(l<r){
        double m = l+(r-l)/2.0;
        double temp = 0;
        bool isOkay = true;
        for(int i=0; i<n; i++){
            if(m*a[i][0]>a[i][1]){
                temp += (m*a[i][0]-a[i][1]);
            }
        }
        if(temp <= (double)p*m){
            answer = m;
            l = m+0.00001;
        }
        else{
            r = m-0.00001;
        }
    }
    cout << answer << endl;
    return 0;
}