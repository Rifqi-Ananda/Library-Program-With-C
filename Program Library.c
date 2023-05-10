#include <stdio.h>

// a function adding a new book.
int enroll_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *book_length);

// a function shoinwg the information of all books in library
int display_all(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length);

// a function showing the information of the book by searching
int compare(char *str1, char *str2);                          // checking the same of characters for searching.
int search_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length);
int search_name(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length);
int search_writer(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length);
int search_publisher(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length);

// a function borrowing a book.
int borrow_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length);

// a function returning a book
int return_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length);


int main()
{
	char book_name[100][100];
	char book_writer[100][100];
	char book_publisher[100][100];
	int commander = 0;                                 // a variable for user's command.
	int book_length = 0;
	int borrow[100] = { 0 };

	printf("This is library management program.\n");
	printf("1. Display all books in library \n2. Search \n3. Borrow \n4. Return \n5. Enroll a new book \n"); 
	printf("Please, type the command you want : ");

	while (1)
	{
		if (scanf_s("%d", &commander) == 0) getchar();                    // if an user enter character and 
		                                                                  // there is not this statement, an infinite loop will occur.
		switch (commander)
		{
		case 1:
			display_all(book_name, book_writer, book_publisher, borrow, &book_length);
			break;
		case 2:
			search_book(book_name, book_writer, book_publisher, borrow, &book_length);
			break;
		case 3:
			borrow_book(book_name, book_writer, book_publisher, borrow, &book_length);
			break;
		case 4:
			return_book(book_name, book_writer, book_publisher, borrow, &book_length);
			break;
		case 5:
			enroll_book(book_name, book_writer, book_publisher, &book_length);
			break;
		default:
			printf("\nYou put the wrong command. Please try again.\n");
			break;
		}

		printf("\n1. Display all books in library \n2. Search \n3. Borrow \n4. Return \n5. Enroll a new book \n");
		printf("Please, type the command you want : ");
		

	}

	return 0;
}

int enroll_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *book_length)
{
	printf("Please enter the name of the book which you want to enroll : ");
	scanf_s("%99s", book_name[*book_length], 100);

	printf("Please enter the writer of the book which you want to enroll : ");
	scanf_s("%99s", book_writer[*book_length], 100);

	printf("Please enter the publisher of the book which you want to enroll : ");
	scanf_s("%99s", book_publisher[*book_length], 100);
	
	printf("The book is enrolled in library system. \n");

	(*book_length)++;

	return 0;
}

int display_all(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length)
{
	for (int i = 0; i < *book_length; i++)
	{
		printf("\nNo. %d\n", i);
		printf("The name of book : %s\n", book_name[i]);
		printf("The writer of book : %s\n", book_writer[i]);
		printf("The publisher of book : %s\n", book_publisher[i]);
		if (borrow[i] == 0) printf("This book is available to borrow.\n");
		else if (borrow[i] == 1) printf("This book is borrowed.\n");
	}

	return 0;
}

int compare(char *str1, char *str2)                 // checking character 
{
	int same_count = 0;
	
	while (*str1)
	{
		if (*str1 == *str2) ++same_count;

		str1++;
		str2++;
	}

	if (same_count > 1) return same_count;         // if there are same characters more than two, I will show the information to user.
	else return 0;
}

int search_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length)
{
	int search_command = 0;
	

	printf("\nHow do you want to search the information of a book?\n");
	printf("1. Display all books in library\n2. Search by name \n3. Search by writer \n4. Search by publisher\n");
	printf("Please type the command you want : ");

	
	if (scanf_s("%d", &search_command) == 0) getchar();

	switch(search_command)
	{
	case 1:
		display_all(book_name, book_writer, book_publisher, borrow, book_length);
		break;
	case 2:
		search_name(book_name, book_writer, book_publisher, borrow, book_length);
		break;
	case 3:
		search_writer(book_name, book_writer, book_publisher, borrow, book_length);
		break;
	case 4:
		search_publisher(book_name, book_writer, book_publisher, borrow, book_length);
		break;
	default:
		printf("\nYou put the wrong command. Please try again.\n");
		search_book(book_name, book_writer, book_publisher, borrow, book_length);
		break;
	}
	
	return 0;

}

int search_name(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length)
{
	char user_search[100];
	printf("Please enter the name of the book which you want to search : ");
	scanf_s("%99s", user_search, 100);

	int count = 0;

	for (int i = 0; i < *book_length; i++)
	{
		if (compare(book_name[i], user_search) > 1)
		{
			count++;
			printf("\nNo. %d\n", i);
			printf("The name of book : %s\n", book_name[i]);
			printf("The writer of book : %s\n", book_writer[i]);
			printf("The publisher of book : %s\n", book_publisher[i]);
			if (borrow[i] == 0) printf("This book is available to borrow.\n");
			else if (borrow[i] == 1) printf("This book is borrowed.\n");
		}
	}

	if (count == 0)
	{
		printf("The book which you type is not searched in the library.\n");
		printf("If you want to search by name again, Press 1.\n");
		printf("If not, Press 2.");
		scanf_s("%d", &count);
		if (count == 1) search_name(book_name, book_writer, book_publisher, borrow, book_length);
		if (count == 2) return 0;
	}

	return 0;
}

int search_writer(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length)
{
	char user_search[100];
	printf("Please enter the writer of the book which you want to search : ");
	scanf_s("%99s", user_search, 100);

	int count = 0;

	for (int i = 0; i < *book_length; i++)
	{
		if (compare(book_writer[i], user_search) > 1)
		{
			count++;
			printf("\nNo. %d\n", i);
			printf("The name of book : %s\n", book_name[i]);
			printf("The writer of book : %s\n", book_writer[i]);
			printf("The publisher of book : %s\n", book_publisher[i]);
			if (borrow[i] == 0) printf("This book is available to borrow.\n");
			else if (borrow[i] == 1) printf("This book is borrowed.\n");
		}
	}

	if (count == 0)
	{
		printf("The writer you type is not searched in the library.\n");
		printf("If you want to search by writer again, Press 1.\n");
		printf("If not, Press 2.");
		scanf_s("%d", &count);
		if (count == 1) search_writer(book_name, book_writer, book_publisher, borrow, book_length);
		if (count == 2) return 0;
	}

	return 0;
}

int search_publisher(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length)
{
	char user_search[100];
	printf("Please enter the writer of the book which you want to search : ");
	scanf_s("%99s", user_search, 100);

	int count = 0;

	for (int i = 0; i < *book_length; i++)
	{
		if (compare(book_publisher[i], user_search) > 1)
		{
			count++;
			printf("\nNo. %d\n", i);
			printf("The name of book : %s\n", book_name[i]);
			printf("The writer of book : %s\n", book_writer[i]);
			printf("The publisher of book : %s\n", book_publisher[i]);
			if (borrow[i] == 0) printf("This book is available to borrow.\n");
			else if (borrow[i] == 1) printf("This book is borrowed.\n");
		}
	}

	if (count == 0)
	{
		printf("The publisher you type is not searched in the library.\n");
		printf("If you want to search by publisher again, Press 1.\n");
		printf("If not, Press 2.");
		scanf_s("%d", &count);
		if (count == 1) search_publisher(book_name, book_writer, book_publisher, borrow, book_length);
		if (count == 2) return 0;
	}

	return 0;
}

int borrow_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length)
{
	int user_borrow = 0;

	search_book(book_name, book_writer, book_publisher, borrow, book_length);

	printf("\nIf you want to borrow a book, please enter the 'NO.' number of the book. : ");
	
	scanf_s("%d", &user_borrow);
	

	if (borrow[user_borrow] == 1)
	{
		printf("Sorry. The book is already borrowed.\n");
		printf("\nIf you want to borrow other books, Please enter '1'\nif not, please enter '2' : ");
		scanf_s("%d", &user_borrow);

		if (user_borrow == 1) borrow_book(book_name, book_writer, book_publisher, borrow, book_length);
		else if (user_borrow == 2) return 0;
	}
	else
	{
		borrow[user_borrow] = 1;
		printf("The book is borrowed now. Thank you!\n");
		return 0;
	}

	return 0;

}

int return_book(char(*book_name)[100], char(*book_writer)[100], char(*book_publisher)[100], int *borrow, int *book_length)
{
	int user_return = 0;

	search_book(book_name, book_writer, book_publisher, borrow, book_length);

	printf("\nIf you want to return a book, please enter the 'NO.' number of the book. : ");

	scanf_s("%d", &user_return);


	if (borrow[user_return] == 0)
	{
		printf("Sorry. The book is not borrowed.\n");
		printf("\nIf you want to return other books, Please enter '1'\nif not, please enter '2' : ");
		scanf_s("%d", &user_return);

		if (user_return == 1) return_book(book_name, book_writer, book_publisher, borrow, book_length);
		else if (user_return == 2) return 0;
	}
	else
	{
		borrow[user_return] = 0;
		printf("The book is returned now. Thank you!\n");
		return 0;
	}

	return 0;

}