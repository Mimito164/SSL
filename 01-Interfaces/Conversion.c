#include "Conversion.h"

double Celsius(double Farenheit) { return 5 * (Farenheit - 32) / 9; }

double Farenheit(double Celsius) { return (9 * Celsius / 5) + 32; }