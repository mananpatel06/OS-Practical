#include <stdio.h>
int mat[10][6];

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mat[j][1] > mat[j + 1][1]) {
                for (int k = 0; k < 5; k++) {
                    swap(&mat[j][k], &mat[j + 1][k]);
                }
            }
        }
    }
}

void completionTime(int num, int mat[][6])
{
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2]; //0-> ID, 1-> AT, 2-> BT, 3->ET, 4->WT, 5-> TAT
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];
    
    
    for (int l = 1; l < num; l++) {
        for (int m = 1; m < num - l; m++) {
            if (mat[m][2] > mat[m + 1][2]) {
                for (int k = 0; k <3; k++) {
                    swap(&mat[m][k], &mat[m + 1][k]);
                }
            }
        }
    }
    // printf("\narrangeBt...\nProcess ID\tAT\tBT\tTAT\tWT\n");
    // for (int l = 0; l < num; l++) {
    //     printf("\n%d\t\t\t%d\t%d\t%d\t%d\n",mat[l][0],mat[l][1],mat[l][2],mat[l][5],mat[l][4]);
        
    // }
    for(int i=1; i<num;i++)
    {
        temp = mat[i - 1][3];
        mat[i][3] = temp + mat[i][2];
        mat[i][5] = mat[i][3] - mat[i][1];
        mat[i][4] = mat[i][5] - mat[i][2];
    }
    
    }


int main()
{
    int num;

printf("Enter number of Process: ");
scanf("%d",&num);

printf("...Enter the process ID...\n");
    for (int i = 0; i < num; i++) {
        printf("...Process %d...\n",i+1);
        printf("Enter Process Id: ");
        scanf("%d",&mat[i][0]);
        printf("Enter Arrival Time: ");
        scanf("%d",&mat[i][1]);
        printf("Enter Burst Time:: ");
        scanf("%d",&mat[i][2]);
    }

    arrangeArrival(num, mat);
    
    // printf("\narrangeArrival...\nProcess ID\tAT\tBT\tTAT\tWT\n");
    // for (int i = 0; i < num; i++) {
    //     printf("%d\t\t\t%d\t%d\t%d\t%d\n",mat[i][0],mat[i][1],mat[i][2],mat[i][5],mat[i][4]);
        
    // }
    completionTime(num, mat);
    
    printf("\nFinal Result...\nProcess ID\tAT\tBT\tTAT\tWT\n");
    
    for (int i = 0; i < num; i++) {
        printf("%d\t\t\t%d\t%d\t%d\t%d\n",mat[i][0],mat[i][1],mat[i][2],mat[i][5],mat[i][4]);
        
    }
    int tat=0,wt=0;
    for(int i=0;i<num;i++)
    {
        tat=tat+mat[i][5];
        wt=wt+mat[i][4];
    }
    float avgtat=(float)tat/num;
    float avgwt=(float)wt/num;
    printf("avg tat = %f\navg wt = %f",avgtat,avgwt);
    printf("\n-------Manan Patel--------");
}
