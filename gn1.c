#include <math.h>
#include "MT.h"
#define pi 3.14159265358979323846
// sgma は分散の平方根
double gn1(double sgma,double mu){
  double z,x,u;
  u=genrand_real3();
  z=sgma*(sqrt(2.0*log(1.0/(1.0-u))));
  u=genrand_real3();
  x=z*cos(2.0*pi*u);
  return x+mu;
}
