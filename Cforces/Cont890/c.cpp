
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int last[200001]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	int curr_time =0;
	int curr_room =1;
	int flag =0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	map<int,int> mp;
	map<int,int> mp2;
	set<int> ms;
	mp.insert({0,1});
	mp2.insert({1,0});
	ms.insert(1);
	for(int i=0;i<n;i++)
	{
		curr_time++;
		if(mp.find(arr[i])==mp.end() )
		{
			curr_room++;
			mp.insert({curr_time,curr_room});
//			mp2.insert({curr_room,curr_time});
		}
		else
		{
//			mp2[mp[arr[i]]] = curr_time;
//			curr_room = mp[arr[i]];
			mp.erase(arr[i]);
			mp.insert({curr_time,curr_room});
		}
		ms.insert(curr_room);
	}
	cout<<ms.size();

}
