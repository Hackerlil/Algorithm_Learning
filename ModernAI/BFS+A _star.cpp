#include<iostream>
#include<cstdlib>
#include<queue>
#include<map>
#include<string>
using namespace std;

#define b 3
#define n2 9

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };
const char dir[4] = { 'u','l','d','r' };

struct puzzle {
	int f[n2];
	int space;
	string path;
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

bool istarget(puzzle p)
{
	for (int i = 0; i<n2; i++) {
		if (p.f[i] != (i + 1)) {
			return false;
		}
	}
	return true;
}

string bfs(puzzle s)
{
	queue<puzzle>q;
	map<puzzle, bool>V;
	puzzle u, v;
	s.path = "";
	q.push(s);
	V[s] = true;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		if (istarget(u)) {
			return u.path;
		}
		int sx = u.space / b;
		int sy = u.space%b;
		for (int r = 0; r<4; r++) {
			int tx = sx + dx[r];
			int ty = sy + dy[r];
			if (tx<0 || ty<0 || tx >= b || ty >= b) {
				continue;
			}
			v = u;
			v.space = tx*b + ty;
			swap(v.f[v.space], v.f[u.space]);
			if (!V[v]) {
				V[v] = true;
				v.path += dir[r];
				q.push(v);
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
	string ans = bfs(in);
	cout << ans << endl;
	cout << ans.size() << endl;
	system("pause");
	return 0;
}
/*
1 3 0
4 2 5
7 8 6
*/
