#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j,k;
    float ratio,sum=0;
    printf("***********************************************\n");
    printf("*           Gauss Elimination Method          *\n");
    printf("***********************************************\n\n");

    printf("Enter the size of matrix i.e. number of unknowns\n");
    scanf("%d",&n);
    float a[n][n+1], x[n];
    printf("Enter the elements of augmented matrix [A:C]\n");
    

    /* Reading Input*/
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            printf("a[%d][%d]= ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }

    for(i=0;i<n;i++){
        if(a[i][i]==0){
            printf("Mathematical Error !!!.  Gauss Elimination method can't be applied\n");
            exit(0);
        }
    }

/* Forward Elimination*/
  for(i=0; i<n-1; i++) {
    for(j=i+1; j<n; j++) {
        ratio = a[j][i] / a[i][i];
        for(k=0; k<=n; k++) {
            a[j][k] -= ratio * a[i][k];
        }
    }
}

    /*Backward substitution */
    if(a[n-1][n-1]==0 && a[n-1][n]==0){
        printf("The system is consistent and it has infinite solution\n");
    }
    else if(a[n-1][n-1]==0 && a[n-1][n]!=0){
        printf("The system is inconsistent and it has no solution\n");
    }
    else{
       x[n-1]=a[n-1][n]/a[n-1][n-1];
       for(i=n-2;i>=0;i--){
        sum=0;
        for(j=i+1;j<n;j++){
            sum=sum+a[i][j]*x[j];
        }
        x[i]=(a[i][n]-sum)/a[i][i];
       }
        /* printing the solution*/
        printf("\n\nThe system is consistent and it has unique solution\n");
        for(i=0;i<n;i++){
            printf("x[%d]=%0.6f\n",i+1,x[i]);
        }
    }

    return 0;
}