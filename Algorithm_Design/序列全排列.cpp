#include<iostream>
using namespace std; 
int a[10],b[10],n,cnt;
void all_perme(int step){
    if (step==n+1){
    	//���ȵ���n��������� 
        for (int i=1;i<=n;i++)
        cout<<a[i];
        cout<<endl;
        cnt++;
    }
    for (int i=1;i<=n;i++){
        if (b[i]==0){
            a[step]=i;
            b[i]=1;
            all_perme(step+1);
            b[i]=0;
        }
    }
    
}
int main(){
	cnt=0;
	cout<<"���������ָ���n(1-9�������):"<<endl; 
    cin>>n;
    all_perme(1);//��������Ĭ�ϴ�1��ʼ 
    cout<<n<<"�����ֵ�ȫ���й���"<<cnt<<"��"<<endl; 
    return 0;
}

