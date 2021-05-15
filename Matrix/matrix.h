#pragma once
#include <iostream>
#include<vector>	
#include<cmath>

using namespace std;

// ����� ������
class Matrix {
private:
	int size;
	vector<vector<int>> matrix;
public:
	Matrix(vector<vector<int>> init_vec)
	{
		matrix.assign(init_vec.size(), vector<int>(init_vec.size(), 0));

		size = init_vec.size();

		for (size_t i = 0; i < init_vec.size(); i++)
		{
			for (size_t j = 0; j < init_vec.size(); j++)
			{
				matrix[i][j] = init_vec[i][j];
			}
		}
	}
	Matrix() {}

	//�����������
	Matrix(int size)
	{
		this->size = size;

		matrix.resize(size);

		for (auto& it : matrix)
		{
			it.resize(size);
		}
	}
	//����������
	~Matrix()
	{
		for (int i = 0; i < size; i++)
			matrix[i].clear();

		matrix.clear();
	}

	void ResizeMatrix(int dimension); //��������� �������

	void PrintMatrix(); // ����� ������� � �������

	double GetDetMatrix(vector<vector<int>> ob, int n); // ���������� ������������ �������
	int GetMatrixDim()const; // ���������� ����������� �������
	vector<vector<int>> GetMatrix()const; // ���������� ������� �������

};
void Matrix::ResizeMatrix(int new_dimension)// ����� ��������� ������� ������� ����� ��������� 0
{
	if (new_dimension > size)matrix.assign(new_dimension, vector<int>(new_dimension, 0)); // ���� ����� ������ ������ �� ������� ��������� ��� ������ � ������� ������, ����� ����� ��������� �������
	else { // ����� ��������� ������
		matrix.resize(new_dimension);
		for (auto& it : matrix)
		{
			it.resize(new_dimension);
		}
	}
	size = new_dimension; // ��������� ����� �������� �������
}

vector<vector<int>> Matrix::GetMatrix()const// �� ���������� ����� ��� ��������� �������
{
	return matrix;
}

int Matrix::GetMatrixDim()const // ����������� ����� ��������� ������� �������
{
	return size;
}

void Matrix::PrintMatrix() // ����� ������� 
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



double Matrix::GetDetMatrix(vector<vector<int>> ob, int size) // ����������� �������� ���������� ������������ 
{
	int i, j;
	double det = 0;
	vector<vector<int>> m;
	if (size == 1)
	{
		det = ob[0][0];
	}
	else if (size == 2)
	{
		det = ob[0][0] * ob[1][1] - ob[0][1] * ob[1][0];
	}
	else
	{
		m.resize(size - 1);
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size - 1; ++j)
			{
				if (j < i)
					m[j] = ob[j];
				else
					m[j] = ob[j + 1];
			}
			det += pow((double)-1, (i + j)) * GetDetMatrix(m, size - 1) * ob[i][size - 1];
		}
	}
	return det;
}