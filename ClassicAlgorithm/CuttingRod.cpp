//#include<iostream>
//#include<cstring>
//#include <algorithm>
//using namespace std;
//const int N = 1000;
//int p[11];
//int r[N], s[N];
////initializer for prices and optimal solution
//void init() {
//	memset(r, -1, sizeof(r));//initialize r
//	r[0] = 0;
//	p[0] = 0;
//	p[1] = 1;
//	p[2] = 5;
//	p[3] = 8;
//	p[4] = 9;
//	p[5] = 10;
//	p[6] = 17;
//	p[7] = 17;
//	p[8] = 20;
//	p[9] = 24;
//	p[10] = 30;
//}
//int BottomUp(int n)
//{
//	if (r[n] > 0)
//		return r[n];//previous computed
//	for (int j = 0; j <= n; j++)
//	{
//		int q = 0;
//		for (int i = 1; i <= j; i++)
//		{
//			q = max(q, p[i] + r[j - i]);//get maxmium
//		}
//		r[j] = q;
//
//	}
//	return r[n];
//
//
//}
//int extendedBottomUpCutRod(int n) {
//	if (r[n] != -1)
//		return r[n];
//	for (int j = 1; j <= n; j++) {
//		int q = 0;
//		for (int i = 1; i <= j; i++) {
//			if (q < p[i] + r[j - i]) {
//				q = p[i] + r[j - i];
//				s[j] = i;
//			}
//		}
//		r[j] = q;
//
//	}
//	return r[n];
//}
//
////print the extended method's output
//void printCutRodSol(int n) {
//	do {
//		cout << s[n] << " ";
//	} while ((n -= s[n]) > 0);
//}
//
//int main() {
//	init();
//	int n;
//	cout << "please input the length of the rod: " << endl;
//	cin >> n;
//	cout << BottomUp(n) << endl;
//	//cout << extendedBottomUpCutRod(n) << endl;
////	printCutRodSol(n);
//	system("pause");
//	return 0;
//}