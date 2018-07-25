
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

ll modpower(ll x, ll y, ll p) //x^y mod p
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y %2!= 0)
            res = (res*x) % p;
 
        // y must be even now
        y = y/2;
        x = (x*x) % p;  
    }
    return res;
}

int visited[100001]={0};
set<int> ms;
void dfs(int src, vector< vector< int> > &graph)
{
	for(int i=0;i<graph[src].size();i++)
	{
		int u = graph[src][i];
		if(visited[u]==0)
		{
			visited[u]=1;
			ms.insert(u);
			dfs(u,graph);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<vector<int>> graph(n+1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			ms.clear();
			ms.insert(i);
			visited[i]=1;
			dfs(i,graph);
			for(auto it = ms.begin();it!=ms.end();it++)
			{
				if(ms.find(arr[*it]-1)!=ms.end())
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;

}








