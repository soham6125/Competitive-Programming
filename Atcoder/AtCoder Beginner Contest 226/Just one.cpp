#include <bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define loopr(a,b,i)     for(long long int i=a;i>=b;i--)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
#define sz(x)            (ll)((x).size())
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
 
const ll mod = 998244353;
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

const int N = 200001;
vector<int> graph[N];
 
void DFSCycle(int u, int p, int color[], int mark[], int par[], int& cyclenumber)
{
   if (color[u] == 2) {
      return;
   }
   if (color[u] == 1) {
      cyclenumber++;
      int cur = p;
      mark[cur] = cyclenumber;
      while (cur != u) {
         cur = par[cur];
         mark[cur] = cyclenumber;
      }
      return;
   }
   par[u] = p;
   color[u] = 1;
   for (int v : graph[u]) {
      if (v == par[u]) {
         continue;
      }
      DFSCycle(v, u, color, mark, par, cyclenumber);
   }
   color[u] = 2;
}
 
void solve()
{
    int n; cin>>n;
    int m; cin>>m;
    if(n != m)
    {
        cout<<0;
        return;
    }
    for(int i=0; i<m; i++)
    {
        int u,v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int color[N], par[N], mark[N];
    ll ans = 1;
    vector<ll> diff;
    for(int i=1; i<=n; i++)
    {
        int cyclenumber=0;
        if(color[i]==2) continue;
        DFSCycle(i, 0, color, mark, par, cyclenumber);
        if(cyclenumber==0)
        {
           cout << 0;
           return;
        }
        ll nc = cyclenumber*1ll;
        ll now = power(2,nc);
        diff.push_back(now);
    }
    for(ll i=0; i<diff.size(); i++)
    {
        ans = ans*diff[i];
        ans %= mod;
    }
    cout<<ans;
}
 
signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
    int tc = 1;
    // cin >> tc; 
    loop(0,tc,Q)
    {   
        // cout << "Case #" << Q+1 << ": ";
        solve();
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
