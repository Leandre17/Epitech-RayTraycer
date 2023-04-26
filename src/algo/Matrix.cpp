/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Matrix
*/

#include "Algo.hpp"

Matrix::Matrix() {
    m_nRows = 1;
    m_nCols = 1;
    m_nElements = 1;
    m_matrixData = nullptr;
}

Matrix::Matrix(int nRows, int nCols) {
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new double[m_nElements];
    for (int i = 0; i < m_nElements; i++) m_matrixData[i] = 0.0;
}

Matrix::Matrix(int nRows, int nCols, const double* inputData) {
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new double[m_nElements];
    for (int i = 0; i < m_nElements; i++) m_matrixData[i] = inputData[i];
}

Matrix::Matrix(const Matrix& inputMatrix) {
    m_nRows = inputMatrix.m_nRows;
    m_nCols = inputMatrix.m_nCols;
    m_nElements = inputMatrix.m_nElements;

    m_matrixData = new double[m_nElements];
    for (int i = 0; i < m_nElements; i++) m_matrixData[i] = inputMatrix.m_matrixData[i];
}

Matrix::Matrix(int nRows, int nCols, const std::vector<double>& inputData) {
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new double[m_nElements];
    for (int i = 0; i < m_nElements; ++i) m_matrixData[i] = inputData.at(i);
}

Matrix::~Matrix() {
    if (m_matrixData) delete[] m_matrixData;

    m_matrixData = nullptr;
}

bool Matrix::Resize(int numRows, int numCols) {
    m_nRows = numRows;
    m_nCols = numCols;
    m_nElements = (m_nRows * m_nCols);
    delete[] m_matrixData;
    m_matrixData = new double[m_nElements];
    if (m_matrixData != nullptr) {
        for (int i = 0; i < m_nElements; i++) m_matrixData[i] = 0.0;

        return true;
    } else {
        return false;
    }
}

// // Function to convert the existing matrix into an identity matrix.
void Matrix::SetToIdentity() {
    if (m_nCols != m_nRows) throw std::invalid_argument("Cannot form an identity matrix that is not square.");

    for (int row = 0; row < m_nRows; ++row) {
        for (int col = 0; col < m_nCols; ++col) {
            if (col == row)
                m_matrixData[Sub2Ind(row, col)] = 1.0;
            else
                m_matrixData[Sub2Ind(row, col)] = 0.0;
        }
    }
}

double Matrix::GetElement(int row, int col) const {
    int linearIndex = Sub2Ind(row, col);
    if (linearIndex >= 0)
        return m_matrixData[linearIndex];
    else
        return 0.0;
}
double Matrix::GetElement(int elem) const {
    return m_matrixData[elem];
}

bool Matrix::SetElement(int row, int col, double elementValue) {
    int linearIndex = Sub2Ind(row, col);
    if (linearIndex >= 0) {
        m_matrixData[linearIndex] = elementValue;
        return true;
    } else {
        return false;
    }
}

int Matrix::GetNumRows() const {
    return m_nRows;
}

int Matrix::GetNumCols() const {
    return m_nCols;
}

Vector3D operator*(const Matrix& lhs, const Vector3D& rhs) {
    // Verify the dimensions of the inputs.
    if (lhs.m_nCols != rhs.GetNumDims())
        throw std::invalid_argument("Number of columns in matrix must equal number of rows in vector.");

    // Setup the vector for the output.
    Vector3D result(lhs.m_nRows);

    // Loop over rows and columns and perform the multiplication operation element-by-element.
    for (int row = 0; row < lhs.m_nRows; ++row) {
        double cumulativeSum = 0.0;
        for (int col = 0; col < lhs.m_nCols; ++col) { cumulativeSum += (lhs.GetElement(row, col) * rhs.GetElement(col)); }
        result.SetElement(row, cumulativeSum);
    }

    return result;
}

Matrix operator*(const double& lhs, const Matrix& rhs) {
    int numRows = rhs.GetNumRows();
    int numCols = rhs.GetNumCols();
    int numElements = numRows * numCols;
    double* tempResult = new double[numElements];
    for (int i = 0; i < numElements; ++i) tempResult[i] = lhs * rhs.GetElement(i);

    Matrix result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}

Matrix operator*(const Matrix& lhs, const double& rhs) {
    int numRows = lhs.GetNumRows();
    int numCols = lhs.GetNumCols();
    int numElements = numRows * numCols;
    double* tempResult = new double[numElements];
    for (int i = 0; i < numElements; ++i) tempResult[i] = lhs.GetElement(i) * rhs;

    Matrix result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    int r_numRows = rhs.m_nRows;
    int r_numCols = rhs.m_nCols;
    int l_numRows = lhs.m_nRows;
    int l_numCols = lhs.m_nCols;

    if (l_numCols == r_numRows) {
        // This is the standard matrix multiplication condition.
        // The output will be the same size as the RHS.
        double* tempResult = new double[lhs.m_nRows * rhs.m_nCols];

        // Loop through each row of the LHS.
        for (int lhsRow = 0; lhsRow < l_numRows; lhsRow++) {
            // Loop through each column on the RHS.
            for (int rhsCol = 0; rhsCol < r_numCols; rhsCol++) {
                double elementResult = 0;
                // Loop through each element of this LHS row.
                for (int lhsCol = 0; lhsCol < l_numCols; lhsCol++) {
                    // Compute the LHS linear index.
                    int lhsLinearIndex = (lhsRow * l_numCols) + lhsCol;

                    // Compute the RHS linear index (based on LHS col).
                    // rhs row number equal to lhs column number.
                    int rhsLinearIndex = (lhsCol * r_numCols) + rhsCol;

                    // Perform the calculation on these elements.
                    elementResult += (lhs.m_matrixData[lhsLinearIndex] * rhs.m_matrixData[rhsLinearIndex]);
                }

                // Store the result.
                int resultLinearIndex = (lhsRow * r_numCols) + rhsCol;
                tempResult[resultLinearIndex] = elementResult;
            }
        }
        Matrix result(l_numRows, r_numCols, tempResult);
        delete[] tempResult;
        return result;
    } else {
        Matrix result(1, 1);
        return result;
    }
}

bool Matrix::operator==(const Matrix& rhs) {
    // Check if the matricies are the same size, if not return false.
    if ((this->m_nRows != rhs.m_nRows) && (this->m_nCols != rhs.m_nCols)) return false;

    // Check if the elements are equal.
    bool flag = true;
    for (int i = 0; i < this->m_nElements; ++i) {
        // if (this->m_matrixData[i] != rhs.m_matrixData[i])
        if (!CloseEnough(this->m_matrixData[i], rhs.m_matrixData[i])) flag = false;
    }
    return flag;
}

Matrix Matrix::operator=(const Matrix& rhs) {
    // Make sure we're not assigning to ourself.
    if (this != &rhs) {
        m_nRows = rhs.m_nRows;
        m_nCols = rhs.m_nCols;
        m_nElements = rhs.m_nElements;

        if (m_matrixData) delete[] m_matrixData;

        m_matrixData = new double[m_nElements];
        for (int i = 0; i < m_nElements; i++) m_matrixData[i] = rhs.m_matrixData[i];
    }

    return *this;
}

bool Matrix::Separate(Matrix& matrix1, Matrix& matrix2, int colNum) {
    // Compute the sizes of the new matrices.
    int numRows = m_nRows;
    int numCols1 = colNum;
    // int numCols2 = m_nCols - colNum;

    // Resize the two matrices to the proper dimensions.
    matrix1.Resize(numRows, numCols1);
    matrix2.Resize(numRows, numCols1);

    // Loop over the original matrix and store data into the appropriate elements of the two
    // output matrices.
    for (int row = 0; row < m_nRows; ++row) {
        for (int col = 0; col < m_nCols; ++col) {
            if (col < colNum) {
                matrix1.SetElement(row, col, this->GetElement(row, col));
            } else {
                matrix2.SetElement(row, col - colNum, this->GetElement(row, col));
            }
        }
    }
    return true;
}

bool Matrix::Join(const Matrix& matrix2) {
    // Extract the information that we need from both matrices
    int numRows1 = m_nRows;
    int numRows2 = matrix2.m_nRows;
    int numCols1 = m_nCols;
    int numCols2 = matrix2.m_nCols;

    // If the matrices have different numbers of rows, then this operation makes no sense.
    if (numRows1 != numRows2)
        throw std::invalid_argument("Attempt to join matrices with different numbers of rows is invalid.");

    // Allocate memory for the result.
    // Note that only the number of columns increases.
    double* newMatrixData = new double[numRows1 * (numCols1 + numCols2)];

    // Copy the two matrices into the new one.
    int linearIndex, resultLinearIndex;
    for (int i = 0; i < numRows1; ++i) {
        for (int j = 0; j < (numCols1 + numCols2); ++j) {
            resultLinearIndex = (i * (numCols1 + numCols2)) + j;

            // If j is in the left hand matrix, we get data from there...
            if (j < numCols1) {
                linearIndex = (i * numCols1) + j;
                newMatrixData[resultLinearIndex] = m_matrixData[linearIndex];
            }
            // Otherwise, j must be in the right hand matrix, so we get data from there...
            else {
                linearIndex = (i * numCols2) + (j - numCols1);
                newMatrixData[resultLinearIndex] = matrix2.m_matrixData[linearIndex];
            }
        }
    }

    // Update the stored data.
    m_nCols = numCols1 + numCols2;
    m_nElements = m_nRows * m_nCols;
    delete[] m_matrixData;
    m_matrixData = new double[m_nElements];
    for (int i = 0; i < m_nElements; ++i) m_matrixData[i] = newMatrixData[i];

    delete[] newMatrixData;
    return true;
}

bool Matrix::Inverse() {
    // Check if the matrix is square (we cannot compute the inverse if it isn't).
    if (m_nCols != m_nRows) throw std::invalid_argument("Cannot compute the inverse of a matrix that is not square.");

    // If we get to here, the matrix is square so we can continue.

    // Form an identity matrix with the same dimensions as the matrix we wish to invert.
    Matrix identityMatrix(m_nRows, m_nCols);
    identityMatrix.SetToIdentity();

    // Join the identity matrix to the existing matrix.
    int originalNumCols = m_nCols;
    Join(identityMatrix);

    // Begin the main part of the process.
    int cRow, cCol;
    int maxCount = 100;
    int count = 0;
    bool completeFlag = false;
    while ((!completeFlag) && (count < maxCount)) {
        for (int diagIndex = 0; diagIndex < m_nRows; ++diagIndex) {
            // Loop over the diagonal of the matrix and ensure all diagonal elements are equal to one.
            cRow = diagIndex;
            cCol = diagIndex;

            // Find the index of the maximum element in the current column.
            int maxIndex = FindRowWithMaxElement(cCol, cRow);

            // If this isn't the current row, then swap.
            if (maxIndex != cRow) {
                // std::cout << "Swap rows " << cRow << " and " << maxIndex << std::endl;
                SwapRow(cRow, maxIndex);
            }
            // Make sure the value at (cRow,cCol) is equal to one.
            if (m_matrixData[Sub2Ind(cRow, cCol)] != 1.0) {
                double multFactor = 1.0 / m_matrixData[Sub2Ind(cRow, cCol)];
                MultRow(cRow, multFactor);
                // std::cout << "Multiply row " << cRow << " by " << multFactor << std::endl;
            }

            // Consider the column.
            for (int rowIndex = cRow + 1; rowIndex < m_nRows; ++rowIndex) {
                // If the element is already zero, move on.
                if (!CloseEnough(m_matrixData[Sub2Ind(rowIndex, cCol)], 0.0)) {
                    // Obtain the element to work with from the matrix diagonal.
                    // As we aim to set all the diagonal elements to one, this should
                    // always be valid for a matrix that can be inverted.
                    int rowOneIndex = cCol;

                    // Get the value stored at the current element.
                    double currentElementValue = m_matrixData[Sub2Ind(rowIndex, cCol)];

                    // Get the value stored at (rowOneIndex, cCol)
                    double rowOneValue = m_matrixData[Sub2Ind(rowOneIndex, cCol)];

                    // If this is equal to zero, then just move on.
                    if (!CloseEnough(rowOneValue, 0.0)) {
                        // Compute the correction factor.
                        // (required to reduce the element at (rowIndex, cCol) to zero).
                        double correctionFactor = -(currentElementValue / rowOneValue);

                        MultAdd(rowIndex, rowOneIndex, correctionFactor);

                        // std::cout << "Multiply row " << rowOneIndex << " by " << correctionFactor <<
                        //	" and add to row " << rowIndex << std::endl;
                    }
                }
            }

            // Consider the row.
            for (int colIndex = cCol + 1; colIndex < originalNumCols; ++colIndex) {
                // If the element is already zero, move on.
                if (!CloseEnough(m_matrixData[Sub2Ind(cRow, colIndex)], 0.0)) {
                    // Obtain the element to work with from the matrix diagonal.
                    // As we aim to set all the diagonal elements to one, this should
                    // always be valid for a matrix that can be inverted.
                    int rowOneIndex = colIndex;

                    // Get the value stored at the current element.
                    double currentElementValue = m_matrixData[Sub2Ind(cRow, colIndex)];

                    // Get the value stored at (rowOneIndex, colIndex)
                    double rowOneValue = m_matrixData[Sub2Ind(rowOneIndex, colIndex)];

                    // If this is equal to zero, then just move on.
                    if (!CloseEnough(rowOneValue, 0.0)) {
                        // Compute the correction factor.
                        // (required to reduce the element at (cRow, colIndex) to zero).
                        double correctionFactor = -(currentElementValue / rowOneValue);

                        // To make this equal to zero, we need to add -currentElementValue multiplied by
                        // the row at rowOneIndex.
                        MultAdd(cRow, rowOneIndex, correctionFactor);

                        // std::cout << "Multiply row " << rowOneIndex << " by " << correctionFactor <<
                        //	" and add to row " << cRow << std::endl;
                    }
                }
            }
        }

        // Separate the result into the left and right halves.
        Matrix leftHalf;
        Matrix rightHalf;
        this->Separate(leftHalf, rightHalf, originalNumCols);

        // When the process is complete, the left half should be the identity matrix.
        if (leftHalf == identityMatrix) {
            // Set completedFlag to true to indicate that the process has completed.
            completeFlag = true;

            // Rebuild the matrix with just the right half, which now contains the result.
            m_nCols = originalNumCols;
            m_nElements = m_nRows * m_nCols;
            delete[] m_matrixData;
            m_matrixData = new double[m_nElements];
            for (int i = 0; i < m_nElements; ++i) m_matrixData[i] = rightHalf.m_matrixData[i];
        }

        // Increment the counter.
        count++;
    }

    // Return whether the process succeeded or not.
    return completeFlag;
}

// // Function to return the linear index corresponding to the supplied row and column values.
int Matrix::Sub2Ind(int row, int col) const {
    if ((row < m_nRows) && (row >= 0) && (col < m_nCols) && (col >= 0))
        return (row * m_nCols) + col;
    else
        return -1;
}

// // Function to swap rows i and j (in place).
void Matrix::SwapRow(int i, int j) {
    // Store a tempory copy of row i.
    double* tempRow = new double[m_nCols];
    for (int k = 0; k < m_nCols; ++k) tempRow[k] = m_matrixData[Sub2Ind(i, k)];

    // Replace row i with row j.
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(i, k)] = m_matrixData[Sub2Ind(j, k)];

    // Replace row k with the tempory copy of the original row i.
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(j, k)] = tempRow[k];

    // Tidy up after ourselves.
    delete[] tempRow;
}

// // Function to add a multiple of row j to row i (in place).
void Matrix::MultAdd(int i, int j, double multFactor) {
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(i, k)] += (m_matrixData[Sub2Ind(j, k)] * multFactor);
}

// // Function to the find the row with the maximum element at the column given.
// // Returns the row index.
int Matrix::FindRowWithMaxElement(int colNumber, int startingRow) {
    double tempValue = m_matrixData[Sub2Ind(startingRow, colNumber)];
    int rowIndex = startingRow;
    for (int k = startingRow + 1; k < m_nRows; ++k) {
        if (fabs(m_matrixData[Sub2Ind(k, colNumber)]) > fabs(tempValue)) {
            rowIndex = k;
            tempValue = m_matrixData[Sub2Ind(k, colNumber)];
        }
    }
    return rowIndex;
}

// // Function to multiply a row by the given value.
void Matrix::MultRow(int i, double multFactor) {
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(i, k)] *= multFactor;
}

bool Matrix::CloseEnough(double f1, double f2) {
    return fabs(f1 - f2) < 1e-9;
}
