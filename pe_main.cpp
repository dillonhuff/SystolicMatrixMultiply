#include "Vpe.h"
#include "verilated.h"

#define POSEDGE(top, signal) (top)->signal = 0; (top)->signal = 1; (top)->eval();
#define NEGEDGE(top, signal) (top)->signal = 1; (top)->signal = 0; (top)->eval();

#include <iostream>

using namespace std;

void test_rst() {
  Vpe* top = new Vpe();

  POSEDGE(top, rst);
  NEGEDGE(top, rst);

  assert(top->dbg_c == 0);

  delete top;
}

void test_accumulate() {

  Vpe* top = new Vpe();
  top->clk = 0;
  top->rst = 0;

  POSEDGE(top, rst);
  NEGEDGE(top, rst);
  POSEDGE(top, rst);

  assert(top->dbg_c == 0);

  top->input_valid = 1;
  top->a = 10;
  top->b = 3;

  POSEDGE(top, clk);

  cout << "c = " << top->dbg_c << endl;

  assert(top->dbg_c == 30);
  
  delete top;
}

int main() {
  test_rst();
  test_accumulate();
}
