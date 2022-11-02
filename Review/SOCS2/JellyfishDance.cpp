#include <stdio.h>
/* Jellyfish Dance, jadi pertama terdapat 5 case yaitu jumlah penonton (2 1 5 9 7) perharinya
lalu terdapat 4 case mulai dari 1 1 (1-1) berarti untuk mengecek penonton dari hari pertama
ke pertama, lalu ada 1-3 untuk melihat jumlah penonton dari hari ke 1-3*/

int main()
{
    int inputCase, numOfCase;
    int startDate, endDate;
    int total = 0;

    scanf("%d", &inputCase);

    int views[inputCase];
    int viewsPerDay[100];

    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%d", &views[tc]);
    }

    scanf("%d", &numOfCase);
    for(int i = 0; i < numOfCase; i++)
    {
        scanf("%d %d", &startDate, &endDate);
        for(int j = startDate; j <= endDate; j++)
        /*(<=) misal rentang waktu 1 - 3 maka views 
        di j akan menambahkan views dari array ke 0 - 2*/
        {
            total = total + views[j - 1];
        }
        viewsPerDay[i] = total;
        total = 0;
    }

    for(int i = 0; i < numOfCase; i++)
    {
        printf("Case #%d: %d\n", i + 1, viewsPerDay[i]);
    }
    

    return 0;
}
