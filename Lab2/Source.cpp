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
    cout << "Введите количество книг: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        cout << "Книга " << i + 1 << ":\n";
        cout << "Автор: ";
        cin >> books[i].author;
        cout << "Название: ";
        cin >> books[i].title;
        cout << "Год издания: ";
        cin >> books[i].year1;
        cout << "Число страниц: ";
        cin >> books[i].pages1;
        cin.ignore(); 
    }
}

void outBooks(const Book books[], int count) {
    cout << "Список книг:\n";
    for (int i = 0; i < count; i++) {
        cout << "Автор: " << books[i].author << endl 
             << "Название: " << books[i].title << endl 
             << "Год издания: " << books[i].year1 << endl 
             << "Число страниц: " << books[i].pages1 << endl;
        
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
    cout << "\nВведите имя автора для поиска количества его книг: ";
    cin >> author;
    cout << "Количество книг автора " << author << ": " << countBooksAuthor(books, count1, author) << endl;
    
    Book last = findLastBook(books, count1);
    cout << "\nКнига с самым поздним годом издания:\n";
    cout << "Автор: " << last.author << ", Название: " << last.title
        << ", Год издания: " << last.year1 << ", Число страниц: " << last.pages1 << endl;

    return 0;
}