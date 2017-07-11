/*** Answer 1 ***/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <iterator>
#include <vector>
#include <map>
#include <set>
//#include <bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define po_ba(x) pop_back(x)
#define pu_ba(x) push_back(x)
#define ba(x) back(x)
#define sqr(x) ((x)*(x))

typedef long long ll;                   // type define long long 
using namespace std;

const long long maxLL = 1e18;           // defind MAX
const long long maxL = 4294967296LL;
const long long maxI = 32767LL;
const long long maxB = 255LL;
const double PI = atan(1)*4;

ll n, m, ol, i, j;
string s, ss;
vector <ll> res, ans; bool ff;

int main()
{
    ios_base :: sync_with_stdio(0);
    //freopen (".in", "r", stdin);
    //freopen (".out", "w", stdout);

    cin >> n >> m >> s >> ss;
    if (s == ss){
        cout << 0;
        return 0;
    }

    for (i=0; i<m-n+1; ++i){
        res.clear();
        for (j=i; j<i+n; ++j){
            if (s[j-i] != ss[j])res.push_back(j+1-i);
        }
        if (res.size() < ans.size() || !ff){
            ans.clear(); ff = 1;
            while (res.size()){
                ans.pu_ba(res.back());
                res.pop_back();
            }
        }
    }

    cout << ans.size() << "\n";
    while (ans.size()){
        cout << ans.back() << " "; ans.pop_back();
    }

    return 0;
}


/*** Answer 2 ***/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

vector<int> calc(const string& s, const string& t, int start) {         // Try create a function
  vector<int> ans;
  for(size_t i = 0; i < s.size(); ++i){
    if(s[i] != t[start + i]){
      ans.push_back(i + 1);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);                                          // Attention ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<int> best(n + 1);
  for(int i = 0; i + n <= m; ++i){
    vector<int> ans = calc(s, t, i);                                    // Attention 
    if(ans.size() < best.size()){
      best = ans;
    }
  }
  cout << best.size() << endl;
  copy(best.begin(), best.end(), ostream_iterator<int>(cout, " "));     // Attention
  cout << endl;
}