#include <iostream>
#include <fstream>
#include <string>
#include "CourseWork.hpp"
using namespace std;
using namespace ext;
Book book = {};
ifstream input;
ofstream output;
int getSize() {
	int currentSize;
	input.open("books.bin", istream::ate | istream::binary | istream::in);
	currentSize = (input.tellg() / sizeof(Book));
	input.close();
	return currentSize;
}
void ArrayOutput(Book arrayOfBooks[], int currentSize) {
	for (int i = 0; i < currentSize; ++i) {
		cout << arrayOfBooks[i] << endl;
	}
}
Book* getArray() {
	int currentSize = 0;
	input.open("books.bin", istream::ate | istream::in | istream::binary);
	currentSize = (input.tellg() / sizeof(Book));
	Book* arrayOfBooks = new Book[currentSize]{};
	input.seekg(0, ios_base::beg);
	for (int i = 0; i < currentSize; i++) {
		input.read(reinterpret_cast<char*>(&arrayOfBooks[i]), sizeof(Book));
	}
	input.close();
	return arrayOfBooks;
}
void arraySort() {
	int size = getSize();
	Book* array = new Book[size];
	array = getArray();
	cout << "Current (unsorted) array: " << endl;
	ArrayOutput(array, size);
	cout << endl;
	bubbleSort(array, size);
	cout << "Sorted array: " << endl;
	ArrayOutput(array, size);
}
void createBook() {
	int currentSize = 0;
	cout << "Enter parameters of your book: " << endl;
	cin >> book;
	input.open("books.bin", istream::app | istream::binary);
	input.seekg(0, ios_base::end);
	currentSize = (input.tellg() / sizeof(Book) + 1);
	book.Id = currentSize;
	input.close();
	output.open("books.bin", istream::app | istream::binary);
	output.seekp(0, ios_base::end);
	output.write(reinterpret_cast<char*>(&book), sizeof(Book));
	output.close();
}
void redact() {
	cout << "Enter id of a book which you would like to redact: " << endl;
	cin >> book.Id;
	cout << "Enter new values: " << endl;
	cin >> book;
	int Size = getSize();
	Book* array = new Book[getSize()];
	array = getArray();
	array[book.Id - 1] = book;
	output.open("books.bin", istream::binary | istream::out);
	for (int i = 0; i < Size; i++) {
		output.write(reinterpret_cast<char*>(&array[i]), sizeof(Book));
	}
	output.close();
}
void getIdByAuthor() {
	int Size = getSize();
	char input[20] = {};
	cout << "Input author's name: " << endl;
	cin >> input;
	Book* array = new Book[Size];
	array = getArray();
	bubbleSort(array, getSize());
	cout << "Unique ID of your book is: "<< binarySearch(array, Size, input) << endl;

}
void statistics() {
	int currentSize = 0, overallCost = 0, overallQuanity = 0;
	currentSize = getSize();
	Book* recivedArray = new Book[currentSize];
	recivedArray = getArray();
	for (int i = 0; i < currentSize; i++) {
		overallCost += recivedArray[i].Price;
		overallQuanity += recivedArray[i].Quantity;
	}
	cout << "Overall cost of books: " << overallCost << ", number of'em: " << overallQuanity << endl;
}

int main() {
	createBook();
	cout << endl;
	ArrayOutput(getArray(), getSize());
	redact();
	cout << endl;
	ArrayOutput(getArray(), getSize());
	cout << endl;
	arraySort();
	cout << endl;
	getIdByAuthor();
	cout << endl;
	statistics();
}