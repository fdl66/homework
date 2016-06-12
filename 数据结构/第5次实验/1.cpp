#include <iostream> 
#include <cstdio>
#include <algorithm>
#define Max 20
using namespace std; 

struct Num{
	int data;
	int num;
};

bool cmp(Num N1,Num N2)
{
	if(N1.data<N2.data)   //从小到大排序！ 
		return 1;
	else
		return 0;
}

int erfenf(Num N[],int k,int n)
{
	int low=1,high=n,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(N[mid].data==k)
		{
			return mid; 
		} 
		else
		{
			if(k<N[mid].data)
			{
				high=mid-1; 
			} 
			else
			{
				low=mid+1; 
			} 
		} 
	} 
	return 0; 
} 

int erfend(Num N[],int low,int high,int k) 
{
	if(low>high)
	{
		return 0; 
	} 
	if(N[(low+high)/2].data==k)
	{
		return (low+high)/2; 
	}
	else
	{
		if(N[(low+high)/2].data<k)
		{
			return erfend(N,(low+high)/2+1,high,k); 
		} 
		else
		{
			return  erfend(N,low,(low+high)/2-1,k);
		} 
	} 
} 

int main()
{
	printf("请输入一组数据，回车代表输入结束:\n");
	char c;
	Num N[Max];
	int i=1;
	int k,knum; 
	while(c!='\n'&&i<Max)
	{
		scanf("%d",&N[i].data);
		N[i].num=i; 
		c=getchar();
		i++;
	}
	printf("排序前:\n");
	for(int j=1;j<i;j++)
	{
		printf("%d ",N[j].data); 
	} 
	printf("\n"); 
	sort(N+1,N+i,cmp); 
	printf("排序后:\n");
	for(int j=1;j<i;j++)
	{
		printf("%d ",N[j].data); 
	} 
	printf("\n请输入你要找的数 :");
	scanf("%d",&k);
	cout<<endl<<"非递归折半查找："<<endl; 
	knum=erfenf(N,k,i) ;
	printf("\n寻找结果为:\n") ;
	if(knum==0)
	{
		printf("表中没有这个数!\n\n") ;
	} 
	else
	{
		printf("%d\n\n\n",N[knum].num); 
	} 

	 
	cout<<endl<<"递归折半查找："<<endl; 
	knum=erfend(N,1,i-1,k) ;
	printf("\n寻找结果为:\n") ;
	if(knum==0)
	{
		printf("表中没有这个数!\n\n\n") ;
	} 
	else
	{
		printf("%d",N[knum].num); 
	} 

	return 0;
}

