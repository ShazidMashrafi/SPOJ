#include <bits/stdc++.h>
using namespace std;
// #if defined(LOCAL) && !defined(ONLINE_JUDGE)
// #include "debug.h"
// #else
// #define dbg(...)
// #endif
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

ll power(ll x, ll y, ll m = LLONG_MAX) {
    ll ans = 1;
    x %= m;
    while(y) {
        if(y & 1) ans = (ans * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return ans;
}

struct Node {
    ll sum, inc;
};

struct SegTree {
    int size = 1;
    vector<Node> tree;
    Node neutral = {0, 0};
    
    SegTree(int n) {
        while(size <= n) size <<= 1;
        tree.assign(2 * size, neutral);
    }
    
    void push(int curr, int lx, int rx) {
        if(tree[curr].inc == 0) return;
        int mid = (lx + rx) / 2;
        tree[2 * curr + 1].inc += tree[curr].inc;
        tree[2 * curr + 1].sum += tree[curr].inc * (mid - lx);
        tree[2 * curr + 2].inc += tree[curr].inc;
        tree[2 * curr + 2].sum += tree[curr].inc * (rx - mid);
        tree[curr].inc = 0;
    }

    void set(ll inc, int l, int r, int curr, int lx, int rx) {
        if(rx <= l || lx >= r) return;
        if(lx >= l && rx <= r) {
            tree[curr].inc += inc;
            tree[curr].sum += inc * (rx - lx);
            return;
        }
        push(curr, lx, rx);
        int mid = (lx + rx) / 2;
        set(inc, l, r, 2 * curr + 1, lx, mid);
        set(inc, l, r, 2 * curr + 2, mid, rx);
        tree[curr].sum = tree[2 * curr + 1].sum + tree[2 * curr + 2].sum;
    }
    
    void set(ll inc, int l, int r) {
        set(inc, l, r, 0, 0, size);
    }

    ll get(int l, int r, int curr, int lx, int rx) {
        if(rx <= l || lx >= r) return 0;
        if(lx >= l && rx <= r) {
            return tree[curr].sum;
        }
        push(curr, lx, rx);
        int mid = (lx + rx) / 2;
        ll s1 = get(l, r, 2 * curr + 1, lx, mid);
        ll s2 = get(l, r, 2 * curr + 2, mid, rx);
        return s1 + s2;
    }
    
    ll get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
};

void solve() {
    int n, query;
    cin >> n >> query;
    
    SegTree sg(n);

    while(query--) {
        int type;
        cin >> type;
        if(type == 0) {
            int p, q;
            ll v;
            cin >> p >> q >> v;
            sg.set(v, p, q + 1);
        } else {
            int p, q;
            cin >> p >> q;
            cout << sg.get(p, q + 1) << endl;
        }
    }
}

signed main() {
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC) {
        solve();
    }
}