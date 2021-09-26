#include <bits/stdc++.h>
#define int              long long int 
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 

const int N = 1e5;
const int LG = ceil(log2(N));

vector<int> g[N+1];
int par[N+1][LG + 1], dep[N+1], sz[N+1], parent[N+1], dist[N+1];
bool vis[N+1];
vector<int> ans(N+1);

void dfs(int u, int p = 0) 
{
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for(int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for(auto v: g[u]) if (v != p) 
    {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int lca(int u, int v) 
{
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = LG; k >= 0; k--)
    {
        if(dep[par[u][k]] >= dep[v])
        { 
            u = par[u][k];
        }
    }
    if(u == v)
    {
        return u;
    }
    for(int k = LG; k >= 0; k--)
    {
        if(par[u][k] != par[v][k])
        {
            u = par[u][k]; 
            v = par[v][k];
        }
    }
    return par[u][0];
}

signed main() 
{ quick; 

    int t; cin>>t; 
    while(t--)
    {   
        int n,q; cin >> n >> q;
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            dep[i] = 0;
            sz[i] = 0;
            ans[i] = 0;
            parent[i] = -1;
            vis[i] = false;
            dist[i] = 0;
        }
        memset(par,0,sizeof(par));
        unordered_map<int,vector<int>> m;
        for(int i = 1; i < n; i++) 
        {
            int u, v; cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        queue<pair<int,int>> qu; 
        qu.push({ 0ll, -1ll }); 
        vis[0] = true;
        dist[0] = 0;
        int mx_ht = 0;
        while(!qu.empty())  
        { 
            pair<int,int> p = qu.front();  
            qu.pop(); 
            parent[p.first] = p.second;  
            for(int i=0;i<g[p.first].size();i++) 
            { 
                if(!vis[g[p.first][i]]) 
                { 
                    qu.push({ g[p.first][i], p.first }); 
                    vis[g[p.first][i]] = true;
                    dist[g[p.first][i]] = dist[p.first] + 1;
                    mx_ht = max(mx_ht , dist[g[p.first][i]]);
                } 
            } 
        } 
        // for(int i=0;i<n;i++) cout<<dist[i]<<" ";
        for(int i=0;i<n;i++) m[dist[i]].push_back(i);
        while(q--) 
        {
            int u, v, x; cin >> u >> v >> x;
            u--; v--;
            int l = lca(u, v);
            ans[u] ^= x;
            ans[v] ^= x;
            ans[l] ^= x;
            if(parent[l] != -1) ans[parent[l]] ^= x;
        }
        for(int i=mx_ht;i>0;i--)
        {
            vector<int> v = m[i];
            for(auto it:v) ans[parent[it]] ^= ans[it];
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res += ans[i];
        }
        cout << res << "\n";
    }
    
return 0;
}
 

