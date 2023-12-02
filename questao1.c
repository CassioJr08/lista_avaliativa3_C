#include <stdio.h>
#include <string.h>


int romanoParaDecimal(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}


int romanoParaDecimalNumero(char* romano) {
    int result = 0;
    int length = strlen(romano);

    for (int i = 0; i < length; i++) {
        int atual = romanoParaDecimal(romano[i]);
        int proximo = (i + 1 < length) ? romanoParaDecimal(romano[i + 1]) : 0;

        if (atual >= proximo) {
            result += atual;
        } else {
            result += (proximo - atual);
            i++;
        }
    }

    return result;
}

int main() {
    char numeroRomano[13];
    scanf("%s", numeroRomano);

    int numeroDecimal = romanoParaDecimalNumero(numeroRomano);
    int sb = 0;
    int temp = numeroDecimal;

    while (temp > 0) {
        sb++;
        temp >>= 1;
    }

    printf("%s na base 2: ", numeroRomano);
    for (int i = sb - 1; i >= 0; i--) {
        printf("%d", (numeroDecimal >> i) & 1);
    }
    
    printf("\n");
    printf("%s na base 10: %d\n", numeroRomano, numeroDecimal);
    printf("%s na base 16: %x\n", numeroRomano, numeroDecimal);

    return 0;
}
