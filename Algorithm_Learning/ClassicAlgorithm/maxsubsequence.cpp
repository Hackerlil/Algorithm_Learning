//#include<iostream>
//#include<string>
//#include <algorithm>
//using namespace std;
//int T[100][100] = { 0 };
//int main() {
//
//	string str1 = "abxcdaf";
//	string str2 = "acbcf";
//	string commonstr = "";
//	int len1 = str1.length();
//	int len2 = str2.length();
//	int maxlen = 0;
//	for (int i = 1; i <=len1; i++) {
//		for (int j = 1; j <= len2; j++) {
//			if (str1[i] == str2[j]) {
//				T[i][j] = T[i - 1][j - 1] + 1;
//			}
//			else {
//				T[i][j] = max(T[i - 1][j], T[i][j - 1]);
//			}
//		}
//	}
//	cout << T[len1][len2] << endl;
//	//cout << len1 << " " << len2 << endl;
//	for (int i = len1; i >0;) 
//	{
//		for (int j = len2; j >0;) 
//		{
//			if (str1[i-1] == str2[j-1]) {
//				commonstr += str1[i-1];
//				i--, j--;
//				
//			}
//			else {
//				if (T[j][i - 1] >= T[j-1][i])
//				{
//					i--;
//				}
//				else
//					j--;
//			}
//		}
//		
//	} 
//	for (int j = commonstr.length() - 1; j >= 0; j--) {
//          cout << commonstr[j];
//	}
//	
//
//	//cout << extendedBottomUpCutRod(n) << endl;
//	//	printCutRodSol(n);
//	system("pause");
//	return 0;
//}