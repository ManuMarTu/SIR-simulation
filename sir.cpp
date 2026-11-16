#include "sir.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

void SIR::SIRSim() {
  int initial_N = S + I + R;
  if (initial_N == 0) {
    std::cerr
        << "errore, la somma iniziale di S, I, R deve essere diversa da zero"
        << std::endl;
    exit(1);
  }

  S_values.push_back(S);
  I_values.push_back(I);
  R_values.push_back(R);

  for (int day = 0; day < numDays; day++) {
    double dS = -beta * S * I / initial_N;
    double dI = (beta * S * I / initial_N) - gamma * I;
    double dR = gamma * I;

    double newS = S + dS;
    double newI = I + dI;
    double newR = R + dR;

    S = (int)newS;
    I = (int)newI;
    R = (int)newR;

    S = std::max(0, S);
    I = std::max(0, I);
    R = std::max(0, R);

    double current_N = S + I + R;
    double diff_N = initial_N - current_N;
    if (diff_N != 0) {
      int avgChange = diff_N / 3;
      S += avgChange;
      I += avgChange;
      R += avgChange;

      int remainder = std::fmod(diff_N, 3.0);
      if (S > 0) {
        I += remainder;
      } else {
        R += remainder;
      }
    }

    assert(S + I + R == initial_N);

    S_values.push_back(S);
    I_values.push_back(I);
    R_values.push_back(R);
  }
};
