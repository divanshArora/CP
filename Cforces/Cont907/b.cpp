
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string arr[9][3];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}

	int x,y;
	cin>>x>>y;
	x--;y--;
	int col = y/3;
	int incol = y%3;

	int new_field_x = x%3, new_field_y = y%3;
	int flag=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i+3*new_field_x][new_field_y][j]=='.')
			{
				flag = 1;
			}
		}
	}
	if(flag==1)
	{
		for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i+3*new_field_x][new_field_y][j]=='.')
			{
				arr[i+3*new_field_x][new_field_y][j]='!';	
			}
		}
	}
	}
	else
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					if(arr[i][j][k]=='.')
					{
						arr[i][j][k]='!';
					}
				}
			}
		}		
	}
	for(int i=0;i<9;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					
					cout<<arr[i][j][k];
				}
				cout<<" ";
			}
			cout<<'\n';
			if((i+1)%3==0)cout<<"\n";
		}


	return 0;
}
