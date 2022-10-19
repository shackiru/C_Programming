#include <stdio.h>
#include <ctype.h>

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
        if(isupper(word[stringChange]))
        {
            word[stringChange] = tolower(word[stringChange]);
        }
         /* Untuk pengecekan huruf jika huruf di array 0 adalah huruf kecil maka akan
        diubah ke dalam huruf kapital.*/
        else if(islower(word[stringChange]))
        {
            word[stringChange] = toupper(word[stringChange]);
        }
    }
    printf("%s\n", word);
    return 0;
}