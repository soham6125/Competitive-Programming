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

signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    
    int tc = 1;
    cin>>tc; 
    loop(0,tc,q)
    {
        cout<<"Case #"<<q+1<<": ";
        ll n; cin>>n;
        vector<vector<char>> a(n,vector<char>(n));
        unordered_map<ll,ll> row1, col1, row2, col2;
        loop(0,n,i)
        {
            loop(0,n,j)
            {
                cin>>a[i][j];
                if(a[i][j]=='X')
                {
                    row1[i]++; col1[j]++;
                }
                else if(a[i][j]=='O')
                {
                    row2[i]++; col2[j]++;
                }
            }
        }
        unordered_map<ll,ll> m;
        loop(0,n,i)
        {
            if(row2.find(i)==row2.end())
            {
                ll ins = 0;
                if(row1.find(i)!=row1.end()) ins += row1[i];
                m[n-ins]++; 
            }
        }
        loop(0,n,j)
        {
            if(col2.find(j)==col2.end())
            {
                ll ins = 0;
                if(col1.find(j)!=col1.end()) ins += col1[j];
                m[n-ins]++; 
            }
        }
        ll ans1 = INT_MAX, ans2 = 0;
        for(auto it:m)
            ans1 = min(ans1,it.f);
        if(ans1==INT_MAX){
            cout<<"Impossible\n"; cn;
        }
        map<vector<pll>,ll> mm;
        loop(0,n,i)
        {
            if(row2.find(i)==row2.end())
            {
                ll ins = 0;
                if(row1.find(i)!=row1.end()) ins += row1[i];
                if(n-ins == ans1)   
                {
                    vector<pll> st;
                    loop(0,n,j)
                    {
                        if(a[i][j]=='.') st.pb({i,j});
                    }
                    sort(all(st));
                    mm[st]++;
                }
            }
        }
        loop(0,n,i)
        {
            if(col2.find(i)==col2.end())
            {
                ll ins = 0;
                if(col1.find(i)!=col1.end()) ins += col1[i];
                if(n-ins == ans1)   
                {
                    vector<pll> st;
                    loop(0,n,j)
                    {
                        if(a[j][i]=='.') st.pb({j,i});
                    }
                    sort(all(st));
                    mm[st]++;
                }
            }
        }
        cout << ans1 << " " << sz(mm) << endl;
    }   

cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
