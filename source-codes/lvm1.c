// LVM I  system
#include<stdio.h>
#include<math.h>
// defining parameters
double a=0.2,b=0.1,e=1.0,m=0.1;
// function for prey population
double dx(double t,double x,double y) {
    return a*x-b*x*y;
}
// function for predator population
double dy(double t,double x,double y) {
    return e*b*x*y-m*y;
}
int main()
{
    int i=0,N=1000;
    double t[N],x[N],y[N],h=0.5;
    double k1,k2,k3,k4,m1,m2,m3,m4;

    FILE*fp=NULL;
    fp=fopen("lvm1.txt","w");
    // giving initial conditions
    t[0]=0,x[0]=2.0,y[0]=1.3;
    do
    {
        fprintf(fp,"%.1lf\t%lf\t%lf\n",t[i],x[i],y[i]);
        k1=h*dx(t[i],x[i],y[i]);
        m1=h*dy(t[i],x[i],y[i]);

        k2=h*dx(t[i]+h/2,x[i]+k1/2,y[i]+m1/2);
        m2=h*dy(t[i]+h/2,x[i]+k1/2,y[i]+m1/2);

        k3=h*dx(t[i]+h/2,x[i]+k2/2,y[i]+m2/2);
        m3=h*dy(t[i]+h/2,x[i]+k2/2,y[i]+m2/2);

        k4=h*dx(t[i]+h,x[i]+k3,y[i]+m3);
        m4=h*dy(t[i]+h,x[i]+k3,y[i]+m3);
         
        x[i+1]=x[i]+(k1+2*k2+2*k3+k4)/6;
        y[i+1]=y[i]+(m1+2*m2+2*m3+m4)/6;         
        t[i+1]=t[i]+h;
        i++;

    } while(i<=N);
}