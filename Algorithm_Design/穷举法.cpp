#include<iostream>
#include<time.h>
#include<string>
using namespace std;
#define MAX_INT 9999
#define N 11//tsp问题中的城市个数 
int a[20], b[20], n, cnt,mincost=MAX_INT;//a表示排列，b表示标志位 避免重复 
char node[15] = { '0','1', '2', '3', '4','5','6', '7', '8', '9','A','B', 'C', 'D','E' };
string road;
int path[N][N] = {{0,3,3,2,8,9,7,14,12,14,17},
{3,0,4,3,13,3,10,10,16,9,8},
{3,4,0,14,10,7,4,11,5,2,14},
{2,3,14,0,9,13,7,14,8,13,13},
{8,13,10,9,0,1,7,8,6,4,15},
{9,3,7,13,1,0,16,8,14,8,15},
{7,10,4,7,7,16,0,7,5,14,17},
{14,10,11,14,8,8,7,0,12,8,15},
{12,16,5,8,6,14,5,12,0,4,16},
{14,9,2,13,4,8,14,8,4,0,10},
{17,8,14,13,15,15,17,15,16,10,0}}; 
int factorial(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}
/*穷举法*/
void all_perme(int step) {
	if (step == n&&cnt<factorial(n-1)) {
		//计算该条路径的长度
		string temp_road;
		int cost = 0;//
		for (int i =0; i <n; i++)//计算从初始节点出发所需代价
		{
			
			temp_road += node[a[i]];//保存路径
			temp_road += "->";
			int length = path[a[i] % n][a[i + 1] % n];
			if (length == MAX_INT)
			{
				cost = MAX_INT+1;
				break;//若是节点间路径长度为MAX_INT,说明此条路径不成立
			}else
				cost += path[a[i]%n][a[i+1]%n];
		}
		if (cost < mincost)
		{
			mincost = cost;
			road = temp_road;
		}
		cnt++;
		
	}
	for (int i = 0; i<n; i++) {
		if (b[i] == 0) {
			a[step] = i;
			b[i] = 1;
			all_perme(step + 1);
			b[i] = 0;
		}
	}

}
int main() {
	cnt = 0;
	cout << "该tsp问题的测试数据中，节点个数为:"<<N << endl;
	n=N;
	clock_t start, finish;
	double totaltime;
	start = clock();
	all_perme(0);//排列数字默认从1开始
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "程序运行时间为：" << totaltime << endl;
	cout << "此tsp的最短路径为" << mincost << endl;
	cout << "对应路径为" << road+"0" << endl;
	cout << endl;
	system("pause");
	return 0;
}

