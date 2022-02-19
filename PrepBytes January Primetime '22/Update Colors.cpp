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
// #define print(a,n)       for(ll i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll mod = 1e9 + 7;
const ll MAX = 8000000000000000064LL;
const ll MIN = -8000000000000000064LL;
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

const int maxn = 100100; 
vector<int> g[maxn];
int vis[maxn], col[maxn];
tuple<int, int, int> op[maxn];

void dfs(int v, int d, int c)
{
	if (vis[v] >= d) return;
	vis[v] = d;
	if (!col[v]) col[v] = c;
	if (d)
	{
		int sz = g[v].size();
		for (int i = 0; i < sz; i++)
			dfs(g[v][i], d - 1, c);
	}
}
int main()
{
	int n, m, q;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++) g[i].clear();
		fill(vis, vis + n + 1, -1);
		fill(col, col + n + 1, 0);
		while (m--)
		{
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cin>>q;
		for (int i = 0; i < q; i++)
		{
			int v, d, c;
			cin>>v>>d>>c;
			op[i] = tuple<int, int, int>(v, d, c);
		}
		for (int i = q - 1; i >= 0; i--)
		{
			int v, d, c;
			tie(v, d, c) = op[i];
			dfs(v, d, c);
		}
		for (int i = 1; i <= n; i++)
			cout << col[i] << endl;
	}
	return 0;
}
