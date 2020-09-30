#include <ctime>
#include <iostream>
#include <random>

#include "local_simulator.h"

int main() {

  /* Publication note:
      This driver does NOT take into account the late design decision
      to use prototype, i.e. there is no clone mechanism for Routes.

      Any update to this driver should refactor the code to make use of
      the Clone() method for each prototype route, rather than creating
      a new one.
  */

  int rounds = 50; //Number of rounds of generation to simulate in test

  srand((long)time(NULL)); //Seed the random number generator...

  LocalSimulator my_sim;

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "         STARTING" << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "*************************/" << std::endl;

  my_sim.Start();

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "*************************/" << std::endl;

  for (int i = 0; i < rounds; i++) {
	  my_sim.Update();
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "         COMPLETE" << std::endl;
  std::cout << "*************************/" << std::endl;

  return 0;
}
