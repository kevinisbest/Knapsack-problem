#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int T[1000][1000]={0};
void knapsack(int n, int W,int v[],int w[]){//裝背包 
	
	
	for (int i=1;i<=n;i++)
	{
		for (int j=W;j>w[i];j--)//j是最大重量再去減 
		{
			if(v[j-w[i-1]]+v[i-1]>v[j])//如果加i-1這個物品的價值比較高 
			{
				v[j]=v[j-w[i-1]]+v[i-1];//更新(裝進去) 
				T[i][j]=1;//紀錄有裝起來的 
			}
		}
	}

	cout<<v[W]<<endl;
	
	int m= 0;//裝幾個數量 
	
	for (int i=n-1,j=W;i>=0;i--)
	{
		if(T[i][j]==1) m++;//有找到為一的就++ 
	}
	cout <<m<<endl;

	cout << "(";
	for (int i=1,j=W;i<n;i++)
	{
		if (T[i][j]==1)   
		{
			cout<<i;
			if (i!=n-1)
			cout<< ",";
		}
	}
	cout<<")"<<endl;

	
}
  
int main()
{
	
	int n,W;
	cin>>n;

	int value[100]={0};//價值 
	int weight[100]={0};//重量 
	if (n>0&&n<=100)
	{
		for (int i=1;i<= n;i++)	
		{
			cin >> value[i];
		}
		
		for (int i=1;i<= n;i++)
		{
			cin >> weight[i];
		}
		
		cin>>W;
		if (W>0&&W <= 1000)
			knapsack(n,W,value,weight);
		
		else if(n==0)
			cout<<"0"<<endl<<"0"<<endl<<"(0,0)"<<endl;
		
		else
			cout<<"參數之範圍為n<=100與W<=1000,vi,wi<=100。"<<endl;
	}
	else if(n==0)
		cout<<"0"<<endl<<"0"<<endl<<"(0,0)"<<endl;
	
	else
		cout<<"參數之範圍為n<=100與W<=1000,vi,wi<=100。"<<endl;
	system("pause");
	return 0;
	
	
 } 
