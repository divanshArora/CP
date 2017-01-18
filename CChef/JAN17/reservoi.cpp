#include <iostream>
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(false);
 
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		string u;
		cin>>a>>b;
		char mat[a+2][b+2];
		for(int i=1;i<=a;i++)
		{
			cin>>u;
			for(int j=1;j<=u.size();j++)
			{
				mat[i][j] = u[j-1];
			}
		}
 
		for(int i=0;i<b+2;i++)
		{
			mat[0][i] = 'X';
			mat[a+1][i]='X';
		}
		for(int i=0;i<a+2;i++)
		{
			mat[i][0] = 'X';
			mat[i][b+1] = 'X';
		}
		/*cout<<"\n\nMAT:\n\n";
		for(int i=0;i<a+2;i++)
		{
			for(int j=0;j<b+2;j++)
			{
				cout<<mat[i][j];
			}
			cout<<endl;
		}
		cout<<"\n\n\n";
		*/
		int flag=true;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(mat[i][j]=='B')
				{	
					//cout<<"HERE: "<<mat[i-1][j]<< " "<< mat[i-1][j]<<endl;
					if(mat[i+1][j]=='A'|| mat[i+1][j]=='W')
					{ 
						//cout<<1<<endl;
						flag= false;
					}
				}
				else if(mat[i][j]=='W')
				{
					if(mat[i][j+1]=='A'||mat[i][j+1]=='X')
					{
						//cout<<2<<endl;
						flag= false;
					}
					if(mat[i][j-1]=='A'||mat[i][j-1]=='X')
					{
						//cout<<3<<endl;
						flag= false;
					}
					if(mat[i+1][j]=='A')
					{
						//cout<<4<<endl;
						flag= false;
					}
				}
				else if(mat[i][j]=='A')
				{
					if(mat[i-1][j]=='B'|| mat[i-1][j] =='W')
					{
						//cout<<5<<endl;
						flag=false;
					}
 
				}
				
			}
		}
		if(flag==false)
		{
			cout<<"no"<<endl;
		}
		else
		{
			cout<<"yes"<<endl;
		}
	}
 
	return 0;
} 