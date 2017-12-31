
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

//PROB: http://codeforces.com/contest/339/problem/D

const int N = 1e6;

int arr[2*N];


void build(int n)
{
	int turn = 0;
	for(int i=n-1;i>=1;i--)
	{
		if(2*i<n)
		{
			turn  = 1-turn;
			n = n/2;
		}
		if(turn==0)
		{
			arr[i] = arr[2*i]|arr[2*i + 1];
		}
		else
		{	
			arr[i]  = arr[2*i] ^ arr[2*i +1];
		}

	}

}

void print_tree(int n)
{
	cout<<"TREE--------------\n";
	for(int i=1;i<2*n;i++)
	{
		cout<<arr[i]<<" ";
	}cout<<'\n';
}

void modify(int p, int value, int n)
{
	p+=n;
	arr[p] = value;
	int turn = 0;
	for(int i=p;i>1;i/=2)
	{
		if(i<n)
		{
			turn = 1-turn;
			n = n/2;
		}
		if(turn==0)
		{
			arr[i/2] = arr[i]|arr[i^1];
		}
		else
		{
			arr[i/2] = arr[i]^arr[i^1];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int two_pow_n = 1;
	for(int i=0;i<n;i++)
	{
		two_pow_n*=2;
	}
	for(int i=0;i<two_pow_n;i++)
	{
		cin>>arr[i+two_pow_n];
	}
	build(two_pow_n);
	//print_tree(two_pow_n);
	for(int i=0;i<m;i++)
	{
		int p,b;
		cin>>p>>b;
		modify(p-1,b,two_pow_n);
		//print_tree(two_pow_n);
		cout<<arr[1]<<'\n';
	}
	return 0;	
}
