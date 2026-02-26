//
// Created by Joaquin Eid Mier on 2/26/26.
//
#include "Matrices.h"

Matrix::Matrix() {
    matrix = vector<vector<double> >{};
}

Matrix::Matrix(vector<vector<double>> Matrix) {
    matrix = Matrix;
    checkProbs(Matrix);
}

vector<double> Matrix::getRow(int i) {
    return matrix[i];
}

vector<double> Matrix::getColumn(int j) {
    vector<double> column(matrix.size());
    for (auto & i : matrix) {
        column.push_back(i[j]);
    }
    return column;
}

int Matrix::rows() {
    return matrix.size();
}

int Matrix::columns() {
    return matrix[0].size();
}

void Matrix::setRow(vector<double> row, int i) {
    matrix[i] = row;
    checkProbs(matrix);
}

void Matrix::setColumn(vector<double> column, int j) {
    for (auto & i : matrix) {
        for (auto & z : column){
            i[j] = z;
        }
    }
    checkProbs(matrix);
}

void Matrix::checkProbs(Matrix Matrix) {
    for (int i = 0; i < Matrix.rows(); i++) {
        double rowsum = 0;
        for (int j = 0; j < Matrix.columns(); j++) {
            if (Matrix.getValue(i,j) < 0) {
                __throw_logic_error("All entries on the matrix aren't >= 0");
            }
            rowsum += Matrix.getValue(i,j);
        }
        if (rowsum != 1) {
            __throw_logic_error("Matrix rows don't sum to 1");
        }
        rowsum = 0;
    }
}
