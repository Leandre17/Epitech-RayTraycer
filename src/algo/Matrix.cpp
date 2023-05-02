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
}

Matrix::Matrix(int nRows, int nCols) {
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    for (int i = 0; i < m_nElements; i++) m_matrixData.push_back(0.0);
    for (int i = 0; i < m_nElements; i++) m_matrixData[i] = 0.0;
}

Matrix::Matrix(const Matrix& inputMatrix) {
    m_nRows = inputMatrix.m_nRows;
    m_nCols = inputMatrix.m_nCols;
    m_nElements = inputMatrix.m_nElements;

    for (int i = 0; i < m_nElements; i++) m_matrixData.push_back(0.0);
    for (int i = 0; i < m_nElements; i++) m_matrixData[i] = inputMatrix.m_matrixData[i];
}

Matrix::Matrix(int nRows, int nCols, const std::vector<double>& inputData) {
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    for (int i = 0; i < m_nElements; i++) m_matrixData.push_back(0.0);
    for (int i = 0; i < m_nElements; ++i) m_matrixData[i] = inputData.at(i);
}

bool Matrix::Resize(int numRows, int numCols) {
    m_nRows = numRows;
    m_nCols = numCols;
    m_nElements = (m_nRows * m_nCols);
    for (int i = 0; i < m_nElements; i++) m_matrixData.push_back(0.0);
    for (int i = 0; i < m_nElements; i++) m_matrixData[i] = 0.0;
    return true;
}

// // Function to convert the existing matrix into an identity matrix.
void Matrix::SetToIdentity() {
    for (int row = 0; row < m_nRows; ++row) {
        for (int col = 0; col < m_nCols; ++col) {
            if (col == row)
                m_matrixData[Sub2Ind(row, col)] = 1.0;
            else
                m_matrixData[Sub2Ind(row, col)] = 0.0;
        }
    }
}

double Matrix::GetElement(int row, int col) const { return m_matrixData[Sub2Ind(row, col)]; }
double Matrix::GetElement(int elem) const { return m_matrixData[elem]; }
void Matrix::SetElement(int row, int col, double elementValue) { m_matrixData[Sub2Ind(row, col)] = elementValue; }

int Matrix::GetNumRows() const { return m_nRows; }
int Matrix::GetNumCols() const { return m_nCols; }

Vector3D operator*(const Matrix& lhs, const Vector3D& rhs) {
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
    std::vector<double> tempResult;

    for (int i = 0; i < numElements; i++) tempResult.push_back(0.0);
    for (int i = 0; i < numElements; ++i) tempResult[i] = lhs * rhs.GetElement(i);
    Matrix result(numRows, numCols, tempResult);
    return result;
}

Matrix operator*(const Matrix& lhs, const double& rhs) {
    int numRows = lhs.GetNumRows();
    int numCols = lhs.GetNumCols();
    int numElements = numRows * numCols;
    std::vector<double> tempResult;

    for (int i = 0; i < numElements; i++) tempResult.push_back(0.0);
    for (int i = 0; i < numElements; ++i) tempResult[i] = lhs.GetElement(i) * rhs;

    Matrix result(numRows, numCols, tempResult);
    return result;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    std::vector<double> tempResult;

    if (lhs.m_nCols == rhs.m_nRows) {
        for (int i = 0; i < lhs.m_nRows * rhs.m_nCols; i++) tempResult.push_back(0.0);
        // Loop through each row of the LHS.
        for (int lhsRow = 0; lhsRow < lhs.m_nRows; lhsRow++) {
            // Loop through each column on the RHS.
            for (int rhsCol = 0; rhsCol < rhs.m_nCols; rhsCol++) {
                double elementResult = 0;
                // Loop through each element of this LHS row.
                for (int lhsCol = 0; lhsCol < lhs.m_nCols; lhsCol++) {
                    // Compute the LHS linear index.
                    int lhsLinearIndex = (lhsRow * lhs.m_nCols) + lhsCol;

                    // Compute the RHS linear index (based on LHS col).
                    // rhs row number equal to lhs column number.
                    int rhsLinearIndex = (lhsCol * rhs.m_nCols) + rhsCol;

                    // Perform the calculation on these elements.
                    elementResult += (lhs.m_matrixData[lhsLinearIndex] * rhs.m_matrixData[rhsLinearIndex]);
                }

                // Store the result.
                int resultLinearIndex = (lhsRow * rhs.m_nCols) + rhsCol;
                tempResult[resultLinearIndex] = elementResult;
            }
        }
        Matrix result(lhs.m_nCols, rhs.m_nCols, tempResult);
        return result;
    } else {
        Matrix result(1, 1);
        return result;
    }
}

bool Matrix::operator==(const Matrix& rhs) {
    bool flag = true;
    // Check if the matricies are the same size, if not return false.
    if ((this->m_nRows != rhs.m_nRows) && (this->m_nCols != rhs.m_nCols)) return false;

    // Check if the elements are equal.
    for (int i = 0; i < this->m_nElements; ++i) {
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

        for (int i = 0; i < m_nElements; i++) m_matrixData.push_back(0.0);
        for (int i = 0; i < m_nElements; i++) m_matrixData[i] = rhs.m_matrixData[i];
    }
    return *this;
}

bool Matrix::Separate(Matrix& matrix1, Matrix& matrix2, int colNum) {
    // Compute the sizes of the new matrices.
    int numRows = m_nRows;
    int numCols1 = colNum;

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

void Matrix::Join(const Matrix& matrix2) {
    // Extract the information that we need from both matrices
    int numCols1 = m_nCols;
    int numCols2 = matrix2.m_nCols;
    std::vector<double> newMatrixData;
    int linearIndex = 0;
    int resultLinearIndex = 0;

    for (int i = 0; i < m_nRows * (numCols1 + numCols2); i++) newMatrixData.push_back(0.0);
    // Copy the two matrices into the new one.
    for (int i = 0; i < m_nRows; ++i) {
        for (int j = 0; j < (numCols1 + numCols2); ++j) {
            resultLinearIndex = (i * (numCols1 + numCols2)) + j;
            if (j < numCols1) {
                linearIndex = (i * numCols1) + j;
                newMatrixData[resultLinearIndex] = m_matrixData[linearIndex];
            } else {
                linearIndex = (i * numCols2) + (j - numCols1);
                newMatrixData[resultLinearIndex] = matrix2.m_matrixData[linearIndex];
            }
        }
    }

    m_nCols = numCols1 + numCols2;
    m_nElements = m_nRows * m_nCols;
    for (int i = 0; i < m_nElements; i++) m_matrixData.push_back(0.0);
    for (int i = 0; i < m_nElements; ++i) m_matrixData[i] = newMatrixData[i];
}

void Matrix::Inverse() {
    Matrix identityMatrix(m_nRows, m_nCols); 
    int originalNumCols = m_nCols;
    int maxCount = 100;
    bool completeFlag = false;

    identityMatrix.SetToIdentity();
    Join(identityMatrix);
    for (int count = 0; (!completeFlag) && (count < maxCount); count++) {
        for (int diagIndex = 0; diagIndex < m_nRows; ++diagIndex) {
            // Find the index of the maximum element in the current column.
            int maxIndex = FindRowWithMaxElement(diagIndex, diagIndex);
            if (maxIndex != diagIndex) SwapRow(diagIndex, maxIndex);
        
            // Make sure the value at (cRow,cCol) is equal to one.
            if (m_matrixData[Sub2Ind(diagIndex, diagIndex)] != 1.0) {
                double multFactor = 1.0 / m_matrixData[Sub2Ind(diagIndex, diagIndex)];
                MultRow(diagIndex, multFactor);
            }

            // Consider the column.
            for (int rowIndex = diagIndex + 1; rowIndex < m_nRows; ++rowIndex) {
                // If the element is already zero, move on.
                if (!CloseEnough(m_matrixData[Sub2Ind(rowIndex, diagIndex)], 0.0)) {
                    double currentElementValue = m_matrixData[Sub2Ind(rowIndex, diagIndex)];
                    double rowOneValue = m_matrixData[Sub2Ind(diagIndex, diagIndex)];

                    if (!CloseEnough(rowOneValue, 0.0)) {
                        double correctionFactor = -(currentElementValue / rowOneValue);
                        MultAdd(rowIndex, diagIndex, correctionFactor);
                    }
                }
            }
            for (int colIndex = diagIndex + 1; colIndex < originalNumCols; ++colIndex) {
                // If the element is already zero, move on.
                if (!CloseEnough(m_matrixData[Sub2Ind(diagIndex, colIndex)], 0.0)) {
                    double currentElementValue = m_matrixData[Sub2Ind(diagIndex, colIndex)];
                    double rowOneValue = m_matrixData[Sub2Ind(colIndex, colIndex)];

                    if (!CloseEnough(rowOneValue, 0.0)) {
                        double correctionFactor = -(currentElementValue / rowOneValue);
                        MultAdd(diagIndex, colIndex, correctionFactor);
                    }
                }
            }
        }
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
            for (int i = 0; i < m_nElements; i++) m_matrixData.push_back(0.0);
            for (int i = 0; i < m_nElements; ++i) m_matrixData[i] = rightHalf.m_matrixData[i];
        }
    }
}

// // Function to return the linear index corresponding to the supplied row and column values.
int Matrix::Sub2Ind(int row, int col) const {
    if ((row < m_nRows) && (row >= 0) && (col < m_nCols) && (col >= 0))
        return (row * m_nCols) + col;
    else
        return 0;
}

// // Function to swap rows i and j (in place).
void Matrix::SwapRow(int i, int j) {
    // Store a tempory copy of row i.
    std::vector<double> tempRow;
    for (int i = 0; i < m_nElements; i++) tempRow.push_back(0.0);
    for (int k = 0; k < m_nCols; ++k) tempRow[k] = m_matrixData[Sub2Ind(i, k)];

    // Replace row i with row j.
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(i, k)] = m_matrixData[Sub2Ind(j, k)];

    // Replace row k with the tempory copy of the original row i.
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(j, k)] = tempRow[k];
}

// // Function to add a multiple of row j to row i (in place).
void Matrix::MultAdd(int i, int j, double multFactor) {
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(i, k)] += (m_matrixData[Sub2Ind(j, k)] * multFactor);
}

// // Function to the find the row with the maximum element at the column given.
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

// Function to multiply a row by the given value.
void Matrix::MultRow(int i, double multFactor) {
    for (int k = 0; k < m_nCols; ++k) m_matrixData[Sub2Ind(i, k)] *= multFactor;
}

bool Matrix::CloseEnough(double f1, double f2) { return abs(f1 - f2) < 0.0000001; }
