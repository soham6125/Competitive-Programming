#include <bits/stdc++.h>
#define int               long long int 
using namespace std; 
 
vector<int> cnt;
vector<int> res;
int ansRoot = 0;
int N;
 
int cntNodesInSubtree(vector<vector<int>> &g, int src, int parent, int dfz) {
    ansRoot += dfz;
    int curCnt = 1;
    for (int nbrs : g[src]) {
        if (nbrs != parent) curCnt += cntNodesInSubtree(g, nbrs, src, dfz + 1);
    }
    cnt[src] = curCnt;  
    return curCnt;
}
 
void fillRes(vector<vector<int>> &g, int src, int parent) 
{
    if (parent != -1) res[src] = res[parent] - cnt[src] + (N - cnt[src]);
    for (int nbrs : g[src]) {
        if (nbrs != parent) fillRes(g, nbrs, src);
    }
}
 
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
{
    vector<vector<int>> g(n);
    cnt.resize(n);
    res.resize(n);
    for (auto e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    cntNodesInSubtree(g, 0, -1, 0);
    N = cnt[0];
    res[0] = ansRoot;
    fillRes(g, 0, -1);
    return res;
}
 
signed main() 
{ 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
    int tc = 1;
    // cin>>tc; 
    while(tc--)
    {   
        // cout<<"Case #"<<q+1<<": ";
        int n; cin>>n;
        vector<vector<int>> edge(n-1);
        for(int i=0;i<n-1;i++)
        {
            int x,y; cin>>x>>y;
            x--; y--;
            edge[i].push_back(x);
            edge[i].push_back(y);
        }
        vector<int> ans = sumOfDistancesInTree(n, edge);
        for(auto it:ans) cout<<it<<endl;
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
