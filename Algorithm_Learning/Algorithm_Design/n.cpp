#include<iostream>
#include<cmath>
using namespace std;
#define num 10
int x[10]; int cnt = 0;
void output()
{
	for (int i = 0; i < num; i++)
		cout << x[i] << " ";
	cout << endl;

}
bool islegal(int a[], int n)
{
	
	for (int j = 0; j<n; j++) //����ǰ��Ļʺ��Ƿ��ͻ 
		if (a[n] == a[j] || n - a[n] == j - a[j] || n + a[n] == j + a[j]) {
			return false;
		}//���ܴ��ڶԽ����ϣ�����ͬһ��ͬһ��
	return true;

}

void backctrack_queen(int n)
{
	if (n ==num)
	{
		//output();//����˻ʺ���ܰڷ�λ��
		cnt++;//����++
	}	
	else
	{
		for (int i = 0; i <num; i++)//������ǰ���
		{
			x[n] = i;
			if (islegal(x, n))//�����ǰ������������ʼ��һ���ʺ�λ������
				backctrack_queen(n + 1);
		}
			
	}

}
void Iterbacktrack()
{
	int t = 0;
	while (t < num)
	{
		for (int i = 0; i < num; i++)
		{
			x[t] = i;
			if (islegal(x, t))
				t++;
			else

		}


	}
}
int main()
{
	backctrack_queen(0); 
	cout << cnt << endl;
	system("pause");
	return 0;
}
