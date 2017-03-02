#include <iostream>

using namespace std;
int a[501][501],b[501][501];


int main()
{
	ios_base::sync_with_stdio(0);

	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>b[i][j];
		}
	}






	for(int i=0;i<n;i++)
	{
		for(int j=m-2;j>=0;j--)
		{
			a[i][j]+= a[i][j+1];
		}
	}

	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<m;j++)
		{
			b[i][j]+=b[i+1][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}