#include <iostream>
#include<cstdlib>
using namespace std;

long double step(long double a, long int b)
{
    long double ans = a;
    if (b == 0) {
        return 1;
    }
    for(int i = 1; i < b; ++i) {
        ans *= a;
    }
    return ans;

}
long long int fact(long int a)
{
    if(a == 0)
    {
        return 1;
    }
    else if (a < 3)
    {
        return a;
    }
    else
    {
        return a * fact(a - 2);
    }
}

long double t(long double x)
{
    long int k;
    long double num = 0, denu = 0;
    for(k = 0; k < 11; k++)
    {
        num += step(x, 2 * k + 1) / fact(2 * k + 1);
    }
    for(k = 0; k < 11; k++)
    {
        denu += step(x, 2 * k) / fact(2 * k);
    }
    return num / denu;
    cout << num / denu << endl;
}
long double ans(long double y)
{
    return (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(step(y, 2) - 1));
}
int main () 
{
    double y;
    cin>>y;
    cout << ans(y) << endl;
    printf("%e", ans(y));
    printf("%.1f\n", ans(y));
    return 0;

}