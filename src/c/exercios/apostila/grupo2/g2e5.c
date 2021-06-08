/* 5. Escrever um programa em "C" que solicita as notas das duas provas feitas por
cada um dos alunos de uma turma (as notas tem de estar no intervalo [0 10]) e
imprime para cada um a média das notas. O programa deve parar
imediatamente após ter sido digitado o valor 50 para a nota da primeira prova.
 */
#include <stdio.h>
int main(void){
  float nota1,nota2;
  int contador;
  while (nota1 != 50)
  {
    printf("dijite 50 para sair\n");
    printf("Apenas notas do invervalo de [0 10] \n");
    printf("dijite a primeira nota \n");
    scanf("%f", &nota1);
    if(nota1 == 50){
      printf("saindo...");
      break;
    }
    else if(nota1 <=10){

    printf("Dijite a segunda nota: \n");
    scanf("%f",&nota2);
    printf("Media é %.2f\n", (nota1 + nota2) / 2); 
    }
    else{
      printf("error valor maior que 10");
    }
  }
  return 0;
}