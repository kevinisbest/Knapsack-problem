#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int T[1000][1000]={0};
void knapsack(int n, int W,int v[],int w[]){//�˭I�] 
	
	
	for (int i=1;i<=n;i++)
	{
		for (int j=W;j>w[i];j--)//j�O�̤j���q�A�h�� 
		{
			if(v[j-w[i-1]]+v[i-1]>v[j])//�p�G�[i-1�o�Ӫ��~�����Ȥ���� 
			{
				v[j]=v[j-w[i-1]]+v[i-1];//��s(�˶i�h) 
				T[i][j]=1;//�������˰_�Ӫ� 
			}
		}
	}

	cout<<v[W]<<endl;
	
	int m= 0;//�˴X�Ӽƶq 
	
	for (int i=n-1,j=W;i>=0;i--)
	{
		if(T[i][j]==1) m++;//����쬰�@���N++ 
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

	int value[100]={0};//���� 
	int weight[100]={0};//���q 
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
			cout<<"�ѼƤ��d��n<=100�PW<=1000,vi,wi<=100�C"<<endl;
	}
	else if(n==0)
		cout<<"0"<<endl<<"0"<<endl<<"(0,0)"<<endl;
	
	else
		cout<<"�ѼƤ��d��n<=100�PW<=1000,vi,wi<=100�C"<<endl;
	system("pause");
	return 0;
	
	
 } 
