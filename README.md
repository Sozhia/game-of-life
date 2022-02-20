# game-of-life
## Enunciado
Un autómata celular es un modelo matemático y computacional para un sistema dinámico que evoluciona en pasos discretos. Es adecuado para modelar sistemas naturales que puedan ser descritos como una colección masiva de objetos simples que interactúan localmente.
No existe una definición formal aceptada de autómata celular. Sin embargo, se puede describir como una tupla de objetos caracterizado por los siguientes componentes:
* Una rejilla, o cuadrícula, de enteros infinitamente extendida con dimensión entera positiva. Cada celda se conoce como célula.
* Cada célula puede tomar un valor entero a partir de un conjunto finito de estados.
* Cada célula se caracteriza por su vecindad, un conjunto finito de células en las cercanías de la misma.
* De acuerdo con esto, se aplica a todas las células de la cuadrícula una función de transición que toma como argumentos los valores de la célula en cuestión y los valores de sus vecinos, y retorna el nuevo estado que la célula tendrá en la siguiente etapa de tiempo.

El juego de la vida es un juego de cero jugadores, lo que quiere decir que su evolución está determinada por el estado inicial y no necesita ninguna entrada de datos posterior. La rejilla se extiende hasta el infinito en todas las direcciones. El estado de las células evoluciona en unidades
de tiempo discretas, que denominaremos turnos.
En un turno cada célula de la rejilla actualiza su estado en función de su valor de estado y del estado de sus ocho células vecinas en el turno anterior. El cambio de estado dependerá del número de células vecinas vivas según las siguientes reglas de transición:
* Una célula “muerta” con exactamente 3 células vecinas con estado “viva” pasa al estado “viva” en el siguiente turno. En cualquier otro caso permanece “muerta”.
* Una célula “viva” con 2 ó 3 células vecinas con estado “viva” continúa “viva” en el siguiente turno. En cualquier otro caso pasa al estado “muerta”.

## Notas de implementación
- First item
- Second item
- Third item
    - Indented item
    - Indented item
- Fourth item 
