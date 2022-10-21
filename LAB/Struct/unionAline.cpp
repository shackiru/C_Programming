#include <stdio.h>
#include <string.h>
/* struct, union
book: id, title, genre, quantity, price
*/

//struct Book{
//	int id = 1234;
//	char title[55] = "Genshin";
//	char genre[55] = "Fantasy";
//	int quantity = 10;
//	double price = 19.3;
//};

union Genre{ // hanya bisa isi satu nilai awal
	char name[55];
	char description[105];
};

struct Book{
	int id;
	char title[55];
	char genre[55];
	int quantity;
	double price;
};

struct USB{
	int portNumber;
	char deviceName[55];
};

struct Network{
	char adapterName[55];
	bool connectedToInternet;
};

struct Connection{
	int type;
	union{
		struct USB usb; // type 1
		struct Network network; // type 2
	};
};

int main(){
//	Book newBook = {1234, "Genshin Impact", "Fantasy", 10, 19.4};
//	Book oldBook = {1234, "Genshin Impact", "Fantasy", 10, 19.4};
	struct Book newBook;
	newBook.id = 1234;
	strcpy(newBook.title, "Genshin Impact");
	strcpy(newBook.genre, "Fantasy");
	newBook.quantity = 10;
	newBook.price = 19.4;
	
	printf("Book Detail\n");
	printf("===========\n");
	printf("ID = %d\n", newBook.id);
	printf("Title = %s\n", newBook.title);
	printf("Genre = %s\n", newBook.genre);
	printf("Quantity = %d\n", newBook.quantity);
	printf("Price = %.1lf\n", newBook.price);
	
	newBook.quantity = 20;
	printf("\nNew Quantity: %d\n\n", newBook.quantity);
	
	Genre genre = { "Horror"};
	printf("Genre Detail\n");
	printf("============\n");
	printf("Name: %s\n", genre.name);
	
	strcpy(genre.description, "This is a horror genre");
	printf("Description: %s\n", genre.description);
	
	// kasi dlu nilai, print
	
	
	/*
	Connection
	- USB
		+ port int
		+ name char
	- Network
		+adapter name char
		+connectedtoInternet bool
	*/
	
	struct Connection newConnection;
	newConnection.type = 1;
	newConnection.usb.portNumber = 1;
	strcpy(newConnection.usb.deviceName, "Mouse");
	
	if(newConnection.type == 1){
		printf("Connected to USB\n");
		printf("================\n");
		printf("Port number: %d\n", newConnection.usb.portNumber);
		printf("Device name: %s\n", newConnection.usb.deviceName);
	}else if(newConnection.type == 2){
		printf("Connected to Network\n");
		printf("================\n");
		printf("Adapter name: %s\n", newConnection.network.adapterName);		
		
		newConnection.network.connectedToInternet == true ?
						printf("Connected to internet\n") :
						printf("Not connected to internet\n");
	}
	return 0;
}