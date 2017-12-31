#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007
 
using namespace std;
 
string graph[2];
 
int x[4]= {0,0,1,-1};
int y[4]= {1,-1,0,0};
string visited[2];
 
void dfs(int srcx,int srcy,int n)
{
	visited[srcx][srcy]='X';
	for(int i=0;i<4;i++)
	{
		if(srcx + x[i] >=0 && srcx + x[i] <=1 && srcy + y[i] >=0 && srcy + y[i] <=n-1 && visited[srcx + x[i]][srcy + y[i]]=='#')
		{
			dfs(srcx + x[i],srcy + y[i],n);
		}
	}
	
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>graph[0];
		cin>>graph[1];
		string a,b;
		a= graph[0];b=graph[1];
		int finalflag = 0;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(graph[i][j]=='#')
				{
					visited[0] = graph[0];
					visited[1]=graph[1];
					int flag = 0;
					dfs(i,j,n);
					for(int p=0;p<2;p++)
					{
						for(int q=0;q<n;q++)
						{
							if(visited[p][q]=='#')flag = 1;
						}
					}
					if(flag==0)
					{
						finalflag=1;
					}
				}
			}
		}
		//cout<<graph[0]<<endl<<graph[1]<<endl;
		if(finalflag==1)cout<<"yes\n";else cout<<"no\n";
	}
}
 
Comments 
