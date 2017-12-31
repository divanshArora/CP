
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


vector < pair < int, int> > arr(1001);

int visited[1001]={0};
ll ans = 0;
int n;

void help(int u)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i] ==0 && (arr[i].FF ==  arr[u].FF || arr[i].SS ==  arr[u].SS))
		{
			visited[i]=1;
			help(i);
		}
	}
}

void dfs()
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			visited[i]=1;
			ans++;
			help(i);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		arr[i]= {x,y};
	}

	dfs();
	cout<<ans-1<<endl;

	return 0;
}
