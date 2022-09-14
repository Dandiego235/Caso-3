# Caso 3
**Estructuras de Datos**  
*Por: Daniel Granados Retana, carné 2022104692*  
  
*Prof. Rodrigo Núnez*  
  
*Problema 1*
-------------------------
En este problema, para hacer la conversión de infijo a posfijo, realicé el procedimiento en dos partes:
1. Convertí el string de la expresión infija a un string de la expresión posfija.
2. Con el string de la expresión posfija, lo evalué usando una pila para guardar los operandos.  
  
Usé un algoritmo de conversión de infija a posfija que consiste en lo siguiente:
1. Si leemos un número, lo agregamos al string.
2. Si leemos un paréntesis izquierdo lo metemos en la pila.
3. Si leemos un paréntesis derecho, sacamos todos los operadores de la pila y los agregamos al string.
4. Si leemos un operador:
4.1 Si el operador al tope de la pila tiene menor precedencia, agregamos el nuevo operador a la pila.
4.2 Si el operador al tope de la pila tiene igual o mayor precedencia, lo sacamos de la pila y lo agregamos al string. Hacemos esto hasta que no se cumpla esta condición y metemos el nuevo operador en la pila.
5. Si al final de analizar la expresión quedan operandos en la pila, los sacamos.

Luego para evaluar la expresión posfija, se usó el siguiente algoritmo:
1. Si se lee un número, se mete a la pila.
2. Si se lee un operando, se sacan los primeros dos elementos de la pila y se operan. El resultado se vuelve a meter en la pila.  

Se repite este proceso hasta que se acabe de analizar la expresión.

Para implementar la estructura de pila, se usó una lista doblemente enlazada, donde la operación de push agrega al principio y la de pop elimina del principio. Así, se evita recorrer toda la lista para agregar o remover al final.

En este problema, se le pide una expresión para que digite el usuario. Este expresión no puede contener espacios, debe ser todo pegado. Adicionalmente, no se considera una multiplicación implícita entre paréntesis, como en la expresión (2+1)(3-17), por lo que no es permitido.

*Problema 2*
----------------------
En este problema, debíamos implementar la estructura de datos cola usando como máximo 2 pilas.

Para esta implementación, se usaron 2 pilas. Se desarrolló en el archivo queue_stack.cpp
Esta consiste en tener una pila donde se van a meter los nuevos elementos y tener otra pila donde se van a sacar. El problema de las pilas, es que solo puedo sacar del final, y con la cola yo necesito poder sacar del principio. Por lo tanto, la segunda pila va a necesitar tener los elementos de la primera pila en un orden invertido.

Para lograr esto, cuando vamos a hacer un dequeue o conseguir el elemento en el "front", sacamos todos los elementos de la pila de enqueue y se meten inmediatamente en la pila de dequeue. Así, la pila de dequeue queda con los elementos en un orden invertido. El del principio va a quedar al tope de la pila. Este procedimiento se hace en el método privado prepareDequeue(). Este método se hace por aparte porque en ocasiones se ocupa hacer este procedimiento para hacer un dequeue o para obtener el elemento front. Al hacer este procedimiento un método aparte, se pudo reutilizar el código.

En el archivo Prob2.cpp, se realizó una prueba de que todas las operaciones requeridas funcionaran correctamente.

*Problema 3*
---------------------------
Para modelar los vuelos, se definió la clase Flight, la cual contiene atributos como el nombre de la aerolínea, el número de vuelo, la cantidad de pasajeros y la hora del vuelo. La hora del vuelo es el atributo flightTime de tipo time_t. Este es un tipo de datos entero que almacena la cantidad de segundos a partir del epoch definido. Por esta razón, a menor la hora de vuelo, menor va a ser este valor. Por lo tanto, resulta muy útil para ordenar los vuelos en cuanto a una prioridad ascendente, donde los vuelos que salen más temprano tienen una mayor prioridad.

Para generar los vuelos aleatorios, se usó un método que depende del uso de uniform_int_distribution de la librería <random>, la cual busca generar una probabilidad uniforme para cada número del rango. Así, se pudo generar una hora de salida y un atraso aleatorios para cada vuelo. Adicionalmente, se asignó una aerolínea aleatoria entre los valores de un arreglo.

Para ordenar los vuelos, se usaron colas por prioridad, definidas en la clase PriorityQueue. Para conformar estas estructuras, se usaron las clases PriorityNode y PriorityList, las cuales son iguales a sus contrapartes sin prioridad, pero agregan la implementación de la prioridad, la cual es un atributo de tipo entero en el nodo.

En la clase PriorityQueue se crearon los métodos para enqueue y dequeue. El método enqueue recorre la cola e inserta el elemento justo antes del nodo que tenga una prioridad mayor, ya que las prioridades van de menor a mayor. Esto se permite por medio del método insertAtNode, de PriorityList, que inserta justo antes de un nodo.

El método de dequeue simplemente borra y retorna el elemento en la primera posición.

Para representar el aeropuerto y las pistas, se creó la clase Airport, la cual contiene principalmente un vector que contiene PriorityQueues con tipo de Flight. Estas colas van a representar las pistas. Se accede a cada pista con su índice del vector. Para ir llenando las pistas, se va agregando un vuelo uno por uno a cada pista, y de esta forma las pistas quedan con una distribución balanceada. Como la generación de vuelos fue aleatoria, los vuelos que quedan en cada pista también es aleatorio. Sin embargo, sí quedan ordenados de acuerdo con su prioridad, por lo que el primer vuelo de la cola será el primer en salir.

El método departures() simula las salidas. Va obtienendo el primer elemento de la primera pista no vacía y lo compara con los primeros elementos de las otras pistas para quedarse con el menor de todos. Cuando tiene el menor elemento, imprime sus datos y lo saca de la cola. Cuando una pista queda vacía, elimina este índice, para que no la pueda volver a acceder. De esta forma, se van sacando los vuelos en el orden correcto.

Finalmente, en el archivo Prob3.cpp, se tiene el código main para ejecutar esta simulación. En la sección de definición de constantes, podemos cambiar el atraso, con la constante OFFSET, el número de aerolíneas, la cantidad máxima de pasajeros y la cantidad de pistas que tendrá el aeropuerto.

En este archivo, se crean los vuelos con la función fillFlights, la cual llena una lista de vuelos con vuelos aleatorios. Se le puede pasar la cantidad de vuelos, la hora de inicio y la hora final como argumentos. Seguidamente, se crea un objeto del aeropuerto, se le asigna la lista de vuelos para que llene las pistas y se llama el método de departures para que imprime el planeamiento de la salida de los aviones.
