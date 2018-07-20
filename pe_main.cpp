#include "Vpe.h"
#include "verilated.h"

#include "verilator_utils.h"

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

  top->a = 3;
  top->b = 5;

  POSEDGE(top, clk);
  
  assert(top->dbg_c == (30 + 15));
  
  delete top;
}

int main() {
  test_rst();
  test_accumulate();
}
