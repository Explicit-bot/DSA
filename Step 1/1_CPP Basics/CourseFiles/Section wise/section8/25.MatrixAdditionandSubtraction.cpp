# include<iostream>
using namespace std;
    
int main()
{
	int a[2][3]={3,3,3,3,3,3};
	int b[2][3]={1,1,1,1,1,1};
	int c[2][3];
    int d[2][3];

    //Addition of matrix
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
    //Subtraction of matrix
    for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			d[i][j]=a[i][j]-b[i][j];
		}
	}

    cout<<"Added Matrix"<<"\n";
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}

    cout<<"Subtracted Matrix"<<"\n";
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}    

	return 0;
}
