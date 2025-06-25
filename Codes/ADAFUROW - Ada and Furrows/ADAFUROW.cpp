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
    int q;
    cin >> q;
    const int mxn = 2e4 + 1;
    vector<bitset<mxn>> furrows(mxn);
    
    while(q--)
    {
        char op;
        int x, y;
        cin >> op >> x >> y;

        if(op == '+')
            furrows[x].set(y);
        else if(op == '-')
            furrows[x].reset(y);
        else if(op == 'v')
            cout << (furrows[x] | furrows[y]).count() << endl;
        else if(op == '^')
            cout << (furrows[x] & furrows[y]).count() << endl;
        else if(op == '!')
            cout << (furrows[x] ^ furrows[y]).count() << endl;
        else
            cout << (furrows[x] & (~furrows[y])).count() << endl;
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