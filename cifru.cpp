#include <fstream>
#include <climits>
#include <cmath>
using namespace std;
ifstream fin("cifru.in");
ofstream fout("cifru.out");
#define MAX 10000
int prime[1230];
bitset <MAX+1> p;
int main()
{
    int n,i,x,max1=INT_MIN,max2=INT_MIN,cate-0,j,k,r;
    fin>>n;
    r=sqrt(MAX);
    p[0]=p[1]=1;
    prime[++cate]=2;
    
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
    }
    fout<<max1<<" "<<max2<<"\n";
    
}
