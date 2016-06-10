#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
double f(double x)
{
	return 4/(1+pow(x,2));
}
int main()
{
	int k[10],n[[10]];
	for(int i=0;i<6;i++){
		k[i]=i;
		n[i]=pow(2,i);
	}
	double ti[50],xin[50],ke[50],lon[50];
	memset(ti,0,sizeof(ti));
	memset(xin,0,sizeof(xin));
	memset(ke,0,sizeof(ke));
	memset(lon,0,sizeof(lon));
	double x[50];
	memset(x,0,sizeof(x));
	
	//复化梯形公式 
	for(int i=0;i<6;i++){
		for(int j=0;j<=pow(2,i);j++){
			x[j]=double(i)/pow(2,i);
		}
		ti[(int)(pow(2,i))]+=(f(x[0])+f(x[int(pow(2,i))]));
		for(int i=1;i<pow(2,i);i++){
			ti[(int)(pow(2,i))]+=f(x[i]);
		}
	}
	//复化辛普森公式
	for(int i=1;i<6;i++){
		for(int j=0;j<=pow(2,i);j++){
			x[j]=double(i)/pow(2,i);
		}
		xin[(int)(pow(2,i-1))]+=(f(x[0])+f(x[int(pow(2,i))]));
		for(int i=1;i<pow(2,i);i++){
			if(i%2==1)xin[(int)(pow(2,i-1))]+=4*f(x[i]);
			else xin[(int)(pow(2,i-1))]+=2*f(x[i]);
		}
	} 
	//复化科特斯公式
	for(int i=2;i<6;i++){
		for(int j=0;j<=pow(2,i);j++){
			x[j]=double(i)/pow(2,i);
		}
		
	}
	//龙贝格
	
	 
	return 0;
}
