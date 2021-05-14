#include <iostream>
#include<vector>	
#include<cmath>

using namespace std;

// Класс матриц
class Matrix {
private:
	int size;
	vector<vector<int>> matrix;
public:

	Matrix(int size = 1)
	{
		this->size = size;

		matrix.resize(size);

		for (auto& it : matrix)
		{
			it.resize(size);
		}
	}
	//деструктор
	~Matrix()
	{
		for (int i = 0; i < size; i++)
			matrix[i].clear();

		matrix.clear();
	}

	void ResizeMatrix(int dimension); //изменение размера
	
	void PrintMatrix(); // вывод матрицы в консоль

	int GetDetMatrix(vector<vector<int>> mat,int size_mat); // нахождение определителя матрицы
	int GetMatrixDim(); // Возвращает размерность матрицы

};
void Matrix::ResizeMatrix(int new_dimension)// после изменения размера матрица будет заполнена 0
{
	matrix.assign(new_dimension, vector<int>(new_dimension,0));
}

int Matrix::GetMatrixDim()
{
	return size;
}
void Matrix::PrintMatrix()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
float Matrix::GetDetMatrix(vector<vector<int>> mat, int size_mat)


int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix a =((1, 0, 0), (0, 1, 0), (0, 0, 1));

	a.PrintMatrix();

	a.GetDetMatrix(a, a.GetMatrixDim());

	return 0;

}

