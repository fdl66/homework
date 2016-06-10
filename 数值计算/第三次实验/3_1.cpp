#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
double f(double x)
{
	return 1/(1+pow(x,2));
}
int main()
{
	int n;
	cout<<"请输入区间等分次数："<<endl; 
	cin>>n;
	n=pow(2,n);
	double fk[20];
	memset(fk,0,sizeof(fk));
	double ans=0;
	for(int i=0;i<=n;i++){
		fk[i]=f(i/(n));
	}
	ans+=(fk[0]+fk[n]);
	for(int i=1;i<=n-1;i++){
		if(i%2==1)ans+=fk[i]*4;
		else ans+=fk[i]*2;
	}
	ans/=(6*n/2);
	printf("方程的解为：%lf\n",ans);
	return 0;
}
