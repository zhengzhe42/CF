#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <unordered_map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <array>
#include <math.h>
#include <cassert>
#include <limits>
#include <memory.h>

//#pragma comment(linker,"/STACK:102400000,102400000") // 100 mb

#pragma warning(disable : 4996)

using namespace std;

#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   //freopen("input.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);

   int n;
   cin >> n;

   vector<int> sila(3000001);
   map<int, int> cnt;
   int maxSila = INT_MIN;
   for (int from = 0; from < n; ++from)
   {
      int d;
      cin >> d;
      sila[from] = d;
      cnt[d + 2]++;
      maxSila = max(maxSila, d);
   }

   vector<vector<int>> g(n);
   for (int from = 0; from < n - 1; ++from)
   {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   int ans = maxSila + 2;
   for (int from = 0; from < n; ++from)
   {
      cnt[sila[from] + 2]--;
      cnt[sila[from]]++;
      for (auto to : g[from])
      {
         int x = sila[to];
         cnt[x + 2]--;
         cnt[x + 1]++;
      }

      if (cnt[maxSila + 2] == 0)
      {
         ans = min(ans, maxSila + 1);
         if (cnt[maxSila + 1] == 0)
            ans = min(ans, maxSila);
      }

      cnt[sila[from] + 2]++;
      cnt[sila[from]]--;
      for (auto to : g[from])
      {
         int x = sila[to];
         cnt[x + 2]++;
         cnt[x + 1]--;
      }
   }

   cout << ans << endl;

   return 0;
}