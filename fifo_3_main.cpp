#include "Vfifo_3.h"
#include "verilated.h"

#define POSEDGE(top, signal) (top)->signal = 0; (top)->eval(); (top)->signal = 1; (top)->eval();
#define NEGEDGE(top, signal) (top)->signal = 1; (top)->eval(); (top)->signal = 0; (top)->eval();

#include <iostream>

using namespace std;

int main() {
  assert(false);
}