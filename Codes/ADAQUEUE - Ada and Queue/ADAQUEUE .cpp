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
    deque<ll>d;
    int q;
    cin >> q;
    bool reversed = false;
    while(q--)
    {
        string s;
        cin >> s;
        if(s == "back")
        {
            if(d.empty()) cout << "No job for Ada?" << endl;
            else
            {
                if(!reversed)
                {
                    cout << d.back() << endl;
                    d.pop_back();
                }
                else
                {
                    cout << d.front() << endl;
                    d.pop_front();
                }
            }
        }
        else if(s == "front")
        {
            if(d.empty()) cout << "No job for Ada?" << endl;
            else
            {
                if(!reversed)
                {
                    cout << d.front() << endl;
                    d.pop_front();
                }
                else
                {
                    cout << d.back() << endl;
                    d.pop_back();
                }
            }
        }
        else if(s == "reverse")
        {
            reversed = !reversed;
        }
        else if(s == "push_back")
        {
            int n;
            cin >> n;
            if(!reversed)   d.push_back(n);
            else    d.push_front(n);
        }
        else if(s == "toFront")
        {
            int n;
            cin >> n;
            if(!reversed)   d.push_front(n);
            else    d.push_back(n);
        }
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