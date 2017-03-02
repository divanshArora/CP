#include <iostream>
#include <algorithm>
#define lli long long int
#define F first 
#define S second
using namespace std;

lli arr[(int)1e6 + 5];

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	
	while(t--)
	{
		int n; 
		lli l,r;
		cin>>n>>l>>r;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		// vector< pair <lli,pair< int , int > > > v;
		// for(int i=1;i<n;i++)
		// {
		// 	v.push_back(make_pair(arr[i]-arr[i-1]+1,make_pair(arr[i],arr[i-1])));
		// }
		// sort(v.begin(),v.end());
		// lli ans = 0;
		// lli max_till_now = v[0].S.S+v[0].S.F-1;
		// lli min_till_now = v[0].F;

		// for(int i=0;i<v.end();i++)
		// {
		// 	if(v[i].S.F>max_till_now)
		// 	{
		// 		ans+= min(max_till_now ,r) - min_till_now -1;//chnge
		// 	} 

		// }
		vector <pair< lli,lli > > b;
		for(int i=1;i<n;i++)
		{
			//a.push_back(arr[i]+arr[i-1]-1);
			b.push_back(make_pair(arr[i]-arr[i-1]+1,arr[i]+arr[i-1]-1));
		}
		for(int i=0;i<b.size();i++)
		{
			if(b[i].S>r)
			{
				b[i].S=r;
			}
			if(b[i].F<l)
			{
				b[i].F=l;
			}
		}
		sort(b.begin(),b.end());
		vector< pair< lli, lli> > myvec;	
		//cout<<"HERE1"<<endl;
		lli min_till_now = b[0].F  , max_till_now= b[0].S;
		for(int i=0;i<b.size();i++)
		{
			if(b[i].F<=max_till_now)
			{
				max_till_now= max(max_till_now,b[i].S);
			}
			else
			{
				if(b[i].F>r)
				{
					if(i!=0)
					myvec.push_back(make_pair(min_till_now,max_till_now));
					break;
				}
				else 
				{
					myvec.push_back(make_pair(min_till_now,max_till_now));
					min_till_now = b[i].F;
					max_till_now = max(max_till_now,b[i].S);
				}
			}
			if(i==b.size()-1)
				{
					myvec.push_back(make_pair(min_till_now,max_till_now));
				}

		}
		lli ans =0;
		for(int i=0;i<myvec.size();i++)
		{
			if(myvec[i].S- myvec[i].F  + 1>=0)
			ans+=myvec[i].S- myvec[i].F  + 1 ;
			//cout<<myvec[i].F<<" "<<myvec[i].S<<endl;
		}
		cout<<ans<<endl;

	}

}