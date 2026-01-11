#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//início criação de variéveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string

	
	printf("\tDigite o CPF a ser cadastrado:"); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	// início da criação das variáveis
	char cpf[40];
	char conteudo[200];
	// fim da criação das variáveis
	
	printf("\tDigite o CPF a ser consultar:"); // mostrar informação de texto ao usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("\tNão foi possível abrir o arquivo, não localizado!.\n"); // mostrar informação de texto ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	//início criação de variéveis/string
	char cpf[40];
	//final criação de variéveis/string
	
	printf("\tDigite o CPF do usuário a ser deletado:"); // mostrar informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("\tO usuário não se encontra no sistena!.\n"); // Mostrar informação do usuário
		system("pause");
	}
}

int main()
{
	int opcao=0; // definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		printf( "\tCartório da EBAC\n\n"); //Inicio de menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:"); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responável por limpar a tela
		
		switch(opcao) // inicio da seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
				
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
				
			default:
			printf("\tEsta opção não está disponível!\n");
			system("pause");
			break;
		}// fim da seleção
	
}
}
	
