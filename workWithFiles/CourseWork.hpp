#include <fstream>
#include <iostream>
using namespace std;
#pragma once
namespace ext {
	struct Book {
		static const int BUFFER_SIZE = 20;
		int Id;
		char Title[BUFFER_SIZE];
		char Author[BUFFER_SIZE];
		float Price;
		int Quantity;
	};
	ostream& operator << (ostream& out, Book& book) {
		out << book.Id << " " << " " << book.Title << " " << book.Author << " " << book.Price << " " << book.Quantity << endl;
		return out;
	}
	istream& operator >> (istream& in, Book& book) {
		in >> book.Title >> book.Author >> book.Price >> book.Quantity;
		return in;
	}

	int findIndexReq(Book data[], int left, int right, char value[20]) {
		int middle = (left + right) / 2;
		if (strcmp(data[middle].Author, value) == 0) {
			return data[middle].Id;
		}
		if (strcmp(data[middle].Author, value) > 0) {
			return findIndexReq(data, left, middle - 1, value);
		}
		else {
			return findIndexReq(data, middle - 1, right, value);
		}
	}
	int binarySearch(Book array[], int size, char value[20]) {
		return findIndexReq(array, 0, size - 1, value);
	}
	void bubbleSort(Book arr[], int size) {
		Book temp = {};
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (strcmp(arr[j].Author, arr[j + 1].Author) > 0) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size - 1; i++) {
			if (strcmp(arr[i].Author, arr[i + 1].Author) == 0) {
				if (strcmp(arr[i].Title, arr[i + 1].Title) > 0) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}
}