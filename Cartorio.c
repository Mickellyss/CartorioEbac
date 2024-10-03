#include <stdio.h> //biblioteca de comunica��o do usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()//fun��o de cadastrar os usuarios
{
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	    //inicio da cria��o das variaveis/string
	    char arquivo[40];
	    char cpf[40];
	    char nome[40];
	    char sobrenome[40];
	    char cargo [40];
	    //final da cria��o das variaveis/string
	    
	    printf("Digite o cpf a ser cadastrado:  \n");//coletando informa��o do usuario
	    scanf("%s", cpf);//%s salva as strings
	    
	    strcpy(arquivo, cpf);//copiando os valores das strings
	    
	    FILE *file; //cria o arquivo	
	    file = fopen(arquivo, "w");//cria o arquivo
		fprintf(file, "CPF: ");
	    fprintf(file, cpf);//salva o valor da variavel
	    fclose(file);//fecha o arquivo
	    
	    file = fopen(arquivo, "a");//cria/atualiza o arquivo
	    fprintf(file, "\nNome:  ");//salva o valor da variavel
	    fclose(file);//fecha o arquivo
	    
	    printf("Digite o nome a ser cadastrado: \n");
	    scanf("%s", nome);
	    
	    file = fopen(arquivo, "a");//cria/atualiza o arquivo
	    fprintf(file,nome);//salva o valor da variavel
	    fclose(file);//fecha o arquivo
	    
	    file = fopen(arquivo, "a");//cria/atualiza o arquivo
	    fprintf(file, "\nSobrenome:  ");
	    fclose(file);//fecha o arquivo
	    
	    printf("Digite o sobrenome a ser cadastrado: \n");
	    scanf("%s", sobrenome);
	    
	    file = fopen(arquivo, "a");//cria/atualiza o arquivo
	    fprintf(file,sobrenome);//salva o valor da variavel
	    fclose(file);//fecha o arquivo
	    
	    file = fopen(arquivo, "a");//cria/atualiza o arquivo
	    fprintf(file, "\nCargo: ");
	    fclose(file);//fecha o arquivo
	    
	    printf("Digite o cargo a ser cadastrado:  \n");
	    scanf("%s",cargo);
	    
	    file = fopen(arquivo, "a");//cria/atualiza o arquivo
	    fprintf(file,cargo );//salva o valor da variavel
	    fprintf(file, "\n");
	    fclose(file);//fecha o arquivo
	    
	    system("pause");
}

int consulta()
{
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	    
	    //inicio cria��o de variaveis 
    	char cpf[40];
    	char conteudo[200];
    	//fim cria��o de variaveis 
    	
    	printf("Digite o CPF a ser consultado:  \n");//coletando informa��es do usuario
    	scanf("%s",cpf);//coletando informa��es do usuario
    	
    	FILE *file;//abrindo arquivo
    	file = fopen (cpf, "r");//lendo arquivo
    	
    	if(file == NULL)//caso usuario invvalido
    	{
    		printf("N�o foi possivel encontrar CPF desejado. \n");
    
		}
		
		printf("\n Informa��es do usuario: \n\n");
		
		while(fgets(conteudo, 200, file) != NULL)//busca pelo usuario
		{
			
			printf("%s", conteudo);//informa��es do usuario
			
		}
		system("pause");
}

int deletar ()
{
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	    
	    //inicio de cra��o das variaveis
    	char cpf[40];
    	//fim da cra��o das variaveis
    	
    	printf ("Digite CPF do usu�rio: ");//coletando informa��es do usuario
    	scanf ("%s",cpf);//coletando informa��es do usuario
    	
    	FILE *file;//abrindo arquivo
    	file = fopen(cpf, "r");//lendo o arquivo
    	
    	if (file == NULL)//caso usuario invalido
    	{
    		printf ("Usu�rio n�o se encontra no sistema.\n");
    		system("pause");
		}
		
		else
		{
			remove(cpf);//responsavel por remover o usuario 
			printf("Usu�rio deletado com sucesso. \n");
			
		}
		system("pause");
}


int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
	    system ("cls");
	    
        setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
      	printf( "### Cart�rio da EBAC ### \n\n" ); //inicio do menu
	    printf( "Escolha a op��o desejada no menu: \n\n");
	    printf(" \t1 - Registrar nomes \n");
	    printf(" \t2 - Consultar nomes \n");
	    printf(" \t3 - Deletar nomes \n");
	    printf("Op��o:"); //Fim do menu
	
	    scanf("%d", &opcao); //armazenando escolha do usuario
	 
	    system ("cls");//responsavel por limpar a tela
	
	switch(opcao) //inicio das op��es
	{
		case 1:
			registro();//chamada da fun��o 
		    break;
		    
		case 2:
			consulta();//chamada da fun��o 
		    break;
		    
		case 3: 
		    deletar();//chamada da fun��o 
		    break;
		    
	    default:
	    	printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break; //Fim das op��es

	}
	
}
}
