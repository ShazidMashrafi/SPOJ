#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
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

void solve()
{
    int n;
    cin >> n;
    unordered_map<ll, ll> mp;
    ll ct = 0;
    while(n--)
    {
        string s;
        ll k;
        cin >> s >> k;

        if(s == "insert")
        {
            mp[k]++;
            if(mp[k] == 2) ct++;
        }   
        else
        {
           if(mp.count(k) && mp[k])
           {    
                if(mp[k] == 2) ct--;
                mp[k]--;
                if(mp[k] == 0) mp.erase(k);
           }
        }

        bool homo = ct > 0, hetero = sz(mp) > 1;
        
        string ans;
        if(homo && hetero) ans = "both";
        else if(homo && !hetero) ans = "homo";
        else if(!homo && hetero)   ans = "hetero";
        else ans = "neither";

        cout << ans << endl;
    }
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}