#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
int n,i;
char *arr=(char *)malloc(1000000*sizeof(char));
scanf("%s",arr);
printf("------------ %c",arr[1000000-1]);
int l=strlen(arr);
int count=0;
for(i=0;i<l;i++){
    if(arr[i]=='b')
        count++;
}
int a[l];
int k=0;
for(i=0;i<l;i++){
    if(arr[i]=='a')
        {
            a[k]=count;
            k++;

        }
    if(arr[i]=='b')
            count--;
}
int sum=0,ans=0;
for(i=k-1;i>=0;i--){
    sum=(ans+a[i])%1000000007;
    ans=(ans+sum)%1000000007;
}
printf("%d",ans);
}	