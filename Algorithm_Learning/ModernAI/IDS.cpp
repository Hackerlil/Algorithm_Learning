#include<iostream>
#include<cstdlib>
#include<stack>
#include<map>
#include<string>
#include<windows.h>
using namespace std;

#define b 3
#define n2 9
#define MAX_DEPTH 20//控制搜索深度

const int dx[4] = {0,-1,0,1 };
const int dy[4] = {1,0,-1,0 };
const char dir[4] = { 'r','u','l','d'};


struct puzzle {
	int f[n2];//状态
	int space;//0所在位置
	int step;//所走步数
	string path;//所走的步骤
	bool operator < (const puzzle &p)const {
		for (int i = 0; i<n2; i++) {
			if (f[i] == p.f[i]) {
				continue;
			}
			return f[i]>p.f[i];
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
string path = "";
stack<puzzle>q;//搜索队列
map<puzzle, bool>V;//记录这个状态是否走过
void clear_stack()
{
	while (!q.empty())
		q.pop();
}
void iterative_dfs(puzzle s,int depth)
{
	puzzle  v;
	V[s] = true;//状态访问过
	s = q.top();
	q.pop();//出队
	if (istarget(s)) {
		path = s.path;
		return;
	}
	if (s.step >= depth)
		return;
	if (path == "")
	{
		int sx = s.space / b;
		int sy = s.space%b;
		for (int r = 0; r < 4; r++)
		{
			int tx = sx + dx[r];//不同动作
			int ty = sy + dy[r];
			if (tx < 0 || ty < 0 || tx >= b || ty >= b) {//出界
				continue;
			}
			v = s;
			v.space = tx*b + ty;//访问后位置的变化 
			swap(v.f[v.space], v.f[s.space]);//新状态
			if (!V[v]) {
				V[v] = true;
				v.step++;
				v.path += dir[r];
				q.push(v);//压入栈
				iterative_dfs(v, depth);
			}
		}

	}
}

int main()
{

	puzzle in;
	for (int i = 0; i<n2; i++) {
		cin >> in.f[i];
		if (in.f[i] == 0) {
			in.f[i] = n2;
			in.space = i;
		}
	}
	in.step = 0; 
	DWORD start_time = GetTickCount(); 
	for (int k = 0; k < MAX_DEPTH; k++)
	{
		V.clear(); clear_stack();
		q.push(in);
		iterative_dfs(in, k);

	}
		

	DWORD end_time = GetTickCount();
	cout << "运行时间:" << (end_time - start_time) << "ms!" << endl;//输出运行时间
	if (path == "")
	{
		cout << MAX_DEPTH << "深度内";
		cout << "DFS无解!" << endl;
	}
	else
	{
		in.f[in.space] = 0;
		cout << "步骤:" << path << endl;
		cout << path.size() << endl;
		print_seque(path, in);
	}
	system("pause");
	return 0;
}

/*
1 3 0
4 2 5
7 8 6
*/
