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
		for(int j=1;j<pow(2,i);j++){
			ti[(int)(pow(2,i))]+=2*f(x[j]);
		}
		ti[(int)(pow(2,i))]/=(2*(pow(2,i)));
	}
	
	//复化辛普森公式
	for(int i=0;i<5;i++){
		xin[(int)(pow(2,i))]=3*ti[2*(int)(pow(2,i))]/4-ti[(int)(pow(2,i))]/4;
	}

	//复化科特斯公式
	for(int i=0;i<4;i++){
		ke[(int)(pow(2,i))]=16*xin[2*(int)(pow(2,i))]/15-xin[(int)(pow(2,i))]/15;
	}

	//龙贝格
	for(int i=0;i<3;i++){
		lon[(int)(pow(2,i))]=64*ke[2*(int)(pow(2,i))]/63-ke[(int)(pow(2,i))]/63;
	}
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	for(int i=0;i<6;i++){
		cout<<i<<" ";
		int k=pow(2,i);
		printf("%2d ",k);
		printf("%11.7lf  ",ti[k]);
		if(i-1>=0)printf("%11.7lf  ",xin[(int)(pow(2,i-1))]);
		if(i-2>=0)printf("%11.7lf  ",ke[(int)(pow(2,i-2))]);
		if(i-3>=0)printf("%11.7lf  ",lon[(int)(pow(2,i-3))]);
		cout<<endl;
	} 
	return 0;
}
