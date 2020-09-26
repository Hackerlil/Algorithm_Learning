//////#include<iostream>
//////using namespace std;
//////int cnt = 0;//统计每一次输出之后的划分个数
///////*本文思想类似用一个连续内存空间来模拟两个栈*/
//////void output(int a[], int top2)      //当s1为空的时候输出s2中的结果
//////{
//////	int i;
//////	for (i = 0; i<top2 - 1; i++)
//////	{
//////		cout << a[i]<<" ";
//////	}
//////	cout << a[i] << endl;//控制换行
//////	cnt++;
//////}
//////
//////void partion(int top1, int top2, int a[])
//////{
//////	
//////	if (top1 == 0)          //如果s1中已无元素，则划分完毕，输出
//////	{
//////		output(a, top2);
//////	}
//////	else
//////	{
//////		for (int i = top1; i >= 1; i--)
//////		{
//////			if (top2 == 0 || i <= a[top2 - 1])
//////			{
//////				a[top2] = i;                  //从s1中取出的1的个数压入s2
//////				partion(top1 - i, top2 + 1, a);   //对s1中剩下的1再次进行取栈操作
//////			}
//////		}
//////	}
//////	
//////}
//////int main()
//////{
//////	int top1, top2;
//////	int *a;//建立一个指针变量
//////	while ( cin>>top1 && top1 >= 0)
//////	{
//////		cout << "请输入带划分整数序列" << endl;
//////		top2 = 0;
//////		a = (int *)malloc(top1*sizeof(int));//为定义的指针变量申请top1*sizeof(int)大小的内存空间
//////		partion(top1, top2, a);
//////		cout << cnt << endl;
//////		cnt = 0;
//////	}
//////	return 0;
//////}
//#include <iostream>
//#include <vector>
//#include<windows.h>
//using namespace std;
//int cnt = 0;
//#define N 100;
//int f[150][150];
//void print(vector<int>& v, int level) {
//	for (int i = 0; i <= level; i++)
//		cout << v[i] << " ";
//	cout << endl;
//	cnt++;
//}
//
//int recursion_count(int n, int m) {
//	if (n == 1 || m == 1) {
//		return 1;
//	}
//	else if (n < m) {
//		return recursion_count(n, n);
//	}
//	else if (n == m) {
//		return recursion_count(n, m - 1) + 1;
//	}
//	else if (n >= m) {
//		return recursion_count(n, m - 1) + recursion_count(n - m, m);
//	}
//}
//
//
//void partitioncount(int n)
//{
//	n++;//因为划分中没有0
//	for (int j = 1; j <= n; j++) {
//		f[1][j] = 1;
//		for (int i = 2; i <= n; i++) {
//			if (i<j) f[i][j] = f[i][j - 1];
//			else f[i][j] = f[i - j][j] + f[i][j - 1];
//		}
//	}
//	cout << "动态规划划分个数为:" << f[n][n]<< endl;
//}
//void partition(int n, vector<int>& v, int level) {
//	int first; /* 表示每层递归中使用的第一个元素*/
//	if (n < 1)
//		return;
//	v[level] = n;//每次递归的第一个划分就是本身n,并且输出
//	//print(v, level);
//	if (level == 0)
//		first = 1;
//	else
//		first = v[level - 1];
//	for (int i = first; i <= n / 2; i++) {
//		v[level] = i; /* 替换之前输出过的容器末尾元素 */
//		partition(n - i, v, level + 1);
//	}
//}
//
//int main() {
//	int num;
//	cout << "请输入划分整数:";
//	cin >> num;
//
//	vector<int> v(num);
//
//	partition(num, v, 0); 
//	DWORD start_time = GetTickCount();
//	cout<<recursion_count(num, num)<<endl;
//	DWORD end_time1 = GetTickCount();
//	cout << "递归方式1运行时间:" << (end_time1- start_time) << "ms!" << endl;//输出运行时间
//	partitioncount(num);
//	DWORD end_time2= GetTickCount();
//	cout << "动态规划运行时间:" << (end_time2 - end_time1) << "ms!" << endl;//输出运行时间
//	
//	
//	system("pause");
//	return 0;
//}