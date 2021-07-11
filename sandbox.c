#include <stdio.h>
#include <string.h>

/*typedef struct Books {
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} xyu;

*//* function declaration *//*
void printBook( struct Books *book );
int main( ) {

	xyu Book1;        *//* Declare Book1 of type Book *//*
	xyu Book2;        *//* Declare Book2 of type Book *//*

	*//* book 1 specification *//*
	strcpy( Book1.title, "C Programming");
	strcpy( Book1.author, "Nuha Ali");
	strcpy( Book1.subject, "C Programming Tutorial");
	Book1.book_id = 6495407;

	*//* book 2 specification *//*
	strcpy( Book2.title, "Telecom Billing");
	strcpy( Book2.author, "Zara Ali");
	strcpy( Book2.subject, "Telecom Billing Tutorial");
	Book2.book_id = 6495700;

	*//* print Book1 info by passing address of Book1 *//*
	printBook( &Book1 );

	*//* print Book2 info by passing address of Book2 *//*
	printBook( &Book2 );

	return 0;
}

void printBook( struct Books *book ) {

	printf( "Book title : %s\n", book->title);
	printf( "Book author : %s\n", book->author);
	printf( "Book subject : %s\n", book->subject);
	printf( "Book book_id : %d\n", book->book_id);
}*/
/*

struct person
{
	int age;
	char name[20];
};

int main(void)
{
	struct person kate = {31, "Kate"};
	struct person *p_kate = &kate;

	char * name = p_kate->name;
	int age = (*p_kate).age;

	printf("name = %s \t age = %d \n", name, age);

	// изменим элемент age в структуре
	kate.age = 32;
	printf("name = %s \t age = %d \n", kate.name, kate.age);
	return 0;
}
*/

/*
#include <stdio.h>

# define FLG_NONE	0b00000000
# define FLG_ONE	0b00000001
# define FLG_TWO	0b00000010
# define FLG_THREE	0b00000100
# define FLG_FOUR	0b00001000

int main()
{
	unsigned char	flags;

	flags = FLG_NONE;
	if (flags & FLG_ONE)
		printf("[-] FLG_ONE exist\n");
	else
		printf("[+] FLG_ONE not exist\n");

	flags = flags | FLG_ONE;
	if (flags & FLG_ONE)
		printf("[+] FLG_ONE exist\n");
	else
		printf("[-] FLG_ONE not exist\n");

	flags = flags | FLG_TWO;
	if ((flags & FLG_ONE) && (flags & FLG_TWO))
		printf("[+] FLG_ONE and FLG_TWO exist\n");
	else
		printf("[-] FLG_ONE or FLG_TWO not exist\n");

	flags = flags & (~FLG_TWO);
	if ((flags & FLG_ONE) && (flags & FLG_TWO))
		printf("[-] FLG_ONE and FLG_TWO exist\n");
	else
		printf("[+] FLG_ONE or FLG_TWO not exist\n");

	return (0);
}*/

int main ()
{

}