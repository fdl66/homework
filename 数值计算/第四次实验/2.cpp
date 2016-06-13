#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#define e 2.71828182
using namespace std;

int main()
{
	double h,l1,l2,l3,l4,z[11],y[11];
	cout<<"ÇëÊäÈë²½³¤:"<<endl;
	cin>>h;
	z[0]=-0.6;
	y[0]=-0.4;
	for(int i=1;i<=10;i++){
		l1=pow(e,2*(i-1)*h)*sin((i-1)*h)-2*y[i-1]+2*z[i-1];
		l2=pow(e,2*((i-1)*h+0.05))*sin((i-1)*h+0.05)-2*(y[i-1]+0.05*z[i-1])+2*(z[i-1]+0.05*l1);
		l3=pow(e,2*((i-1)*h+0.05))*sin((i-1)*h+0.05)-2*(y[i-1]+0.05*(z[i-1]+0.05*l1))+2*(z[i-1]+0.05*l2);
		l4=pow(e,2*((i-1)*h+0.1))*sin((i-1)*h+0.05)-2*(y[i-1]+0.1*(z[i-1]+0.05*l2))+2*(z[i-1]+0.05*l3);
		y[i]=y[i-1]+h*z[i-1]+h*h*(l1+l2+l3)/6;
		z[i]=z[i-1]+h*(l1+2*l2+2*l3+l4)/6;
	} 
	printf("\n\nXn    Y(Xn) \n");
	for(int i=0;i<=10;i++){
		printf("%.1lf %10.6lf\n",i*h,y[i],z[i]);
	}
	return 0;
}
