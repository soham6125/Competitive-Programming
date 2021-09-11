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
 
void bfs(vector<int> adj[], int src, int dist[],int paths[], int n)
{
    bool visited[n];
    loop(0,n,i) visited[i] = false;
    dist[src] = 0;
    paths[src] = 1;
    queue <int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto x : adj[curr])
        {
            if(visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
            if(dist[x] > dist[curr] + 1)
            {
                dist[x] = dist[curr] + 1;
                paths[x] = paths[curr];
            }
            else if (dist[x] == dist[curr] + 1)
            {
                paths[x] += paths[curr];
                paths[x] %= mod;
            }
        }
    }
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
        int n,m; cin>>n>>m;
        vector<int> adj[n];
        loop(0,m,i)
        {
            int x,y; cin>>x>>y;
            x--; y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        int dist[n], paths[n];
        loop(0,n,i) dist[i] = INT_MAX;
        loop(0,n,i) paths[i] = 0;
        bfs(adj, 0, dist, paths, n);
        cout << paths[n-1];
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
