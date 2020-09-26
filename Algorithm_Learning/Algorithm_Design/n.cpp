#include<iostream>
#include<cmath>
using namespace std;
#define num 10
int x[10]; int cnt = 0;
void output()
{
	for (int i = 0; i < num; i++)
		cout << x[i] << " ";
	cout << endl;

}
bool islegal(int a[], int n)
{
	
	for (int j = 0; j<n; j++) //检查和前面的皇后是否冲突 
		if (a[n] == a[j] || n - a[n] == j - a[j] || n + a[n] == j + a[j]) {
			return false;
		}//不能处在对角线上，不能同一行同一列
	return true;

}

void backctrack_queen(int n)
{
	if (n ==num)
	{
		//output();//输出八皇后可能摆放位置
		cnt++;//计数++
	}	
	else
	{
		for (int i = 0; i <num; i++)//遍历当前层次
		{
			x[n] = i;
			if (islegal(x, n))//如果当前满足条件，开始下一个皇后位的搜索
				backctrack_queen(n + 1);
		}
			
	}

}
void Iterbacktrack()
{
	int t = 0;
	while (t < num)
	{
		for (int i = 0; i < num; i++)
		{
			x[t] = i;
			if (islegal(x, t))
				t++;
			else

		}


	}
}
int main()
{
	backctrack_queen(0); 
	cout << cnt << endl;
	system("pause");
	return 0;
}
