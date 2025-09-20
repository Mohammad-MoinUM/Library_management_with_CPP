#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Book {
	int book_id;
public:
	int pages;
	string book_name, author_name, book_type;
	bool available = true;
	Book (int book_id, int pages, string book_name, string author_name, string book_type) {
		this->book_id = book_id;
		this->pages = pages;
		this->book_name = book_name;
		this->author_name = author_name;
		this->book_type = book_type;
	}
	void toggle_available() {
		this->available = !(this->available);
	}
};

class User {
	int user_id;
	string password;
	bool logged_in = false;
public:
	string user_name;
	User (int user_id, string user_name, string password, bool logged_in = true) {
		this->user_id = user_id;
		this->user_name = user_name;
		this->password = password;
		this->logged_in = logged_in;
	}
};

class LibraryManagement {
	vector<Book> book_list = {};
	vector<User> user_list = {};
public:
	void add_book();
	void add_user();
	void display_book();
	void display_user();
	void search_book();
	void borrow_book();
	void return_book();
};

void LibraryManagement:: add_book() {
	system("cls");
	int book_id;
	int pages;
	string book_name, author_name, book_type;
	bool available = true;

	cout << "Enter book name : " ;
	cin >> book_name;
	cout << "Enter book author name : " ;
	cin >> author_name;
	cout << "Enter book type (action, adventure, horror) : " ;
	cin >> book_type;
	cout << "Enter book pages : " ;
	cin >> pages;
	cout << "Enter book id : " ;
	cin >> book_id;

	Book temp(book_id, pages, book_name, author_name, book_type);

	book_list.push_back(temp);
}

void LibraryManagement:: add_user() {
	system("cls");

	int user_id;
	string user_name;
	string password;

	cout << "Enter user name : " ;
	cin >> user_name;
	cout << "Enter user id : " ;
	cin >> user_id;
	cout << "Give a password : ";
	cin >> password;

	User temp(user_id, user_name, password, true);

	user_list.push_back(temp);
}

void LibraryManagement :: display_book() {
	system("cls");
	for (Book it : book_list) {
		cout << endl;
		cout << "Book name: " << it.book_name << endl;
		cout << "Book author: " << it.author_name << endl;
		cout << "Number of page: " << it.pages << endl;
		cout << "Book type: " << it.book_type << endl;
		cout << endl;
	}
}

void LibraryManagement :: display_user() {
	system("cls");
	for (User it : user_list) {
		cout << endl;
		cout << "User name: " << it.user_name << endl;
		cout << endl;
	}
}

void LibraryManagement :: search_book() {
	system("cls");
	string bname;
	
	cout << "Enter the book name you are searching: ";
	cin >> bname;

	for (Book it : book_list) {
		if (it.book_name == bname && it.available) {
			cout << "The book is available." << endl;
			return;
		} else if (it.book_name == bname && !it.available) {
			cout << "The book is not available at this moment." << endl;
			return;
		}
	}

	cout << "Sorry, we don't have the book in our collection." << endl;
}

void LibraryManagement :: borrow_book() {
	system("cls");
	string bname;
	
	cout << "Enter the book name you want to borrow: ";
	cin >> bname;

	for (Book it : book_list) {
		if (it.book_name == bname && it.available) {
			it.available = false;
			cout << "You borrowed the book." << endl;
			return;
		} else if (it.book_name == bname && !it.available) {
			cout << "Sorry, the book is not available at this moment." << endl;
			return;
		}
	}

	cout << "Sorry, we don't have the book in our collection." << endl;
}

int main () {

	cout<< "moin\n";
	cout<< "uddin\n";

	LibraryManagement library;
	int operation;

	while(operation != 7) {

		cout << endl;

		cout << "1.Add book" << endl;
		cout << "2.Display book" << endl;
		cout << "3.Add user" << endl;
		cout << "4.Display user" << endl;
		cout << "5.Search book" << endl;
		cout << "6.Borrow book" << endl;
		cout << "7.Exit" << endl;

		cout << endl;

		cout << "Enter your operation: ";
		cin >> operation;

		switch (operation) {
			case 1:
				library.add_book();
				break;
			case 2:
				library.display_book();
				break;
			case 3:
				library.add_user();
				break;
			case 4:
				library.display_user();
				break;
			case 5:
				library.search_book();
				break;
			case 6:
				library.borrow_book();
				break;
			case 7:
				return 0;
			default:
				cout << "Your input was wrong" << endl;
		}
	}

	return 0;
}