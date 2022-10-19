#include <stdio.h>


/*
    numOfString untuk menentukan panjang array string
    numOfCase untuk banyaknya kata yang ingin diubah
    stringChange untuk mengganti kata sesuai urutan array
*/

int main()
{
    int numOfString, numOfCase, stringChange;
    char word[205];

    scanf("%d %d", &numOfString, &numOfCase);
    scanf("%s", word);
    getchar();

    for(int i = 0; i < numOfCase; i++)
    {
        scanf("%d", &stringChange);
        /* Untuk pengecekan huruf jika huruf di array 0 adalah kapital maka akan
        diubah ke dalam huruf kecil.*/
        if('a' <= word[stringChange] && word[stringChange] <= 'z')
        {
            word[stringChange] = word[stringChange] + 'A' - 'a';
        }
         /* Untuk pengecekan huruf jika huruf di array 0 adalah huruf kecil maka akan
        diubah ke dalam huruf kapital.*/
        else
        {
            word[stringChange] = word[stringChange] + 'a' - 'A';
        }
    }
    printf("%s\n", word);
    return 0;
}