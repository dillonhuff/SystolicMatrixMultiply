#include "Vinner_product_3.h"
#include "verilated.h"

#include "verilator_utils.h"

void test_reset() {
  Vinner_product_3* top = new Vinner_product_3();

  RESET(top);

  assert(top->c == 0);

  delete top;
}

void test_normal_run() {
  Vinner_product_3* top = new Vinner_product_3();

  top->u_valid = 0;
  top->v_valid = 0;
  
  RESET(top);

  assert(top->c == 0);

  // Loading data into fifos
  for (int i = 0; i < 3; i++) {
    top->u_valid = 1;
    top->u_in = i;

    top->v_valid = 1;
    top->v_in = i + 2;

    POSEDGE(top, clk);
  }

  assert(top->c == 0);

  top->u_valid = 0;
  top->v_valid = 0;

  for (int i = 0; i < 3; i++) {
    POSEDGE(top, clk);
  }

  assert(top->c == (0 + 1*3 + 2*4));

  delete top;
}

int main() {
  test_reset();
  test_normal_run();
}
