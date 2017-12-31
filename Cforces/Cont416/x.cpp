using namespace std;

#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007
#define ld long double

ll srt(ll a)
{
	ll  i;
	for( i=1;i*i<=a;i++)
	{
		if(i*i<a)
		{

		}
		else
		{
			break;
		}
	}
	if(i*i>a)
	{
		return i-1;
	}
	return i;
}

ll srtb(ll b)
{
	ll  i;
	for( i=1;i*(i+1)<=b;i++)
	{
		if(i*(i+1)<b)
		{

		}
		else
		{
			break;
		}
	}
	if(i*(i+1)>b)
	{
		return i-1;
	}
	return i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll a,b;
	cin>>a>>b;

	if(srt(a)>srtb(b))
	{
		cout<<"Valera";
	}
	else
	{
		cout<<"Vladik";
	}
	return 0;	
}