
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

boolean chk(string s)
{
	int a[28]={0};
	for(int i=0;i<27;i++)
	{
		a[s[i]-'a']++;
	}
	for(int i=0;i<27;i++)
	{
		if(a[i]>1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(chk(arr[i])==false)
		{
			cout<<"NO";
			return 0;
		}
	}
	

	return 0;
}
