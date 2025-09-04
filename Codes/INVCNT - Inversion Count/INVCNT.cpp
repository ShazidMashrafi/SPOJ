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

ll merge(auto &a, ll l, ll m, ll r)
{
    vector<ll> left(a.begin() + l, a.begin() + m + 1);
    vector<ll> right(a.begin() + m + 1, a.begin() + r + 1);

    ll i = 0, j = 0, k = l, cnt = 0;
    while(i < sz(left) && j < sz(right)) {
        if(left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
            cnt += sz(left) - i;
        }
    }

    while(i < sz(left)) {
        a[k++] = left[i++];
    }
    while(j < sz(right)) {
        a[k++] = right[j++];
    }
    return cnt;
}


ll merge_sort(auto &a, ll l, ll r) 
{
    ll cnt = 0;
    if(l >= r)  return 0;
    ll m = l + (r - l) / 2;
    cnt += merge_sort(a, l, m);
    cnt += merge_sort(a, m + 1, r);
    cnt += merge(a, l, m, r);
    return cnt;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(auto &i : a) cin >> i;
    ll cnt = merge_sort(a, 0, n - 1);
    cout << cnt << endl;
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