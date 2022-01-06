# C é uma linguagem simples e minimalista

C não tem try/catch por padrão até a formas de implementar usando
macros mas não recomendo.

Então como tratar erros em C ?

Bem só existe 3 tipos de erros:

* Erros de sintaxe

* Erros de IO

* Erros de memoria

Erros de sintaxe:

Esses são os mais fáceis de resolver por que normalmente são apontados pelo
compilador como warings e erros.

**Erros de IO + Erros de meoria**

Saída são um dos mais difíceis de serem resolvidos por não depender apenas do
programador mas também do usuário e fatores eternos alguns exemplos são receber
texto do teclado do usuário, receber dados da internet, comunicar com hardware etc.
Normalmente esses erros são a causa dos erros de memoria alguns exemplos:

```c
#include <stdio.h>

int main(void) {
  char nome[25];
  scanf("%s", nome);
  puts(nome);
}
```

Bem esse programa gera um [segment fault] caso o nome ocupar mais de 25 bytes,
outro erro comum é o calculo de memoria errado ex:
quantos bytes a palavra "palhaço" ocupa ? 7 + 1 = 8 ? Não,
na verdade ocupa 9 bytes já que o `ç` utiliza 2 bytes para sua representação
pode verificar com `echo -n "ç" | hd`
Então como resolver esse problema ?

Simples usar o scanf de uma forma segura:

```c
scanf("%24s", nome);
```

Nesse caso o scanf vai ler os primeiros 24 bytes e parar mas
ainda pode acontecer outros erros, como o nome ocupar mais de
24 bytes. A solução para isso é simples aumenta o buffer.

Outra melhoria é:

```c
int st = scanf("%24s", nome);

if(st != 1 || st == EOF) {
  /*....DEU ERRO....*/
}

```

O 1 é os argumentos que o scanf conseguiu ler ou seja o
_nome_. [EOF](https://pt.wikipedia.org/wiki/EOF) é caso haver
algum problema com o [stdin](https://pt.wikipedia.org/wiki/Fluxos_padr%C3%A3o)

Mas e agora oque fazer quando deu erro ? Haha o mesmo que você faria em um catch

## Já sabemos que em C usamos IF inves de try/cach é só isso ?

Não, temos algumas ferramentas para nos ajudar como _perror_, _ferror_, _error_, _err_ , _errno_ etc. Tem muitas variações.

# Retornando erros em variáveis globais


# Assert

# Tratando sinais do sistema operacional

# Usando goto

# Usando as funções setjmp() and longjmp()



