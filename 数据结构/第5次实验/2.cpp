#include <iostream> 
#include <cstdlib>
#include <cstdio>
using namespace std;
 
typedef struct node
{
	int data;
	struct node *lchild,*rchild; 
} *BiTree;

void insert(BiTree &T,int k)
{
	if(T==NULL)
	{
		T=(BiTree)malloc(sizeof(node));
		T->data=k;
		T->lchild=T->rchild=NULL; 
		return ;
	} 
	else
	{
		if(k<T->data)
		{
			insert(T->lchild,k); 
		} 
		else
		{
			insert(T->rchild,k); 
		} 
		return ;
	} 
} 

void InOrder(BiTree T)
{
	if(T==NULL)
	{
		return ;
	}
	InOrder(T->lchild);
	printf("%d ",T->data);
	InOrder(T->rchild); 
} 

int main()
{
	BiTree T=NULL;
	int k;
	char c='0';
	cout<<"请输入一串数:"<<endl;
	while(c!='\n')
	{
		scanf("%d",&k);
		insert(T,k);
		c=getchar();
	}
	printf("二叉排序输入的前序遍历为:\n");
	InOrder(T);
	return 0;
}

