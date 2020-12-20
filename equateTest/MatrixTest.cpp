#include "pch.h"
#include "CppUnitTest.h"
#include "..\equate\Matrix.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace equateTest
{
	TEST_CLASS(MatrixTest)
	{
	public:
		
		TEST_METHOD(MatrixCtor_Default)
		{
			// Prepare
			// Execute
			const Matrix matrix;
			const std::vector<int> expected{};

			// Assert
			Assert::AreEqual(0, matrix.getNbRows(), L"The matrix's nbRows property was not set to zero.");
			Assert::AreEqual(0, matrix.getNbColumns(), L"The matrix's nbColumns property was not set to zero.");
			Assert::IsTrue(expected == matrix.getData());

			// Clean
		}

		TEST_METHOD(MatrixCtor_CtorNbRowsNegative_ThrowsInvalidArgumentException)
		{
			// Prepare
			const auto constructMatrix = [] { Matrix matrix(-1, 0); };

			// Execute
			// Assert
			Assert::ExpectException<std::invalid_argument>(constructMatrix, L"An invalid_argument exception should be thrown whenever nbRows is passed a value less than 0.");

			// Clean
		}

		TEST_METHOD(MatrixCtor_CtorNbRowsNull_SetsNbRowsToZero)
		{
			// Prepare
			// Execute
			const Matrix matrix(NULL, 0);
			const std::vector<int> expected{};

			// Assert
			Assert::AreEqual(0, matrix.getNbRows(), L"The matrix's nbRows property was not set to zero.");
			Assert::IsTrue(expected == matrix.getData());

			// Clean
		}

		TEST_METHOD(MatrixCtor_CtorNbRowsGood_SetsNbRowsToValue)
		{
			// Prepare
			// Execute
			const Matrix matrix(3, 1);
			const std::vector<int> expected{ 0, 0, 0 };

			// Assert
			Assert::AreEqual(3, matrix.getNbRows(), L"The matrix's nbRows property was not set to the correct value.");
			Assert::IsTrue(expected == matrix.getData());

			// Clean
		}

		TEST_METHOD(MatrixCtor_CtorNbColumnsNegative_ThrowsInvalidArgumentException)
		{
			// Prepare
			const auto constructMatrix = [] { Matrix matrix(0, -1); };

			// Execute
			// Assert
			Assert::ExpectException<std::invalid_argument>(constructMatrix, L"An invalid_argument exception should be thrown whenever nbColumns is passed a value less than 0.");

			// Clean
		}

		TEST_METHOD(MatrixCtor_CtorNbColumnsNull_SetsNbColumnsToZero)
		{
			// Prepare
			// Execute
			const Matrix matrix(0, NULL);
			const std::vector<int> expected{};

			// Assert
			Assert::AreEqual(0, matrix.getNbColumns(), L"The matrix's nbColumns property was not set to zero.");
			Assert::IsTrue(expected == matrix.getData());

			// Clean
		}

		TEST_METHOD(MatrixCtor_CtorNbColumnsGood_SetsNbColumnsToValue)
		{
			// Prepare
			// Execute
			const Matrix matrix(1, 3);
			const std::vector<int> expected{ 0,0,0 };

			// Assert
			Assert::AreEqual(3, matrix.getNbColumns(), L"The matrix's nbColumns property was not set to the correct value.");
			Assert::IsTrue(expected == matrix.getData());

			// Clean
		}

		TEST_METHOD(MatrixSquareCtor_SizeNegative_ThrowsInvalidArgumentException)
		{
			// Prepare
			const auto constructMatrix = [] { Matrix matrix(-1); };

			// Execute
			// Assert
			Assert::ExpectException<std::invalid_argument>(constructMatrix, L"An invalid_argument exception should be thrown whenever size is passed a value less than 0.");

			// Clean
		}

		TEST_METHOD(MatrixSquareCtor_SizeZero_SetsNbRowsNbColumnsToZero)
		{
			// Prepare
			// Execute
			const Matrix matrix(0);
			const std::vector<int> expected{};

			// Assert
			Assert::AreEqual(0, matrix.getNbRows());
			Assert::AreEqual(0, matrix.getNbColumns());
			Assert::IsTrue(expected == matrix.getData());

			// Clean
		}

		TEST_METHOD(MatrixSquareCtor_SizeGreaterThanZero_SetsNbRowsNbColumnsToSize)
		{
			// Prepare
			// Execute
			const Matrix matrix(3);
			const std::vector<int> expected{ 0,0,0,0,0,0,0,0,0 };

			// Assert
			Assert::AreEqual(3, matrix.getNbRows());
			Assert::AreEqual(3, matrix.getNbColumns());
			Assert::IsTrue(expected == matrix.getData());

			// Clean
		}

		TEST_METHOD(SetData_DataSizeDoesntMatch_ThrowsInvalidArgumentException)
		{
			const auto call = [] {
				// Prepare
				Matrix matrix(3);
				const std::vector<int> data{ 0,0,0,0,0 };

				// Execute
				matrix.setData(data);
			};

			// Assert
			Assert::ExpectException<std::invalid_argument>(call, L"An invalid_argument exception should be thrown whenever the data size doesn't match the matrix size.");

			// Clean
		}

		TEST_METHOD(SetData_DataSizeDoesMatch_SetsDataToData)
		{
			// Prepare
			Matrix matrix(3);
			const std::vector<int> data{ 1,2,3,4,5,6,7,8,9 };

			// Execute
			matrix.setData(data);

			// Assert
			Assert::IsTrue(data == matrix.getData());

			// Clean
		}

		TEST_METHOD(Size_ReturnsMatrixSize)
		{
			// Prepare
			const Matrix matrix(3);

			// Execute
			const int result = matrix.size();

			// Assert
			Assert::AreEqual(9, result);

			// Clean
		}
	};
}
