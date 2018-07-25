
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll inf = numeric_limits<ll>::max();
    ll mini = inf;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<mini)mini = arr[i];
    }	
    for(int i=0;i<n;i++)
    {
        arr[i]-=mini;
    }
    int curr_pos = mini%n;
    if(arr[curr_pos]<=0)
    {
        cout<<(curr_pos)+1;
        return 0;
    }
    ll minus = 0;
    while(true)
    {
        //arr[curr_pos]-=minus;
        if(arr[curr_pos]-minus<=0)
        {
            cout<<(curr_pos%n)+1;
            return 0;
//            break;
        }
        minus++;
        curr_pos++;
        curr_pos%=n;
    }
//    cout<<curr_pos%n;

}
