# 7 Fases de la Traducción y Errores

## Secuencia de Pasos

### Preprocesador

1. Escribí el código `hello2.c`
2. Preprocesé `hello2.c` con el comando `gcc -E hello2.c`
3. Escribí el código `hello3.c`
4. La funcion de la primera linea lo que intenta hacer es imprimir por consola un mensaje para ello espera necesariamente un puntero de tipo `char` y otros posibles (ninguno o muchos) argumentos, de los cuales no hay ninguna restricción sobre su tipo. Finalmente se devuelve un entero para indicar si se ejecutó con éxito la función o no.
5. Para preprocesar `hello3.c` y generar `hello3.i` use el siguiente comando `gcc -E hello2.c -o hello2.i`

### Compilación

1. Para compilar y generar `hello3.s` use la linea `gcc -S hello3.c`
2. Luego corregí los errores, así me quedo `hello4.c`:
```c
int printf(const char * restrict s, ...);
int main(void){
int i=42;
 prontf("La respuesta es %d\n");
}
``` 

3. - En el bloque `.LC0` prepara las constantes que sera utilizadas en este programa y hace movimientos en la pila para llamar a las funciones.
   - Las primeras instrucciones de main son para "preparar" la pila para posterior llamado de "prontf"
   - luego se hace un llamado a la función "prontf" y el código asume un retorno del llamado
   - Finalmente mueve un cero al acumulador y finaliza el programa.

4. Para ensamblar `hello4.s` en `hello4.o` use el siguiente comando `gcc -c hello4.s -o hello4.o`

### Vinculación

1. para vincular `hello4.o` use el comando `gcc hello4.o` pero me arrojo un error del *linker*.

2. Corregí el error y así me quedo `hello5.c`:

```c
int printf(const char * restrict s, ...);
int main(void){
  int i=42;
  printf("La respuesta es %d\n");
}
```

1. luego de ejecutar el código me arrojo lo siguiente por la terminal. Esto sucede porque la información que se le paso a printf esta haciendo uso de un puntero el cual no se le ingreso como segundo parámetro, entonces el comportamiento es indefinido.

```bash
La respuesta es 462609528
```

### Corrección de Bug

1. Corregí el código y así me quedo `hello6.c`:

```c
int printf(const char * restrict s, ...);
int main(void){
  int i=42;
  printf("La respuesta es %d\n", i);
}
```

### Remoción de Prototipo

1. Escribí `hello7.c`
2. Esto funciona porque el compilador gcc detecta que existe una declaración implícita de la función printf, como en este estándar (c18) no estaba definido el procedimiento a seguir, como se trata de la función printf se hace un tratamiento particular y la vincula con la función "built-in" de printf.

### Compilación Separada: Contratos y Módulos

1. Escribí `hello8.c` y `studio.c`
2. Para generar el ejecutable con ambos códigos fuente use `gcc studio.c hello8.c -o hello8`
3. Si se elimina el segundo argumento o ambos, tiene un comportamiento similar al de `hello5`. Si se agregan argumentos el compilador arroja un error ya que ahora si esta definido en el prototipo la cantidad de parametros que debe recibir y esta cantidad no se puede superar.
4. - Escribí `studio.h`
   - Escribí `hello9.c`
   - Escribí `studio2.c`
   - Permite definir de forma mas clara tanto al proveedor como al cliente sobre el comportamiento de la función que se desee desarrollar o utilizar.