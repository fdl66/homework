#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,k,j;
	double x0,y0,t,min,tempx,tempy;
	cout<<"������ѡȡ�Ľڵ�ĸ���:"<<endl;
	cin>>n;
	cout<<"�������ֵ��:"<<endl;
	cin>>x0;
	double x[10],y[10],z[6]={0};
	cout<<"��������������xi��yi"<<endl;
	for(int i=0;i<6;i++)
	{
		
		cin>>x[i]>>y[i];
	}
	for(int a=0;a<6;a++)
	{
		min=fabs(x0-x[a]);
		for(int b=a+1;b<6;b++)
		{
			if(min>fabs(x0-x[b]))
			{
				min=fabs(x0-x[b]);
				tempx=x[a];
				tempy=y[a];
				x[a]=x[b];
				y[a]=y[b];
				x[b]=tempx;
				y[b]=tempy;
			}
		}
		
	}
	
	y0=0;
	k=0;
	while(k<=n)
	{
		t=1;
		cout<<"���ε�ѡȡ��xΪ"<<x[k]<<endl; 
		for(int j=0;j<=k-1;j++)
		{
			t=((x0-x[j])/(x[k]-x[j]))*t;
		}
		for(int j=k+1;j<=n;j++)
		{
			t=((x0-x[j])/(x[k]-x[j]))*t;
		}
		y0=y0+t*y[k];
		cout<<"������ f("<<k<<"):"<<y0<<endl;
		k=k+1;
	}
	cout<<"�����:"<<y0<<endl;
	return 0;
}


