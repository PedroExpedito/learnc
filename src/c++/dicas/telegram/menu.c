#include "menu.h"
#include <stdio.h>
int mainMenu(){
    printf("\e[1;1H\e[2J");
    printf("            ========   CLIMANAGER   ========\n\n"

    "    .____________________________________________________.\n"
    "    |                                                    |\n"
    "    |                   Menu principal                   |\n"
    "    |____________________________________________________|\n"
    "    |                                                    |\n"
    "    |                                                    |\n"
    "    |       [1] - Menu de cadastros                      |\n"
    "    |       [2] - Menu de consultas                      |\n"
    "    |       [3] - Sair do Programa                       |\n"
    "    |                                                    |\n"
    "    |____________________________________________________|\n"

    "\nFavor selecionar alguma opção: \n\n");


    int choice;
    scanf("%d", &choice);
    return choice;
}
int registerMenu(){
  printf("\e[1;1H\e[2J");
  printf("            ========   CLIMANAGER   ========\n\n"

      "    .____________________________________________________.\n"
      "    |                                                    |\n"
      "    |                   Menu de cadastros                |\n"
      "    |____________________________________________________|\n"
      "    |                                                    |\n"
      "    |                                                    |\n"
      "    |       [1] - Cadastros usuários                     |\n"
      "    |       [2] - Cadastrar pacientes                    |\n"
      "    |       [3] - Cadastrar médicos                      |\n"
      "    |       [4] - Cadastrar filial                       |\n"
      "    |       [5] - Cadastrar agendamentos                 |\n"
      "    |       [6] - Voltar ao menu principal               |\n"
      "    |       [7] - Sair do Programa                       |\n"
      "    |                                                    |\n"
      "    |____________________________________________________|\n"

      "\nFavor selecionar alguma opção: \n\n");

    int choice;
    scanf("%d", &choice);
    return choice;
}

int appointmentMenu(){
  printf("\e[1;1H\e[2J");
   printf("            ========   CLIMANAGER   ========\n\n"

    "    .____________________________________________________.\n"
    "    |                                                    |\n"
    "    |                   Menu de consultas                |\n"
    "    |____________________________________________________|\n"
    "    |                                                    |\n"
    "    |                                                    |\n"
    "    |       [1] - Consultar usuários                     |\n"
    "    |       [2] - Consultar pacientes                    |\n"
    "    |       [3] - Consultar médicos                      |\n"
    "    |       [4] - Consultar filial                       |\n"
    "    |       [5] - Consultar agendamentos                 |\n"
    "    |       [6] - Voltar ao menu principal               |\n"
    "    |       [7] - Sair do Programa                       |\n"
    "    |                                                    |\n"
    "    |____________________________________________________|\n");

    int choice;
    scanf("%d", &choice);
    return choice;

}

