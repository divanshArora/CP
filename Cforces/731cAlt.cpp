#include <bits/stdc++.h>
using namespace std;

int visited[200001]={0};
int col[200001]={0};

map<int,int> mp;

void dfs(int u, vector<vector<int>> &graph)
{
    visited[u]=1;
    if(mp.find(col[u])==mp.end())mp[col[u]]=1;
    else mp[col[u]]++;
    for(int i=0;i<graph[u].size();i++)
    {
        if(visited[graph[u][i]]==0)
        {
            dfs(graph[u][i],graph);
        }
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>col[i];
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        graph[l].push_back(r);
        graph[r].push_back(l);
    }
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            mp.clear();
            dfs(i,graph);
            ans+=max_element(mp.begin(),mp.end(),[](const pair<int, int> &p1, const pair<int, int> &p2){
                             return p1.second<p2.second;
                             })->second;
        }
    }
    cout<<n-ans;

	return 0;
}
