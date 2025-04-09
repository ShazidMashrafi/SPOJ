#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  int  long long
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=1e9+7) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}


void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    
    string ans = s;
    for (int i = 0; i < n / 2; i++)  
        ans[n - 1 - i] = ans[i];

    if (ans > s) 
    {
        cout << ans << endl;
        return;
    }

    int mid = (n - 1) / 2;
    for (int i = mid; i >= 0; i--) 
    {
        if (ans[i] < '9') 
        {
            ans[i]++;
            ans[n - 1 - i] = ans[i];
            break;
        } 
        else 
        {
            ans[i] = '0';
            ans[n - 1 - i] = '0';
        }
    }

    if (ans[0] == '0') 
    {
        ans[0] = '1';
        ans += '1';
        ans[n] = '1';
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}