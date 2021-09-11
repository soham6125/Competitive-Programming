#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<string>
#define ll long long int 
#define loop(a,b,i) for(long long int i=a;i<b;i++)
#define loopr(a,b,i) for(long long int i=n-1;i>=0;i--)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
using namespace std;
 
const ll MAX = 2e5;
ll id[MAX], nodes, edges, k=0;
pair<ll, pair<ll,ll> > p[MAX];
map<pair<ll,pair<ll,ll>>,ll> m;
 
void initialize()
{
    for(ll i = 0;i < MAX;++i)
        id[i] = i;
}
 
ll root(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
 
void union1(ll x, ll y)
{
    ll p = root(x);
    ll q = root(y);
    id[p] = id[q];
}
 
ll kruskal(pair<ll,pair<ll, ll> > p[])
{
    ll x, y;
    ll cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
            m[{cost,{x,y}}]++;
        }    
    }
    return minimumCost;
}
 
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    ll x, y;
    ll weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = mp(weight, mp(x, y));
    }
    sort(p, p + edges);
    minimumCost = kruskal(p);
    ll ans = 0;
    loop(0,edges,i)
    {
        ll x = p[i].se.f;
        ll y = p[i].se.se;
        ll cost = p[i].f;
        if(cost>0 and m.find({cost,{x,y}})==m.end()) ans += cost;
    }
    cout << ans;
    return 0;
}
