#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

bool isprime[100003]={false};

void sieve(int n)
{
	isprime[1] = false;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i]==true)
		{
			int count=2;
			while(i*count<=n)
			{
				isprime[i*count]= false;
				count++;
			}
		}
	}
}

ll arr[(int)1e7];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(i>0)arr[i] = arr[i]* arr[i-1];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,x,y;cin>>l>>r>>x>>y;
		l--;r--;
		ll prod= arr[r]/arr[l];
		

		
	}




	return 0;
}
