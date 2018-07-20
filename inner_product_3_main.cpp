#include "Vinner_product_3.h"
#include "verilated.h"

#include "verilator_utils.h"

void test_reset() {
  Vinner_product_3* top = new Vinner_product_3();

  RESET(top);

  assert(top->c == 0);

  delete top;
}

int main() {
  test_reset();
}
