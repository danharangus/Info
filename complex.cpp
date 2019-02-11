#include <iostream>
#include <cmath>
using namespace std;


class complex
{
public:
    double x, y;

    friend complex operator +(complex a, complex b);
    friend complex operator -(complex a, complex b);
    friend ostream& operator <<(ostream& o, complex a);
    friend istream& operator >>(istream& i, complex &a);

    double modul()
    {
        return sqrt(x*x + y*y);
    }

};

complex operator +(complex a, complex b)
{
    complex result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;

}

complex operator -(complex a, complex b)
{
    complex result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

ostream& operator <<(ostream& o, complex a)
{
    o<<a.x<<' '<<a.y;
}

istream& operator >>(istream& i, complex &a)
{
    i>>a.x>>a.y;
}

int main()
{
    complex z1, z2;

    cin>>z1>>z2;

    cout<<z1+z2<<endl;
    cout<<z1-z2<<endl;
    cout<<z1.modul()<<endl;
    cout<<z2.modul()<<endl;
}
