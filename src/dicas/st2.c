#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i; //mes
int j; //dia
int cont = 0; //quebra linha
int ano, mes, dia, bis;
int g, c, x, z, e, d, n;
int mesDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[]=
{
    "Janeiro",
    "Fevereiro",
    "Marco",
    "Abril",
    "Maio\t",
    "Junho",
    "Julho",
    "Agosto",
    "Setembro",
    "Outubro",
    "Novembro",
    "Dezembro"
};

int main(int argc, char *argv[]) {
    printf("Digite o ano: ");
    scanf("%d", &ano);


    //P A S C O A

    g = (ano % 19) + 1; //resto inteiro - AUREO
    c = (ano / 100) + 1; //SECULO
    x = ((3 * c) / 4) - 12; //CORRECAO 1
    z = (((8 * c) + 5) / 25) - 5; //CORRECAO 2
    e = ((11 * g) + 20 + z - x) % 30; //resto inteiro

    //EPACTA
    if(e == 25 && g > 11){
        e++;
    }
    else if(e == 24){
        e++;
    }

    //LUA CHEIA
    n = 44 - e;
    if(n < 21){
        n += 30;
    }

    //DOMINGO DE PASCOA
    d = ((5 * ano) / 4) - (x + 10);


    //DIA/MES PASCOA
    n = (n + 7) - ((d + n) % 7);

    if(n > 31){
        n = n - 31;
        printf("Pascoa: %d de abril", n);
        mes = 4;
    }
    else{
        printf("Pascoa: %d de marco", n);
        mes = 3;
    }

    // B I S S E X T O

    if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) {
        printf("\nAno bissexto.");
        bis = 1;
        mesDias[1] = 29;
    }
    else {
        printf("\nAno nao bissexto.");
        bis = 0;
    }


    //1   D E    J A N E I R O
    if(mes == 4){
        dia = 8 - ((n + bis + 31 + 28 + 31 ) % 7) ;
    }
    else if(mes == 3){
        dia = 8 - ((n + bis + 31 + 28) % 7) ;
    }
    if(dia > 6) dia -= 7;

    dia++;

    if(dia == 1){
        printf("\n1 de jan: domingo\n");
    }else if(dia == 2){
        printf("\n1 de jan: segunda\n");
    }else if(dia == 3){
        printf("\n1 de jan: terca\n");
    }else if(dia == 4){
        printf("\n1 de jan: quarta\n");
    }else if(dia == 5){
        printf("\n1 de jan: quinta\n");
    }else if(dia == 6){
        printf("\n1 de jan: sexta\n");
    }else if(dia == 7){
        printf("\n1 de jan: sabado\n");
    }

    printf("\n\n");


    /*CALENDÁRIO*/

    printf("Calendario do ano %d\n", ano);

    printf("|-----------------------------|\n");
    for(i = 0; i < 2; i++){

    printf("|%s\t\t      |\n", months[i]);
    printf("| dom seg ter qua qui sex sab |\n");
    printf("|");
    printf("  ");

    /*pular dias vazios*/
    if(i == 0){
        for ( j = 0; j < dia - 1; j++ ){
            printf("--  ");
            cont++;
        }
    }else{
        if(dia != 0){
            for ( j = 0; j < dia - 1; j++ ){
                printf("--  ");
                cont++;
            }
        }else{
            for ( j = -1; j < dia - 1; j++ ){
                printf("--  ");
                cont++;
            }
        }

        printf("--  ");
    }


    /*escrever mesesdo dia*/
    for(j = 1; j < mesDias[i] + 1; j++){

        if(j <= 9){

            if(cont >= 6){
                printf(" %d |\n|  ", j);
                cont = 0;
            }else{
                printf(" %d  ", j);
                cont++;
            }


        }else{
            if(j == 10){
                printf("%d", j);
                cont++;
            }else{
                printf("  %d", j);
                cont++;
            }

            if(cont > 6){
                printf(" |\n|");
                cont = 0;
            }
        }

        if(cont > 6){
            printf("\n|\n|\n|\n|  ");
            cont = 0;
        }

    }
    printf("\n");
    dia = cont;

    printf("\ndia: %d\n", dia);

    }

            return 0;
}
