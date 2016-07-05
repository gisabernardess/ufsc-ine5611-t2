#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        unsigned int id; 
        char nome[256]; 
        char sexo; 
        float salario; 
} Funcionario;

FILE *f;
Funcionario func, leFunc;
char *caminhoArquivo;

void Inserir();
void Excluir();
void MediaSalario();
void Exportar();
void Compactar();
void Consultar();

int main(int argc, char *argv[])
{
	caminhoArquivo = (char*) argv[1];
	if (argc != 2){
		printf("	O programa não foi inicializado corretamente\n");
		printf("Exemplo de utilização: ./trabalho2 /home/gisabernardes/Documentos/funcionario.bin\n");
	} else {
		int opcao;
		do{	
			printf("\n\n	|------- Gerência de Funcionário -------|\n");
			printf("	|   [1] Inserir Funcionário             |\n");
			printf("	|   [2] Remover Funcionário             |\n");
			printf("	|   [3] Calcular Média de Salários      |\n");
			printf("	|   [4] Exportar Dados para Texto       |\n");
			printf("	|   [5] Compactar Base de Dados         |\n");
			printf("	|   [6] Consultar                       |\n");
			printf("	|   [0] Sair                            |\n");
			printf("	|---------------------------------------|\n");
			fflush(stdin);
			printf("	   OPÇÃO: ");
			scanf("%d", &opcao);
			getchar();
			printf("\n");

			switch(opcao){
			case 1: {
					if ((f = fopen(caminhoArquivo, "a+b")) == NULL) {
						printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
					} else {
						Inserir();
					}
					break;
				}
			case 2: {
					if ((f = fopen(caminhoArquivo, "r+b")) == NULL) {
						printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
					} else {
						Excluir();
					}
					break;
				}
			case 3: {
					if ((f = fopen(caminhoArquivo, "rb")) == NULL) {
						printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
					} else {
						MediaSalario();
					}
					break;
				}
			case 4: {
					if ((f = fopen(caminhoArquivo, "r+b")) == NULL) {
						printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
					} else {
						Exportar();
					}
					break;
				}
			case 5: {
					if ((f = fopen(caminhoArquivo, "r+b")) == NULL) {
						printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
					} else {
						Compactar();
					}
					break;
				}
			case 6: {
					if ((f = fopen(caminhoArquivo, "rb")) == NULL) {
						printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
					} else {
						Consultar();
					}
					break;
				}
			case 0: {
					printf("	              ATÉ MAIS =D \n\n");
					printf("	|---------------------------------------|\n");					
					printf("	|     Trabalho 2 - E/S e Arquivos       |\n");
					printf("	|    INE5611 - Sistemas Operacionais    |\n");
					printf("	|   Desenvolvido por Gisele Bernardes   |\n");
					printf("	|---------------------------------------|\n\n");
				break;
				}
			default:{
				system("clear");
				printf("	|----------- Opção Inválida! -----------|\n");
				break;
				}
			}                             

		}while(opcao!=0);
		return 0;
	}
}

void Inserir(){
	int cont = 0;
	system("clear");
	fflush(stdin);
	printf("   Digite o ID do Funcionário: ");
	scanf("%d", &func.id);
	printf("   Digite o Nome do Funcionário: ");
	scanf("%s", func.nome);
	printf("   Digite o sexo do Funcionário:(F/M) ");
	scanf(" %c", &func.sexo);
	printf("   Digite o Salário do Funcionário: ");
	scanf("%f", &func.salario);

	fseek(f, 0, SEEK_SET);
	
	while (!feof(f)){
		fread(&leFunc, sizeof(func), 1, f);
		if(leFunc.id == func.id){
			cont++;			
		}
	}

	if (cont > 0){
		system("clear");
		printf("\n	|-  Já existe funcionário com este ID! -|");
	} else {
		if (func.id <= 0){
			system("clear");
			printf("\n	|------------- ID inválido! ------------|");
		} else {
			fwrite(&func, sizeof(func), 1, f);
			system("clear");
			printf("\n	|------- Cadastrado com sucesso! -------|");
		}			
	}
	
	if (ferror(f)){
		printf("\n	|----- Erro na gravação do arquivo! ----|");
	}
	fclose(f);
}

void Excluir(){
	int contador = 0;
	system("clear");
	fflush(stdin);
	Consultar();
	printf("\n   Digite o ID do Funcionário que deseja excluir: ");
	scanf("%d", &func.id);

	fseek(f, 0, SEEK_SET);

	while(1){
		int cont = fread(&leFunc, sizeof(func), 1, f); 		
		if (cont == 0){
			break;
		}
		if (leFunc.id == func.id) {
			if (leFunc.id == 0) {
				contador = -1;
				break;
			} else {
				contador = 1;
				leFunc.id = 0;
				fseek(f, -1*sizeof(func) , SEEK_CUR);
				fwrite(&leFunc, sizeof(func), 1, f);
				break;
			}
		}
	}

	if (contador == 1){
		system("clear");
		printf("\n	|---  Exclusão efetuada com sucesso! ---|");
	} else {
		if (contador == -1) {
			system("clear");
			printf("\n	|----------- Tente Novamente! ----------|\n");
			printf("       Funcionário já excluído com o ID informado!\n");
		} else {
			system("clear");
			printf("\n	|------- Funcionário não existe! -------|\n");
			printf("	|-------- Exclusão não efetuada  -------|\n");
		}
	}

	if (ferror(f)){
		printf("\n	|----- Erro na gravação do arquivo! ----|");
	}
	fclose(f);
}

void MediaSalario(){
	float somaF, somaM, mediaF, mediaM;
	int contF = 0, contM = 0;
	
	system("clear");
	fflush(stdin);
	fseek(f, 0, SEEK_SET);
	while(1){
		int cont = fread(&leFunc, sizeof(func), 1, f); 		
		if (cont == 0){
			break;
		}
		if (((leFunc.sexo == 'f') || (leFunc.sexo == 'F')) && (leFunc.id > 0)){
			somaF += leFunc.salario;
			contF++;
		}
		if (((leFunc.sexo == 'm') || (leFunc.sexo == 'M')) && (leFunc.id > 0)){
			somaM += leFunc.salario;
			contM++;
		}
	}

	mediaF = somaF/contF;
	mediaM = somaM/contM;
	printf("\n   |- Média dos Salários - F: %f \t M: %f -|", somaF, somaM);
	fclose(f);
}

void Exportar(){
	FILE *arqTxt;
	arqTxt = fopen("arquivo.txt","w");

	system("clear");
	fflush(stdin);
	fprintf(arqTxt, "|----------------------------------------- Funcionários ----------------------------------------------|\n");
	fprintf(arqTxt, "|-----------------------------------------------------------------------------------------------------|\n");
	fseek(f, 0, SEEK_SET);
	while(1){
		int cont = fread(&leFunc, sizeof(func), 1, f); 		
		if (cont == 0){
			break;
		}
		if (leFunc.id > 0) {
			fprintf(arqTxt, "|- ID: %u\t Nome: %s\t Sexo: %c Salário: %f\t \n", leFunc.id, leFunc.nome, leFunc.sexo, leFunc.salario);
			fprintf(arqTxt, "|-----------------------------------------------------------------------------------------------------|\n");
		}
	}
	fclose(f);
	fclose(arqTxt);

	if ((arqTxt = fopen("arquivo.txt", "r")) == NULL) {
		printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
	} else {
		system("clear");
		printf("\n	|-------------- Exportado! -------------|");
	}

}

void Compactar(){
	FILE *arq;
	arq = fopen("arquivo.bin","a+b");

	system("clear");
	fflush(stdin);
	fseek(f, 0, SEEK_SET);
	while(1){
		int cont = fread(&leFunc, sizeof(func), 1, f); 		
		if (cont == 0){
			break;
		}
		if (leFunc.id > 0) {
			fwrite(&leFunc, sizeof(func), 1, arq);
		}
	}
	fclose(f);
	fclose(arq);
	remove(caminhoArquivo);
	rename("arquivo.bin", caminhoArquivo);

	if ((f = fopen(caminhoArquivo, "r+b")) == NULL) {
		printf("\n	|---- Erro ao tentar abrir arquivo! ----|");
	} else {
		system("clear");
		printf("\n	|---------- Base Compactada! -----------|");
	}
}

void Consultar(){
	system("clear");
	fflush(stdin);
	fseek(f, 0, SEEK_SET);
	printf("	|------- Lista de Funcionários: --------|\n");
	while(1){
		int cont = fread(&leFunc, sizeof(func), 1, f); 		
		if (cont == 0){
			break;
		}
		printf("   ID: %u  Nome: %s\t Sexo: %c  Salário: %f\t \n", leFunc.id, leFunc.nome, leFunc.sexo, leFunc.salario);
	}
}
