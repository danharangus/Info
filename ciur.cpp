#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;
ifstream fin("eratostene.in");
ofstream fout("eratostene.out");
#define MAX 1000
bitset <MAX+1>p;
int prime[170];
int main()
{
    int cate=0,i,j,r;
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
                p[j]=1;
            }
        }
    }
    r+=(r%2 == 0);
    for(i=r; i<=MAX; i+=2)
    {
        if(!p[i])
        {
            prime[++cate]=i;
        }
    }
    fin.close();
    fout.close();
    return 0;
}

