
// http://www.spoj.com/problems/HORRIBLE/
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007


//SOURCE 
//http://codeforces.com/blog/entry/18051

const int MAX_N = 1e6+3;
int n; //array  size 
int t[(2*MAX_N)];
int tmin[(2*MAX_N)];
//n = 16 t[15] = t[30] +  t[31]

void build_tree()
{
	for(int i=n-1;i>0;--i)
	{
		//cout<<"i = "<<i<<endl;
		t[i] = max(t[2*i] ,t[2*i+1]); // t[i] = t[2*i] + t[2*i + 1]
	}
}


void modify(int p, int value) //set value at position p
{
	p+=n;
	t[p]= value;
	for(;p>1;p=p/2)
	{
		t[p/2] = max(t[p],t[p^1]); //p^1 is sibling 	
	}
}

int query(int l,int r) //sum in range [l,r)
{

	int res= 0;
	l+=n;r+=n;
	for( ;l<r; l=l/2 , r=r/2)
	{
		if(l%2!=0) //if l is even then index l will be added
		{
			res=max(t[l],res);
			l++;
		}
		if(r%2!=0)
		{
			r--;
			res=max(t[r],res);
		}
	}
	return res;
}

void build_treemin()
{
	for(int i=n-1;i>0;--i)
	{
		tmin[i] = min(tmin[2*i] ,tmin[2*i+1]); // t[i] = t[2*i] + t[2*i + 1]
	}
}


void modifymin(int p, int value) //set value at position p
{
	p+=n;
	tmin[p]= value;
	for(;p>1;p=p/2)
	{
		tmin[p/2] = min(tmin[p],tmin[p^1]); //p^1 is sibling 	
	}
}

int querymin(int l,int r) //sum in range [l,r)
{

	int res= 100000006;
	l+=n;r+=n;
	for( ;l<r; l=l/2 , r=r/2)
	{
		if(l%2!=0) //if l is even then index l will be added
		{
			res=min(tmin[l],res);
			l++;
		}
		if(r%2!=0)
		{
			r--;
			res=min(tmin[r],res);
		}
	}
	return res;
}




int main()
{
	ios_base::sync_with_stdio(false);	

	 int q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>t[i+n];
		tmin[i+n] = t[i+n];
	}
	build_treemin();
	build_tree();
	// for(int i=0;i<=2*n;i++)
	// {
	// 	cout<<t[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=0;i<=2*n;i++)
	// {
	// 	cout<<tmin[i]<<" ";
	// }
	while(q--)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x,y;
			cin>>x>>y;
			x--;y;
			cout<<query(x,y)-querymin(x,y)<<'\n';
		}
		else
		{
			int i,x;
			cin>>i>>x;
			i--;
			modify(i,x);
			modifymin(i,x);
		}
	}
	


	return 0;
}
