#include <string.h>
#include <stdio.h>

union Genre
{
    int id;
    char name[55];
    char description[105];
}newGenre, oldGenre;

struct Book
{
    int id;
    char title[55];
    char genre[55];
    int quantity;
    double price;
};

struct Connection
{

};

int main()
{
    Genre genre = {"Horror"};
    printf("Genre Detail\n");
    printf("======================\n");
    printf("Name: %s\n", genre.name);

    strcpy(genre.description, "This is a horror genre");
    printf("Description : %s\n", genre.description);

    return 0;
}