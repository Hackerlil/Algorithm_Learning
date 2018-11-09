#include<iostream>
using namespace std; 
int a[10],b[10],n,cnt;
void all_perme(int step){
    if (step==n+1){
    	//长度到达n，可以输出 
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
	cout<<"请输入数字个数n(1-9避免溢出):"<<endl; 
    cin>>n;
    all_perme(1);//排列数字默认从1开始 
    cout<<n<<"个数字的全排列共有"<<cnt<<"种"<<endl; 
    return 0;
}

