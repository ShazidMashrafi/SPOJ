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

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        string best;
        int ct;
        
        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            best = "";
            ct = 0;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
    }
    
    void update(string word, int count) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            node = node->children[index];
            
            if (count > node->ct || (count == node->ct && word < node->best)) {
                node->ct = count;
                node->best = word;
            }
        }
    }
    
    pair<string, int> findMostOccurring(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index])
                return {"", -1};
            node = node->children[index];
        }
        
        if (node->ct == 0)
            return {"", -1};
        
        return {node->best, node->ct};
    }
};

void solve()
{
    int n;
    cin >> n;
    
    map<string, int> wordCnt;
    vector<string> words;
    
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
        wordCnt[word]++;
    }
    
    Trie trie;
    
    for (auto& [word, ct] : wordCnt) {
        trie.insert(word);
    }
    
    for (auto& [word, ct] : wordCnt) {
        trie.update(word, ct);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        string query;
        cin >> query;
        
        auto [word, ct] = trie.findMostOccurring(query);
        
        if (ct == -1) {
            cout << -1 << endl;
        } else {
            cout << word << " " << ct << endl;
        }
    }
}

signed main()
{
    FAST;
    
    int TCS = 1;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        solve();
    }
}