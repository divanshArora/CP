#include <iostream>
#include <algorithm>

using namespace std;
/**
 * x is the distance to nearest fillling station
 * runs kil km in accelerated mode consumes 2*kil liters of fuel and time consumed = kil;
 * runs x-kil km in normal mode time= 2*(x-kil) and fuel used = x-kil
 * 
 * 
 **/

long long int c[2*((int)1e5) + 2],v[2*((int)1e5) + 2], station_position[2*((int)1e5) + 6];

bool predicate(long long int f, long long int s, long long int k, long long int t);
int main()
{
	ios_base::sync_with_stdio(false);

	long long int n,k,s,t;
	cin>>n>>k>>s>>t; //no. of cars, no. of gas stations, length of road, time available	
	for(int i=0;i<n;i++){
		cin>>c[i];
		cin>>v[i];
	}
	station_position[0] = 0;
	for(int i=1;i<=k;i++)
	{
		cin>> station_position[i];
	}
	station_position[k+1] = s;

	sort(station_position,station_position+k+1);

	long long int inf_tank_capacity = (long long int )1e9 + 1; //try this
	//long long int low =0 ,high = inf_tank_capacity;//try this
	long long int low =0 ,high = *max_element(v,v+n);
		while(low<high)
	{
	
		long long int mid = (low+high)/2;

		if(predicate(mid,s,k,t)==true)
		{	
			high = mid;
		}
		else
		{	
			low  = mid+1;
		}
	}
	if(predicate(low,s,k,t)==false)
	{
		cout<<"-1";
	}
	else
	{
		long long int ans = inf_tank_capacity;
		for(int i=0;i<n;i++)
		{
			if(v[i]>=low)
			{
				ans= min(ans, c[i]);
			}
		}

		cout<<ans;
	}	




	return 0;
}

bool predicate(long long int f, long long int s, long long int k, long long int t)
{
	long long int time = 0;
	for(int i=1;i<=k+1;i++)
	{
		long long int x = station_position[i]-station_position[i-1];
		if(x>f)
		{
			return false;
		}
		else
		{
			long long int kil = min(f-x, x); //2*kil + x-kil <=f and cannot go more than x kilometers i.e if f-x>x
			time+=  kil*1 + (x-kil)*2;

		}	
	}
	if(time<=t)
	{
		return true;
	}
	else
	{
		return false;
	}
}




