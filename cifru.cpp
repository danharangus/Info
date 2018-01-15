#include <fstream>
#include <climits>
#include <cmath>
#include <bitset>
using namespace std;
ifstream fin("cifru.in");
ofstream fout("cifru.out");
#define MAX 10000
int prime[1230];
bitset <MAX+1> p;
int main()
{
    int n,i,x,max1=INT_MIN,max2=INT_MIN,cate=0,j,k,r,rx,pr1,pr2,nr=INT_MIN;
    fin>>n;
    r=sqrt(MAX);
    p[0]=p[1]=1;
    prime[++cate]=2;
    for(i=3; i<=r; i+=2)
    {
        if(!p[i])
        {
            prime[++cate]=i;
            for(j=i*i; j<=MAX; j+=2*i)
            {
                p[j]=i;
            }
        }
    }
    r+=(r%2==0);
    for(i=r; i<=MAX; i+=2)
    {
        if(p[i]==0)
        {
            prime[++cate]=i;
        }
    }
    for(i=1; i<=n; i++)
    {
        fin>>x;
        if(x>max1)
        {
            max2=max1;
            max1=x;
        }
        else if(x>max2)
        {
            max2=x;
        }
        rx=sqrt(x);
        if((rx * rx == x) && (x%2==0))
        {
            pr1=x/2+1;
            while(p[pr1]==0)
            {
                pr1++;
            }
            pr2=x/2-1;
            while(p[pr2]==0)
            {
                pr2--;
            }
            if((pr1+pr2==x) && (x>nr))
            {
                nr=x;
            }
        }
    }
    fout<<max1<<" "<<max2<<"\n"<<nr;
}
