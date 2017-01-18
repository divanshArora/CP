#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int xfun(char a[],long int l,long int q, long int r)
{
    long int i=0,j=q+1;
    while(i<=l && j<=r)
    {
        if(a[i]!=a[j])
        {
            return 0;
 
        }
        else
        {
            i++;
            j++;
        }
    }
        return 1;
}
 
int lhsfun(char a[],long int l,long int q, long int r)
{
 
    long int i=0,j=q,stray =0;
    //printf("l= %ld q = %ld r = %ld\n",l,q,r);
    while(i<=l && j<=r && stray<=1)
    {
 
        if(a[i]!=a[j])
        {
            //printf("i = %ld j = %ld\n",i,j);
            stray++;
            //printf("i = %ld j = %ld stray = %ld\n",i,j,stray);
            if(stray>=2)
            {
                return 0;
            }
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if(stray>=2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int rhsfun(char a[],long int l,long int q, long int r)
{
 
    long int i=0,j=q,stray =0;
    //printf("l= %ld q = %ld r = %ld\n",l,q,r);
    while(i<=l && j<=r && stray<=1)
    {
 
        if(a[i]!=a[j])
        {
            //printf("i = %ld j = %ld\n",i,j);
            stray++;
            //printf("i = %ld j = %ld stray = %ld\n",i,j,stray);
            if(stray>=2)
            {
                return 0;
            }
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if(stray>=2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        char a[1000003];
        scanf("%s",a);
        long int i,len=strlen(a),stray=0,flag =0;
        if(len%2==0)
        {
            for(i=0;i<=(len/2)-1;i++)
            {
                if(a[i]!=a[i+(len/2)])
                {
                    flag =1;
                    break;
                }
            }
            if(flag ==1)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
        else if(len%2!=0 && len>1)
        {
            long int x=0;
             x+=xfun(a,len/2-1,len/2,len-1);
             //printf("x1 = %ld\n",x);
             x+=rhsfun(a,len/2-1,len/2,len-1);
             //printf("x2 = %ld\n",x);
             x+=lhsfun(a,len/2,len/2+1,len-1);
             //printf("x3 = %ld\n",x);
             if(x>0)
             {
                printf("YES\n");
             }
             else{
             printf("NO\n");
             }
        }
        else{
        printf("NO\n");
        }
 
 
    }
    return 0;
}
 
