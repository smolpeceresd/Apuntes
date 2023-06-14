# Ejercicio 1

- Se debe realizar la función de Fibonazzi de forma recursiva. -> KO No has hecho recursividad.
- Se debe repetir el proceso tantas veces como el usuario quiera. -> OK 
- Se debe mostrar el resultado de la función de Fibonazzi. -> OK 

IMPORTANTE

- Si el usuario introduce un número negativo, se debe mostrar un mensaje de error y volver a pedir el número. -OK
- Si se piden 4 números de la sucesión saldrá : 0 1 1 2 . ->OK 

## Resolucion Ejercicio 1 4 OK 1 KO => Realmente KO , si lo califico es un 0.  ☹️ 

- Una función VOID que tiene un return ? NUNCA.

<img width="480" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/c41e3b09-83bb-45b4-829f-47c451d0050b">

- Mala gestión del negativo.

<img width="454" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/d49d3414-6a83-406e-99fd-33961d8b0006">

- Esto no es la eficiencia de la recursividad.

<img width="320" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/1af90daa-f320-445b-80bc-1417f991f8ad">

- Intentas forzar el cierre del programa y en caso de ser intencionado, no lo hace.

<img width="484" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/dc2ecbc1-5148-4cfa-bc9f-2ebf309c64d5">


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

- Forma corta -> función find(). (Mejor opción Recursividad).
- Sin la función fund().

Salida

<img width="800" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/0d8172e8-f9d8-4466-a716-eb6753f5e3b3">

# Ejercicio 3

- Se debe pedir al usuario que introduzca cualquier tipo de texto. -> OK
- La palabra para finalizar el conteo debe ser "Salir". -> OK
- Se debe guardar cuantas veces se escribe cada palabra. -> OK
- Adicionalmente se debe calcular el número de veces que que se repite cada letra (La mejor opcion es la recursividad). -> KO
- Para este ejercicio la base de datos debe estar dentro del main. -> Ok
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


¡¡¡¡Importante!!!! -> Para poder hacer el UpperCase, añade estas librerías

 - include <algorithm>
 - include <string>
  

Salida
  
  
  - <img width="198" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/d8d1e659-5440-4886-a6af-c9a28511639b">
  - <img width="327" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/0eede980-ec1d-452a-85c2-599f05a7425e">
  - <img width="330" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/296b6721-52a4-4a32-a6a4-62af58190f6e">

  

# Importante

- Se deben entregar los ejercicios por separado.
- Se debe tener en cuenta que tipo de dato es mejor para manejar el almacenaje.
  
# Reolución del ejercicio 3 -> 4 OK 1 KO -> Funciona el flujo, pero con la rúbrica de abajo, diría que estaría suspenso, no hace lo que pido: 3 ☹️ 
- No tiene la misma salida. 
  
- No cuenta el número de veces que aparece una letra 
  
<img width="420" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/dafd83b5-ef18-4839-86b1-7fad979c08db">
  
-  Si meto la misma palabra 2 veces, en el funcionamiento normal, no cuenta el numero de veces que aparece la letra, y en este caso, no lo cueta 2 veces. 
  
<img width="451" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/8b84693a-1777-4e34-b9a8-cc3cc2c9065c">

- Creas la estructura para no usarla
  
 <img width="172" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/c5dfde32-1112-4003-8380-275532542799">

- Generas una función VOID en la que cuentas el número de letras y lo guardas en un vector que es un parámetro de la función ( muy mala practica )
  
 <img width="544" alt="image" src="https://github.com/carmenschez5/Apuntes/assets/54994511/ec147316-07b1-4fe6-ac09-c6a32be02705">
  
 - No se ha hecho el UpperCase()
