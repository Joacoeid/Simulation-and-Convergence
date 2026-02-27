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

vector<double> Matrix::getRow(int i) const {
    return matrix[i];
}

vector<double> Matrix::getColumn(int j) const {
    vector<double> column;
    for (const auto & row : matrix) {
        column.push_back(row[j]);
    }
    return column;

}

double Matrix::getValue(int i, int j) const {
    return matrix[i][j];
}

int Matrix::rows() const {
    return matrix.size();
}

int Matrix::columns() const {
    if (matrix.empty()) {
        return 0;
    }
    return matrix[0].size();
}

void Matrix::setRow(vector<double> row, int i)  {
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

void Matrix::checkProbs(const vector<vector<double>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        double rowsum = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] < 0) {
                throw std::logic_error("All entries on the matrix aren't >= 0");
            }
            rowsum += mat[i][j];
        }
        if (std::abs(rowsum - 1.0) > 1e-10) {
            throw std::logic_error("Matrix rows don't sum to 1");
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Matrix& M) {
    for (int i = 0; i < M.rows(); i++) {
        for (int j = 0; j < M.columns(); j++) {
            out << M.getValue(i,j) << "\t";
        }
        out << "\n";
    }
    return out;
}