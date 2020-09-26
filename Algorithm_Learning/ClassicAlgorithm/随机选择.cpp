//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//#include<string>
//using namespace std;
//int partition(int a[], int low, int high)//经典划分算法
//{
//	int pivot = a[low];
//	while (low<high)
//	{
//		while (low < high&&a[high] >= pivot)
//			high--;
//		int temp = a[low];
//		a[low] = a[high];
//		a[high] = temp;
//		while (low < high&&a[low] <= pivot)
//			low++;
//		temp = a[low];
//		a[low] = a[high];
//		a[high] = temp;
//
//	}
//	return low;
//}
//void Swap(int &x, int &y)
//{
//	int temp=x;
//	x=y;
//	y = temp;
//}
//inline int Random(int p, int r)
//{
//	srand((unsigned)time(0));//随机数种子 
//	int ran = rand() % (r - p) + p;
//	return ran;//产生p，r间的数字
//}
//int Random_partition(int a[], int p,int r)
//{
//	int pivot=Random(p,r);
//	Swap(a[p],a[pivot]);
//	return partition(a, p, r);//随机产生划分基准
//}
//int Random_selected(int a[],int p,int r,int k)
//{
//	if (p==r)
//	{
//		return a[p];
//	}
//	int pivot = Random_partition(a, p, r);
//	int j = pivot - p + 1;
//	if (k <= j)
//	{
//		return Random_selected(a, p, pivot, k);
//	}
//	else
//	{
//		return Random_selected(a, pivot + 1, r, k - j);
//	}
//}
//int main()
//{
//	int a[10] = {0,5,33,23,4,5,9,7,8,3};
//	for (int i = 0; i < 10; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	cout<<Random_selected(a, 0, 9, 5);
//	system("pause");
//	return 0;
//}
////void quicksort(int a[], int low, int high)
////{
////	if (low < high)
////	{
////		int r = partition(a, low, high);
////		quicksort(a, low, r - 1);
////		quicksort(a, r + 1, high);
////	}
////
////}