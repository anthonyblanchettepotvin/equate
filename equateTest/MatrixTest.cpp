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
		
		TEST_METHOD(MatrixInstantiation_DefaultCtor)
		{
			// Prepare
			// Execute
			const Matrix* matrix = new Matrix();
			const std::vector<std::vector<int>> expected{};

			// Assert
			Assert::AreEqual(0, matrix->getNbRows());
			Assert::AreEqual(0, matrix->getNbColumns());
			Assert::IsTrue(expected == matrix->getData());

			// Clean
			delete matrix;
		}

		TEST_METHOD(MatrixInstantiation_CtorNbRowsLessThanZero_ThrowsException)
		{
			// Prepare
			const auto constructMatrix = [] { Matrix(-1, 0); };

			// Execute
			// Assert
			Assert::ExpectException<std::invalid_argument>(constructMatrix, L"An invalid_argument exception should be thrown whenever nbRows is passed a value less than 0.");

			// Clean
		}

		TEST_METHOD(MatrixInstantiation_CtorNbRowsNull_SetNbRowsToZero)
		{
			// Prepare
			// Execute
			const Matrix* matrix = new Matrix(NULL, 0);
			const std::vector<std::vector<int>> expected{};

			// Assert
			Assert::AreEqual(0, matrix->getNbRows(), L"The matrix's nbRows property was not set to zero.");
			Assert::IsTrue(expected == matrix->getData());

			// Clean
			delete matrix;
		}

		TEST_METHOD(MatrixInstantiation_CtorNbRowsGood_SetNbRowsToValue)
		{
			// Prepare
			// Execute
			const Matrix* matrix = new Matrix(3, 3);
			const std::vector<std::vector<int>> expected{ {0,0,0}, {0,0,0}, {0,0,0} };

			// Assert
			Assert::AreEqual(3, matrix->getNbRows(), L"The matrix's nbRows property was not set to the correct value.");
			Assert::IsTrue(expected == matrix->getData());

			// Clean
			delete matrix;
		}

		TEST_METHOD(MatrixInstantiation_CtorNbColumnsLessThanZero_ThrowsException)
		{
			// Prepare
			const auto constructMatrix = [] { Matrix(0, -1); };

			// Execute
			// Assert
			Assert::ExpectException<std::invalid_argument>(constructMatrix, L"An invalid_argument exception should be thrown whenever nbColumns is passed a value less than 0.");

			// Clean
		}

		TEST_METHOD(MatrixInstantiation_CtorNbColumnsNull_SetNbColumnsToZero)
		{
			// Prepare
			// Execute
			const Matrix* matrix = new Matrix(0, NULL);

			// Assert
			Assert::AreEqual(0, matrix->getNbColumns(), L"The matrix's nbColumns property was not set to zero.");

			// Clean
			delete matrix;
		}

		TEST_METHOD(MatrixInstantiation_CtorNbColumnsGood_SetNbColumnsToValue)
		{
			// Prepare
			// Execute
			const Matrix* matrix = new Matrix(0, 0);

			// Assert
			Assert::AreEqual(0, matrix->getNbColumns(), L"The matrix's nbColumns property was not set to the correct value.");

			// Clean
			delete matrix;
		}
	};
}
