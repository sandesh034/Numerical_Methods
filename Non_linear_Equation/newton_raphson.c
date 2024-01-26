#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) 4*exp(-x)*sin(x)-1
#define df(x) 4*exp(-x)*(cos(x)-sin(x))

void main() {
    float x0, x1, f1, f0, df0, e;
    int iteration = 1, N;

    printf("Enter the value of initial guess:\t");
    scanf("%f", &x0);
    printf("Enter the value of maximum error:\t");
    scanf("%f", &e);
    printf("Enter the value of maximum iteration:\t");
    scanf("%d", &N);

    printf("_________________________________________________________________________\n");
    printf("Iteration\t x0\t\t f(x0)\t\t x1\t\t f(x1)\n");
    printf("_________________________________________________________________________\n");

    do {
        f0 = f(x0);
        df0 = df(x0);
        x1 = x0 - f0 / df0;
        f1 = f(x1);

        if (df0 == 0.0) {
            printf("Mathematical Error\n");
            exit(0);
        } else {
            printf("%d\t\t %0.8f\t %0.8f\t %0.8f\t %0.8f\n", iteration, x0, f0, x1, f1);
            x0 = x1;
            iteration = iteration + 1;

            if (iteration > N) {
                printf("The solution does not converge\n");
                break;
            }
        }
    } while (fabs(f1) > e);
    printf("_________________________________________________________________________\n");
    printf("The approximate real solution is:\t%0.8f\n", x1);

    return;
}
