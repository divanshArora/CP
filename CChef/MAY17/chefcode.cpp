using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007
 
typedef vector<ll> vll;
 
ll arr[31];
 double darr[31];
ll kk;
double k;
int n,maxlen;
double prefix[31]; 
ll cnt =0;
 


void ans(int i, double  stn )
{
 
	if(i>n)return;
 	
	if(stn>k+0.1)
		{
			return;
		}
	// cout<<"i = "<<i<<endl;
	// cout<<"ptn = "<<ptn<<endl;
	// cout<<"cnt = "<<cnt<<endl;
	if(i==n && stn<k && stn>0.0 ) {cnt++;//cout<<"new cnt = "<<cnt<<endl;
	return;}
 	if(darr[i]	>k)return;
	ans(i+1,stn); 
	if(stn<-0.1){
		ans(i+1,darr[i]);
	}
	else
		ans(i+1,stn+darr[i]); 
}

ll pp(int x)
{
	if(x==0)return 1;
	double temp = pp(x/2);
	if(x%2==0)
	{
		return temp*temp;
	}
	else
	{
		return temp*temp*2;	
	}
}

void fn(double xk, int i)
{

	//cout<<"i = "<<i<<" xk = "<<xk<<" cnt= "<<cnt<<endl;
	if(i<-1)return;
	if(xk<0.0)
	{
		return;
	}

	
	if(xk>=0.00000 && i==-1)
	{
		//cout<<"increasing cnt from "<<cnt <<" to "<<cnt+1<<endl;
		cnt++;
	}
	if(i==-1)return;
	if(prefix[i]<=xk )
	{
		//cout<<"prefix found  i = "<<i<<" prefix = " << prefix[i]<< " xk = "<<xk <<endl;
		cnt+=pp(i+1);
		return;
	}
	fn(xk,i-1);
	fn(xk- darr[i], i-1 );


}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>kk;
	for(int i=0;i<n;i++)cin>>arr[i];
	
 
		//if k!=1
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		if(arr[i]>kk)
		{
			n = i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		darr[i] = log(arr[i]);
		if(i>0)prefix[i]=prefix[i-1]+darr[i];
		else 	prefix[0]= darr[0];

	}
	k=log(kk);
	// cout<<"prefix = "<<endl;
	// for(int i=0;i<n;i++) cout<<" "<<prefix[i]<<" ";
	// cout<<endl;
	// cout<<" k = "<<k<<endl;
	fn(k,n-1);
	cout<<max(0LL,cnt-1)<<endl;
 
	return 0;
}
