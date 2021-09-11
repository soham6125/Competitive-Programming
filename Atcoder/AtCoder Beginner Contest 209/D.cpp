#include <bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define loopr(a,b,i)     for(long long int i=a;i>=b;i--)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
#define endl             "\n"
#define lb               lower_bound
#define ub               upper_bound
#define f                first
#define se               second
#define vll              vector<ll>
#define pll              pair<ll,ll>
#define vpll             vector< pair<ll,ll> >
#define all(x)           x.begin(),x.end()
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const ll mod = 1e9 + 7;
const ll MAX  = 8000000000000000064LL;
const ll MIN  = -8000000000000000064LL;
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std; 
 
const ll dx[] = {-1,1,0,0,1,1,-1,-1};
const ll dy[] = {0,0,1,-1,-1,1,-1,1};

const int N = 1e5;
const int L = ceil(log2(N));
vector<ll> v[N+1];
vll dis(N+1);
ll in[N+1], out[N+1];
ll a[N+1][L + 1];
ll tim = 0;
 
void init(ll n)
{
    for ( ll i = 0; i <= n; i++)
    {
        v[i].clear();
        in[i] = 0;
        out[i] = 0;
        dis[i] = 0;
        for ( ll j = 0; j <= L; j++)
        {
            a[i][j] = 0;
        }
    }
    tim = 0;
 
}
 
void dfs( ll src, ll par)
{
    in[src] = tim++;
    a[src][0] = par;
    for ( ll i = 1; i <= L; i++)
    {
        a[src][i] = a[a[src][i - 1]][i - 1];
    }
    for ( auto i : v[src])
    {
        if (i ^ par)
        {
            dis[i] = dis[src] + 1;
            dfs(i, src);
        }
    }
    out[src] = tim++;
}
 
bool isancestor(ll u, ll v)
{
    return (in[u] <= in[v] and out[u] >= out[v]);
}
 
ll getlca( ll u, ll v)
{
    if (isancestor(u, v))
    {
        return u;
    }
    if (isancestor(v, u))
    {
        return v;
    }
 
    for ( ll i = 0; i <= L; i++)
    {
        if (!isancestor(a[u][i], v))
        {
            u = a[u][i];
        }
    }
 
    return a[u][0];
}
 
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
        ll n,q; cin>>n>>q;
        init(n);
        loop(0,n-1,i)
        {
            ll x,y; cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs(1,0);
        while(q--)
        {
            ll a,b; cin>>a>>b;
            ll x = getlca(a,b);
            ll ans = dis[a] + dis[b] - 2*dis[x];
            if(ans%2) cout<<"Road\n";
            else cout<<"Town\n";
        }
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
