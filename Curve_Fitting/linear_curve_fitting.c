#include<stdio.h>
#include<math.h>

int main(){
    int n,i;
    double sum_X=0,sum_Y=0,sum_XY=0,sum_X2=0,a,b;
    printf("____________________________________________________________\n");
    printf("\tLinear Curve Fitting By Least Square Method\n");
    printf("____________________________________________________________\n\n");
    printf("Enter the number of data points:\t");
    scanf("%d",&n);
    double X[n],Y[n];
    printf("Enter the respective value of x and y\n");

    for(i=0;i<n;i++){
        printf("data %d:\n",i+1);
        printf("X:\t");
        scanf("%lf",&X[i]);
        printf("Y:\t");
        scanf("%lf",&Y[i]);
    }

    printf("The table of data you entered is:\n");
    printf("_____________________________________________________\n");
    printf("SN \t\t X\t\t\tY\n");
    printf("_____________________________________________________\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%lf\t\t%lf\n",i+1,X[i],Y[i]);
    }
    printf("_____________________________________________________\n");

    for(i=0;i<n;i++){
        sum_X+=X[i];
        sum_Y+=Y[i];
        sum_XY+=X[i]*Y[i];
        sum_X2+=X[i]*X[i];
    }
    b=(n*sum_XY-sum_X*sum_Y)/(n*sum_X2-sum_X*sum_X);
    a=(sum_Y-b*sum_X)/n;
    printf("\nThe required value of a and b are:\na=%0.8lf and b=%0.8lf",a,b);
    printf("\nThe best fitted line is:\ty=%0.8lf+%0.8lfx",a,b);
    return 0;
}