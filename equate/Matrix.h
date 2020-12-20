#pragma once
#include <iostream>
#include <vector>

// Documentation for how to make his own static library :
// - https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-160

class Matrix
{
private:
	int nbRows = 0;
	int nbColumns = 0;
	std::vector<int> data;

public:
	// Constructors
	/* Default constructor. */
	Matrix();

	/**
	 * Constructor that initializes the matrix with a user-defined number of rows and number of columns.
	 * @param nbRows The number of rows to initialize the matrix with.
	 * @param nbColumns The number of columns to initialize the matrix with.
	 */
	Matrix(const int nbRows, const int nbColumns);

	/** 
	 * Constructor that initializes the matrix with a user-defined size. The resulting matrix is a square matrix.
	 * @param size The size of the square matrix.
	 */
	Matrix(const int size);

	/**
	 * Copy constructor.
	 * @param other The other matrix to copy into this instance.
	 */
	Matrix(const Matrix& other);

	// Destructors
	/* Default destructor. */
	~Matrix();

	// Getters/setters
	/* Getter for nbRows */
	int getNbRows() const;

	/* Getter for nbColumns */
	int getNbColumns() const;

	/* Getter for data */
	const std::vector<int> getData() const;

	/* Setter for data */
	void setData(const std::vector<int> data);

	// Utilities
	int size() const;

	// Operator overloads
	int& operator()(int row, int column) const;

	friend Matrix& operator+(Matrix& matrix, double other);

	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
	// Helpers
	/**
	 * Returns the data index that corresponds to the row and column arguments.
	 * @param row The row's index.
	 * @param column The column's index.
	 * @return The data index that corresponds to the row and column arguments.
	 */
	int getDataIndex(const int row, const int column) const;

	/**
	 * Checks if the data size matches the matrix size.
	 * @param data The data to check.
	 */
	void checkDataMatchesSize(const std::vector<int> data) const;
};

/* Addition operator overload for Matrix class. */
Matrix& operator+(Matrix& matrix, double other);

/* Insertion operator overload for Matrix class. */
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
