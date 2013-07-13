#include<iostream>
main(){char c[][9]={"black","blue","lime","aqua","red","fuchsia","yellow","white"},i[9];for(;std::cin>>i,i[0]!=48;)printf("%s\n",c[(i[1]>55?4:0)+(i[3]>55?2:0)+(i[5]>55?1:0)]);}