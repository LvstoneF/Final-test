#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;

}

int main()
{
    int a = 1, b =3;
    swap(a, b);
    cout << a << b;
}
