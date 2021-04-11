// LVM I  system equilibrium conditions
#include<stdio.h>
#include<math.h>

int main()
{
    FILE*fp=NULL;
    fp=fopen("equi.txt","w");

    float x,y,t,h=0.5;
    double a=0.2,b=0.1,e=1.0,m=0.1;
    x=m/(e*b);
    y=a/b;
    t=0;
    do {        
        fprintf(fp,"%lf\t%lf\t%lf\n",t,x,y);         
        t=t+h;    
    } while(t<=500);
 
}