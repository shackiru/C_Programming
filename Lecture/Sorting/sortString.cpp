#include <stdio.h>
#include <string.h>

// void Swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void bubbleString(char arr[105][50], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(strcmp(arr[j], arr[j+1]) > 0)
            {
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main()
{
    char name[105][50] =
    {
        "ABRAHAM MAHAYANA SETIAWAN",
        "ALEXANDER IMMANUEL SAMOSIR",
        "ANDREAS LIUJAYA WIRANATA",
        "CAROLINE NATALIA AMRAN",
        "CATHERINE OLIVIA WINANDA",
        "DAVIN RAFFILIO",
        "DEXTER VALERIAN KRISNADHI",
        "DIANDRA PRAMESTI KINASIH",
        "EVOTIANUS",
        "FELIX GUSTINO TJUATJA",
        "FREDY SUNJAYA",
        "GRACE ADELINE KHARISMA",
        "GRISELLA MEIRISIA ZEGA",
        "HOSANNIA MICHAELA MARSINTA HARDIPUTRI",
        "HOWAN ANDERSON",
        "IGNES ANGELICA",
        "MICHAEL",
        "MUHAMMAD ARYA AQILAH FAUZAN",
        "PETER PRATAMA MULYADI",
        "RICHIE HARTONO",
        "SUPANDI SAPUTRA",
        "VALINA EVELYN PRANOTO",
        "VANECHKA RADJA WINATA",
        "AGNES RINAWATI NAULITA SIANTURI",
        "KEREN HOSANNA BIRILA",
        "STEPHANIE ANASTASIA MAKMUR",
        "NEISYA HOLLY SANTOSO",
        "NATHASYA RIZANDI",
        "ARI KUSUMADEWI",
        "JOELIARDO GERALD LEVIOTHNIEL",
        "SHAQUILLE DITAMA PUTRA",
        "MICHAEL SCUDERIA TANUDJAJA",
        "ARIYA GUNANANDA",
        "MATTHEW ALBERT SETIAWAN",
        "PUTU ARYASATYA DHARMA KENZHIE",
    };

    bubbleString(name, 35);
    for(int i = 0; i < 35; i++)
    {
        printf("%s\n", name[i]);
    }

    return 0;
}
