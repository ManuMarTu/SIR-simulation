#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sir.hpp"

TEST_CASE("SIR simulation produces correct results") {
  double beta = 0.2;
  double gamma = 0.1;
  int S = 800;
  int I = 200;
  int R = 0;
  int numDays = 10;

  SIR sir(beta, gamma, S, I, R, numDays);

  sir.SIRSim();

  std::vector<int> S_values = sir.getSValues();
  std::vector<int> I_values = sir.getIValues();
  std::vector<int> R_values = sir.getRValues();
  int numDaysSimulated = sir.getNumDays();

  REQUIRE(S_values[numDaysSimulated] == 481);
  REQUIRE(I_values[numDaysSimulated] == 278);
  REQUIRE(R_values[numDaysSimulated] == 241);

  int initial_N = S + I + R;
  CHECK(S_values[numDays] + I_values[numDays] + R_values[numDays] == initial_N);
}
TEST_CASE("SIR simulation with gamma=beta") {
  double beta = 0.3;
  double gamma = 0.3;
  int S = 990;
  int I = 0;
  int R = 0;
  int numDays = 30;

  SIR sir(beta, gamma, S, I, R, numDays);

  sir.SIRSim();

  std::vector<int> S_values = sir.getSValues();
  std::vector<int> I_values = sir.getIValues();
  std::vector<int> R_values = sir.getRValues();
  int numDaysSimulated = sir.getNumDays();

  REQUIRE(S_values[numDaysSimulated] == 990);
  REQUIRE(I_values[numDaysSimulated] == 0);
  REQUIRE(R_values[numDaysSimulated] == 0);

  int initial_N = S + I + R;
  CHECK(S_values[numDays] + I_values[numDays] + R_values[numDays] == initial_N);
}
TEST_CASE("SIR simulation with gamma > beta") {
  double beta = 0.24;
  double gamma = 0.45;
  int S = 750;
  int I = 150;
  int R = 0;
  int numDays = 30;

  SIR sir(beta, gamma, S, I, R, numDays);

  sir.SIRSim();

  std::vector<int> S_values = sir.getSValues();
  std::vector<int> I_values = sir.getIValues();
  std::vector<int> R_values = sir.getRValues();
  int numDaysSimulated = sir.getNumDays();

  REQUIRE(S_values[numDaysSimulated] == 612);
  REQUIRE(I_values[numDaysSimulated] == 4);
  REQUIRE(R_values[numDaysSimulated] == 284);

  int initial_N = S + I + R;
  CHECK(S_values[numDays] + I_values[numDays] + R_values[numDays] == initial_N);
}
