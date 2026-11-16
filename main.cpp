#include <SFML/Graphics.hpp>
#include <iostream>

#include "graph.hpp"
#include "sir.hpp"

int main() {
  double beta, gamma;
  int S, I, R;
  int numDays;

  SetBeta(beta);
  SetGamma(gamma);
  SetSirPar(S, I, R);
  SetDays(numDays);

  SIR sir(beta, gamma, S, I, R, numDays);
  sir.SIRSim();

  std::vector<int> S_values = sir.getSValues();
  std::vector<int> I_values = sir.getIValues();
  std::vector<int> R_values = sir.getRValues();
  int numDaysSimulated = sir.getNumDays();
  std::cout << "Giorni | S | I | R | N\n";
  for (int day = 0; day <= numDaysSimulated; day++) {
    std::cout << day << " | " << S_values[day] << " | " << I_values[day]
              << " | " << R_values[day] << " | "
              << (S_values[day] + I_values[day] + R_values[day]) << "\n";
  }

  int maxPopulation = std::max({S, I, R});

  Graph graph(800, 600, numDaysSimulated, maxPopulation, S_values, I_values,
              R_values);
  graph.run();
  return (0);
}