#include <stdio.h>
#include <string.h>

struct Books {
	char  title;
	char  author;
	char  subject;
	int   book_id;
};

/* function declaration */
void printBook( struct Books book );

int main( ) {

	struct Books Book1;        /* Declare Book1 of type Book */
	struct Books Book2;        /* Declare Book2 of type Book */

	/* book 1 specification */
	Book1.title   = strdup( "C Programming");
	Book1.author = strdup(  "Nuha Ali");
	Book1.subject = strdup( , "C Programming Tutorial");
	Book1.book_id = 6495407;

	/* book 2 specification */
	Book2.title   = strdup("Telecom Billing");
	Book2.author  = strdup("Zara Ali");
	Book2.subject = strdup("Telecom Billing Tutorial");
	Book2.book_id = 6495700;

	/* print Book1 info */
	printBook( Book1 );

	/* Print Book2 info */
	printBook( Book2 );

	return 0;
}

void printBook( struct Books book ) {

	printf( "Book title : %s\n", book.title);
	printf( "Book author : %s\n", book.author);
	printf( "Book subject : %s\n", book.subject);
	printf( "Book book_id : %d\n", book.book_id);
}