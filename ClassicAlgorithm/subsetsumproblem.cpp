//#include<iostream>
//#include<cstring>
//#include <algorithm>
//using namespace std;
//const int N = 1000;
//int T[5][100] = { 1 };
//int main() {
//	int arr[5] = { 2,3,7,8,10 };
//	int n; cin >> n; n++;
//	for (int i = 0; i < 5; i++)
//	{
//		T[i][0] = 1;
//	}
//	for (int j = 1; j < n; j++)
//	{
//		if (j == arr[0]) {
//			T[0][j] = 1;
//		}
//		else {
//			T[0][j] = false;
//		}
//	}
//	for (int i = 1; i < 5; i++)
//	{
//		for (int j = 1; j < n; j++) 
//		{
//			if (j < arr[i])
//				T[i][j] = T[i - 1][j];
//			else
//				T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i]];
//		}
//	}
//	cout << T[4][n - 1];
//	system("pause");
//	return 0;
//}