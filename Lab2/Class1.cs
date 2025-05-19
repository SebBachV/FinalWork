using System;

public class Class1
{
	public Class1()
	{
# include <iostream>
# include <vector>
# include <string>

        using namespace std;

// Определение структуры "Книга"
struct Book
{
    string author;
    string title;
    int year;
    int pages;
};

// Функция для ввода массива структур
void inputBooks(vector<Book>& books, int count)
{
    for (int i = 0; i < count; i++)
    {
        Book book;
        cout << "Введите данные для книги " << i + 1 << " (автор, название, год издания, число страниц):\n";
        cin.ignore();
        getline(cin, book.author);
        getline(cin, book.title);
        cin >> book.year >> book.pages;
        books.push_back(book);
    }
}

// Функция для вывода массива структур
void printBooks(const vector<Book>& books)
{
    cout << "\nСписок книг:\n";
    for (const auto&book : books) {
        cout << "Автор: " << book.author << ", Название: " << book.title
             << ", Год издания: " << book.year << ", Страниц: " << book.pages << "\n";
    }
}

// Функция для подсчета книг заданного автора
int countBooksByAuthor(const vector<Book>& books, const string& author)
{
    int count = 0;
    for (const auto&book : books) {
        if (book.author == author)
        {
            count++;
        }
    }
    return count;
}

// Функция для поиска книги с наиболее поздним годом издания
Book findLatestBook(const vector<Book>& books)
{
    if (books.empty())
    {
        throw runtime_error("Список книг пуст.");
    }
    Book latest = books[0];
    for (const auto&book : books) {
        if (book.year > latest.year)
        {
            latest = book;
        }
    }
    return latest;
}

int main()
{
    int n;
    cout << "Введите количество книг: ";
    cin >> n;

    vector<Book> books;
    inputBooks(books, n);
    printBooks(books);

    string author;
    cout << "\nВведите имя автора для поиска его книг: ";
    cin.ignore();
    getline(cin, author);
    cout << "Количество книг автора " << author << ": " << countBooksByAuthor(books, author) << "\n";

    try
    {
        Book latestBook = findLatestBook(books);
        cout << "\nКнига с самым поздним годом издания:\n";
        cout << "Автор: " << latestBook.author << ", Название: " << latestBook.title
             << ", Год издания: " << latestBook.year << ", Страниц: " << latestBook.pages << "\n";
    }
    catch (const runtime_error&e) {
        cout << e.what() << "\n";
    }

    return 0;
    }

}
}
