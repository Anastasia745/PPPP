#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputMatr(int n, int m, int **matr)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matr[i][j];
}
void outputMatr(int n, int m, int** matr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << " ";
		cout << endl;
	}
}
void randMatr(int n, int m, int** matr)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = rand() % 10;
}
int** memory(int n, int m)
{
	int** M = new int* [n];
	for (int i = 0; i < n; i++)
		M[i] = new int[m];
	return M;
}
void clearMemory(int n, int** matr)
{
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
}

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	int row_1, column_1;
	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> row_1 >> column_1;
	} while (row_1 <= 0 || column_1 <= 0);

	int row_2, column_2;
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> row_2 >> column_2;
	} while (row_2 <= 0 || column_2 <= 0);

	int** matrix1 = memory(row_1, column_1);
	int** matrix2 = memory(row_2, column_2);

	int choice;
	do
	{
		cout << "Выберите способ заполнения матриц\n" << endl;
		cout << "1 - Вручную \n2 - Случайным образом\n";
		cin >> choice;
	} while (choice < 1 || choice > 2);
	switch (choice)
	{
	case 1:
		inputMatr(row_1, column_1, matrix1);
		inputMatr(row_2, column_2, matrix2);
		cout << "\nМатрица 1\n\n";
		outputMatr(row_1, column_1, matrix1);
		cout << "\nМатрица 2\n\n";
		outputMatr(row_2, column_2, matrix2);
		break;
	case 2:
		randMatr(row_1, column_1, matrix1);
		randMatr(row_2, column_2, matrix2);
		cout << "\nМатрица 1\n\n";
		outputMatr(row_1, column_1, matrix1);
		cout << "\nМатрица 2\n\n";
		outputMatr(row_2, column_2, matrix2);
		break;
	}

	int size = 2;
	while (size < row_1 || size < row_2 || size < column_1 || size < column_2)
		size *= 2;
	int** M1 = memory(size, size);
	int** M2 = memory(size, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			M1[i][j] = 0;
			M2[i][j] = 0;
		}
	}
	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < column_1; j++)
			M1[i][j] = matrix1[i][j];
	}
	for (int i = 0; i < row_2; i++)
	{
		for (int j = 0; j < column_2; j++)
			M2[i][j] = matrix2[i][j];
	}
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	outputMatr(size, size, M1);
	cout << "\nМатрица 2\n\n";
	outputMatr(size, size, M2);

	int** mat1 = memory(size / 2, size / 2);
	int** mat2 = memory(size / 2, size / 2);
	int** mat3 = memory(size / 2, size / 2);
	int** mat4 = memory(size / 2, size / 2);
	int** mat5 = memory(size / 2, size / 2);
	int** mat6 = memory(size / 2, size / 2);
	int** mat7 = memory(size / 2, size / 2);
	int** mat8 = memory(size / 2, size / 2);

	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			mat1[i][j] = M1[i][j];
			mat2[i][j] = M1[i][j + size / 2];
			mat3[i][j] = M1[i + size / 2][j];
			mat4[i][j] = M1[i + size / 2][j + size / 2];
			mat5[i][j] = M2[i][j];
			mat6[i][j] = M2[i][j + size / 2];
			mat7[i][j] = M2[i + size / 2][j];
			mat8[i][j] = M2[i + size / 2][j + size / 2];
		}
	}

	int** inter_matr1 = memory(size / 2, size / 2);
	int** inter_matr2 = memory(size / 2, size / 2);
	int** inter_matr3 = memory(size / 2, size / 2);
	int** inter_matr4 = memory(size / 2, size / 2);
	int** inter_matr5 = memory(size / 2, size / 2);
	int** inter_matr6 = memory(size / 2, size / 2);
	int** inter_matr7 = memory(size / 2, size / 2);
	int** inter_matr8 = memory(size / 2, size / 2);

	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			inter_matr1[i][j] = inter_matr2[i][j] = inter_matr3[i][j] = inter_matr4[i][j] = inter_matr5[i][j] = inter_matr6[i][j] = inter_matr7[i][j] = 0;
			for (int z = 0; z < size / 2; z++)
			{
				inter_matr1[i][j] += (mat1[i][z] + mat4[i][z]) * (mat5[z][j] + mat8[z][j]);
				inter_matr2[i][j] += (mat3[i][z] + mat4[i][z]) * mat5[z][j];
				inter_matr3[i][j] += mat1[i][z] * (mat6[z][j] - mat8[z][j]);
				inter_matr4[i][j] += mat4[i][z] * (mat7[z][j] - mat5[z][j]);
				inter_matr5[i][j] += (mat1[i][z] + mat2[i][z]) * mat8[z][j];
				inter_matr6[i][j] += (mat3[i][z] - mat1[i][z]) * (mat5[z][j] + mat6[z][j]);
				inter_matr7[i][j] += (mat2[i][z] - mat4[i][z]) * (mat7[z][j] + mat8[z][j]);
			}
		}
	}

	int** add_matr1 = memory(size / 2, size / 2);
	int** add_matr2 = memory(size / 2, size / 2);
	int** add_matr3 = memory(size / 2, size / 2);
	int** add_matr4 = memory(size / 2, size / 2);

	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			add_matr1[i][j] = inter_matr1[i][j] + inter_matr4[i][j] - inter_matr5[i][j] + inter_matr7[i][j];
			add_matr2[i][j] = inter_matr3[i][j] + inter_matr5[i][j];
			add_matr3[i][j] = inter_matr2[i][j] + inter_matr4[i][j];
			add_matr4[i][j] = inter_matr1[i][j] - inter_matr2[i][j] + inter_matr3[i][j] + inter_matr6[i][j];
		}
	}
	
	int** RES = memory(size, size);

	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			RES[i][j] = add_matr1[i][j];
			RES[i][j + size / 2] = add_matr2[i][j];
			RES[i + size / 2][j] = add_matr3[i][j];
			RES[i + size / 2][j + size / 2] = add_matr4[i][j];
		}
	}

	int x = 0, align_row = 100, align_column = 100;
	for (int i = 0; i < size; i++)
	{
		x = 0;
		for (int j = 0; j < size; j++)
		{
			if (RES[i][j] != 0)
			{
				x++;
				align_row = 100;
				align_column = 100;
			}
		}
		if (x == 0 && i < align_row)
			align_row = i;
		if (x == 0 && i < align_column)
			align_column = i;
	}
	
	int** ALIGN_MATR = memory(align_row, align_column);
	for (int i = 0; i < align_row; i++)
	{
		for (int j = 0; j < align_column; j++)
			ALIGN_MATR[i][j] = RES[i][j];
	}

	cout << "\nРезультирующая матрица\n\n";
	outputMatr(align_row, align_column, ALIGN_MATR);
	system("pause");

	clearMemory(row_1, matrix1);
	clearMemory(row_2, matrix2);
	clearMemory(size, M1);
	clearMemory(size, M2);
	clearMemory(size, RES);
	clearMemory(size / 2, ALIGN_MATR);
	clearMemory(size / 2, mat1);
	clearMemory(size / 2, mat2);
	clearMemory(size / 2, mat3);
	clearMemory(size / 2, mat4);
	clearMemory(size / 2, mat5);
	clearMemory(size / 2, mat6);
	clearMemory(size / 2, mat7);
	clearMemory(size / 2, mat8);
	clearMemory(size / 2, add_matr1);
	clearMemory(size / 2, add_matr2);
	clearMemory(size / 2, add_matr3);
	clearMemory(size / 2, add_matr4);
	clearMemory(size / 2, inter_matr1);
	clearMemory(size / 2, inter_matr2);
	clearMemory(size / 2, inter_matr3);
	clearMemory(size / 2, inter_matr4);
	clearMemory(size / 2, inter_matr5);
	clearMemory(size / 2, inter_matr6);
	clearMemory(size / 2, inter_matr7);
}