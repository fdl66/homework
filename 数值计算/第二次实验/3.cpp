#include <iostream>
#include <cmath> 
#include <algorithm>
using namespace std;

class point {
public:
	double x;
	double y;
	double d_x;
};

bool BJ(point a,point b)
{
	return a.d_x<b.d_x;
}

int main()
{
	cout<<"请输入函数列表："<<endl;
	point L[5];
	double x;
	for(int i=0;i<5;i++)
	{
		cin>>L[i].x>>L[i].y;
	} 
	cout<<"请输入 x 值："<<endl;
	cin>>x;
	for(int j=0;j<5;j++)
	{
		L[j].d_x=fabs(L[j].x-x);
	}
	sort(L,L+5,BJ); 
	for(int k=0;k<2;k++)
	{
		cout<<"节点"<<k+1<<":"<<L[k].x<<"  "<<L[k].y<<endl;	
	} 
	double y;
	y=(x-L[1].x)/(L[0].x-L[1].x)*L[0].y+(x-L[0].x)/(L[1].x-L[0].x)*L[1].y;
	cout<<"分段插值结果为: "<<y<<endl;
}
