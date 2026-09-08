# Actividad Ordenamiento

## Resultados

Tiempo promedio de 30 búsquedas, en nanosegundos:

| Tamaño de entrada | Búsqueda Lineal | Búsqueda Binaria | Búsqueda Trinaria |
|---:|---:|---:|---:|
| 10⁵ | 156 806 ns | 206 ns | 200 ns |
| 10⁶ | 1 589 170 ns | 953 ns | 613 ns |
| 10⁷ | 20 055 170 ns | 1 393 ns | 926 ns |
| 10⁸ | 135 288 780 ns | 1 833 ns | 1 336 ns |


## Complejidad computacional
 
| Algoritmo | Complejidad temporal |
|---|---|
| `busquedaLineal` | O(n) |
| `busquedaBinaria` | O(log₂ n) |
| `busquedaTrinaria` | O(log₃ n) |

## Análisis de resultados

**Búsqueda lineal.**
Aquí el tiempo crece de manera casi de manera proporcional al tamaño de 
la entrada. Al pasar de 10^5 a 10^8, la entrada aumento con un factor de 1000, y la
salida aumentó en un factor de 862, lo que es coherente con su complejidad.

**Búsqueda binaria y trinaria.** 
Ambas crecen de manera mucho más lenta: al pasar de 10⁵ a 10⁸ elementos el tiempo solo 
sube aproximadamente 1600 ns en la binaria, y 1200 en la trinaria.
En uno crece x6 y en el otro x10, podemos ver que al tener una entrada muy grande, la 
salida fue muy chica lo que confirma su crecimiento logarítmico

**Binaria vs. trinaria.** Aunque log₃ n < log₂ n, que teoricamente la trinaria 
realiza menos iteraciones, esto no significa que sea más rápida en todos los casos.
Esto se debe a que cada iteración de la búsqueda trinaria requiere hasta 2 comparaciones,
en vez de 1 como la binaria y más operaciones aritméticas

## Conclusión

No existe un único algoritmo que sea más rápido siempre en todos los casos.

La busqueda lineal es la más lenta, su tiempo crece linealmente. Las busquedas binarias
son O(log n), en notación Big O tienen la misma complejidad, para este experimento la
busqueda trinaria fue la mas rapida, pero en otros casos puede ser más lenta que la
binaria, por el número de comparaciones que debe hacer y por otros motivos de hardware.
