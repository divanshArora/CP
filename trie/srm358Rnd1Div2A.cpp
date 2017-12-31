#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <algorithm> 
#include <ctype.h> 
#include <map> 
#include <cmath> 
#define pb push_back
using namespace std; 

#define PI 3.1415926535897932384 
#define inf 123456789 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define all(c) c.begin(), c.end() 

typedef long long ll; 
typedef vector<int> vi; 

bool check(string a, string b)
{
  for(int i=0;i<b.length();i++)
  {
    if(b[i]==a[0])
    {
      string x="";
      x+=b.substr(i,b.length()-i);
      if(i>0)
      {
        x+=b.substr(0,i);
      }
//      cout<<"x = "<<x<<endl;
      if(x==a)return true;
    }
  }
  return false;
}

class CyclicWords { 
  public: 
  int differentCW(vector <string> a) { 
    vector<string> till_now;
    till_now.pb(a[0]);
    for(int i=1;i<a.size();i++)
    {
      int flag=0;
      for(int j=0;j<till_now.size();j++)
      {
        if(check(a[i],till_now[j]))
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
      {
        till_now.pb(a[i]);
      }
    }
    return till_now.size();
  } 
}; 
// int main() {
//   CyclicWords * obj= new CyclicWords();
//   string arr[] = {"aaaa", "aaa", "aa", "aaaa", "aaaaa"};
//   vector< string> a(begin(arr),end(arr));
//   cout<< obj->differentCW(a)<<"\n";
//   return 0;
// }