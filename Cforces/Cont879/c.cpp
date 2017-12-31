#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int op(int f2, int b ,string a)
{
	//cout<<"a = "<<a<<'\n';
	if(a[0]=='^')
	{
		return (f2^b);
	}
	else if(a[0] =='&')
	{
		return (f2&b);
	}
	else
	{
		return (f2|b);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string f1;int f2;
	for(int i=0;i<n;i++)
	{
		string a; int b;
		cin>>a;cin>>b;	
		if(i==0)
		{
			f1 = a;
			f2 = b;
		}
		else
		{
			f2 = op(f2,b,a);
		}
		//cout<<"f2 = "<<f2<<'\n';

	}
	cout<<1<<'\n';
	cout<<(f1)<<" "<<f2;

	return 0;
}
