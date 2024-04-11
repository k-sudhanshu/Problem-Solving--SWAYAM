#include<bits/stdc++.h>
using namespace std;
 
bool hasOnlyOneChild(int pre[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if ((pre[i] - pre[i+1]) * (pre[i] - pre[size-1]) < 0)
            return false;
    }
    return true;
}
int main()
{
    int pre[] = {8, 3, 5, 7, 6};
    int size = sizeof(pre)/sizeof(pre[0]);
    if (hasOnlyOneChild(pre, size) == true )
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
