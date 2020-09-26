//#include<cstdio>
//#include<iostream>
//using namespace std;
//#define N 55
//int f[N][N];
//int main() {
//	int n;
//	while (cin >> n) {
//		n;
//		for (int j = 1; j <= n; j++) {
//			f[1][j] = 1;//划分中因子不大于1的划分只有一种
//			for (int i = 2; i <= n; i++) {
//				if (i<j) f[i][j] = f[i][j - 1];//若
//				else f[i][j] = f[i - j][j] + f[i][j - 1];
//			}
//		}
//		printf("%d\n", f[n][n]);
//		for (int i = 0; i <= n; i++) {
//			
//			for (int j=0 ; j <= n; j++) {
//				cout << f[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//
//}
