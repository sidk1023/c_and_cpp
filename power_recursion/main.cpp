#include <iostream>

using namespace std;
pow(int x, int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        int y;
        y = pow(x,n/2);
        return y*y;
    }
    return(x*pow(x,n-1));
}
int main()
{
    cout<<pow(4,5);
    return 0;
}
//O(logn)
