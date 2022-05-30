#include <stdio.h>

#include "Conversion.h"

void PrintTablas(double limiteInferior, double limiteSuperior,
                 double incremento);

void PrintTablaCelcius(double limiteInferior, double limiteSuperior,
                       double incremento);

void PrintTablaFarenheit(double limiteInferior, double limiteSuperior,
                         double incremento);

void PrintFilas(double (*conversion)(), double limiteInferior,
                double limiteSuperior, double incremento);

void PrintFila(double (*conversion)(), double temperatura);

int main() {
  const double li = 0, ls = 5, i = 0.2;

  PrintTablas(li, ls, i);

  return 0;
}

void PrintTablas(double limiteInferior, double limiteSuperior,
                 double incremento) {
  PrintTablaCelcius(limiteInferior, limiteSuperior, incremento);
  printf("\n");
  PrintTablaFarenheit(limiteInferior, limiteSuperior, incremento);
}

void PrintTablaCelcius(double limiteInferior, double limiteSuperior,
                       double incremento) {
  printf(
      "  ºF  |  ºC  \n"
      "-------------\n");

  PrintFilas(Celsius, limiteInferior, limiteSuperior, incremento);
}

void PrintTablaFarenheit(double limiteInferior, double limiteSuperior,
                         double incremento) {
  printf(
      "  ºC  |  ºF  \n"
      "-------------\n");

  PrintFilas(Farenheit, limiteInferior, limiteSuperior, incremento);
}

void PrintFilas(double (*conversion)(), double limiteInferior,
                double limiteSuperior, double incremento) {
  for (double i = limiteInferior; i < limiteSuperior; i += incremento) {
    PrintFila(conversion, i);
  }
}

void PrintFila(double (*conversion)(), double temperatura) {
  printf("%-6.2lf|%6.2lf\n", temperatura, conversion(temperatura));
}