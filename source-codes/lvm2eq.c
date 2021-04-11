//  LVM II  system equilibrium conditions
#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("equi.txt","w");

    double x,y,t,h=0.5;
    double a=0.2,b=0.1,e=1.0,m=0.1,K=20;
    x=m/(e*b);
    y=a/b*(1-m/(e*b*K));
    t=0;
    do {        
        fprintf(fp,"%.1lf\t%lf\t%lf\n",t,x,y);         
        t=t+h;    
    } while(t<=500);
 
}