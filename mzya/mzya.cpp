// mzya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<conio.h>
#include<stdio.h>

struct matrix
{
    int row;
    int col;
    int** matrix_elements;
};

extern "C"
{
   bool _cdecl Mul_Matrix(const matrix&, const matrix&, matrix&);
}

int main()
{
    system("chcp 1251");
    system("cls");

 
    matrix A;
    matrix B;
    matrix C;

    std::cout << "Введите количество строк первой матрицы: ";
    std::cin >> A.row;
    std::cout << "Введите количество столбцов первой матрицы: ";
    std::cin >> A.col;
    std::cout << "Введите количество строк второй матрицы: ";
    std::cin >> B.row;
    std::cout << "Введите количество столбцов второй матрицы: ";
    std::cin >> B.col;
    std::cout << "Введите элементы первой матрицы" << std::endl;

    C.row = A.row;
    C.col = B.col;

    A.matrix_elements = new int*[A.row];
    for (int i = 0; i < A.row; i++)
    {
        A.matrix_elements[i] = new int[A.col];
        for (int j = 0; j < A.col; j++)
        {
            std::cout << "a[" << i << "][" << j << "]= ";
            std::cin >> A.matrix_elements[i][j];
        }
    }
    std::cout << "Введите элементы второй матрицы" << std::endl;

    B.matrix_elements = new int* [B.row];
    for (int i = 0; i < B.row; i++)
    {
        B.matrix_elements[i] = new int[B.col];
        for (int j = 0; j < B.col; j++)
        {
            std::cout << "b[" << i << "][" << j << "]= ";
            std::cin >> B.matrix_elements[i][j];
        }
    }
    C.matrix_elements = new int* [C.row];
    for (int i = 0; i < A.row; i++)
    {
        C.matrix_elements[i] = new int[C.col];
        for (int j = 0; j < B.col; j++)
        {
            C.matrix_elements[i][j] = 0;
        }
    }

    bool mulIsExist =  Mul_Matrix(A, B, C); //    bool mulIsExist = A.col == B.row;

    if (mulIsExist)  // Если размерности матриц введны верно
    {
        std::cout << "Матрица произведения" << std::endl;
        for (int i = 0; i < A.row; i++)
        {
            for (int j = 0; j < B.col; j++)
                std::cout << C.matrix_elements[i][j] << " ";

            std::cout << std::endl;
        }
    }
    else // Иначе
    {
        std::cout << "Размерости матриц введены неверно" << std::endl;
    }

}