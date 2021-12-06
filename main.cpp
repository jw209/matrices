// Matrix operations
// Created by: Jesse Wood on 12/6/2021
#include <iostream>
#include <stdlib.h>

void printMatrix(int** matrix, int cols, int rows);
void transpose(int** &matrix, int &cols, int &rows);
int** initMatrix(int cols, int rows);
int** echelonForm(int** matrix, int cols, int rows);

int main(int argc, char* argv[]) {
    char* p;
    int rows = 0;
    int cols = 0;
    if (argv[1] != 0 && argv[2] != 0) {
        rows = strtol(argv[1], &p, 10);
        cols = strtol(argv[2], &p, 10);
    }

    std::cout << "Starting with matrix: " << rows << " rows and " << cols << " columns\n";

    int** matrix = initMatrix(cols, rows);

    std::cout << "\n\n";

    printMatrix(matrix, cols, rows);
    
    transpose(matrix, cols, rows);

    printMatrix(matrix, cols, rows);

    return 0;
}

int** initMatrix(int cols, int rows) {
    // initialize matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) matrix[i] = new int[cols];

    // populate matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Position [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int cols, int rows) {
    // print matrix transposed
    for (int i = 0; i < rows; i++) {
        std::cout << "| ";
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << " |\n";
    }
}

void transpose(int** &matrix, int &cols, int &rows) {
    // swap rows and columns
    int temp = rows;
    rows = cols;
    cols = temp;

    int** transposedMatrix = new int*[rows];
    for (int i = 0; i < rows; ++i) transposedMatrix[i] = new int[cols];

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) matrix[i] = new int[cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = transposedMatrix[i][j];
        }
    }
}

/*
int** echelonForm(int** matrix, int cols, int rows) {

}
*/