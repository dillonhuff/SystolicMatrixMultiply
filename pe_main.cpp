#include "Vpe.h"
#include "verilated.h"

#define POSEDGE(top, signal) (top)->signal = 0; (top)->signal = 1;
#define NEGEDGE(top, signal) (top)->signal = 1; (top)->signal = 0;

void test_rst() {
  Vpe* top = new Vpe();

  POSEDGE(top, rst);
  NEGEDGE(top, rst);

  assert(top->dbg_c == 0);

  delete top;
}

int main() {
  test_rst();
}
