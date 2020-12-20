#include "pch.h"
#include "Matrix.h"

// Constructors
Matrix::Matrix() {}

Matrix::Matrix(const int nbRows, const int nbColumns) : nbRows(nbRows), nbColumns(nbColumns)
{
	if (nbRows < 0) throw std::invalid_argument("The nbRows argument must be greater or equal than 0.");
	if (nbColumns < 0) throw std::invalid_argument("The nbColumns argument must be greater or equal than 0.");

	for(int i = 0; i < nbRows * nbColumns; i++) {
		this->data.insert(this->data.end(), 0);
	}
}

Matrix::Matrix(const int size) : nbRows(size), nbColumns(size)
{
	if (size < 0) throw std::invalid_argument("The size argument must be greater or equal than 0.");

	for (int i = 0; i < size * size; i++) {
		this->data.insert(this->data.end(), 0);
	}
}

Matrix::Matrix(const Matrix& other) : nbRows(other.nbRows), nbColumns(other.nbColumns) {}

// Destructors
Matrix::~Matrix() {}

// Getters/setters
int Matrix::getNbRows() const
{
	return this->nbRows;
}

int Matrix::getNbColumns() const
{
	return this->nbColumns;
}

const std::vector<int> Matrix::getData() const
{
	return this->data;
}

void Matrix::setData(const std::vector<int> data)
{
	this->checkDataMatchesSize(data);

	this->data = data;
}

// Utilities
int Matrix::size() const
{
	return this->getNbRows() * this->getNbColumns();
}

// Helpers
int Matrix::getDataIndex(const int row, const int column) const
{
	return row * this->getNbColumns() + column;
}

void Matrix::checkDataMatchesSize(const std::vector<int> data) const
{
	if (data.size() != this->size())
		throw std::invalid_argument("The data argument size doesn't match with the matrix size.");
}
