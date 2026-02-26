//
// Created by Joaquin Eid Mier on 2/26/26.
//

#include "MarkovChain.h"
#include <iostream>

using namespace std;

MarkovChain::MarkovChain(const Matrix &TransitionMatrix){
    P = TransitionMatrix;
    n = P.rows();
}

Matrix MarkovChain::getP() {
    return P;
}

int MarkovChain::getN() {
    return n;
}

int MarkovChain::nextState(int currentState) {
    vector<double> Row = P.getRow(currentState);

    discrete_distribution<int> Distribution(Row.begin(), Row.end());

    int nextState = Distribution(rng);

    return nextState;
}

vector<int> MarkovChain::simulate(int startState, int steps) {

}


