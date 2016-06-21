#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        unsigned int id; //4bytes
        char nome[256]; //256bytes
        char sexo; //1byte
        float salario; //4bytes
} Funcionario;

FILE *f;
Funcionario func;

void Inserir(){
	fflush(stdin);
	printf("Digite o ID do Funcionário: ");
	scanf("%d", &func.id);
	printf("Digite o Nome do Funcionário: ");
	scanf("%s", &func.nome[256]);
	printf("Digite o Salário do Funcionário: ");
	scanf("%f", &func.salario);
	printf("Digite o sexo do Funcionário: ");
	scanf("%c", &func.sexo);

	if (func.id > 0) {
		fwrite(&func, sizeof(func), 1, f);
	} else {
		printf("\nID Inválido! Tem que ser maior que zero.\n");
	}

	if(ferror(f)){
		printf("\nErro na gravação do arquivo!\n\n");
	} else {
		fclose(f);
		printf("\nCadastrado com sucesso!\n\n");
	}
}

int main()
{
	int opcao;

	do{
		printf("++++++++++++++++ Gerência de Funcionário +++++++++++++\n");
		printf("[1] Inserir Funcionário\n");
		printf("[2] Remover Funcionário\n");
		printf("[3] Calcular Média de Salários\n");
		printf("[4] Exportar Dados para Texto\n");
		printf("[5] Compactar Base de Dados\n");
		printf("[0] Sair\n");
		fflush(stdin);
		printf("Opção: ");
		scanf("%d", &opcao);
		getchar();
		printf("\n");

		switch(opcao){
		case 1: {
			if((f = fopen("funcionario.bin", "wb")) == NULL) {
				printf("Erro ao abrir arquivo\n");
				return 1;
			} else {
				Inserir();	
			}
			break;
			}
		case 2: {
			/*if((f = fopen("funcionario.bin", "wb")) == NULL) {
				printf("Erro ao abrir arquivo\n");
				return 1;
			} else {
				Inserir();
			}*/
			printf("Entrou no case 2\n");
			break;
			}
		case 3: {
			/*if((f = fopen("funcionario.bin", "wb")) == NULL) {
				printf("Erro ao abrir arquivo\n");
				return 1;
			} else {
				Inserir();
			}*/
			printf("Entrou no case 3\n");
			break;
			}
		case 4: {
			printf("Entrou no case 4\n");
			break;
			}
		case 5: {
			printf("Entrou no case 5\n");
			break;
			}
		case 0: {
			break;
			}
		default:{
			printf("Opção Inválida!\n");
			break;
			}
		}                             

	}while(opcao!=0);
	return 0;
}
