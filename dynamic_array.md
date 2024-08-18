# Arreglos dinámicos
## Arreglos unidimensionales
La declaración de un arreglo unidimensional en lenguaje C se realiza de la siguiente forma.

``` C
[data type] *variable;
```

por ejemplo:
Inicialización y uso de un arreglo unidimensional dinámico
``` C
int *pv = (int*) malloc(5 * sizeof(int));  
+
for(int i=0; i<5; i++) {  
	pv[i] = i+1;  
}

```
### Actividad
Realice un programa en C que genere una lista de los primeros 10 números pares, deberá imprimirlos en orden inverso.

- posteriormente deberá modificar el valor almacenado en el índice correspondiente al último dígito de su número cuenta por -1
   Por ejemplo:
```markdown
| 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 | 20 |
```

Número de cuenta 410092686
```markdown
| 2 | 4 | 6 | 8 | 10 | 12 | -1 | 16 | 18 | 20 |
```

## Arreglos bidimensionales
La declaración de un arreglo bidimensional en lenguaje C se realiza de la siguiente forma.

``` C
[data type] variable [dimension1][dimension2];
```

por ejemplo:
Inicialización y uso de un arreglo bidimensional dinámico
``` C
int rows = 2;  
int columns = 5;  
int **matrix = (int **) malloc(rows * sizeof(int *));  

for (int i = 0; i < rows; i++) {  
	matrix[i] = (int *) malloc(columns * sizeof(int));  
}

```

### Actividad 1
Considere el  siguiente arreglo matricial:

```markdown
| Nombre   | Edad | Calificación |
|----------|------|--------------|
| Alberto  | 22   | 9            |
| Fernando | 19   | 4            |
| ...   	  | ...  | ...          |
| Brenda   | 34   | 7            |
```

Realice un programa que acepte una lista de *n* alumnos, el arreglo deberá ser de *n*x3, la primera columna deberá tener un espacio de 25 caracteres, la segunda y tercera deberá aceptar números enteros.

- El programa después de capturar los datos, deberá devolver el promedio de edad y de calificación grupal.
- El programa deberá imprimir los nombres de los alumnos en sentido inverso al que fueron ingresados o se encuentran almacenados.
- Puede ser del tipo char todo el arreglo, solo recuerde hacer el "casteo" para los elementos numéricos.

### Actividad 2

Genere un arreglo dinámico variable bidimensional de acuerdo a su número de cuenta y será rellenado con los dígitos correspondientes a su cuenta. Por ejemplo para el número de cuenta 410592683:

```markdown
| 4 | 4 | 4 | 4 | 
| 1 |
| 5 | 5 | 5 | 5 | 5 |
| 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 |
| 2 | 2 |
| 6 | 6 | 6 | 6 | 6 | 6 |
| 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 | 9 |
| 3 | 3 | 3 |
```

- El programa deberá solicitar el número de cuenta al usuario.

*nota*: en los ejemplos previos no se ha considerado el caso en que no sea posible asignar el espacio necesario de forma dinámica
``` C
if (ptr == NULL)
	return -1;
```

Se recomienda la lectura del libro: Understanding and Using C Pointers, capítulo 4 y 5
