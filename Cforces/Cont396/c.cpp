#include <iostream>
#define F first
#define S second
#define lli long long int
using namespace std;

lli powerx(lli a, lli n)
{

	if(n == 0)return 1;
	a%=M;
	//cout<<"a = "<<a<<endl;

	lli x = (powerx(a%M,n/2))%M;
	x%=M;
	lli y = (x*x)%M;
	if(n%2==0)
	{
		return y%M;
	}
	else 
	{
		return (y*a)%M;	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
		

		
return 0;
} 