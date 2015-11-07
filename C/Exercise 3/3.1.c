#include <stdio.h>
#include <math.h>
double calcSemiperim (double a, double b, double c);
double calcArea(double s, double a, double b, double c);
double calcPerimeter(double a, double b, double c);

int main(void)
{
    double a, b, c;
    double s, area, perim;

    printf("Enter first length: ");
    scanf("%lf", &a);
    printf("\nEnter second length: ");
    scanf("%lf", &b);
    printf("\nEnter third lengthL ");
    scanf("%lf", &c);

    s = calcSemiperim(a, b, c);
    area = calcArea(s, a, b, c);
    perim = calcPerimeter(a, b, c);

    if (s <=0|| area<=0 || perim <= 0)
    {
        printf("This ain't a triangle...");
    }
    else
    {
        printf("\nHere are the parameters of your triangle:\n");
        printf("Area:\t%lf\n", area);
        printf("Perimeter:\t%lf\n", perim);
    }
    return 0;
}

double calcSemiperim (double a, double b, double c)
{
    return (a + b + c ) / 2;
}

double calcArea(double s, double a, double b, double c)
{
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

double calcPerimeter(double a, double b, double c)
{
    return a + b + c;
}
