/*Bibliotecas para o programas*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>


/*Estrutura do endereço*/
typedef struct
{
	char logradouro[15];
	char Complemento[50];
	char bairro[30];
	char cidade[20];
	char estado[3];
	char cep[10];
}Address;

/*Estrutura do usuário*/
typedef struct
{
	int codigo;
	char nome[50];
	char telefone[12];
	char email[100];
	char cpf[11];
	char usuario[20];
	char senha[20];
	char senha2[20];
	Address endereco;
}user;

/*Estrutura do paciente*/
typedef struct
{
	char nome[50];
	char telefone[12];
	char email[100];
	char cpf[11];
	Address endereco;
}patient;

/*Métodos do programa*/
char menu();
void login();
void cad_usuario();
void cad_paciente();
void consulta_user();


char menu()
{

	printf("	        ========   CLIMANAGER   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu principal                   |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Cadastrar pacientes                    |\n");
	printf("    |       [2] - Consultar pacientes                    |\n");
	printf("    |       [3] - Cadastrar usuários                     |\n");
	printf("    |       [4] - Consultar usuários                     |\n");
	printf("    |       [5] - Sair do Programa                       |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");

	printf("\nFavor selecionar alguma opção: \n\n");

	return _getch();
}

void main()
{
inicio:
	switch (menu())
	{
	case '1': login();			break;
	case '2': cad_paciente();	break;
	case '3': cad_usuario();	break;
	case '4': consulta_user();	break;
	case '5': goto fim;
		exit(0);
	}
	printf("\n\n");
	system("pause");
	goto inicio;
fim:
	;
}

void login()
{
	printf("Teste");
}

void cad_usuario()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação

	/*Ponteiros do metodo*/
	FILE* puser;
	errno_t err;
	system("mkdir dados");
	puser = fopen("dados\\cad_usuario.txt", "a");
	user cusuario = { NULL };
	int tam = 0, tam2 = 0;
	memset(cusuario.usuario, 0x00, sizeof(cusuario.usuario));
	memset(cusuario.senha, 0x00, sizeof(cusuario.senha));
	memset(cusuario.senha2, 0x00, sizeof(cusuario.senha2));

	/*Buscar último código cadastrado*/


	/*Cadastro dos dados*/
	printf("\033[2J\033[1;1H");
	printf("CADASTRO DE USUÁRIOS\n\n");

	printf("\n\nCodigo do usuário: \n");
	scanf_s("%d%*[^\n]\n", &cusuario.codigo);

	printf("\n\nNome do usuário: \n");
	fgets(cusuario.nome, 50, stdin);

	printf("\n\nTelefone do usuário: \n");
	fgets(cusuario.telefone, 12, stdin);

	printf("\n\nE-mail do usuário: \n");
	fgets(cusuario.email, 12, stdin);

	printf("\n\nCPF do usuário: \n");
	fgets(cusuario.cpf, 11, stdin);

	printf("\n\nUsuário para acesso: \n");
	fgets(cusuario.usuario, 20, stdin);

	/* ---------- TRATAMENTO NO CAMPO SENHA ---------- */

inicio:

	tam = 0;
	tam2 = 0;

	printf("\n\nSenha do usuário: \n");
	fflush(stdin);

	do
	{
		cusuario.senha[tam] = _getch();
		if (cusuario.senha[tam] == 0x08 && tam > 0)  //Backspace
		{
			printf("\b \b");
			cusuario.senha[tam] = 0x00;
			tam--;

		}
		else if (cusuario.senha[tam] == 13) // Enter
		{
			cusuario.senha[tam] = 0x00;
			break;
		}
		else if (cusuario.senha[tam] != 0x08)
		{
			putchar('*');
			tam++;
		}
	} while (tam < 20);


	printf("\n\nDigite a senha novamente: \n");

	fflush(stdin);

	do
	{
		cusuario.senha2[tam2] = _getch();
		if (cusuario.senha2[tam2] == 0x08 && tam > 0)  //Backspace
		{
			printf("\b \b");
			cusuario.senha2[tam2] = 0x00;
			tam2--;

		}
		else if (cusuario.senha2[tam2] == 13) // Enter
		{
			cusuario.senha2[tam2] = 0x00;
			break;
		}
		else if (cusuario.senha2[tam2] != 0x08)
		{
			putchar('*');
			tam2++;
		}
	} while (tam2 < 20);


	if (strcmp(cusuario.senha, cusuario.senha2) != 0)
	{
		printf("\nAs senhas não conferem!\n");
		goto inicio;
	}
	else
	{
		printf("\n\nUsuário cadastrado com sucessso!");
		goto fim;
	}

fim:

	/*GRAVAR OS DADOS NO ARQUIVO DE TEXTO*/
	printf("\n");

	fprintf(puser, "%s\n\n", "\n ==============  Usuário criado  ============== ");
	//hora
	time_t mytime;
	mytime = time(NULL);
	printf("\n");
	fprintf(puser, ctime(&mytime));



	printf("\n\n");

	fprintf(puser, "Código: %i \n", cusuario.codigo);
	fprintf(puser, "Nome: %s", cusuario.nome);
	fprintf(puser, "Telefone: %s", cusuario.telefone);
	fprintf(puser, "E-mail: %s", cusuario.email);
	fprintf(puser, "CPF: %s", cusuario.cpf);
	fprintf(puser, "Usuário: %s", cusuario.usuario);
	fprintf(puser, "Senha: %s", cusuario.senha);

	fclose(puser);
}

void consulta_user()
{
	printf("teste");
}

void cad_paciente()
{
	printf("Teste");
}
