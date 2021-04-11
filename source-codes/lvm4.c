// LVM system with two predator and one prey populations
#include<stdio.h>
#include<math.h>
// defining parameters
double a=0.2,K=1.7;
double b1=0.1,e1=1.0,m1=0.1;
double b2=0.2,e2=2.0,m2=0.1;
// function for prey population
double dx(double t,double x,double y1,double y2) {
    return a*x*(1-x/K)-(b1*y1+b2*y2)*x;
}
// function for predator I population
double dy1(double t,double x,double y1,double y2) {
    return e1*b1*y1*x-m1*y1;
}
// function for predator II population
double dy2(double t,double x,double y1,double y2) {
    return e2*b2*y2*x-m2*y2;
}
int main()
{
    int i=0,N=1000;
    double t[N],x[N],y1[N],y2[N],h=0.5;
    double k1,k2,k3,k4,m1,m2,m3,m4,n1,n2,n3,n4;

    FILE*fp=NULL;
    fp=fopen("lvm4.txt","w");

    // giving initial conditions
    t[0]=0,x[0]=1.7,y1[0]=1.7,y2[0]=1.0;
    do {
        fprintf(fp,"%.1lf\t%lf\t%lf\t%lf\n",t[i],x[i],y1[i],y2[i]);
        k1=h*dx(t[i],x[i],y1[i],y2[i]);
        m1=h*dy1(t[i],x[i],y1[i],y2[i]);
        n1=h*dy2(t[i],x[i],y1[i],y2[i]);

        k2=h*dx(t[i]+h/2,x[i]+k1/2,y1[i]+m1/2,y2[i]+n1/2);
        m2=h*dy1(t[i]+h/2,x[i]+k1/2,y1[i]+m1/2,y2[i]+n1/2);
        n2=h*dy2(t[i]+h/2,x[i]+k1/2,y1[i]+m1/2,y2[i]+n1/2);

        k3=h*dx(t[i]+h/2,x[i]+k2/2,y1[i]+m2/2,y2[i]+n2/2);
        m3=h*dy1(t[i]+h/2,x[i]+k2/2,y1[i]+m2/2,y2[i]+n2/2);
        n3=h*dy2(t[i]+h/2,x[i]+k2/2,y1[i]+m2/2,y2[i]+n2/2);

        k4=h*dx(t[i]+h,x[i]+k3,y1[i]+m3,y2[i]+n3);
        m4=h*dy1(t[i]+h,x[i]+k3,y1[i]+m3,y2[i]+n3);
        n4=h*dy2(t[i]+h,x[i]+k3,y1[i]+m3,y2[i]+n3);

        x[i+1]=x[i]+(k1+2*k2+2*k3+k4)/6;
        y1[i+1]=y1[i]+(m1+2*m2+2*m3+m4)/6;
        y2[i+1]=y2[i]+(n1+2*n2+2*n3+n4)/6;
        t[i+1]=t[i]+h;

        i++;
    } while(i<=N);
 
}