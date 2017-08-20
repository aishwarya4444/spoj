#include<iostream>
using namespace std;
typedef unsigned long long int ULLI;

// http://en.wikipedia.org/wiki/Primality_test

bool primalityTest(ULLI i)
{
    if(i==1)return false;
    if(i==2 || i==3)return true;
    if(i%2==0 || i%3==0)return false;
    for(ULLI j=5;j*j<=i;j+=6)
    {
        if(i%(j)==0 || i%(j+2)==0)return false;
    }
    return true;
}

int main( void)
{
    ULLI t, i, l, r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;;
        for(i=l;i<=r;i++)
        {
            if(primalityTest(i))cout<<i<<'\n';
        }
        cout<<endl;
    }
    return 0;
}
