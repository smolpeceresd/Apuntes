# Ejercicio 1

- Se debe realizar la función de Fibonazzi de forma recursiva.
- Se debe repetir el proceso tantas veces como el usuario quiera.
- Se debe mostrar el resultado de la función de Fibonazzi.

IMPORTANTE

- Si el usuario introduce un número negativo, se debe mostrar un mensaje de error y volver a pedir el número.
- Si se piden 4 números de la sucesión saldrá : 0 1 1 2 .

# Ejercicio 2

- Se debe buscar una subcadena dentro de un texto.
- La subcadena que se debe buscar la debe introducir el usuario.
- El texto es predetermiando, si la palabra que se busca no esta en el texto, se debe indicar que esta palabra no existe en el texto.
- Se debe mostrar la posición donde se encuentra cada ocurrencia.
- Se debe mostrar el número total de ocurrencias.

El texto:

El rey de Constantinopla esta constantinoplizado.
Consta que Constanza, no lo pudo desconstantinoplizar.
El desconstantinoplizador que desconstantinoplizare al rey de Constantinopla,buen desconstantinoplizador será.

Se debe buscar la subcadena: Consta.

No es CaseSensitive, es decir, la palabra puede tener cualquier estructura de mayúsculas y minúscualas.

Realizar de 2 formas:

- Forma corta -> dunción find(). (Mejor opción Recursividad).
- Sin la función fund().

Salida

Palabra: Santiago
Número de repeticiones: 2
Posiciones : 1, 2 ,3

# Ejercicio 3

- Se debe pedir al usuario que introduzca cualquier tipo de texto.
- La palabra para finalizar el conteo debe ser "Salir".
- Se debe guardar cuantas veces se esribe cada palabra.
- Adicionalmente se debe calcular el número de veces que que se repite cada letra (La mejor opcion es la recursividad).
- Para este ejercicio la base de datos debe estar dentro del main.
  EJEMPLO

cin>> Santiago

cin>> Carmen

Salida

<img width="311" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/4872fef8-22b2-46ac-97fd-f879e3381d58">

---

Pista->

Para hacer este apartado, es mejor usar la función UpperCAse().
Cuando decimos que un lenguaje es CaseSensitive, es que distingue entre masyúsculas y minúsculas.
Para poder encontrar todas las 'A' que hay , debemos contemplar 'A' & 'a'. La forma más sencilla para poder hacer esto es convertir todo el texto a mayúsculas o minúsculas.

Ejemplo de UpperCase() Poner en mayúsculas todo el texto.

std::string str = "Hello World";

std::transform(str.begin(), str.end(), str.begin(), ::toupper);


<img width="472" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/504baf2e-65b5-4f6c-b947-3601d957583c">


¡¡¡¡mportante!!!! -> Para poder hacer el UpperCase, añade estas librerías

#include <algorithm>

#include <string>
A -> 3

C -> 1

E -> 1

I -> 1

M -> 1

N -> 2

R -> 1

S -> 1

T -> 1

# Importante

- Se deben entregar los ejercicios por separado.
- Se debe tener en cuenta que tipo de dato es mejor para manejar el almacenaje.
