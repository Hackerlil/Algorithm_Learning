#include<iostream>
#include<cstdlib>
#include<queue>
#include<map>
#include<string>
#include<windows.h>
using namespace std;

#define b 3
#define n2 9

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };
const char dir[4] = { 'u','l','d','r' };

struct puzzle {
	int f[n2];//状态
	int space;//0所在位置
	string path;//所走的步骤
	int cost;//距离目标状态距离
	bool operator < (const puzzle &p)const {
		for (int i = 0; i<n2; i++) {
			if (f[i] == p.f[i]) {
				continue;
			}
			return f[i]>p.f[i];
			return cost > p.cost;
		}
		return false;
	}
};
void swap(int &x, int &y)//模拟tiles移动时的位置变化
{
	int temp = x;
	x = y;
	y = temp;
}
void print_state(int a[])//输出每一个状态
{
	for (int i = 0; i < n2; i++)
	{
		if ((i + 1) % 3 == 0)
		{
			cout << a[i] << endl;
		}
		else
		{
			cout << a[i] << " ";
		}

	}
	cout << endl;
}
void print_seque(string seq, puzzle in)//输出搜索过程
{
	for (int i = 0; i < seq.size(); i++)
	{
		switch (seq[i])
		{
		case 'u'://向上
			swap(in.f[in.space], in.f[in.space - 3]);
			in.space -= 3;
			print_state(in.f);
			break;
		case 'l'://向左
			swap(in.f[in.space], in.f[in.space - 1]);
			in.space--;
			print_state(in.f);
			break;
		case 'd'://向下
			swap(in.f[in.space], in.f[in.space + 3]);
			in.space += 3;
			print_state(in.f);
			break;
		case 'r'://向右
			swap(in.f[in.space], in.f[in.space + 1]);
			in.space++;
			print_state(in.f);
			break;
		}
	}
}

bool istarget(puzzle p)//判断状态是否终止
{
	for (int i = 0; i<n2; i++) {
		if (p.f[i] != (i + 1)) {
			return false;
		}
	}
	return true;
}
int hamming_dist(int a[])//启发函数，到目标状态汉明距离
{
	int dist = 0;
	for (int i = 0; i < n2; i++)
	{
		if (a[i] != (i + 1))
			dist++;
	}
	return dist;
}
string bfs(puzzle s)
{
	queue<puzzle>q;//搜索队列
	map<puzzle, bool>V;//记录这个状态是否走过
	puzzle u, v;
	s.path = "";//初始化path
	q.push(s);
	V[s] = true;//状态访问完
	while (!q.empty()) {
		u = q.front();//访问堆头
		q.pop();//出队
		if (istarget(u)) {
			return u.path;
		}
		int sx = u.space / b;
		int sy = u.space%b;
		/*搜索时选择一个离终止状态汉明距离最近的状态*/
		//从当前可搜索的方向中选择一个代价最小的
		for (int r = 0; r < 4; r++)
		{
			int tx = sx + dx[r];//不同动作
			int ty = sy + dy[r];
			if (tx < 0 || ty < 0 || tx >= b || ty >= b) {//出界
				continue;
			}
			v = u;
			v.space = tx*b + ty;//访问后位置的变化
			swap(v.f[v.space], v.f[u.space]);//新状态
			v.cost = hamming_dist(v.f);
			if (!V[v]) {
				V[v] = true;
				v.path += dir[r];
				q.push(v);//进队
			}
		}
	}
	return "unsolvable";
}

int main()
{

	puzzle in;
	for (int i = 0; i<n2; i++) {
		//scanf("%d", &in.f[i]);
		cin >> in.f[i];
		if (in.f[i] == 0) {
			in.f[i] = n2;
			in.space = i;
		}
	}
	DWORD start_time = GetTickCount();
	string ans = bfs(in);
	DWORD end_time = GetTickCount();
	cout << "运行时间:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	in.f[in.space] = 0;
	//print_seq(in.f);
	if (ans == "unsolvable")
	{
		cout << "greedy solution无解!" << endl;
	}
	else
	{
		cout << "步骤:" << ans << endl;
		cout << ans.size() << endl;
		print_seque(ans, in);
	}
	system("pause");
	return 0;
}
//贪婪搜索的一种,
//缺点是可能出现循环，BFS可解出来，但Greedy first无解

/*
1 3 0
4 2 5
7 8 6
*/
