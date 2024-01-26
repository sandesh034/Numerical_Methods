#include<stdio.h>
#include<math.h>
#define f(x) x*sin(x)-1

void main(){
    float x0,x1,x2,f0,f1,f2,e;
    int iteration=1;
    input:
    printf("Enter the value of lower limit of initial guess:\t");
    scanf("%f",&x0);
    printf("Enter the value of upper limit of initial guess:\t");
    scanf("%f",&x1);
    printf("Enter the value of predefined error:\t\t\t");
    scanf("%f",&e);

    f0=f(x0);
    f1=f(x1);
    if(f0*f1>0){
        printf("Invalid initial guess\n\n");
        goto input;
    }
    else{
        printf("__________________________________________________________________________\n");
        printf("Iteration\t x0 \t\t x1 \t\t x2 \t\t f(x2)\n");
        printf("__________________________________________________________________________\n");

        do{
            x2=(x1+x0)/2;
            f2=f(x2);
            printf("%d\t\t%f\t%f\t%f\t%f\n",iteration,x0,x1,x2,f2);

            if(f0*f2<0.0){
                x1=x2;
                f1=f2;
            }
            else{
                x0=x2;
                f0=f2;
            }
            iteration=iteration+1;
        }while(fabs(f2)>e);  
         printf("__________________________________________________________________________\n");
         printf("The approximate real root is:\t%0.8f",x2);
    }
    return;
}