#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node
{
	char s[20];
	int n;
	node *next;
};

node* a[20]={NULL};


int main()
{
	int n;
	printf("�������˵ĸ���:");
	scanf("%d",&n);
	//����hash�� 
	char s[20],c;
	int value=0;
	node *temp,*t_temp;
	printf("������%d���˵����֣�Сд��ĸ��:\n",n);
	for(int m=0;m<n;m++)
	{
		value=0;
		scanf("%s",&s);
		for(int i=0;i<strlen(s);i++)
		{
			value=value+(int )s[i];
		}
		temp=(node *)malloc(sizeof(node));
		for(int j=0;j<strlen(s);j++)
		{
			temp->s[j]=s[j];
		}
		temp->n=strlen(s);

		t_temp=a[value%20];
		a[value%20]=temp;
		temp->next=t_temp;
	}
	printf("\n��������Ҫ��ѯ���˵�����:\n");
	scanf("%s",&s);
	value=0;
	for(int i=0;i<strlen(s);i++)
	{
		value=value+(int )s[i];
	}
	temp=a[value%20];
	int ppp;
	int TTT=0;
	while(temp!=NULL)
	{
		ppp=1;
		if(temp->n==strlen(s))
		{
			for(int i=0;i<temp->n;i++)
			{
				if(temp->s[i]!=s[i])
				{
					ppp=0;
				}
			}
		}

		if(ppp==1)
		{
			TTT++;
		}
		temp=temp->next;
	}
	printf("���ҽ��:\n");
	if(TTT==0)
	{
		printf("����û�������!");
	}
	else
	{
		printf("����������ˡ�");
	}
	return 0;
}

