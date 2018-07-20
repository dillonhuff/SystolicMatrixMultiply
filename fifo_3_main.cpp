#include "Vfifo_3.h"
#include "verilated.h"

#define POSEDGE(top, signal) (top)->signal = 0; (top)->eval(); (top)->signal = 1; (top)->eval();
#define NEGEDGE(top, signal) (top)->signal = 1; (top)->eval(); (top)->signal = 0; (top)->eval();

#include <iostream>

using namespace std;

void test_reset() {
  Vfifo_3* top = new Vfifo_3();

  POSEDGE(top, rst);
  NEGEDGE(top, rst);
  POSEDGE(top, rst);

  assert(top->data_valid == 0);
  
  delete top;
}

void test_valid_out() {
  Vfifo_3* top = new Vfifo_3();

  POSEDGE(top, rst);
  NEGEDGE(top, rst);
  POSEDGE(top, rst);

  assert(top->data_valid == 0);

  top->in_data_valid = 1;
  top->in_data = 23;

  POSEDGE(top, clk);

  top->in_data = 5;

  assert(top->data_valid == 0);
  assert(top->data_out == 0);

  POSEDGE(top, clk);

  top->in_data = 78;
  
  assert(top->data_valid == 0);
  assert(top->data_out == 0);  

  POSEDGE(top, clk);

  top->in_data_valid = 0;

  assert(top->data_valid == 1);
  assert(top->data_out == 23);

  POSEDGE(top, clk);

  assert(top->data_valid == 1);
  assert(top->data_out == 5);

  POSEDGE(top, clk);

  assert(top->data_valid == 1);
  assert(top->data_out == 78);

  POSEDGE(top, clk);

  assert(top->data_valid == 0);
  
}

int main() {
  test_reset();
  test_valid_out();
}
