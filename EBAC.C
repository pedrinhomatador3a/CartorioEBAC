#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int registrar() // fun��o responsavel para cadastrar os usuarios do sistema 

{
	// inicio cria��o  de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final de cria��o de variavel
	
	printf("Digite o CPf a ser cadastrado: "); // coletando a informa��o o usuario
	scanf("%s", cpf); // %s refere-se a strings 
	
	strcpy(arquivo, cpf); // responsavel pra copiar valores
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w");
	fprintf(file,cpf); //salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o seu nome a ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o seu sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	
	printf("Digite o seu cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); 
	
}


int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF ao ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("N�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL); // enquatando tiver conteudo ele tras o conteudo
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}


int deletar()
{
	char cpf[40];
	
	printf ("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("usuario n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
	
}

int main()
{
	int opcao=0; // int definir variaveis
	int laco=1;
	 
	for(laco=1; laco==1;)
	{
		
		system("cls"); // responsabel por deletar a tela 
	
	
	
		setlocale(LC_ALL, "Portuguese");
		
		printf("Cartorio da EBAC\n\n");
		printf("Escolha a op��o desejada do menu \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Op��o:");
	
		scanf("%d" , &opcao);
	
		system("cls");
		
		
		switch(opcao) // inicio da sele��o ao menu
		{
			case 1:
			registrar(); // chama de fun��o 
			break;
			
			
			case 2:
			consultar();
			break;
			
			
			case 3:
			deletar();
			break;
			
			
			default:
			printf("N�o tem esta escolha\n");
			system("pause");
			break;
				// fim da sele��o
		}
			
		

	
	}
}
