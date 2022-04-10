#include <stdio.h>
int main(void)
{
    double  x2 = 1.0, y2 = 2.0;
    double  x0 = -3.0, y0 = 0.5;
    double  x1 = 1.0, y1 = -1.5;
    double  B = x1 - x0;
    double  A = -(y1 - y0);
    double  C = -A * x0 - B * y0;
    double  x = 1.0, y = -1.5;
    double  a = 2.0, b = 0.0;
    double  first_line;
	double	test;

    printf("A : %lf\n", A);
    printf("B : %lf\n", B);
    printf("C : %lf\n", C);
    first_line = A * x2 + B * y2 + C;
	test = (A * a + B * b + C);
	printf("first = %lf,	second = %lf\n", first_line, test);
    if (test * first_line > 0)
        printf("(%lf, %lf) is inside\n", x, y);
    else
        printf("(%lf, %lf) is outside\n", x, y);
    if ((A * a + B * b + C) * first_line > 0)
        printf("(%lf, %lf) is inside\n", a, b);
    else
        printf("(%lf, %lf) is outside\n", a, b);
}
/*
y = ((y1 - y0) / (x1 - x0)) * (x - x0) + y0;
(x1 - x0) * y = (y1 - y0) * (x - x0) + (x1 - x0) * y0
(x1 - x0) * y = (y1 - y0) * x - (y1 - y0) * x0 + (x1 - x0) * y0
(x1 - x0) * y - (y1 - y0) * x + (y1 - y0) * x0 - (x1 - x0) * y0 = 0
B * y + A * x + C = 0
A = y0 - y1
B = x1 - x0
C = -A * x0 - B * y0
*/

