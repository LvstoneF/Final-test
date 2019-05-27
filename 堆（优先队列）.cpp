

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5] = {4, 6, 3, 9, 0};

    priority_queue<int> qi;

    priority_queue<int, vector<int>, greater<int> > qi;
    for(int i = 0; i<5; i++)
    {
        qi.push(a[i]);
    }
    for(int i = 0; i<5;i++)
    {
        cout << qi.top() << " ";
        qi.pop();
    }
}



