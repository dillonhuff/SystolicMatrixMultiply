#define POSEDGE(top, signal) (top)->signal = 0; (top)->eval(); (top)->signal = 1; (top)->eval();
#define NEGEDGE(top, signal) (top)->signal = 1; (top)->eval(); (top)->signal = 0; (top)->eval();

#define RESET(top) POSEDGE(top, rst); NEGEDGE(top, rst); POSEDGE(top, rst);

#include <iostream>

using namespace std;
