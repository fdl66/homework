#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x[10], y[10],x0,p[5][5];
	memset(p, 0, sizeof(p));
	cout << "请输入函数表:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> x[i] >> y[i];
		p[i][0] = y[i];
	}
	cout << "请输入插值点:" << endl;
	cin >> x0;

	for (int i = 1; i <=3; i++) {
		for (int j = i; j <=4; j++) {
			p[j][i] = (x0 - x[j - 1])*p[j][i - 1] / (x[j] - x[j - 1]) + (x0 - x[j])*p[j - 1][i - 1] / (x[j - 1] - x[j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("x%d%5.1lf%10.5lf", i, x[i], y[i]);
		for (int j = 1; j <= i; j++) {
			if(p[i][j]!=0)
			printf("%10.6lf", p[i][j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}