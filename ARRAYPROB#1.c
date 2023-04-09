#include <stdio.h>
int A[3]={0}, i=0;
int B[3][3]={0}, r=0, c=0;
int C[3]={0};
char ans;
void COMPUTE(int a, int b);
void DISPLAY(int x, int y, int z);


int main(){
do{
    for (i = 0; i < 3; i++)
    {
        printf("Enter the value of array A [%d]: ", i);
        scanf("%d", &A[i]);
    }
    printf("\n");
    for(r=0; r<3; r++){
        for(c=0; c<3; c++){
            printf("Enter the value array of B [%d] [%d]: ", r, c);
            scanf("%d", &B[r][c]);
        }
    }
    COMPUTE(A[3], B[3][3]);
    DISPLAY(A[3], B[3][3], C[3]);

    printf("\nDo you wanna try again? (y/n): ");
    scanf(" %c", &ans);
}while (ans=='y' || ans=='Y');
}

void COMPUTE(int a, int b){
    C[0]=(A[0]*B[0][0])+(A[1]*B[0][1])+(A[2]*B[0][2]);
    C[1]=(A[0]*B[1][0])+(A[1]*B[1][1])+(A[2]*B[1][2]);
    C[2]=(A[0]*B[2][0])+(A[1]*B[2][1])+(A[2]*B[2][2]);
}


void DISPLAY(int x, int y, int z){
    printf("\n");
    printf("DISPLAYING THE ARRAY\n");
    for ( i = 0; i < 3; i++)
    {
        printf("The array A [%d] is: %d\n", i, A[i]);
    }
    printf("\n");
    for ( r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("The array B [%d] [%d] is: %d\n", r, c, B[r][c]);
        }
        printf("\n");
    }

    printf("\nThe answer of C[0] is: %d\n", C[0]);
    printf("The answer of C[1] is: %d\n", C[1]);
    printf("The answer of C[2] is: %d", C[2]);

}
