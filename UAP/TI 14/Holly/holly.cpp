#include<stdio.h>

struct movie
{
    char id[20];
    char name[50];
    int sHour;
    int sMinute;
    int eHour;
    int eMinute;
    int studio;
    int duration;
};

struct movie list[1000];
int data = 0;

void readFile()
{
    FILE *f = fopen("cinema.csv", "r");
    while(!(feof))
    {
        fscanf(f, "%[^,],%[^,],%d:%d,%d:%d,%d", list[data].id, list[data].name, &list[data].sHour, &list[data].sMinute, &list[data].eHour, &list[data].eMinute, &list[data].studio);
        int jam = list[data].eHour - list[data].sHour;
        int menit = list[data].eMinute - list[data].eMinute;
        list[data].duration = (jam*60) + menit;
        data++;
    }
    fclose(f);
}

void merge(int left, int mid, int right)
{
    int sLeft = mid - left+1;
    int sRi = right - mid;

    struct movie leftA[1000], rightA[1000];

    for(int i=0; i<sLeft; i++)
    {
        leftA[i] = list[left+i];
    }
    for(int i=0; i<sRi; i++)
    {
        rightA[i] = list[mid+i+1];
    }

    int p = 0;
    int q = 0;
    int r = left;

    while(p<sLeft && q<sRi)
    {
        if(leftA[p].duration <= rightA[q].duration)
        {
            list[r] = leftA[p];
            p++;
        }else{
            list[r] = rightA[q];
            q++;
        }
        r++;
    }

    while(p<sLeft)
    {
        list[r] = leftA[p];
        p++;
        r++;
    }
    while(q<sRi)
    {
        list[r] = rightA[q];
        q++;
        r++;
    }
}

void mergeSort(int left, int right)
{
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, left);
        merge(left, mid, right);
    }
}

void displayAll()
{
    mergeSort();
    for(int i=0; i<data; i++)
    {
        printf("| %-2d | %-7s | %-25s | %.2d:%-5.2d | %.2d:%-3.2d | %-4d- Minutes  | %5d |", i+1, list[i].id, list[i].name, list[i].sHour, list[i].sMinute, list[i].eHour, list[i].eMinute, list[i].duration, list[i].studio);
    }
}

void viewAll()
{
    if (data == 0)
    {
        printf("Oops. No Movie Available!\n");
        printf("Press Enter To Continue..."); getchar();
    }
    else{
        displayAll();
    }
}

void mainMenu()
{
    int input = 0;
    while(true)
    {
        printf("Hi, There!\n");
        printf("1. View All Movie\n");
        printf("2. Add New Movie\n");
        printf("3. Update Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Save and Exit\n");
        printf("Input [1-5]: ");
        scanf("%d", input);
        getchar();
        switch(input){
            case 1:
                viewAll();
                break;
            case 2:
                // addNew();
                break;
            case 3:
                // update();
                break;
            case 4: 
                // del();
                break;
            case 5: 
                // saveExit();
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
    }
}

int main()
{
    mainMenu();
    
    return 0;
}