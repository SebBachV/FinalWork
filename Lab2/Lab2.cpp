#include <iostream>
#define _USE_MATH_DEFINES 
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

//среднее значение
double SRzn(int* arr, int size) {
   
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

//поиск максимального элемента 
int MaxZn(int* arr, int size) {
   
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

//Функция вставки числа в n позицию
void inZero(int*& arr, int& size, int pos, int a) {
    
    int* newArr = new int[size + 1];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == pos) {
            newArr[i] = a;
        }
        else {
            newArr[i] = arr[j++];            
        }        
    }

    delete[] arr;
    arr = newArr;
    size++;
}

//вставка нуля
void VZero(int*& arr, int& size) {
    int* newArr = new int[size];
    for (int i = 0; i < size + 1; i++) {
        newArr[i] = arr[i];        
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (newArr[i] > 0) {
            inZero(newArr, size, 1 + i, 0);

        }
    }    
    delete[] arr;
    arr = newArr;
}



int main()
{
    system("cls");
    setlocale(LC_ALL, "Russian");

    int N, pos;
    cout << "Введите размер массива: ";
    cin >> N;

    int* X = new int[N];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
        
    

    double SredZnach = SRzn(X, N);
    int maxZnach = MaxZn(X, N);
    VZero(X, N);
    double SrZero = SRzn(X, N);

    cout << "Среднее арифметическое до вставки: " << SredZnach << endl;
    cout << "Максимальный элемент: " << maxZnach << endl;
    cout << "Среднее арифметическое после вставки: " << SrZero << endl;

    cout << "Измененный массив: ";
    for (int i = 0; i < N; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    delete[] X;
    return 0;
}



