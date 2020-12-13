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
	std::vector<std::vector<int>> data;

public:
	// Constructors
	/* Default constructor. */
	Matrix();

	/**
	 * Constructor that initialize the matrix with a user-defined number of rows and number of columns.
	 * @param nbRows The number of rows to initialize the matrix with.
	 * @param nbColumns The number of columns to initialize the matrix with.
	 */
	Matrix(const int nbRows, const int nbColumns);

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
	const std::vector<std::vector<int>> getData() const;

	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

/* Insertion operator overload for Matrix class. */
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
