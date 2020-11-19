# Cine Family Films
## Integrantes
* Luis Alonso Rivera Beltrán 00081220
* Fernando José Meléndez Orellana 00018720
* Kevin Alexander Mejia Hercules 00058620
* Samuel Adonay Ortiz Carballo 00023020
## Descripción
Family Films es un cine al aire libre que acaba de iniciar operaciones y debido a ello necesitaban un software que tiene los siguientes requerimientos:

* Realizar transacciones para la compra de tickets para películas los cuales tienen un precio fijo de $3.50.
* Mostrar un ranking de las tres categorías y con ello mostrar cuál de ellas es más popular (Con el objetivo que el cine sepa a cual categoría es más viable invertir para obtener más ganancias).
* Mostrar las ganancias totales que ha tenido el cine desde su apertura hasta la última transacción.

## Estructuras utilizadas en el proyecto
Nuestro proyecto cuenta con varias estructuras entre las cuales tenemos:

-	3 registros (struct) utilizados dos en las transacciones, una es utilizada para almacenar la información de las películas y otra es utilizada para almacenar los datos de la transacción y la estructura restante es utilizada para ordenar el ranking a partir de la cantidad de tickets que se posee por género.
-	3 listas donde se guardarán las transacciones o ventas por cada genero de película con los que cuenta el software.
-	1 vector que utilizaremos para ver los géneros que mas tickets han vendidos, para desplegarse en pantalla desde el que más ha vendido hasta el que menos ha vendido.
 
