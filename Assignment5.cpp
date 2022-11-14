#include<iostream>
using namespace std;

int v[20][20];
int max1(int a,int b)
{
    return(a>b)?a:b;
}

int  main() {
    int i,j,p[20],w[20],n,max;
    cout<<"\n enter the number of items\n ";
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cout << "\n enter the weight and profit of the  item "<<i <<":";
        cin>> w[i] >> p[i];
    }
    cout<< "\n enter the capacity of the knapsack: ";
    cin>> max;
    for(i=0;i<=n;i++)
        v[i][0]=0;
    for(j=0;j<=max;j++)
        v[0][j]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=max;j++)
        {
            if(w[i]>j)
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max1(v[i-1][j],v[i-1][j-w[i]]+p[i]);
        }
    cout<<"\n\nThe table is\n";
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=max;j++)
            cout<<"\t"<< v[i][j];
        cout<<"\n";
    }
    cout<<"\nThe maximum profit is = "<< v[n][max];
    cout<<"\nThe most valuable subset is:{";
    j=max;
    for(i=n;i>=1;i--)
        if(v[i][j]!=v[i-1][j])
        {
            cout<<"\t item: "<< i;
            j=j-w[i];
        }
        cout<<" }";
}
