#ifndef CONVERSION
#define CONVERSION

// Aca irian los prototipos....
double Celsius(double Farenheit);

double Farenheit(double Celsius);

void PrintTablas(int limiteInferior, int limiteSuperior, int incremento);

void PrintTablaCelcius(int limiteInferior, int limiteSuperior, int incremento);

void PrintTablaFarenheit(int limiteInferior, int limiteSuperior,
                         int incremento);

void PrintFilas(double (*conversion)(), int limiteInferior, int limiteSuperior,
                int incremento);

void PrintFila(double (*conversion)(), double temperatura);

#endif  // CONVERSION
