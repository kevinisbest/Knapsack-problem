#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int T[1000][1000]={0};
void knapsack(int n, int W,int v[],int w[]){//裝背包 
	
	
	for (int i=1;i<=n;i++)
	{
		for (int j=W;j>w[i];j--)
		{
			if(v[j-w[i-1]]+v[i-1]>v[j])
			{
				v[j]=v[j-w[i-1]]+v[i-1];
				T[i][j]=1;
			}
		}
	}
	
	cout<<v[W]<<endl;
	
	int m= 0;//裝幾個數量 
	
	for (int i=n-1,j=W;i>=0;i--)if(T[i][j]) m++;
	
	cout <<m<<endl;

	cout << "(";
	for (int i=1,j=W;i<n;i++)
	{
		if (T[i][j])   
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
	int value[100]={0},weight[100] = {0};//價值 重量 
	if (n<=100)
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
		if (W <= 1000)
		{
			knapsack(n,W,value,weight);
		}
	}
	system("pause");
	return 0;
	
	
 } 
