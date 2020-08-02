#include <iostream>

using namespace std;
mod(int x, int n, int m)
{
    if (n==0){return 1;}
    if (n%2==0){
        int y = mod(x,n/2,m);
        return (y*y)%m;
        }
     return (x%m)*mod(x,n-1,m)%m;
}

int main()
{
    cout<<mod(3,2,2);
    return 0;
}
//(x*y)%m = (x%m * Y%m)%m
