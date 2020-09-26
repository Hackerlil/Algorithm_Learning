//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//int a[100][100] = { 0 };
//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
//		int m = obstacleGrid.size();
//		int n = obstacleGrid[0].size();
//		//int a[m][n]; 
//		int flag = 0;
//		//根据障碍的情况给第一列赋值 
//		for (int i = 0; i < m; i++)
//		{
//			if (obstacleGrid[i][0] == 1) {
//				flag = 1;
//			}
//			if (flag == 1)
//			{
//				if (m == 1) {
//					return 0;
//				}
//				for (int j = i; j < m; j++) {
//					a[i][0] = 0;
//				}
//				i = m;
//
//			}
//			else
//			{
//				a[i][0] = 1;
//			}
//		}
//		//根据障碍的情况给第一行赋值 
//		for (int i = 0; i < n; i++)
//		{
//			if (obstacleGrid[0][i] == 1) {
//				flag = 1;
//			}
//			if (flag == 1)
//			{
//				if (n == 1) {
//					return 0;
//				}
//				for (int j = i; j < n; j++) {
//					a[0][i] = 0;
//				}
//				i = n;
//
//			}
//			else
//			{
//				a[0][i] = 1;
//			}
//		}
//		for (int i = 1; i < m; i++)
//		{
//			for (int j = 1; j < n; j++)
//			{
//				if (obstacleGrid[i][j] == 1)
//				{
//					a[i][j] = 0;
//				}
//				else
//				{
//					a[i][j] = a[i - 1][j] + a[i][j - 1];
//				}
//			}
//		}
//		return a[m - 1][n - 1];
//
//	}
//};
////	int minPathSum(vector<vector<int> >& grid) {
////		int m = grid.size();
////		int n = grid[0].size();
////		int a[m][n]; int sum = 0;
////		for (int i = 0; i<m; i++)
////		{
////			sum += grid[i][0];
////			a[i][0] = sum;
////		}
////		sum = 0;
////		for (int i = 0; i<n; i++)
////		{
////			sum += grid[0][i];
////			a[0][i] = sum;
////		}
////		for (int i = 1; i<m; i++)
////		{
////			for (int j = 1; j<n; j++)
////			{
////				a[i][j] = min(a[i - 1][j], a[i][j - 1]) + grid[i][j];
////			}
////		}
////		return a[m - 1][n - 1];
////	}
//
////
//////tips:采用搜索算法，遍历所有左上角到右下角的所有路径共有2^ 
////int uniquepath(int m, int n)
////{
////	int a[m][n];
////	for (int i = 0; i<m; i++)
////	{
////		a[i][0] = 1;
////	}
////	for (int i = 0; i<n; i++)
////	{
////		a[0][i] = 1;
////	}
////	for (int i = 1; i<m; i++)
////	{
////		for (int j = 1; j<n; j++)
////		{
////			a[i][j] = a[i - 1][j] + a[i][j - 1];
////		}
////	}
////	return a[m - 1][n - 1];
////}
//int main()
//{
//	vector<vector<int> > array(2);
//	for (int i = 0; i<1; i++) {
//		array[i].resize(2);
//	}
//	int a[2][2] = { { 0,0 },{ 1,0 } };
//	for (int j = 0; j<array.size(); j++)
//	{
//		for (int k = 0; k<array[0].size(); k++)
//		{
//
//			array[j][k] = a[j][k];
//		}
//	}
//	Solution s;
//	// cout<<s.minPathSum(array);
//	cout << s.uniquePathsWithObstacles(array);
//
//
//
//	//Solution solu;
//	//cout<<solu.climbStairs(1);
//	return 0;
//}