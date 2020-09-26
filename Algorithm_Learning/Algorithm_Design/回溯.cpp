#include<iostream>
#include<string>
#include<time.h>
using namespace std;
#define MAX_INT 9999
#define N 11//tsp�����еĳ��и��� 
int a[20], b[20], cnt=0,n,cost=0, mincost = MAX_INT;//cost��ʾ��ǰ���ۣ�mincost��ʾ���Ŵ��۱����ظ� 
char node[15] = { '0','1', '2', '3', '4','5','6', '7', '8', '9','A','B', 'C', 'D','E' };//�ڵ���
int road[N];//������
int bestroad[N];
bool vis[N];//���ʱ�־λ
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
/*���ݷ�*/
void backtrack(int i)
{
	if (i > n-1)//��������Ϊnʱ��˵���ҵ�һ����
	{
		//�ж����һ�����к������û�бߣ����Ҽ��ϴ��ۺ��ж��Ƿ�����
		if (path[road[n-1]][0] != MAX_INT && (cost + path[road[n-1]][0]) < mincost)
		{
			mincost = cost + path[road[n - 1]][0];//������С����
			for (int j = 0; j <n; j++)//����·��
				bestroad[j] = road[j];
		}
		cnt++;
	}
	else
	{
		//�ݹ���,����������һ���
		for (int j = 0; j < n; j++)
		{
			if (path[road[i - 1]][j] != MAX_INT && (cost + path[road[i - 1]][j]) < mincost&&!vis[j])
			{
				road[i] = j;
				cost += path[road[i - 1]][j];//���ϴ���
				vis[j] = 1;//��ʾ���ʹ�
				backtrack(i + 1);
				cost -= path[road[i - 1]][j];//������һ���ȥ��Ӧ����
				vis[j] = 0;//��ȥ���ʱ��
			}
		}
	}
}
int main() {
	
	cout << "��tsp����Ĳ��������У��ڵ����Ϊ:" << N << endl;
	n = N;
	//Ĭ���׽ڵ�Ϊ
	vis[0] = 1;//��ʼ��Ĭ�Ϸ��ʹ�
	road[0] = 0;//��ʼ�ڵ�
	clock_t start, finish;
	double totaltime;
	start = clock();
	backtrack(1);//�ӵڶ������п�ʼ����
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "��������ʱ��Ϊ��" << totaltime << endl;
	
	cout << "��tsp�����·��Ϊ" << mincost << endl;
	cout << "��Ӧ·��Ϊ";
	for (int j = 0; j<n; j++)
	{
		cout << bestroad[j] << "->";	
	}
	cout<<"0"<< endl;
	system("pause");
	return 0;
}

