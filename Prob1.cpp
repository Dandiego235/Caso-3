#include "Stack.cpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Función que pasa una expresión con notación infija a posfija.
// Entradas: String con una expresión en notación infija.
// Salida: String con una expresión en notación posfija.
string convertPostfix(string pString){
    Stack<string> stack; // pila para almacenar los caracteres de los operadores
    string postfix = ""; // String para ir construyendo el resultado

    string caracter; // String para almacenar los caracteres que se van leyendo
    string numberAdd = ""; // String para almacenar numeros por si tienen más de 1 dígito.

    while (pString.length() != 0){ // Mientras el string no esté vacío,
        caracter = pString[0]; // Obtiene el primer caracter
        pString = pString.substr(1); // y recorta el string a partir de la primera letra.
        if (caracter == " "){ // Si el caracter es un espacio, continúa.
            continue;
        }
        
        string numString = "0123456789"; // String para verificar si un caracter es un número.
        if (numString.find(caracter) != numString.npos){ // Si el resultado no es npos, sí es un número.
            numberAdd += caracter; // Lo concatena a nuestro string de número por si vienen más dígitos después.
        } else {
            if (numberAdd != ""){ // Si tenemos un número acumulado en numberAdd, lo agrega al string postfix y reestablece numberAdd.
                postfix += numberAdd + " ";
                numberAdd = "";
            }
            if (caracter == "("){ // If caracter es un paréntesis izquierdo, lo metemos en la pila.
                stack.push(caracter);
            } else if (caracter == ")"){ // Si es un paréntesis derecho, sacamos todo de la pila hasta que encontramos el paréntesis izquierdo.
                while (stack.size() != 0 && *stack.getTop() != "("){
                        postfix += *stack.pop() + " ";
                    }
                    stack.pop(); // sacamos el paréntesis izquierdo de la pila.
            } else if (caracter == "*" || caracter == "/" || caracter == "%"){
                // si el caracter es un *, / o %, 
                if (stack.size() == 0 || *stack.getTop() == "+" or *stack.getTop() == "-"){
                    // Si el stack está vacío o si el operador en el top tiene una precedencia menor, se mete al stack.
                        stack.push(caracter);
                    } else {
                        string opString = "*/%"; // String para agrupar los operadores con la mayor precedencia.
                        while (stack.size() != 0 && opString.find(*stack.getTop()) != opString.npos){
                            // mientras el stack no sea 0 y el caracter que sacamos sea un *, / o %,
                            postfix += *stack.pop() + " "; // Agregamos el caracter que sacamos al postfix.
                        }
                        stack.push(caracter); // Metemos el caracter que leímos al stack.
                    }
            } else if (caracter == "+" || caracter == "-"){
                // Si el caracter es un + o un -, 
                if (stack.size() == 0 || *stack.getTop() == "("){
                    // Si la pila está vacía o hay un paréntesis izquierdo, metemos el caracter en la pila.
                    stack.push(caracter);
                } else { // si no está vacía o si no es un (, sacamos todo lo que haya en la pila hasta que quede vacía o nos topemos el paréntesis.
                    while (stack.size() != 0 && *stack.getTop() != "("){
                        postfix += *stack.pop() + " ";
                    }
                    stack.push(caracter); // metemos el caracter en la pila.
                }
            }
        }
    }
    if (numberAdd != ""){ // Cuando terminamos de leer, puede que quede un número acumulado, entonces lo agregamos a postfix.
        postfix += numberAdd + " ";
    }
    while (stack.size() != 0){ // Se agregan los operadores que quedaron en la pila.
        postfix += *stack.pop() + " ";
    }
    return postfix; // Retorna postfix, el resultado en notación postfija.
}

// Función que recibe un string en notación posfija y la evalúa,
// Entrada: String con una expresión en notación posfija.
// Salida: Entero con el resultado de la evaluación.
int evaluatePostfix(string pString){
    Stack<int> stack; // pila para los números de la operación.
    int operando1 = 0; // variable para el primer operando
    int operando2 = 0; // Variable para el segundo operando.
    string caracter; // String para el caracter que se está procesando.
    stringstream ss; // stringstream para convertir los strings a ints.
    int num = 0; // Variable para almacenar el resultado de las conversiones.

    while (pString.length() != 0){ // Mientras el string no sea 0.
        caracter = pString[0]; // Se obtiene el primer caracter.
        pString = pString.substr(1); // Se recorta el string.

        if (caracter == " "){ // Si el caracter es un espacio.
            if (ss.str().empty() == false){ // Revisamos que el stringstream no esté vacío.
                ss >> num; // Se almacena el string convertido a entero en num.

                stack.push(num); // Se mete a num en la pila.
                ss.clear(); // Se reestablece el stringstream.
                ss.str("");
            }
            continue;
        }
        string numString = "0123456789"; // string para verificar si el caracter es un dígito.
        if (numString.find(caracter) != numString.npos){ // Si encuentra el caracter en el string, es un dígito.
            ss << caracter; // Se concatena al stream.
        } else { // Si no es un dígito, es un operador.
            operando2 = *stack.pop(); // Se sacan los dos números anteriors para usarlos de operandos.
            operando1 = *stack.pop();
            if (caracter == "*"){ // Si es un *, se multiplican y el resultado se mete a la pila.
                stack.push(operando1*operando2);
            } else if (caracter == "/"){ // Si es un /, se dividen y el resultado se mete a la pila.
                stack.push(operando1/operando2);
            } else if (caracter == "%"){ // Si es un %, se obtiene el residuo y el resultado se mete a la pila.
                stack.push(operando1%operando2);
            } else if (caracter == "+"){ // Si es un +, se suman y el resultado se mete a la pila.
                stack.push(operando1+operando2);
            } else { // Si es un -, se restan y el resultado se mete a la pila.
                stack.push(operando1-operando2);
            }
        }
    }
    return *stack.pop(); // Retorna el primer elemento de la pila, que al final debería ser el único y el resultado.
}

main(){
    string entradañ
    cout << "Ingrese el número: " << endl;
    cin >> entrada;
    string postfix = convertPostfix(entrada);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;
}