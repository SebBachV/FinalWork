#include <iostream>
#include <cstring>

using namespace std;

struct Book {
    string author;
    string title;
    int year1;
    int pages1;
};

void fillBooks(Book books[], int& count) {
    cout << "������� ���������� ����: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        cout << "����� " << i + 1 << ":\n";
        cout << "�����: ";
        cin >> books[i].author;
        cout << "��������: ";
        cin >> books[i].title;
        cout << "��� �������: ";
        cin >> books[i].year1;
        cout << "����� �������: ";
        cin >> books[i].pages1;
        cin.ignore(); 
    }
}

void outBooks(const Book books[], int count) {
    cout << "������ ����:\n";
    for (int i = 0; i < count; i++) {
        cout << "�����: " << books[i].author << endl 
             << "��������: " << books[i].title << endl 
             << "��� �������: " << books[i].year1 << endl 
             << "����� �������: " << books[i].pages1 << endl;
        
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
        if (books[i].year1 > latest.year1) {
            latest = books[i];
        }
    }
    return latest;
}

int main1() {
    const int Max_B = 100;
    Book books[Max_B];
    int count1;

    fillBooks(books, count1);
    outBooks(books, count1);

    
    string author;
    cout << "\n������� ��� ������ ��� ������ ���������� ��� ����: ";
    cin >> author;
    cout << "���������� ���� ������ " << author << ": " << countBooksAuthor(books, count1, author) << endl;
    
    Book last = findLastBook(books, count1);
    cout << "\n����� � ����� ������� ����� �������:\n";
    cout << "�����: " << last.author << ", ��������: " << last.title
        << ", ��� �������: " << last.year1 << ", ����� �������: " << last.pages1 << endl;

    return 0;
}