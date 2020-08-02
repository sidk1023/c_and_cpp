#include <iostream>

using namespace std;
void toh(int,char,char,char);
int main()
{

  cout<<"how many discs?"<<endl;
  int disc;
  cin>>disc;
  if (disc <= 1){
        cout<<"enter more discs"<<endl;
  }

  else{

  cout<<"you have "<<disc<<" discs in tower 1"<<endl;
  toh(disc,'1','2','3');
  cout<<"\n"<<disc<< " discs have been moved from tower 1 to tower 2"<<endl;
    }
}
void toh(int d, char from, char to, char inter){
  if(d==1)
    {
    cout<<"\n move disk "<<d<<" from tower " <<from << " to tower"<<to;

    return;
    }
   toh(d-1,from,inter,to);
cout<<"\n move disk "<<d<<" from tower " <<from << " to tower"<<to;
   toh(d-1,inter,to,from);
}
