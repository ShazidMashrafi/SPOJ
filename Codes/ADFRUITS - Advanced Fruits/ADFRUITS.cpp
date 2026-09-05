#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define dbg(...)
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve(string& a, string& b)
{
    int n = sz(a), m = sz(b);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <=n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i - 1] == b[j - 1]) {
            ans.pb(a[i - 1]);
            i--;
            j--;
        } else if(dp[i - 1][j] >= dp[i][j - 1]) {
            ans.pb(a[i - 1]);
            i--;
        } else {
            ans.pb(b[j - 1]);
            j--;
        }
    }

    while(i > 0) {
        ans.pb(a[i - 1]);
        i--;
    }
    while(j > 0) {
        ans.pb(b[j - 1]);
        j--;
    }

    reverse(all(ans));
    cout << ans << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    string a, b;
    while(cin >> a >> b)
    {
        // cout<<"Case "<<TC<<": ";
        solve(a, b);
    }
}