#include <iostream>
#include <cstring>

using namespace std;

struct Book {
    string author;
    string title;
    int year;
    int pages;
};

void fillBooks(Book books[], int& count) {
    cout << "������� ���������� ����: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        cout << "����� " << i + 1 << ":\n";
        cout << "��������: ";
        cin >> books[i].author;
        cout << "������������: ";
        cin >> books[i].title;
        cout << "��� �������: ";
        cin >> books[i].year;
        cout << "���������� �������: ";
        cin >> books[i].pages;
        cin.ignore(); 
    }
}

void outBooks(const Book books[], int count) {
    cout << "������ ����:\n";
    for (int i = 0; i < count; i++) {
        cout << "�����: " << books[i].author << endl 
             << "��������: " << books[i].title << endl 
             << "��� �������: " << books[i].year << endl 
             << "����� �������: " << books[i].pages << endl;
        
    }
}

int countBooksAuthor(const Book books[], int count, string author) {
    int authorCount = 0;
    for (int i = 0; i < count; i++) {
        if (books[i].author  == author) {
            authorCount++;
        }
    }
    return authorCount;
}

Book findLastBook(const Book books[], int count) {
    Book latest = books[0];
    for (int i = 1; i < count; i++) {
        if (books[i].year > latest.year) {
            latest = books[i];
        }
    }
    return latest;
}

int main1() {
    const int Max_B = 100;
    Book books[Max_B];
    int count;

    fillBooks(books, count);
    outBooks(books, count);

    
    string author;
    cout << "\n������� ��� ������ ��� ������ ���������� ��� ����: ";
    cin >> author;
    cout << "���������� ���� ������ " << author << ": " << countBooksAuthor(books, count, author) << endl;
    
    Book last = findLastBook(books, count);
    cout << "\n����� � ����� ������� ����� �������:\n";
    cout << "�����: " << last.author << ", ��������: " << last.title
        << ", ��� �������: " << last.year << ", ����� �������: " << last.pages << endl;

    return 0;
}