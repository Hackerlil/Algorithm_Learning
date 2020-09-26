#include<iostream>
using namespace std;
#define MAX_VALUE 999.00
int root[100][100] = { 0 };//保存根结点信息
double e[100][100] = { 0.0 };//e[i][j]表示包含ki...kj的搜索概率
double w[100][100] = { 0.0 };//w[i][j]表示 ki...kj的概率总和
double sum=0.0;
void optimalBST(double p[], double q[], int n)//p关键字节点概率数组，q搜索失败节点概率数组 
{
	//初始化叶子节点的值
	for (int i = 1; i <= n + 1; i++) {//叶子节点一共n+1个是从d0到dn
		e[i][i - 1] = q[i - 1];
		w[i][i - 1] = q[i - 1];
	}
	//对角线方向自顶向下计算平均搜索长度 
	for (int l = 1; l <= n; l++) {//表示从k1到kl有l个关键字参与构造树，1<<l<<n

		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			e[i][j] = MAX_VALUE;//赋予较大值便于比较 
			w[i][j] = w[i][j - 1] + p[j] + q[j];//概率和 
			for (int r = i; r <= j; r++) {//关键字 ki...kj选r为根
				double t = e[i][r - 1] + e[r + 1][j] + w[i][j];//代价值
				if (t<e[i][j]) {//找出不同根节点中代价最小的 
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	cout << "root:" << endl;
	for (int i = 1; i<n + 1; i++) {
		for (int j = 1; j<n + 1; j++) {
			cout << root[i][j] << " ";
		}
		cout << endl;
	}
	cout << "当前的最小代价:" << e[1][n]-sum << endl;
}
string printOBST(int i, int j)//输出代价最优的二叉搜索树，n为BST关键字节点个数
{
	string tree;
	if (i == j)
	{
		char ch = '0' + root[i][j];
		tree += ch;//返回该层次根
	}
	else if (i>j)//i>j返回空字符串
	{
		tree = "";
	}else
	{
		int r = root[i][j];
		char ch = '0' + root[i][j];
		tree+=ch;
		tree+="("+ printOBST(i, r-1) +","+ printOBST(r+1, j)+")";//递归求解
	}
	return tree;
}//用广义表的形式，利用root矩阵输出OBST
int main()
{
	double p[6] = { 0,0.15,0.1,0.05,0.1,0.2 };//关键字k(i,j)，1<=i<=j<=n ，长度n 
	double q[6] = { 0.05,0.1,0.05,0.05,0.05,0.1 };//失败区间关键字d(i,j)，0<=i<=j<=n,长度n+1 
	//double p[8]={0,0.16,0.06,0.09,0.02,0.03,0.03,0.08};//七个关键字节点的搜索概率值
	//double q[8]={0.12,0.08,0.1,0.06,0.09,0.02,0.03,0.03};//八个搜索失败区间的概率值 
	int n=5;//关键字节点个数 
	for(int i=0;i<=n;i++)
	{
		sum+=q[i];
	}
	optimalBST(p, q, n); 
	cout<<printOBST(1,n); 
	system("pause");
	
	return 0;
}
