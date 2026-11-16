#ifndef SIR_HPP
#define SIR_HPP
#include <cstdlib>
#include <iostream>
#include <vector>

class SIR {
 private:
  double beta, gamma;
  int S, I, R;
  int numDays;
  std::vector<int> S_values, I_values, R_values;

 public:
  SIR(double beta, double gamma, int S, int I, int R, int numDays) {
    if (beta >= 0 && beta <= 1 && gamma >= 0 && gamma <= 1 && S >= 0 &&
        I >= 0 && R >= 0 && S == (int)S && I == (int)I && R == (int)R &&
        numDays > 0) {
      this->beta = beta;
      this->gamma = gamma;
      this->S = S;
      this->I = I;
      this->R = R;
      this->numDays = numDays;
    } else {
      std::cerr << "Errore: beta e gamma devono essere compresi tra 0 e 1,  "
                   "S, I e R devono essere maggiori o uguali a 0 e interi, ed "
                   "il numero di giorni deve essere intero e maggiore di 0"
                << std::endl;

      exit(1);
    }
  }

  void SIRSim();
  std::vector<int> getSValues() { return S_values; };
  std::vector<int> getIValues() { return I_values; };
  std::vector<int> getRValues() { return R_values; };
  int getNumDays() { return numDays; };
};

inline void SetBeta(double& beta) {
  std::cout << "Inserisci il valore di beta: ";
  std::cin >> beta;
};

inline void SetGamma(double& gamma) {
  std::cout << "Inserisci il valore di gamma: ";
  std::cin >> gamma;
};
inline void SetSirPar(int& S, int& I, int& R) {
  std::cout << "Inserisci il valore iniziale di S: ";
  std::cin >> S;
  std::cout << "Inserisci il valore iniziale di I: ";
  std::cin >> I;
  std::cout << "Inserisci il valore iniziale di R: ";
  std::cin >> R;
};
inline void SetDays(int& numDays) {
  std::cout << "Inserisci il numero di giorni della simulazione: ";
  std::cin >> numDays;
};

#endif