#include <iostream>

using namespace std;


int main()
{
	
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	long long int mat[n][m];
	long long int mat2[n][m];
	int xmat[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>xmat[i][j];
			mat[i][j] = xmat[i][j];
			mat2[i][j] = xmat[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			{
				if(j-1>=0)
				mat[i][j]+=mat[i][j-1];
			}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i-1>=0)
			{
				mat2[i][j]+=mat2[i-1][j];
			}
		}
	}
	long long int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(xmat[i][j]==0)
			{
				if(mat[i][m-1]>mat[i][j])
				{
					ans++;
				}
				if(mat[i][j]>0)
				{
					ans++;
				}
				if(mat2[i][j]>0)ans++;
				if(mat2[n-1][j] > mat2[i][j])ans++;
			}
		}
	}/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mat2[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<ans;
	return 0;
}

