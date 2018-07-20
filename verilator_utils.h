#define POSEDGE(top, signal) (top)->signal = 0; (top)->eval(); (top)->signal = 1; (top)->eval();
#define NEGEDGE(top, signal) (top)->signal = 1; (top)->eval(); (top)->signal = 0; (top)->eval();

#include <iostream>

using namespace std;
