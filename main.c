#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>




void primeFactors(int number) {

    int factors[100];
    int NFactors = 0;
    int exponentiation[100];
    int powerOfaNumber;


    for (int i = 2; i <= sqrt(number); i++) {
        powerOfaNumber = 0;
        while (number % i == 0) {
            powerOfaNumber++;
            number /= i;
        }
        if (powerOfaNumber > 0) {
            factors[NFactors] = i;
            exponentiation[NFactors] = powerOfaNumber;
            NFactors++;
        }
    }

    if (number > 2) {
        factors[NFactors] = number;
        exponentiation[NFactors] = 1;
        NFactors++;
    }

    for (int i = 0; i < NFactors - 1; i++) {
        for (int j = i + 1; j < NFactors; j++) {
            if (factors[i] < factors[j]) {
                int temp = factors[i];
                factors[i] = factors[j];
                factors[j] = temp;
                temp = exponentiation[i];
                exponentiation[i] = exponentiation[j];
                exponentiation[j] = temp;
            }
        }
    }

    for (int i = 0; i < NFactors; i++) {
        printf("%d^%d ", factors[i], exponentiation[i]);
    }
    printf("\n");
}

int auxiliarPrimeFactors() {

    int number;
    printf("\n    >>Factores Primos\n");
    printf("-Digite el numero a descomponer: ");
    scanf("%d", &number);
    printf("Los factores primos de %d expresados en potencias es: \n", number);
    primeFactors(number);

    return 0;

}


void removeSpaces(char *text) {
    int len = strlen(text);
    int i = 0;
    int j = 0;

    while (isspace(text[i]) && i < len) i++;

    while (isspace(text[len - 1]) && len > 0) len--;

    while (i < len) {
        if (!isspace(text[i]) || (isspace(text[i]) && !isspace(text[j - 1]))) {
            text[j++] = text[i];
        }
        i++;
    }

    text[j] = '\0';
}

char auxiarRemoveSpaces() {
#define MAX_LEN 100
    char text[MAX_LEN];

    printf("Digite una oracion con espacio doble: ");
    fflush(stdin);
    fgets(text, MAX_LEN, stdin);

    removeSpaces(text);
    printf("Asi quedo la oracion ingresada sin los espacios dobles: \n%s ", text);
    printf("\n");
    return 0;
}

int narcissisticNumbers(int number) {
    int digits = floor(log10(number) + 1);
    char cadena[digits + 1];;

    sprintf(cadena, "%d", number);

    int addition = 0;
    for (int i = 0; i < digits; i++) {
        int cont = cadena[i] - '0';

        int elevated = pow(cont, digits);
        addition = addition + elevated;
    }
    if (addition == number) {
        return 1;
    } else {
        return 0;
    }
}

char auxiliarNarcissisticNumbers(){
    int num = 0;
    printf("-------Numeros Egolatras-----\n");
    printf("Ingrese el numero \n ");
    scanf("%d", &num);
    printf("El numero %d %s", num, narcissisticNumbers(num) ? "es egolatra" : "No es egolatra\n");
}

int NumeroMagico(int number) {
    int num1, num2, num3, aux;
    while (num2 <= 9) {
        aux = number;
        while (aux > 0) {
            num3 = aux % 10;
            if (num3 == num2) {
                num1 = (num1 * 10) + num3;
            }
            aux = (aux - num3) / 10;
        }
        num2 = num2 + 1;
    }
    int numMen = num1;
    int inverted = 0;
    while (num1 > 0) {
        inverted = (inverted * 10) + (num1 % 10);
        num1 = num1 / 10;

    }
    int numMay = inverted;

    int sustraccion = numMay - numMen;
    if ( sustraccion== number) {
        return 1;
    } else {
        return 0;
    }

}
int multiplicacionDeMatrices() {
    int a[10][10], b[10][10], c[10][10];
    int fila1, fila2, columna1, columna2;

    int cont, aux;

    printf("\n Digite el numero de filas de la primer matriz  \n");
    scanf("%d", &fila1);

    printf("Digite el numero de columnas de la primer matriz  \n");
    scanf("%d", &columna1);

    printf("Digite el numero de filas de la segunda matriz  \n ");
    scanf("%d", &fila2);

    printf("Digite el numero de columnas de la segunda matriz  \n");
    scanf("%d", &columna2);


    if (fila1 == columna2) {


        for (int i = 0; i < fila1; ++i) {
            for (int j = 0; j < columna1; ++j) {
                a[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < fila2; ++i) {
            for (int j = 0; j < columna2; ++j) {
                b[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < fila1; ++i) {
            for (int j = 0; j < columna1; ++j) {
                for (cont = 0, aux = 0; cont < columna1; ++cont) {
                    aux = aux + a[i][cont] * b[cont][j];
                }
                c[i][j] = aux;
            }
        }

        printf(" ---- Matriz Primera -----");
        for (int i = 0; i < fila1; ++i) {
            printf("\n");
            for (int j = 0; j < columna1; ++j) {
                printf("\t%d", a[i][j]);
            }
        }

        printf("\n ---- Matriz Segunda  ----");
        for (int i = 0; i < fila2; ++i) {
            printf("\n");
            for (int j = 0; j < columna2; ++j) {
                printf("\t%d", b[i][j]);
            }
        }

        printf("\n -----Resultado de la multiplicacion de las matrices-----");
        for (int i = 0; i < fila1; ++i) {
            printf("\n");
            for (int j = 0; j < columna2; ++j) {
                printf("\t%d",c[i][j]);
            }
        }
        printf("\n");
    } else {
        printf("No es posible multiplicar la matriz\n");
        return 0;

    }

    return aux;
}

void matrizMagica(int numMa) {
    int a[numMa][numMa];
    int i = 1;
    int j = (1 + numMa) / 2;
    int aux = 2;


    if (numMa % 2 == 1) {
        for (int i = 1; i <= numMa; i++) {
            for (int j = 1; j <= numMa; j++) {
                a[i][j] = 0;
            }
        }
    } else {
        return;
    }

    a[i][j] = 1;
    while (aux <= (numMa * numMa)) {
        i = i - 1;
        j = j + 1;
        if (i < 1 && j > numMa) {
            i = i + 2;
            j = j - 1;
        } else {
            if (i < 1) {
                i = numMa;
            }
            if (j > numMa) {
                j = 1;
            }
        }
        if (a[i][j] == 0) {
            a[i][j] = aux;
        } else {
            i += 2;
            j -= 1;
            a[i][j] = aux;
        }
        aux++;
    }

    for (int i = 1; i <= numMa; i++) {
        for (int j = 1; j <= numMa; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}


int convertirNumeroRomano(char *str) {
    int result = 0;
    int len = strlen(str);
    int i;
    int count = 1;

    for (i = 0; i < len; i++) {
        if (str[i] == 'I') {
            if (str[i + 1] == 'V' || str[i + 1] == 'X') {
                result -= 1;
                count = 1;
            } else {
                if (count <= 3) {
                    result += 1;
                    count++;
                } else {
                    return -1;
                }
            }
        } else if (str[i] == 'V') {
            if (count == 1) {
                result += 5;
                count++;
            } else {
                return -1;
            }
        } else if (str[i] == 'X') {
            if (str[i + 1] == 'L' || str[i + 1] == 'C') {
                result -= 10;
                count = 1;
            } else {
                if (count <= 3) {
                    result += 10;
                    count++;
                } else {
                    return -1;
                }
            }
        } else if (str[i] == 'L') {
            if (count == 1) {
                result += 50;
                count++;
            } else {
                return -1;
            }
        } else if (str[i] == 'C') {
            if (str[i + 1] == 'D' || str[i + 1] == 'M') {
                result -= 100;
                count = 1;
            } else {
                if (count <= 3) {
                    result += 100;
                    count++;
                } else {
                    return -1;
                }
            }
        } else if (str[i] == 'D') {
            if (count == 1) {
                result += 500;
                count++;
            } else {
                return -1;
            }
        } else if (str[i] == 'M') {
            if (count == 1) {
                result += 1000;
                count++;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }
    return result;
}

void imprimirNumeroRomano() {
    char numero[16];
    printf("Ingrese el numero romano que desea convertir: ");
    scanf("%s", numero);
    int resultado = convertirNumeroRomano(numero);
    if (resultado == -1) {
        printf("Valor invalido\n");
    } else {
        printf("El resultado es: %d\n", resultado);
    }
}


void printDate() {

    printf("Ingrese la fecha en formato dd/mm/aaaa\n");

    char date[10];
    scanf("%s",  date);


    if (date[2] == '/' && date[5] == '/' && date[9] != '\0' && date[8] != '\0' && date[7] != '\0' && date[6] != '\0') {
        char dia1 = date[0];
        char dia2 = date[1];
        char mes1 = date[3];
        char mes2 = date[4];
        char año1 = date[6];
        char año2 = date[7];
        char año3 = date[8];
        char año4 = date[9];

        if (dia1 >= '0' && dia1 <= '2') {
            int month = (mes1 - '0') * 10 + (mes2 - '0');
            if (month >= 1 && month <= 12) {
                switch (month) {
                    case 1:
                        printf("%c%c de Enero de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 2:
                        printf("%c%c de Febrero de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 3:
                        printf("%c%c de Marzo de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 4:
                        printf("%c%c de Abril de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 5:
                        printf("%c%c de Mayo de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 6:
                        printf("%c%c de Junio de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 7:
                        printf("%c%c de Julio de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 8:
                        printf("%c%c de Agosto de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 9:
                        printf("%c%c de Septiembre de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 10:
                        printf("%c%c de Octubre de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 11:
                        printf("%c%c de Noviembre de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                    case 12:
                        printf("%c%c de Diciembre de %c%c%c%c\n", dia1, dia2, año1, año2, año3, año4);
                        break;
                }
            } else {
                printf("El mes no es valido");
            }
        } else {
            printf("El dia no es valido");
        }
    } else {
        printf("La fecha no es correcta. Por favor vuelva a ingresarla con el formato: dd/mm/aaaa");
    }
}




int productoPunto() {

    int vectorUno[5], vectorDos[5];
    int aux[5];
    int resultado = 0;
    int indiceUno, indiceDos;

    printf("\nIngrese la longitud del vector 1\n");
    scanf("%d", &indiceUno);

    printf("Ingrese la longitud del vector 2\n");
    scanf("%d", &indiceDos);


    if (indiceUno != indiceDos) {
        printf("Los vectores deben tener la misma longitud. Vuelva a intentarlo de nuevo.\n");
        return 0;

    }
        printf("Agregue valores al primer vector \n");
        for (int i = 0; i < indiceUno; i++){
            printf("Valor para el vector 1[%d]: ", i);
            scanf("%d", &vectorUno[i]);
        }

        printf("Agregue valores al segundo vector \n");
        for (int i = 0; i < indiceDos; i++){
            printf("Valor para el vector 2[%d]: ", i);
            scanf("%d", &vectorDos[i]);
        }



    for (int i = 0; i < indiceDos; i++) {
        aux[i] = vectorUno[i] * vectorDos[i];
        resultado += aux[i];
    }


    printf("El producto punto de los vectores  es: %d\n", resultado);

    return resultado;
}





int menu;
char *men = "\t********MENU******** \n"
            "Dijite el numero de una opcion del menu\n"
            "------------------------------------\n"
            "1. Numeros Romanos \n"
            "2. Factores Primos\n"
            "3. Borrar Espacios\n"
            "4. Numeros Egolatras\n"
            "5. Numero Magico\n"
            "6. Fechas\n"
            "7. Producto Punto\n"
            "8. Multiplicacion por Matrices\n"
            "9. Matriz Magica\n"
            "\n0. Salir\n"
            "------------------------------------\n";



int main() {
    do {

        printf(men);
        scanf("%i", &menu);
        fflush(stdin);
        switch (menu) {
            int num;
            char date[0];

            case 0:
                printf("Gracias por usar el programa\n");

                break;
            case 1:

                imprimirNumeroRomano();

                break;
            case 2:

                auxiliarPrimeFactors();


                break;
            case 3:
                auxiarRemoveSpaces();


                break;

            case 4:

                auxiliarNarcissisticNumbers();

                break;

            case 5:

                printf("--------Numero Magico--------\n");
                printf("Ingrese el numero para verificar si es magico \n ");
                scanf("%d", &num);
                printf("El numero %d %s", num, NumeroMagico(num) ? "Si es magico" : "No es magico\n");
                printf("\n");

                break;

            case 6:

                printDate();

                break;


            case 7:

                productoPunto();

                break;

            case 8:

                printf("------Multiplicacion de Matrices------");
                multiplicacionDeMatrices();
                printf("\n");
                printf("\n");

                break;

            case 9:

                num = 0;
                printf("---Matriz Magica--");
                printf("Agregue un numero *Impar* de elementos a la matriz magica\n");
                scanf("%d", &num);
                matrizMagica(num);
                printf("\n");

                break;

            default:
                printf("\n\n Seleccione un numero de la opcion del menu\n\n\n");

        }
    } while (menu != 0);


    return 0;
}