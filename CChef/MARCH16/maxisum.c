#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      long long int n,k,i,ans=0,max = 0;
      scanf("%lld %lld",&n,&k);
      long long int a[n],b[n];
      for(i=0;i<n;i++)
      {
        scanf("%lld",&a[i]);
 
      }
      for(i=0;i<n;i++)
        {
        scanf("%lld",&b[i]);
        if(abs(b[i])>=max)
            {
            max = abs(b[i]);
            }
 
        }
        for(i=0;i<n;i++)
        {
        ans+=a[i]*b[i];
        }
        printf("%lld\n",ans+k*max);
 
    }
    return 0;
}
