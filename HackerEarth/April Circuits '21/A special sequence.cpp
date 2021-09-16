#include<bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
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
 
bool isprime(ll n){  
    if(n<=1) return false; 
    if(n==2) return true;
    if(n%2==0 and n!=2) return false;
    for(ll i=2;i<=sqrt(n);i++) 
        if(n%i==0) 
            return false; 
    return true; 
} 
 
bool isPowerOfTwo(ll n){
   if(n==0)return false; 
   return (ceil(log2(n)) == floor(log2(n)));  
}
 
ll sum = 0;
vll ans;
 
void init()
{
  ans.pb(0);
  loop(1,1e6,i)
  {
    ll times = i * floor(sqrt(i));
    times += (i+1)/2;
    sum += times;
    ans.pb(sum);
  }
}
 
signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
  init();
  int tc = 1;
  cin>>tc;
  loop(1,tc+1,t)
  {
    // cout<<"Case #"<<t<<": ";
    ll x,y; 
    cin >> x >> y;
    ll res = 0;
    ll ind1=0, ind2=0;
    ind1 = lb(all(ans),x) - ans.begin();
    ind2 = lb(all(ans),y) - ans.begin();
    // cout<<ind1<<" "<<ind2<<endl;
    res = ind2 - ind1 + 1;
    cout << res << endl;
  }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
