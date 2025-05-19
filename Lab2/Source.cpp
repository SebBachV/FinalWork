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
    cout << "Введите количество книг: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        cout << "Книга " << i + 1 << ":\n";
        cout << "Издатель: ";
        cin >> books[i].author;
        cout << "Наименование: ";
        cin >> books[i].title;
        cout << "Год выпуска: ";
        cin >> books[i].year;
        cout << "Количество страниц: ";
        cin >> books[i].pages;
        cin.ignore(); 
    }
}

void outBooks(const Book books[], int count) {
    cout << "Список книг:\n";
    for (int i = 0; i < count; i++) {
        cout << "Автор: " << books[i].author << endl 
             << "Название: " << books[i].title << endl 
             << "Год издания: " << books[i].year << endl 
             << "Число страниц: " << books[i].pages << endl;
        
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
    cout << "\nВведите имя автора для поиска количества его книг: ";
    cin >> author;
    cout << "Количество книг автора " << author << ": " << countBooksAuthor(books, count, author) << endl;
    
    Book last = findLastBook(books, count);
    cout << "\nКнига с самым поздним годом издания:\n";
    cout << "Автор: " << last.author << ", Название: " << last.title
        << ", Год издания: " << last.year << ", Число страниц: " << last.pages << endl;

    return 0;
}