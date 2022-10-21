#include <stdio.h>
#include <string.h>

//struct Book
//{
//    int id = 1234;
//    char title[55] = "Genshin Impact";
//    char genre[55] = "Fantasy";
//    int quantity = 10;
//    double price = 19.3;
//}newBook;

struct Book
{
    int id;
    char title[55];
    char genre[55];
    int quantity;
    double price;
};

int main()
{
//    Book newBook = {1234, "Genshin Impact", "Fantasy", 10, 19.3};
	Book oldBook;
	oldBook.id = 1234;
	strcpy(oldBook.title, "Genshin Impact");
	strcpy(oldBook.genre, "Fantasy");
	oldBook.quantity = 10;
	oldBook.price = 19.3;

    printf("Book Detail\n");
    printf("==============\n");
    printf("ID : %d\n", oldBook.id);
    printf("Title : %s\n", oldBook.title);
    printf("Genre : %s\n", oldBook.genre);
    printf("Quantity : %d\n", oldBook.quantity);
    printf("Price : %0.1lf\n", oldBook.price);

    oldBook.quantity = 20;
    printf("\nNew Quantity : %d\n", oldBook.quantity);

    Book books[10];

    return 0;
}
