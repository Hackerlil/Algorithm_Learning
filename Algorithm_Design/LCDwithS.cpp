#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//x串的长度
//y串的长度
int c[100][100];
int s[100][100];
string LCDstr(string x, string y,int m,int n)
{
	string lcd;//最长公共子序列
	for (int i = 0; i <= m; i++)
	{
		c[i][0] = 0;
		s[i][0] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		c[0][i] = 0;
		s[0][i] = 0;
	}
	//初始化c,s矩阵的第一行第一列
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				s[i][j] = 1;//串末位相同，子串在x(m-1),y(n-1)中
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				s[i][j] = 2;//子序列在x(m-1),y(n)中
			}
			else
			{
				c[i][j] = c[i][j-1];//子序列在x(m),y(n-1)中
				s[i][j] = 3;
			}
		}
	}
	cout << "最长公共子序列长度为:"<<c[m][n] << endl;
	
	/*for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << s[i][j] << " ";
		}
		cout << endl;
	}*/
	//带有数组s情况下计算子串
	int i = m, j = n;
	while (s[i][j]>0)//从底部开始寻找最大子序列
	{
		if (s[i][j]==1)
		{
			lcd += x[i - 1];
			i--; j--;//第一种情况
		}
		else if (s[i][j] == 2)
		{
			i--; //第二种情况
		}
		else
			j--;//第三种情况
	}
	for (int i = 0, j = lcd.size() - 1; i < j; i++, j--)
	{
		char temp = lcd[i];
		lcd[i] = lcd[j];
		lcd[j] = temp;
	}
	return lcd;

}
int main()
{
	/*运行时修改输入字符串x,y即可*/
	string x = "abdcgcd";
	string y = "abcsabc";
	int m = x.size();
	int n = y.size();
	//LCDstr(x, y);
	cout << x << " " << y << "的";
	cout << "最长公共子序列为:" << LCDstr(x, y, m, n) << endl;
	system("pause");
	return 0;
}
