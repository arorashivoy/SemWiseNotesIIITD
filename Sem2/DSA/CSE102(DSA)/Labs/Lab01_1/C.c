#include<stdio.h>
#include<math.h>

double k;
int f(double mid)
{
    if (mid * mid + sqrt(mid) + 100 - k > 0) return 1;
    return 0;
}
int main()
{
    scanf("%lf", &k);
    double lo = 0, hi = 100000000;
    for (int i = 0; i < 100000; i++) {
        double mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }
    printf("%.10f", hi);
    return 0;
}