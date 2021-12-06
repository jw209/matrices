// Matrix operations
// Created by: Jesse Wood on 12/6/2021
#include <iostream>
#include <stdlib.h> 

int main(int argc, char* argv[]) {
    char* p;
    int rows = 0;
    int cols = 0;
    if (argv[1] != 0 && argv[2] != 0) {
        rows = strtol(argv[1], &p, 10);
        cols = strtol(argv[2], &p, 10);
    }

    std::cout << "Starting with matrix: " << rows << " rows and " << cols << " columns\n";

    // initialize matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) matrix[i] = new int[cols];

    // populate matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int tempNum;
            std::cout << "Position [" << i << "][" << j << "]: ";
            std::cin >> tempNum;
            matrix[i][j] = tempNum;
        }
    }

    std::cout << "\n\n";

    // print matrix
    for (int i = 0; i < rows; i++) {
        std::cout << "| ";
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << " |\n";
    }

    /*
        [1][2]
        [3][4]

        [1][3]
        [2][4]

    */

    // transpose matrix
    int newRows = cols;
    int newCols = rows;
    int** transposedMatrix = new int*[newRows];
    for (int i = 0; i < newRows; ++i) transposedMatrix[i] = new int[newCols];

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    // print matrix transposed
    for (int i = 0; i < rows; i++) {
        std::cout << "| ";
        for (int j = 0; j < cols; j++) {
            std::cout << transposedMatrix[i][j] << " ";
        }
        std::cout << " |\n";
    }

    return 0;
}

