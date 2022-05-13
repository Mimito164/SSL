#include "Conversion.h"

#include <stdio.h>

double Celsius(double Farenheit) { return 5 * (Farenheit - 32) / 9; }

double Farenheit(double Celsius) { return (9 * Celsius / 5) + 32; }

void PrintTablas(int limiteInferior, int limiteSuperior, int incremento) {
  PrintTablaCelcius(limiteInferior, limiteSuperior, incremento);
  printf("\n");
  PrintTablaFarenheit(limiteInferior, limiteSuperior, incremento);
}

void PrintTablaCelcius(int limiteInferior, int limiteSuperior, int incremento) {
  printf(
      "  ºF  |  ºC  \n"
      "-------------\n");

  PrintFilas(Celsius, limiteInferior, limiteSuperior, incremento);
}

void PrintTablaFarenheit(int limiteInferior, int limiteSuperior,
                         int incremento) {
  printf(
      "  ºC  |  ºF  \n"
      "-------------\n");

  PrintFilas(Farenheit, limiteInferior, limiteSuperior, incremento);
}

void PrintFilas(double (*conversion)(), int limiteInferior, int limiteSuperior,
                int incremento) {
  for (int i = limiteInferior; i < limiteSuperior; i += incremento) {
    PrintFila(conversion, i);
  }
}

void PrintFila(double (*conversion)(), double temperatura) {
  printf("%-6.2lf|%6.2lf\n", temperatura, conversion(temperatura));
}