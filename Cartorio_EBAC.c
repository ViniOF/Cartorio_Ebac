#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //define a linguagem em portugu�s
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es
	scanf("%s", cpf); //%s armazena na string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo, "w": "write" escreve 
	fprintf(file, "CPF: "); 
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a": "append" acrescenta
	fprintf(file,"\n"); //move a caixa de texto para a linha de baixo / o mesmo que a tecla "Enter"
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa na tela
}

int consulta() //fun��o respons�vel para consultar informa��es do usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //cria��o de vari�veis
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coleta informa��es
	scanf("%s",cpf); //armazena
	
	FILE *file; 
	file = fopen(cpf,"r"); //abre o arquivo e realiza a leitura "r": "read" ler
	
	if(file == NULL) //caso n�o encontre o arquivo+
	{
		printf("N�o localizado.\n"); //mostra essa mensagem
	}
	else //caso encontre+
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n\n"); //mostra essa
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informa��es do usu�rio
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Fun��o respons�vel por deletar informa��es do usu�rio
{
	char cpf[40]; //criando v�riaveis
	
	printf("Digitar o CPF do usu�rio a ser deletado: "); //coletando informa��es
	scanf("%s",cpf); // buscando informa��es
	
	remove(cpf); //apagando informa��es
	
	FILE *file; //abrindo o arquivo e fazendo a leitura
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso n�o encontre+
	{
		printf("O usu�rio n�o se encontra no sistema! \n"); //mostra essa mensagem
		system("pause");
	}	
}

int main() //fun��o principal
{
	int opcao=0; // DEFININDO VARI�VEIS
	int laco=1; 
	
	for(laco=1;laco=1;) //repeti��o do menu principal
	{
	
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //DEFININDO LINGUAGEM
		
		printf("\t-Cart�rio da EBAC-\n\n"); // INICIO DO MENU
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("Op��o: "); //FIM DO MENU
		
		scanf("%d", &opcao); //ARMAZENANDO A ESCOLHA DO USU�RIO
		
		system("cls");
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chama a fun��o registro
			break;
			
			case 2:	
			consulta(); //chama a fun��o consulta
			break;
			
			case 3:
			deletar(); //chama a fun��o deletar
			break;
			
			default: //caso nao encontre uma op��o, mostra "op��o inv�lida" na tela
			printf("Op��o inv�lida\n");
			system("pause");
			break;
		}	//fim da sele��o de menu	
	}
}
