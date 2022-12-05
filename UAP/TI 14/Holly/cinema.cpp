#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

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
    while(!feof(f))
    {
        fscanf(f, "%[^,],%[^,],%d:%d,%d:%d,%d\n", list[data].id, list[data].name, &list[data].sHour, &list[data].sMinute, &list[data].eHour, &list[data].eMinute, &list[data].studio);
        int jam = list[data].eHour - list[data].sHour;
        int menit = list[data].sMinute - list[data].eMinute;
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
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}

void displayAll()
{
    for(int i=0; i<data; i++)
    {
        printf("| %-2d | %-7s | %-25s | %.2d:%-5.2d | %.2d:%-3.2d | %-4d Minutes  | %-5d |\n", i+1, list[i].id, list[i].name, list[i].sHour, list[i].sMinute, list[i].eHour, list[i].eMinute, list[i].duration, list[i].studio);
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
    	mergeSort(0, data-1);
        displayAll();
    }
}

void addNew()
{
	char nama[50];
	int jamMulai;
	int menitMulai;
	int jamSelesai;
	int menitSelesai;
	int studio;
	
	int panjang =0;
	
	do{
		printf("Enter Movie Name [1-20 Characters]:" );
		scanf("%[^\n]", nama); getchar();
		panjang = strlen(nama);
		if(panjang<1 || panjang>20){
			printf("Movie Name Must Be Between 1-20 Characters!\n");
		}
	}while(panjang<1 || panjang>20);
	
	do{
		printf("Enter Movie Start Time [HH:MM]: ");
		scanf("%d:%d", &jamMulai, &menitMulai); getchar();
		if(jamMulai<0 || jamMulai>23 || menitMulai < 0 || menitMulai>59)
		{
			printf("Invalid Time Format!\n");
		}
		
	}while(jamMulai<0 || jamMulai>23 || menitMulai < 0 || menitMulai>59);
	
	do{
		printf("Enter Movie End Time [HH:MM]: ");
		scanf("%d:%d", &jamSelesai, &menitSelesai); getchar();
		if(jamSelesai<0 || jamSelesai>23 || menitSelesai<0 || menitSelesai>59 || jamSelesai<jamMulai || (jamSelesai == jamMulai && menitSelesai<menitMulai)){
			printf("Invalid Time Format!\n");
		}
	}while(jamSelesai<0 || jamSelesai>23 || menitSelesai<0 || menitSelesai>59 || jamSelesai<jamMulai || (jamSelesai == jamMulai && menitSelesai<menitMulai));
	
	do{
		printf("Enter Movie Studio [1-10]: ");
		scanf("%d", &studio); getchar();
		if(studio<1 || studio>10)
		{
			printf("Movie Studo Must Be Between 1-10!\n");
		}
	}while(studio<1 || studio>10);
	
	char id[20];
	sprintf(id, "MV%d%d%d", rand()%10, rand()%10, rand()%10);
	
	strcpy(list[data].name, nama);
	strcpy(list[data].id, id);
	list[data].sHour = jamMulai;
	list[data].sMinute = menitMulai;
	list[data].eHour = jamSelesai;
	list[data].eMinute = menitSelesai;
	list[data].studio = studio;
	
	int jam = jamSelesai - jamMulai;
	int menit = menitSelesai - menitMulai;
	int duration = (jam*60) + menit;
	list[data].duration = duration;
	
		data++;	
	printf("Movie Added Successfully!\n");
	printf("Press Enter To Continue..."); getchar();
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
        scanf("%d", &input);
        getchar();
        switch(input){
            case 1:
                viewAll();
                break;
            case 2:
                addNew();
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
	srand(time(0));
	readFile();
    mainMenu();
    return 0;
}
