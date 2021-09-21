#include <bits/stdc++.h>
#define int              long long int 
// #define loop(a,b,i)      for(long long int i=a;i<b;i++)
// #define loopr(a,b,i)     for(long long int i=a;i>=b;i--)
// #define cn               continue;
// #define pb               push_back
// #define db               double
// #define mp               make_pair
// #define sz(x)            (ll)((x).size())
// #define endl             "\n"
// #define lb               lower_bound
// #define ub               upper_bound
// #define f                first
// #define se               second
// #define vll              vector<ll>
// #define pll              pair<ll,ll>
// #define vpll             vector< pair<ll,ll> >
// #define all(x)           x.begin(),x.end()
// #define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// const ll mod = 998244352;
// const ll MAX  = 8000000000000000064LL;
// const ll MIN  = -8000000000000000064LL;
// ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
// ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
// ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
// ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
// ll mod_inv(ll x) {return power(x, mod - 2);}
// ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
// ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std; 

// const ll dx[] = {-1,1,0,0,1,1,-1,-1};
// const ll dy[] = {0,0,1,-1,-1,1,-1,1};

class DSU
{
public:
    vector<int> parent, sz;
    int n;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n);
        sz.resize(n);
    }

    void init()
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int a)
    {
        if(parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }

    int size_of_set(int n)
    {
        return sz[find_set(n)];
    }

    int union_set(int a,int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a==b)
        {
            return -1;
        }
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = parent[a];
        sz[a] += sz[b];
        return a;
    }
};

signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin>>tc; 
    while(tc--)
    {   
        // cout<<"Case #"<<q+1<<": ";
        int n,m; cin>>n>>m;
        DSU dsu(n+1);
        dsu.init();
        for(int i=0;i<m;i++)
        {
            int x,y; cin>>x>>y;
            x++; y++;
            int val = dsu.union_set(x,y);
        }
        int ans = 0, prev = 0;
        for(int i=1;i<=n;i++)
        {
            if(dsu.find_set(i) == i)
            {
                int size = dsu.size_of_set(i); 
                ans += prev * size;
                prev += size;
            }
        }
        cout << ans;
    }

cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
