#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Conversion.h"

int main() {
  // Tests Farenheit
  const int delta = 0.0000000001;
  const double resultadoCelsius = abs(Celsius(40) - 4.444444444444444);
  const double resultadoFarenheit = abs(Farenheit(1.54321) - 34.777778);

  printf("%lf", resultadoFarenheit);

  // assert(Celsius(32) == 0);
  // assert(resultadoCelsius < delta);

  // assert(Farenheit(0) == 32);
  // assert(resultadoFarenheit < delta);
  // PrintTablas(0, 25, 1);

  return 0;
}