//////#include<iostream>
//////using namespace std;
//////int cnt = 0;//ͳ��ÿһ�����֮��Ļ��ָ���
///////*����˼��������һ�������ڴ�ռ���ģ������ջ*/
//////void output(int a[], int top2)      //��s1Ϊ�յ�ʱ�����s2�еĽ��
//////{
//////	int i;
//////	for (i = 0; i<top2 - 1; i++)
//////	{
//////		cout << a[i]<<" ";
//////	}
//////	cout << a[i] << endl;//���ƻ���
//////	cnt++;
//////}
//////
//////void partion(int top1, int top2, int a[])
//////{
//////	
//////	if (top1 == 0)          //���s1������Ԫ�أ��򻮷���ϣ����
//////	{
//////		output(a, top2);
//////	}
//////	else
//////	{
//////		for (int i = top1; i >= 1; i--)
//////		{
//////			if (top2 == 0 || i <= a[top2 - 1])
//////			{
//////				a[top2] = i;                  //��s1��ȡ����1�ĸ���ѹ��s2
//////				partion(top1 - i, top2 + 1, a);   //��s1��ʣ�µ�1�ٴν���ȡջ����
//////			}
//////		}
//////	}
//////	
//////}
//////int main()
//////{
//////	int top1, top2;
//////	int *a;//����һ��ָ�����
//////	while ( cin>>top1 && top1 >= 0)
//////	{
//////		cout << "�������������������" << endl;
//////		top2 = 0;
//////		a = (int *)malloc(top1*sizeof(int));//Ϊ�����ָ���������top1*sizeof(int)��С���ڴ�ռ�
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
//	n++;//��Ϊ������û��0
//	for (int j = 1; j <= n; j++) {
//		f[1][j] = 1;
//		for (int i = 2; i <= n; i++) {
//			if (i<j) f[i][j] = f[i][j - 1];
//			else f[i][j] = f[i - j][j] + f[i][j - 1];
//		}
//	}
//	cout << "��̬�滮���ָ���Ϊ:" << f[n][n]<< endl;
//}
//void partition(int n, vector<int>& v, int level) {
//	int first; /* ��ʾÿ��ݹ���ʹ�õĵ�һ��Ԫ��*/
//	if (n < 1)
//		return;
//	v[level] = n;//ÿ�εݹ�ĵ�һ�����־��Ǳ���n,�������
//	//print(v, level);
//	if (level == 0)
//		first = 1;
//	else
//		first = v[level - 1];
//	for (int i = first; i <= n / 2; i++) {
//		v[level] = i; /* �滻֮ǰ�����������ĩβԪ�� */
//		partition(n - i, v, level + 1);
//	}
//}
//
//int main() {
//	int num;
//	cout << "�����뻮������:";
//	cin >> num;
//
//	vector<int> v(num);
//
//	partition(num, v, 0); 
//	DWORD start_time = GetTickCount();
//	cout<<recursion_count(num, num)<<endl;
//	DWORD end_time1 = GetTickCount();
//	cout << "�ݹ鷽ʽ1����ʱ��:" << (end_time1- start_time) << "ms!" << endl;//�������ʱ��
//	partitioncount(num);
//	DWORD end_time2= GetTickCount();
//	cout << "��̬�滮����ʱ��:" << (end_time2 - end_time1) << "ms!" << endl;//�������ʱ��
//	
//	
//	system("pause");
//	return 0;
//}