#include <cstdio>
#include <cstring>
int main()
{
    double a = 0;
    double b = 0;
    double result = 0;
    char op;
    scanf("%lf %c %lf", &a, &op, &b);
    

    if (op == '+')
    {
        result = a + b;
        printf("%.0lf\n", result);
    }
    if (op == '-')
    {
        result = a - b;
        printf("%.0lf\n", result);
    }
    if (op == '*')
    {
        result = a * b;
        printf("%.0lf\n", result);
    }

    return 0;
}