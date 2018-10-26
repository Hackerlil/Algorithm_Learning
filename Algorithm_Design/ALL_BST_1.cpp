#include<iostream>
#include<vector>
#include<string>
using namespace std;
char A[13]={' ','1','2','3','4','5','6','7','8','9','A','B','C'};
int cnt = 0;
vector<string> pTree(int n, int rot, int lor)//输出树形
{
	vector<string> vec;
	if (n == 0)//子树为空没有节点
	{
		vec.push_back("");
		return vec;
	}
	if (n == 1)
	{
		string le; char temp;
		if (lor == 1)//左子树
		{

			le+=A[rot-1]; 
			vec.push_back(le);
		}
		else//右子树
		{
			le+=A[rot+1]; 
			vec.push_back(le);
		}
		return vec;
	}
	if (n == 2)//长度为2的子树有两种
	{
		string le; char temp1;
		char temp2;
		if (lor == 1)//左子树
		{
			//树形1
			le += A[rot-1];
			le += "(";
			le += A[rot-2];
			le += ",)";
			vec.push_back(le);
			le = "";
			//树形2
			le += A[rot-2];
			le += "(,";
			le += A[rot-1];
			le += ")";
			vec.push_back(le);
		}
		else//右子树
		{
			//树形1
			le += A[rot+1];
			le += "(,";
			le += A[rot+2];
			le += ")";
			vec.push_back(le);
			le = "";
			//树形2
			le += A[rot+2];
			le += "(";
		    le += A[rot+1];
			le += ",)";
			vec.push_back(le);
		}
		return vec;
	}
	for (int i = n; i >= 1; i--)
	{
		string tree;
		int flag=i+rot;
		if(flag>n&&lor==1)
		{
			flag-=n+1;
		}
		char root = A[flag];//树根
		vector<string> vec1 = pTree(i-1, flag, 1);//左子树的树形
		vector<string> vec2 = pTree(n - i, flag, 2);//右子树的树形
		for (int k1 = 0; k1 < vec1.size(); k1++)
		{

			for (int k2 = 0; k2 < vec2.size(); k2++)
			{
				tree += root;
				if (vec1[k1].size()>0 || vec2[k2].size()>0)
				{
					tree += "(" + vec1[k1] + "," + vec2[k2] + ")";
					vec.push_back(tree);
					//cout << tree << endl;
				}
				tree = "";
				//分别表示根结点值从1-n和相应左右子树节点个数
			}
		}
	//	cout<<vec1.size()<<"  "<<vec2.size()<<endl;
		//break;

	}
	return vec;
}
int getTreeNum(int n)//长度为n的序列的二叉搜索树的个数
{
	int sum = 0;
	if (n == 1 || n == 0)
		return 1;
	if (n == 2)
		return 2;
	for (int i = 0; i < n; i++)
	{
		sum += getTreeNum(i)*getTreeNum(n - i - 1);
		//分别表示根结点值从1-n和相应左右子树节点个数
	}
	return sum;
}
/*例如n=3，则1,2,3都可以为根结点，相应左右子树中节点个数为0,2；1,1；2,0*/
int main()
{
	int n;
	n = 5;
	/*cout << "请输入节点个数:";
	cin >> n;
	cout<<"节点个数为"<<n<<"时,组成二叉搜索树的个数为"<<getTreeNum(n)<<endl;*/
	vector<string> vec=pTree(n, 0, 0);
	cout<<"节点个数为"<<n<<"的时候,不同形态BST为"<<getTreeNum(n) << endl;
	cout << "vector中的不同形态个数为" << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
	system("pause");
	return 0;
}
