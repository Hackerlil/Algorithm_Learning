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
	int cost;//到达目标状态的距离
	string path;//所走的步骤
	bool operator < (const puzzle &p)const {//重载运算符
		for (int i = 0; i<n2; i++) {
			if (f[i] == p.f[i]) {
				continue;
			}
			return f[i]>p.f[i];
		}
		return false;//这个条件下< 操作符成立
		
	}
};
struct tmp2 //重写仿函数,构造优先队列
{
	bool operator() (puzzle a, puzzle c)
	{
		//return a.cost < a.cost; //大顶堆
		return a.cost > c.cost; //小根堆
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
int mahhaton_dist(int f[])//曼哈顿距离
{
	int dist = 0;
	for (int i = 0; i < n2; i++)
	{
		int sx = (f[i]-1) / b;
		int sy = (f[i]-1) % b;
		int tx = i / b;
		int ty = i % b;
		dist += abs(tx - sx) + abs(ty - sy);
	}
	return dist;
}

string greedy_search(puzzle s)
{
	//priority_queue<puzzle>q;//搜索队列
	//priority_queue<puzzle, vector<puzzle>, less<tmp2> >q;//重载运算符
	priority_queue<puzzle, vector<puzzle>, tmp2> q;
	map<puzzle, bool>V;//记录这个状态是否走过
	puzzle u, v;
	s.path = "";//初始化path
	q.push(s);
	V[s] = true;//状态访问完
	while (!q.empty()) {
		u = q.top();//访问队头//cout << u.cost << endl;
		q.pop();//出队
		if (istarget(u)) {//终止条件
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
			if (!(tx < 0 || ty < 0 || tx >= b || ty >= b)) {//出界
				//continue;
				v = u;
				v.space = tx*b + ty;//访问后位置的变化
				swap(v.f[v.space], v.f[u.space]);//新状态
				v.cost = mahhaton_dist(v.f);
				if (!V[v]) {
					V[v] = true;
					v.path += dir[r];
					q.push(v);//进队
				}
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
	}//输入初始状态
	in.cost = mahhaton_dist(in.f);
	cout << in.cost << endl;
	DWORD start_time = GetTickCount();
	string ans = greedy_search(in);//贪婪搜索
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
		print_seque(ans, in);cout << ans.size() << endl;
	}
	system("pause");
	return 0;
}
//贪婪搜索的一种,下一个是当前
//缺点是可能出现循环，BFS可解出来，但Greedy first无解

/*
1 3 0
4 2 5
7 8 6
*/
