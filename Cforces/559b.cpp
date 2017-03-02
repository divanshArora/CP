#include <iostream>

using namespace std;

string a,b;
int flag=0;

bool conquer(int l, int r, int mid);


bool divide(int l, int r)
{
	if(l<r)
	{
		int mid = l + (r-l)/2;
		divide(l, mid);
		divide(mid+1,r);
		bool ans  = conquer(l,r,mid);
		if(ans==false)
		{
			flag =1;
		}
		return ans;
	}
}

bool conquer(int l, int r, int mid)
{
	string a0 = a.substr(l,mid-l+1);
	string a1 = a.substr(mid+1,r-mid);
	string b0 = b.substr(l,mid-l+1);
	string b1 = b.substr(mid+1,r-mid);
	bool u = a0.compare(b0)==0 && a1.compare(b1)==0 ;
	if(u)return u;
	bool v = a1.compare(b0)==0 && a0.compare(b1)==0;
	return v;
}	


string solve(string s)
{
	if(s.size()%2==0)
	{
		string x = solve(s.substr(0,s.size()/2));
		string y = solve((s.substr(s.size()/2)));
		if(x>y)return (x+y);
		else 
		{
			return y+x;
		}
	}
	return s;
}

int main()
{
	cin>>a>>b;
	divide(0,);


	return 0;
}