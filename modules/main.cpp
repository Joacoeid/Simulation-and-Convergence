//
// Created by Joaquin Eid Mier on 2/26/26.
//
#include <iostream>
#include <vector>
#include <Matrices.h>
#include <MarkovChain.h>
#include <ostream>

using namespace std;

std::ostream& operator<<(std::ostream& out, const std::vector<double>& v) {
    out << "[";
    for (int i = 0; i < v.size(); i++) {
        out << v[i];
        if (i < v.size() - 1) out << ", ";
    }
    out << "]";
    return out;
}

void TestsForErgodicTheorem(MarkovChain& chain) {
    vector<double> Re1 = chain.empiricalDistribution(0, 10);
    vector<double> Re3 = chain.empiricalDistribution(0, 1000);
    vector<double> Re5 = chain.empiricalDistribution(0, 100000);
    vector<double> Re6 = chain.empiricalDistribution(0, 1000000);

    cout << "for steps = 10: " << Re1 << endl;
    cout << "for steps = 1000: " << Re3 << endl;
    cout << "for steps = 100000: " << Re5 << endl;
    cout << "for steps = 1000000: " << Re6 << endl;
}

int main() {
    vector<vector<double>> matrix = {{0.5, 0.3, 0.2}, {0.1, 0.6, 0.3}, {0.2, 0.3, 0.5}};
    Matrix M = Matrix(matrix);
    MarkovChain chain(M);

    cout << "Tests made for M = \n" << M << endl;
    TestsForErgodicTheorem(chain);
    return 0;
}
