#include<iostream>
#include<string>
#include<time.h>
using namespace std;
#define MAX_INT 9999
#define N 11//tsp问题中的城市个数 
int a[20], b[20], cnt=0,n,cost=0, mincost = MAX_INT;//cost表示当前代价，mincost表示最优代价避免重复 
char node[15] = { '0','1', '2', '3', '4','5','6', '7', '8', '9','A','B', 'C', 'D','E' };//节点标记
int road[N];//解向量
int bestroad[N];
bool vis[N];//访问标志位
bool flag = false;
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
/*回溯法*/
void backtrack(int i)
{
	if (i > n-1)//解向量长为n时，说明找到一个解
	{
		//判断最后一个城市和起点有没有边，并且加上代价后判断是否最优
		if (path[road[n-1]][0] != MAX_INT && (cost + path[road[n-1]][0]) < mincost)
		{
			mincost = cost + path[road[n - 1]][0];//更新最小代价
			for (int j = 0; j <n; j++)//保存路径
				bestroad[j] = road[j];
		}
		cnt++;
	}
	else
	{
		//递归框架,不断搜索下一层解
		for (int j = 0; j < n; j++)
		{
			if (path[road[i - 1]][j] != MAX_INT && (cost + path[road[i - 1]][j]) < mincost&&!vis[j])
			{
				road[i] = j;
				cost += path[road[i - 1]][j];//加上代价
				vis[j] = 1;//表示访问过
				backtrack(i + 1);
				cost -= path[road[i - 1]][j];//回溯上一层减去相应代价
				vis[j] = 0;//除去访问标记
			}
		}
	}
}
int main() {
	
	cout << "该tsp问题的测试数据中，节点个数为:" << N << endl;
	n = N;
	//默认首节点为
	vis[0] = 1;//初始点默认访问过
	road[0] = 0;//初始节点
	clock_t start, finish;
	double totaltime;
	start = clock();
	backtrack(1);//从第二个城市开始回溯
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "程序运行时间为：" << totaltime << endl;
	
	cout << "此tsp的最短路径为" << mincost << endl;
	cout << "对应路径为";
	for (int j = 0; j<n; j++)
	{
		cout << bestroad[j] << "->";	
	}
	cout<<"0"<< endl;
	system("pause");
	return 0;
}

