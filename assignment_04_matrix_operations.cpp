// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printMatrix(int mat[10][10], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(5) << mat[i][j];
		}
		cout << endl;
	}
}

// Part A - transpose
void transposeMatrix() {
	int mat[10][10];
	int rows, cols;

	cout << "\n-- Part A: Transpose --" << endl;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> mat[i][j];
		}
	}

	// store the transposed version
	int trans[10][10];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			trans[j][i] = mat[i][j];
		}
	}

	cout << "\nOriginal Matrix:" << endl;
	printMatrix(mat, rows, cols);
	cout << "\nTransposed Matrix:" << endl;
	printMatrix(trans, cols, rows);
}

// Part B - addition
void addMatrices() {
	int A[10][10], B[10][10], C[10][10];
	int rows, cols;

	cout << "\n-- Part B: Matrix Addition --" << endl;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;

	cout << "Enter elements of Matrix A:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> A[i][j];
		}
	}

	cout << "Enter elements of Matrix B:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	cout << "\nMatrix A:" << endl;
	printMatrix(A, rows, cols);
	cout << "\nMatrix B:" << endl;
	printMatrix(B, rows, cols);
	cout << "\nA + B:" << endl;
	printMatrix(C, rows, cols);
}

// Part C - multiplication
void multiplyMatrices() {
	int A[10][10], B[10][10], C[10][10];
	int m, n, p;

	cout << "\n-- Part C: Matrix Multiplication --" << endl;
	cout << "Enter rows of A: ";
	cin >> m;
	cout << "Enter columns of A (= rows of B): ";
	cin >> n;
	cout << "Enter columns of B: ";
	cin >> p;

	cout << "Enter elements of Matrix A:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> A[i][j];
		}
	}

	cout << "Enter elements of Matrix B:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> B[i][j];
		}
	}

	// multiply
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

	cout << "\nMatrix A:" << endl;
	printMatrix(A, m, n);
	cout << "\nMatrix B:" << endl;
	printMatrix(B, n, p);
	cout << "\nA x B:" << endl;
	printMatrix(C, m, p);
}

int main() {
	transposeMatrix();
	addMatrices();
	multiplyMatrices();

	return 0;
}


