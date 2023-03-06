#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size = 0;

typedef struct emp
{
    /* data */
    char name[50];
    char department[50];
}eDetail;

typedef struct comp{
    //1 - 6
    float compA;
    float compB;
    float compC;
    float compD;
    float compE;
}kpiComp;

typedef struct kpi
{
    /* data */
    int idEmployee;
    eDetail empDetail;
    kpiComp components;
    //sum setiap komponen
    float kpiScore;

}KPI;

void inputData(KPI *empKpi)
{
    int n;
    printf("input data: ");
    scanf("%d", &n);
    for(int tc = 0; tc < n; tc++)
    {
        printf("id employee: "); 
        scanf("%d",&empKpi[size].idEmployee);
        getchar();

        printf("employee name: "); 
        scanf("%[^\n]",empKpi[size].empDetail.name);
        getchar();

        printf("employee department: ");
        scanf("%[^\n]", empKpi[size].empDetail.department);
        getchar();

        printf("Employee Component A: ");
        scanf("%f", &empKpi[size].components.compA);
        getchar();

        printf("Employee Component B: ");
        scanf("%f", &empKpi[size].components.compB);
        getchar();

        printf("Employee Component C: ");
        scanf("%f", &empKpi[size].components.compC);
        getchar();

        printf("Employee Component D: ");
        scanf("%f", &empKpi[size].components.compD);
        getchar();

        printf("Employee Component E: ");
        scanf("%f", &empKpi[size].components.compE);
        getchar();

        empKpi -> kpiScore = (
        empKpi -> components.compA +
        empKpi -> components.compB + 
        empKpi -> components.compC +
        empKpi -> components.compD +
        empKpi -> components.compE) / 5;
        
        size++;
    }
    
}

void printData(KPI *empKpi)
{
	for(int i = 0; i < size; i++)
    {
        printf("id employee: %d\n", empKpi[i].idEmployee);
        printf("employee name: %s\n", empKpi[i].empDetail.name);
        printf("employee department: %s\n", empKpi[i].empDetail.department);
        printf("score: %f\n", empKpi[i].kpiScore);
    }
    getchar();
    getchar();
}
void menu(){
    system("CLS");
    printf("1. Input Data\n");
    printf("2. Print Data\n");
    printf("0. exit\n");
}
int main(){
    KPI empKPI[10005];
    int inp = 1;
    while (inp != 0)
    {
        menu();
        scanf("%d",&inp);
        switch (inp)
        {
        case 1:
            inputData(empKPI);
            break;
        
        case 2:
            printData(empKPI);
            break;
        
        default:
            break;
        }
        /* code */
    }
    printf("THANK YOU");
    
}
