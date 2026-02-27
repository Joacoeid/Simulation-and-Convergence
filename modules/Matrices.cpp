//
// Created by Joaquin Eid Mier on 2/26/26.
//
#include "Matrices.h"

Matrix::Matrix() {
    matrix = vector<vector<double> >{};
}

Matrix::Matrix(vector<vector<double>> Matrix, bool SkipCheck) {
    matrix = Matrix;
    if (!SkipCheck) checkProbs(Matrix);
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

Matrix Matrix::transpose() {
    vector<vector<double>> transposed(columns(), vector<double>(rows()));
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < columns(); j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return Matrix(transposed, true);
}

vector<double> Matrix::GaussianElimination(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    for (int col = 0; col < n; col++) {
        //find pivot
        int pivot = col;
        for (int row = 0; row < n; row++) {
            if (abs(A[row][col]) > abs(A[pivot][col])) {
                pivot = row;
            }
        }
        swap(A[col], A[pivot]);
        swap(b[col], b[pivot]);

        if (abs(A[col][col]) < 1e-12) {
            throw logic_error("Matrix is singular, no unique solution found");
        }

        //Eliminate column
        for (int row = 0; row < n; row++) {
            if (row == col) continue ;
            double factor  = A[row][col]/ A[col][col];
            for (int k = 0; k < n; k++) {
                A[row][k] -= factor * A[col][k];
            }
            b[row] -= factor * b[col];
        }
    }

    //extract solution
    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = b[i] / A[i][i];
    }

    return x;
}

vector<double> Matrix::stationaryDistribution() {
    int n = rows();

    // Construction of P^T - I
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = matrix[i][j] - (i == j ? 1 : 0);
        }
    }

    //normalization of the last row (sum pi_i = 1)
    for (int j = 0; j < n; j++) {
        A[n-1][j] = 1.0;
    }

    // null vector for the RHS
    vector<double> b(n, 0.0);
    b[n-1] = 1.0;

    //Gaussian elimination
    return GaussianElimination(A, b);
}

Matrix Matrix::inverse() {
    int n = rows();
    vector<vector<double>> result(n, vector<double>(n));

    for (int j = 0; j < n; j++) {
        vector<double> e(n, 0.0);
        e[j] = 1.0;
        vector<double> col = GaussianElimination(matrix, e);
        for (int i = 0; i < n; i++) {
            result[i][j] = col[i];
        }
    }
    return Matrix(result, true);
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