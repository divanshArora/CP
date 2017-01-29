#include <bits/stdc++.h>

using namespace std;
int alp[27]={0};

int main() {

    int n;
    cin>>n;
    string s;
    cin>>s;
    long long int ans = 0;
    for(int i=0;i<n;i++)
    {
        string in;
        cin>>in;    
        if(in.length()==s.length() )
        {
            int temp =0;
            for(int j=0;j<s.length();j++)
            {   
                if(s[j]!=in[j])
                {
                    temp++;
                }
            }   
            if(temp<=1)
            {
                ans++;
            }
    //        cout<<"temp equal  = "<<temp<<endl;
        }
        else if(s.length()==in.length()+1)
        {
            int temp=0;
            for(int j=0,k=0;j<s.length() && k<in.length() ;j++,k++)
                {
                    if(s[j]!=in[k])
                    {
                        if(temp==0)
                            {
                                j++;
                                temp++;
                            }
                        else
                        {
                            temp++;
                        }
                    }
                }
                if(temp<=1)
                {
                    ans++;
                }
  //              cout<<"temp less  = "<<temp<<endl;

        }
        else if(s.length()==in.length()-1)
            {
                int temp=0;
                for(int j=0,k=0;j<in.length()&&k<s.length();j++,k++)
                {
                    if(s[k]!=in[j])
                    {
                        if(temp==0)
                            {
                                j++;
                                temp++;
                            }
                        else
                        {
                            temp++;
                        }
                    }
                }
                if(temp<=1)
                {
                    ans++;
                }
//               cout<<"temp more  = "<<temp<<endl;

            }
    }
    cout<<ans<<endl;
       return 0;
}