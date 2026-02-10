#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>i; j--)
        {
            cout<<" ";
        }
        for(int k=i; k>1; k--)
        {
            cout<< k;
        }
        for(int l=1; l<=i; l++)
        {
            cout<< l;
        }
        cout<<endl;
    }
    return 0;
}