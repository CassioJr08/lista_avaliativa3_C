#include <stdio.h>
#include <string.h>
#include <ctype.h>


int placaValida(char *placa) {
    int i;

    if (strlen(placa) == 8) {
        for (i = 0; i < 3; i++) {
            if (!isalpha(placa[i]))
                return 0; 
        }
        if (placa[3] != '-')
            return 0; 
        for (i = 4; i < 8; i++) {
            if (!isdigit(placa[i]))
                return 0; 
        }
    } else if (strlen(placa) == 7) {
        for (i = 0; i < 6; i++) {
            if ((i == 3 && !isalpha(placa[i])) || (i != 3 && !isdigit(placa[i])))
                return 0; 
        }
    } else {
        return 0; 
    }

    return 1; 
}


int diaValido(char *dia) {
    char *diasValidos[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    int i;

    for (i = 0; i < 7; i++) {
        if (strcmp(dia, diasValidos[i]) == 0)
            return 1; 
    }

    return 0; 
}

int main() {
    char placa[9];
    char dia[15];

    scanf("%s", placa);
    scanf("%s", dia);

    if (!placaValida(placa)) {
        printf("Placa invalida\n");
    } else if (!diaValido(dia)) {
        printf("Dia da semana invalido\n");
    } else {
        int ultimoDigito = placa[strlen(placa) - 1] - 0;
        int rodizio = (ultimoDigito / 2) % 5;

        if (rodizio == 0 || rodizio == 1)
            printf("%s pode circular %s\n", placa, dia);
        else
            printf("%s nao pode circular %s\n", placa, dia);
    }

    return 0;
}
