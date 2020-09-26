//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//using namespace std;
//int select_median(int a[], int p, int r);
//void Swap(int &x, int &y);
//void Bubblesort(int a[], int p, int r);
//int main()
//{
//	srand((unsigned)time(0));//随机数种子 
//	int a[100];
//	for (int i = 0; i < 100; i++)
//	{
//		a[i] = rand()%102;
//	}
//	cout << select_median(a,0,99);
//	system("pause");
//	return 0;
//}
//int select_median(int a[],int p,int r)
//{
//	for (int i = 0; i <=((r-p )/ 5); i++)
//	{
//		Bubblesort(a,p+i*5, p + i*5+4);
//		Swap(a[p + i], a[p + i*5 + 2]);
//	}
//	Bubblesort(a, p, p + (r-p)/5);
//	return a[(p + p + (r - p) / 5) / 2];
//}
//void Bubblesort(int a[],int p ,int r)
//{
//	bool flag = false;
//	for (int i = p; i <=r-1; i++)
//	{
//		flag = false;
//		for (int j = i + 1; j <= r; j++)
//		{
//			if(a[j]<a[j - 1])
//			{
//				Swap(a[j] , a[j - 1]);
//				flag = true;
//			}
//		}
//		//如果这次遍历没有元素的交换,那么排序结束   
//		if (false == flag)
//		{
//			break;
//		}
//	}
//}
//void Swap(int &x, int &y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}