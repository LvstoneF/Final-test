#include <iostream>

using namespace std;

int main()
{   int n,k;
    cout<<"输入n,k"<<endl;
    cin>>n>>k;
    int a[100];
    cout<<"输入距离"<<endl;
    for(int i=1;i<=k+1;i++)
    {
        cin>>a[i];
    }
    int count=0;
    int sum=0;
    for(int i=1;i<=k+1;i++)
    {
        sum+=a[i];
        if(sum>=n)
        {
            sum=a[i];
            count++;
            cout<<"第"<<count <<"次加油的位置："<<i-1<<endl;
        }
    }

    cout << "总共加油："<<count<<"次"<< endl;
    return 0;
}
