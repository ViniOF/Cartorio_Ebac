#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //define a linguagem em português
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações
	scanf("%s", cpf); //%s armazena na string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo, "w": "write" escreve 
	fprintf(file, "CPF: "); 
	fprintf(file,cpf); //salva o valor da variável
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

int consulta() //função responsável para consultar informações do usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //criação de variáveis
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coleta informações
	scanf("%s",cpf); //armazena
	
	FILE *file; 
	file = fopen(cpf,"r"); //abre o arquivo e realiza a leitura "r": "read" ler
	
	if(file == NULL) //caso não encontre o arquivo+
	{
		printf("Não localizado.\n"); //mostra essa mensagem
	}
	else //caso encontre+
	{
		printf("\nEssas são as informações do usuário:\n\n"); //mostra essa
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informações do usuário
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Função responsável por deletar informações do usuário
{
	char cpf[40]; //criando váriaveis
	
	printf("Digitar o CPF do usuário a ser deletado: "); //coletando informações
	scanf("%s",cpf); // buscando informações
	
	remove(cpf); //apagando informações
	
	FILE *file; //abrindo o arquivo e fazendo a leitura
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso não encontre+
	{
		printf("O usuário não se encontra no sistema! \n"); //mostra essa mensagem
		system("pause");
	}	
}

int main() //função principal
{
	int opcao=0; // DEFININDO VARIÁVEIS
	int laco=1; 
	
	for(laco=1;laco=1;) //repetição do menu principal
	{
	
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //DEFININDO LINGUAGEM
		
		printf("\t-Cartório da EBAC-\n\n"); // INICIO DO MENU
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("Opção: "); //FIM DO MENU
		
		scanf("%d", &opcao); //ARMAZENANDO A ESCOLHA DO USUÁRIO
		
		system("cls");
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chama a função registro
			break;
			
			case 2:	
			consulta(); //chama a função consulta
			break;
			
			case 3:
			deletar(); //chama a função deletar
			break;
			
			default: //caso nao encontre uma opção, mostra "opção inválida" na tela
			printf("Opção inválida\n");
			system("pause");
			break;
		}	//fim da seleção de menu	
	}
}
