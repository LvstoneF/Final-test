#include <iostream>

using namespace std;

int main()
{   int n,k;
    cout<<"����n,k"<<endl;
    cin>>n>>k;
    int a[100];
    cout<<"�������"<<endl;
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
            cout<<"��"<<count <<"�μ��͵�λ�ã�"<<i-1<<endl;
        }
    }

    cout << "�ܹ����ͣ�"<<count<<"��"<< endl;
    return 0;
}
