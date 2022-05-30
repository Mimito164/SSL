#include <assert.h>

#include "Conversion.h"

int main() {
  const double delta = 0.0000000000001;
  const double resultadoCelsius = Celsius(40) - 4.444444444444444;
  const double resultadoFarenheit = Farenheit(1.54321) - 34.777778;

  assert(Celsius(32) == 0);
  assert(resultadoCelsius < delta);

  assert(Farenheit(0) == 32);
  assert(resultadoFarenheit < delta);

  return 0;
}
