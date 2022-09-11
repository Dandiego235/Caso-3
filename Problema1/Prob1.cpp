#include "../Stack.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Función que pasa una expresión con notación infija a posfija.
// Entradas: String con una expresión en notación infija.
// Salida: String con una expresión en notación posfija.
string convertPostfix(string pString){
    Stack<char> stack; // pila para almacenar los caracteres de los operadores
    string postfix = ""; // String para ir construyendo el resultado

    char *caracter; // String para almacenar los caracteres que se van leyendo
    string numberAdd = ""; // String para almacenar numeros por si tienen más de 1 dígito.

    while (pString.length() != 0){ // Mientras el string no esté vacío,
        caracter = (char*) malloc(sizeof(char)); // Obtiene el primer caracter
        *caracter = pString[0];
        pString = pString.substr(1); // y recorta el string a partir de la primera letra.
        cout << *caracter << " y " << pString << endl;
        if (isdigit(*caracter)){ // Se revisa si el caracter es un número.
            numberAdd += *caracter; // Lo concatena a nuestro string de número por si vienen más dígitos después.
            delete caracter;
        } else {
            if (numberAdd != ""){ // Si tenemos un número acumulado en numberAdd, lo agrega al string postfix y reestablece numberAdd.
                postfix += numberAdd + " ";
                numberAdd = "";
            }
            switch(*caracter){
                case '(':
                    stack.push(caracter);
                    break;
                case ')':
                    while (stack.size() != 0 && *stack.getTop() != '('){
                        postfix.push_back(*stack.pop());
                        postfix += " ";
                    }
                    stack.pop(); // sacamos el paréntesis izquierdo de la pila.
                    break;
                case '*':
                case '/':
                case '%':
                    // si el caracter es un *, / o %, 
                    if (stack.size() == 0 || *stack.getTop() == '+' or *stack.getTop() == '-'){
                        // Si el stack está vacío o si el operador en el top tiene una precedencia menor, se mete al stack.
                            stack.push(caracter);
                    } else {
                        string opString = "*/%"; // String para agrupar los operadores con la mayor precedencia.
                        while (stack.size() != 0 && opString.find(*stack.getTop()) != opString.npos){
                            // mientras el stack no sea 0 y el caracter que sacamos sea un *, / o %,
                            postfix.push_back(*stack.pop()); // Agregamos el caracter que sacamos al postfix.
                            postfix += " ";
                        }
                        stack.push(caracter); // Metemos el caracter que leímos al stack.
                    }
                    break;
                case '+':
                case '-':
                    // Si el caracter es un + o un -, 
                    if (stack.size() == 0 || *stack.getTop() == '('){
                        // Si la pila está vacía o hay un paréntesis izquierdo, metemos el caracter en la pila.
                        stack.push(caracter);
                    } else { // si no está vacía o si no es un (, sacamos todo lo que haya en la pila hasta que quede vacía o nos topemos el paréntesis.
                        while (stack.size() != 0 && *stack.getTop() != '('){
                            postfix.push_back(*stack.pop());
                            postfix += " ";
                        }
                        stack.push(caracter); // metemos el caracter en la pila.
                    }
            }
        }
        stack.print();
    }
    if (numberAdd != ""){ // Cuando terminamos de leer, puede que quede un número acumulado, entonces lo agregamos a postfix.
        postfix += numberAdd + " ";
    }
    while (stack.size() != 0){ // Se agregan los operadores que quedaron en la pila.
        postfix.push_back(*stack.pop());
        postfix += " ";
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
    char *caracter; // String para el caracter que se está procesando.
    stringstream ss; // stringstream para convertir los strings a ints.
    int *num; // Variable para almacenar el resultado de las conversiones.
    

    while (pString.length() != 0){ // Mientras el string no sea 0.
        caracter = (char*) malloc(sizeof(char));
        *caracter = pString[0]; // Se obtiene el primer caracter.
        pString = pString.substr(1); // Se recorta el string.

        if (*caracter == ' '){ // Si el caracter es un espacio.
            if (ss.str().empty() == false){ // Revisamos que el stringstream no esté vacío.
                num = (int*) malloc(sizeof(int));
                ss >> *num; // Se almacena el string convertido a entero en num.

                stack.push(num); // Se mete a num en la pila.
                ss.clear(); // Se reestablece el stringstream.
                ss.str("");
            }
            delete caracter;
            continue;
        }
        if (isdigit(*caracter)){ // Se revisa si el caracter es un número.
            ss << *caracter; // Se concatena al stream.
            delete caracter;
        } else { // Si no es un dígito, es un operador.
            num = (int*) malloc(sizeof(int));
            operando2 = *stack.pop(); // Se sacan los dos números anteriors para usarlos de operandos.
            operando1 = *stack.pop();
            switch(*caracter){
                case '*':
                    *num = operando1*operando2;
                    break;
                case '/':
                    *num = operando1/operando2;
                    break;
                case '%':
                    *num = operando1%operando2;
                    break;
                case '+':
                    *num = operando1+operando2;
                    break;
                case '-':
                    *num = operando1-operando2;
            }
            stack.push(num);
        }
    }
    return *stack.pop(); // Retorna el primer elemento de la pila, que al final debería ser el único y el resultado.
}

main(){
    string entrada;
    cout << "Ingrese la expresión: " << endl;
    cin >> entrada;
    string postfix = convertPostfix(entrada);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;
}

// Revisar is digit
//25*7+(100-25)%4-17/3