#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
//ѧ��:20145534 
using namespace std;
//������ 
//2016.6.20
const int maxn=20;
double x[maxn];
//������ԭ�� 
double f1(double a[],double b[],double temp[],int k,int n){
	double ans=b[k];
	for(int i=1;i<=n;i++){
		if(i!=k){
			ans-=a[i]*temp[i];
		}
	}
	return ans;
}

double f2(double a[],double b[],int k,int n){
	double ans=b[k];
	for(int i=1;i<=n;i++){
		if(i!=k){
			ans-=a[i]*x[i];
		}
	}
	return ans;
}

double f3(double a[],double b[],int k,int n,double w){
	double ans=(1-w)*x[k]+w*b[k];
	for(int i=1;i<=n;i++){
		if(i!=k){
			ans-=(w*a[i]*x[i]);
		}
	}
	return ans;
}

int main()
{
	double a[maxn][maxn],b[maxn],ks;
	int n;
	printf("�����뷽�����ά��:\n"/*������*/);
	cin>>n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(x,0,sizeof(x));
	for(int i=1;i<=n;i++){
		x[i]=0;//��ʼ��Xi 
	}
	printf(/*������*/"������ϵ����������ʽA:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	printf(/*������*/"������������B:\n");
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		b[i]/=a[i][i];
		for(int j=1;j<=n;j++){
			if(j!=i){
				a[i][j]/=a[i][i];
			}
		}
	}
	printf(/*������*/"���������ֵ:\n");
	cin>>ks;
	printf("/*****************�������ſ˱�**********************/\n"); 
	printf("\n\n k       x1         x2        x3        x4\n");
	printf(" 0       0          0         0         0\n");
	double cha;
	int count=0;
	do{
		double temp[maxn];
		for(int i=1;i<=n;i++){
			temp[i]=x[i];
		}
		printf("%2d",++count);
		for(int i=1;i<=n;i++){
			x[i]=f1(a[i],b,temp,i,n);
			printf("%11.6lf",x[i]);
		}
		cout<<endl;
		cha=abs(x[n]-temp[n]);
	}while(cha>ks);
	printf("/*****************�������ſ˱�**********************/\n\n\n\n"); 
	
	printf("/*****************��������˹-���¶�**********************/\n"); 
	for(int i=1;i<=n;i++){
		x[i]=0;//��ʼ��Xi 
	}
	printf("\n\n k       x1         x2        x3        x4\n");
	printf(" 0       0          0         0         0\n");
	count=0;
	do{
		double temp;
		temp=x[n];
		printf("%2d",++count);
		for(int i=1;i<=n;i++){
			x[i]=f2(a[i],b,i,n);
			printf("%11.6lf",x[i]);
		}
		cout<<endl;
		cha=abs(x[n]-temp);
	}while(cha>ks);
	printf("/*****************��������˹-���¶�**********************/\n"); 
	
	printf("\n\n\n/*****************�������ɳڷ�**********************/\n"); 
	double flag=1.1;
	int min=1000;
	for(int ii=1;ii<=8;ii++){
		double w=1+ii*0.1;
//		double w=1.46;
		cout<<"wΪ"<<w<<"ʱ:";
		for(int i=1;i<=n;i++){
			x[i]=0;//��ʼ��Xi 
		}
//		printf("\n\n k       x1         x2        x3        x4\n");
//		printf(" 0       0          0         0         0\n");
		count=0;
		do{
			double temp;
			temp=x[n];
			++count;
//			printf("%2d",++count);
			for(int i=1;i<=n;i++){
				x[i]=f3(a[i],b,i,n,w);
//				printf("%11.6lf",x[i]);
			}
//			cout<<endl;
			cha=abs(x[n]-temp);
		}while(cha>ks);
		cout<<"��������Ϊ:"<<count<<endl; 
		if(count<min){
			min=count;
			flag=w;
		}
	}
	printf("\n\nwֵΪ:%.1lfʱ�������������٣�Ϊ;%d \n",flag,min);
	printf("/*****************�������ɳڷ�**********************/\n"); 
	return 0;
}
