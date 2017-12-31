
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;
	#define ROW 51
#define COL 51

int M[ROW][COL];
    int rowNbr[] = { -1,   0, 0,  1 };
    int colNbr[] = {  0,  -1, 1,  0 };


int getmping(int x, int a,int b, int c, int d)
{
	if(x==0)return a;
	if(x==1)return b;
	if(x==2)return c;
	if(x==3)return d;
}

int main()
{
		ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;
	int sl,sr,el,er;
 	for(int i=0;i<n;i++)
 	{
 		string s;
 		cin>>s;
 		for(int j=0;j<s.length();j++)
 		{
 			if(s[j]=='.')M[i][j]=0;
 			else if(s[j]=='#') M[i][j]=1;
 			else if(s[j]=='S'){sl=i;sr=j;M[i][j]=-1;}
 			else if(s[j]=='E'){el=i;er=j;M[i][j]=2;}
 		}
 	}
 	string s;
 	cin>>s;
 	int ans=0;
 	for(int a=0;a<4;a++)
 	{
 		for(int b=0;b<4;b++)
 			for(int c=0;c<4;c++)
 				for(int d=0;d<4;d++)
 					if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
{ 		int l = sl, r = sr;
 		for(int i=0;i<s.length();i++)
	 	{
	 		int dir = getmping(s[i]-'0',a,b,c,d);
	 		//cout<<" --> "<<dir<<'\n';
	 		l= l+rowNbr[dir];
	 		r= r+colNbr[dir];
			if(l==el && r==er){
//				cout<<"-->"<<a<<" "<<b<<" "<<c<<" "<<d<<'\n'; 
				ans++;
				break;
			}
			else if(l<0 || l>=n || r<0 || r>=m)break;
			else if(M[l][r]==1)break;
	 	}
	 }
 	}
 	cout<<ans;
 
    return 0;
}
