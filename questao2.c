#include <stdio.h>
#include <math.h>

void montante(int meses, double aporte_mensal, double taxa_juros, double montantes[]) {
    for (int mes = 1; mes <= meses; mes++) {
        montantes[mes - 1] = aporte_mensal * (1 + taxa_juros) * ((pow(1 + taxa_juros, mes) - 1) / taxa_juros);
    }
}

int main() {
    int meses;
    double aporte_mensal, taxa_juros;
    
    scanf("%d %lf %lf", &meses, &aporte_mensal, &taxa_juros);

    double montantes[meses];
    montante(meses, aporte_mensal, taxa_juros, montantes);

    for (int mes = 0; mes < meses; mes++) {
        printf("Montante ao fim do mes %d: R$ %.2lf\n", mes + 1, montantes[mes]);
    }

    return 0;
}