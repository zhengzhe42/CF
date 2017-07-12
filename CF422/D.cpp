#include <cstdio>                                   // ??
#include <cstring>                                  // ??
#define ll long long                                //define
const int MAXN = 5000005;                           // const initialize
const ll mod = 1000000007;                          // const initialize
int n, l, r;
ll t;
bool isprime[MAXN];
int prime[MAXN];
ll f[MAXN];
using namespace std;
int main()
{
    memset(isprime, true, sizeof isprime);          // memset
    for (int i = 2; i <= 5000000; i ++)
    {
        if (isprime[i])
        {
            prime[n++] = i;
            f[i] = ((ll)i * (i - 1) / 2) % mod;
        }
        for (int j = 0; j < n; j ++)
        {
            if (i * prime[j] > 5000000) break;
            isprime[i * prime[j]] = false;
            f[i * prime[j]] = (i * f[prime[j]] + f[i]) % mod;
            if (i % prime[j] == 0) break;
        }
    }
    scanf("%lld%d%d", &t, &l, &r);                  // scanf 
    ll ans = 0;
    for (int i = r; i >= l; i --)
        ans = (ans * t + f[i]) % mod;
    printf("%lld", ans);
    return 0;
}