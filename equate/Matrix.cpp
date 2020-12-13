#include "pch.h"
#include "Matrix.h"

Matrix::Matrix() {}

Matrix::Matrix(const int nbRows, const int nbColumns) : nbRows(nbRows), nbColumns(nbColumns) {
	if (nbRows < 0) throw std::invalid_argument("The nbRows argument must be greater or equal than 0.");
	if (nbColumns < 0) throw std::invalid_argument("The nbColumns argument must be greater or equal than 0.");

	for (int i = 0; i < nbRows; i++)
	{
		for (int j = 0; j < nbColumns; j++)
		{
			this->data[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& other) : nbRows(other.nbRows), nbColumns(other.nbColumns) {}

Matrix::~Matrix() {}

// Getters/setters
int Matrix::getNbRows() const {
	return this->nbRows;
}

int Matrix::getNbColumns() const {
	return this->nbColumns;
}

const std::vector<std::vector<int>> Matrix::getData() const {
	return this->data;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	for (int i = 0; i < matrix.nbRows; i++)
	{
		os << "(";
		for (int j = 0; j < matrix.nbColumns; j++) {
			os << i << j;
			if (j < matrix.nbColumns - 1) os << " ";
		}
		os << ")" << std::endl;
	}

	return os;
}