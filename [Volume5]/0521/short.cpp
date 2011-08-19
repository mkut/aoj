#include <stdio.h>
main(){int n,v[]={1,5,10,50,100,500,1000},a,i;while(scanf("%d",&n),n){a=0;for(i=0;i<6;)a+=(1000-n)%v[i+1]/v[i++];printf("%d\n",a);}}