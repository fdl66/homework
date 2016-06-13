#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	double h,y[11],ol[11],gol[11],lgkt[11];
	cout<<"请输入步长:"<<endl;
	cin>>h;
	y[0]=ol[0]=gol[0]=lgkt[0]=1;//初始化y[0] 
	
	for(int i=1;i<=10;i++){
		//函数值 
		y[i]=sqrt(1+2*h*i);
		//欧拉法 
		ol[i]=ol[i-1]+h*(ol[i-1]-2*h*(i-1)/ol[i-1]);
		//改进欧拉法 
		double gol_p,gol_c;
		gol_p=gol[i-1]+h*(gol[i-1]-2*(i-1)*h/gol[i-1]);
		gol_c=gol[i-1]+h*(gol_p-2*i*h/gol_p);
		gol[i]=(gol_p+gol_c)/2; 
		
		//四阶龙格-库塔法
		double k1,k2,k3,k4;
		k1=lgkt[i-1]-2*(i-1)*h/lgkt[i-1];
		k2=lgkt[i-1]+h*k1/2-(2*(i-1)*h+h)/(lgkt[i-1]+h*k1/2);
		k3=lgkt[i-1]+h*k2/2-(2*(i-1)*h+h)/(lgkt[i-1]+h*k2/2);
		k4=lgkt[i-1]+h*k3-2*((i-1)*h+h)/(lgkt[i-1]+h*k3);
		lgkt[i]=lgkt[i-1]+h*(k1+2*k2+2*k3+k4)/6;
	}
	printf("\n\nXn   Yn         欧拉     改进欧拉  四阶龙格-库塔\n");
	for(int i=0;i<=10;i++){
		printf("%.1lf%10.6lf%10.6lf%10.6lf%10.6lf\n",i*h,y[i],ol[i],gol[i],lgkt[i]);
	}
	return 0;
}
