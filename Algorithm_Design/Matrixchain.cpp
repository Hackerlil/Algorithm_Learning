#include<iostream>
#include<string>
using namespace std;
#define n 6
void Matrixchain(int *p, int m[n+1][n+1], int s[n+1][n+1],string divide[n+1][n+1]);
//作业要求，输出最后的加括号形式
int main()
{
	int a[n + 1] = { 30,35,15,5,10,20,25 };//存储矩阵尺寸
	int p[n + 1][n + 1];//动态规划矩阵
	int s[n + 1][n + 1];
	string div[n+1][n+1];
	Matrixchain(a, p, s,div);
	//输出括号划分
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (j >= i)
				cout << div[i][j] << " ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
//string数据，输出每个乘次的划分
void Matrixchain(int *p, int m[n+1][n+1],int s[n + 1][n + 1],string divide[n + 1][n + 1])
{
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;//对角线
		s[i][i] = 0;
		divide[i][i] = '0'+i;
		if (i < n)
		{
			string div = "(";
			char ch1 = '0' + i;
			char ch2 = '0' + (i + 1);
			div += ch1;
			div += ch2;
			divide[i][i + 1] = div + ")";
		}
		
	}
		
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n-r+1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
					
			}

		}
	}
	for (int i = 3; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			int j = k + i - 1;
			if (j <= n)
			{
				int flag = s[k][j];
			    divide[k][j] = "(" + divide[k][flag] + divide[flag + 1][j]+")";
			}

			
		}
	}
}
