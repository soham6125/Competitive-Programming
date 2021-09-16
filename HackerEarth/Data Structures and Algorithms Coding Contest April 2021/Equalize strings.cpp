
#include<bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define loopr(a,b,i)     for(long long int i=a-1;i>=b;i--)
#define pb               push_back
#define db               double
#define mp               make_pair
#define endl             "\n"
#define f                first
#define se               second
#define vll              vector<ll>
#define pll              pair<ll,ll>
#define vpll             vector< pair<ll,ll> >
#define all(x)           x.begin(),x.end()
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const ll mod  = 1000000007;
const ll MAX  = 8000000000000000064LL;
const ll MIN  = -8000000000000000064LL;
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
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
   if(n==0) return false; 
   return (ceil(log2(n)) == floor(log2(n)));  
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
      ll n;cin>>n;
      string a,b;
      cin>>a>>b;
      ll ans = 0;
      ll i=0;
      for(i=0;i<n-1;i++)
      {
        if(a[i]!=b[i])
        {
          if(a[i+1]!=b[i+1] and a[i]!=a[i+1])
          {
            ans++;
            i++;
          }
          else ans++;
        }
      }
      if(i==n-1)
      {
        if(a[i]!=b[i]) ans++;
      }
      cout << ans;
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
