#include <iostream>
#include<cmath>

using namespace std;
int compare(int a,int b)
{
    if (a<b)//less than gives ascending, greater than gives descending

    {
        return -1;
    }
    return 1;
}
int abs_compare(int a, int b)
{
    if(abs(a)<abs(b))
    {
        return -1;
    }
    return 1;
}
void swaps(int*a,int*b)
{
    int temp;
    temp = *b ;
    *b = *a;
    *a = temp;

}
int sort(int *arr, int n, int (*compare)(int,int))
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n-1;j++)
        {
            if(compare(arr[j],arr[j+1])>0)
            {
                swaps(&arr[j],&arr[j+1]);
            }
        }
    }

}
int main()
{
    int n;
    cout<<"size of array"<<endl;
    cin>>n;
    int *p = new int[n];
    cout<<"enter "<< n <<" numbers"<<endl;
    for(int i =0; i<n; i++)
    {
        cin>>p[i];
    }
    sort(p,n,abs_compare);
        for(int i =0; i<n; i++)
    {
        cout<<p[i]<<endl;
    }
}
