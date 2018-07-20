#include "Vmul_2x2.h"
#include "verilated.h"

#include "verilator_utils.h"

int main() {
  Vmul_2x2* top = new Vmul_2x2();

  RESET(top);

  

  delete top;
}
