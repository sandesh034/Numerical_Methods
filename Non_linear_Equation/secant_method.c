#include<stdio.h>
#include<math.h>

#define f(x) x*log10(x)-1.2

int main(){
    float x0,x1,x2,f0,f1,f2,e;
    int i=1,N;
    printf("***********************************************************************\n");
    printf("*                           Secant Method                             *\n");
    printf("***********************************************************************\n");
    printf("Enter the initial guess x0 and x1:\n");
    scanf("%f%f",&x0,&x1);
    printf("Enter the value of maximum iteration:\t");
    scanf("%d",&N);
    printf("Enter the value of predefined error :\t");
    scanf("%f",&e);
    printf("_________________________________________________________________________\n");
    printf("Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("_________________________________________________________________________\n");

    do{
        f0=f(x0);
        f1=f(x1);
        if(f1==f0){
            printf("Mathematical Error!!!\n");
            break;
        }
        else{
            x2=x1-((x1-x0)*f1)/(f1-f0);
            f2=f(x2); 
            printf("%d\t\t%f\t%f\t%f\t%f\n",i,x0,x1,x2,f2);
            x0=x1;
            x1=x2;
            if(i>N){
                printf("The solution does not converges\n");
            }
            i++;
        }
    }while(fabs(f2)>e);
    printf("_________________________________________________________________________\n");
    printf("The approximate real solution of f(x) is:\t%0.8f",x2);
    return 0;
}