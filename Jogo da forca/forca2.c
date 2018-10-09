#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

#define Tamanho_Palavra 20

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;
int totalDeErros;
char nome[30];
int pontos = 0;

int acertou(){
	for (int i = 0; i < strlen(palavrasecreta); ++i){
		if (!chutou(palavrasecreta[i])){
			return 0;
		}
	}
	printf("\n");
	printf("\n");
	printf("						 __________\n");
	printf("						|PARABENS|\n");
	printf("						 ----------\n");
	printf("                                      _______                                                         \n");
	printf("                                     [.......]                                                           \n");
	printf("                                    {  *   *  }                                                \n");
	printf("                                     |   &   |                                       \n");
	printf("                                     |__ - __|                                             \n");
	printf("                                     ___| |___                                        \n");
	printf("               _____________________[         ]_____________________________________  \n");
	printf("               |  ****************/             \\******************  |\n");
	printf("               |  ***************/ /|  * |  * |\\ \\**************  |\n");
	printf("               |  **************/ / | ___|___ |*\\ \\*************  |\n");
	printf("               |  *************[__] ||___|___||*[__]*************  |\n");
	printf("               |   *****************||___|___||    Jogo de Forca (^_^)**********   |\n");
	printf("               |  ******************||___*___||******************  |\n");
	printf("               |   *****************|_________|    Jogo de Forca (^_^)**********   |\n");
	printf("               |    ******************  |||*****************|***********    |\n");
	printf("               |    ******************  |||****************/|\\*********     |\n");
	printf("               |    ********************|||******************|*********      |\n");
	printf("               |    ******************[__|__] \\**************** / \\*******       |\n");
	printf("																					");
	printf("               ---------------------------------------------------------------\n");
	
		
	
		return 1;
}


void abertura() {
	printf("\n");
	printf("						 __________\n");
	printf("						|PREPARE-SE|\n");
	printf("						 ----------\n");
	printf("               _______________________________________________________________\n");
	printf("               |  ********************* ___ ****************___ ***********  |\n");
	printf("               |   ******************* (*_*) Jogo de Forca (*_*)**********   |\n");
	printf("               |    *********************|*******************|***********    |\n");
	printf("               |    ********************/|\\*****************/|\\*********     |\n");
	printf("               |    *********************|*******************|*********      |\n");
	printf("               |    ********************/ \\**************** / \\*******       |\n");
	printf("               ---------------------------------------------------------------\n");
}

void chuta() {
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[tentativas] = chute;
	tentativas++;
}
int chutou(char letra){
		int achou = 0;

		for(int j = 0; j < tentativas; j++) {
				if(chutes[j] == letra) {
					achou = 1;
					break;
				}
			}
			return achou;
}

void desenhaforca(){

	int erros=numChuteserrados();

	printf(" ________      \n");
	printf(" |/     |     \n");
	printf(" |     %c%c%c    \n", (erros>=1? '(' : ' ') , (erros>=2? '_' : ' ') ,(erros>=3? ')' : ' ')   );
	printf(" |     %c%c%c   \n", (erros>=4? '\\' : ' ') , (erros>=5? '|' : ' ') ,(erros>=6? '/' : ' ') );
	printf(" |      %c     \n",(erros>=7? '|' : ' '));
	printf(" |     %c %c   \n",(erros>=8? '/' : ' '),(erros>=9? '\\' : ' ') );
	printf(" |            \n");
	printf("_|__             \n");
	printf("\n\n");

	printf("voce ja deu %d chutes\n", tentativas );
	for(int i = 0; i < strlen(palavrasecreta); i++) {
		if(chutou(palavrasecreta[i])) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}
	}
}
void escolhepalavra(){
	FILE* f;
	f= fopen("dicionario.txt","r");
	if (f == 0){
		printf("Erro! Problema no arquivo\n");
		exit(1);
	}
	int quantidadePalavra;
	fscanf(f, "%d",&quantidadePalavra);

	srand(time(0));
	int numeroAleatorio = rand()%quantidadePalavra;

	for (int i = 0; i <=numeroAleatorio; ++i)	{
		fscanf(f, "%s", palavrasecreta);
	}
	fclose(f);
}
int enforcou(){
	int errosAtuais=0;
	
	for(int i = 0; i <= tentativas; i++) {
		int existe=0;
		for (int j = 0; j <= strlen(palavrasecreta); j++){
			if (palavrasecreta[j]==chutes[i]){
				existe = 1;
				break;
			}
		}
		if (existe==0){
			errosAtuais++;
		}
	}	
	return errosAtuais>=totalDeErros;
}
 void adicionarPalavra(){
	char escolha;
	printf("Deseja adicionar Palavra: S ou N\n");
	scanf("%s",&escolha);

	if (escolha == 'S'  || escolha == 's'){
		char novaPalavra[20];
		printf("adicionar Palavra:\n");
		scanf("%s",&novaPalavra);
		if(!palavraExiste(novaPalavra)){
			printf("A palavra ja existe em nosso dicionario!\n");
			system("pause");
			return;
		}

		FILE* f = fopen("dicionario.txt","r+");

		if (f==0){
			printf("Erro\n");
			exit(1);
		}

		fprintf(f,"%s\n",novaPalavra);
		fclose(f);

		f = fopen("palavrastotal.txt","r");
		
		int quantidadeDePalavras;
		fscanf(f,"%d",&quantidadeDePalavras);
		fclose(f);
		quantidadeDePalavras++;
		f = fopen("palavrastotal.txt","w");
		fprintf(f, "%04d\n",quantidadeDePalavras);
		fclose(f);	
	}
}

int letraExiste(char letra){

	for (int j = 0; j <= strlen(palavrasecreta); j++){
			if (palavrasecreta[j]==letra){
				return 1;		
			}
		}
		return 0;
}

int numChuteserrados(){
	int errosAtuais=0;
	
	for(int i = 0; i <= tentativas; i++) {
	
		if (!letraExiste(chutes[i])){
			errosAtuais++;
		}
	}	
	return errosAtuais;
}
////***************************

int main() {	

	abertura();
	dificuldade();
	escolhepalavra();

	do {
		
		desenhaforca();
		printf("\n");
		chuta();

	} while (!acertou() && !enforcou());
	adicionarPalavra();
}
//***************************************************

char letraValida(char chute){
	if(chute >= 65 && chute <= 90){
		chutes[tentativas] = chute;
		tentativas++;
		
	}else{
		printf("So sao permitidas letras maiusculas!\n");
		
	}
 }
 int palavraExiste(char * novaPalavra){
 	FILE *f;
 	int totalDeElementos;
 	f = fopen("palavrastotal.txt","r");
 	fscanf(f,"%d",&totalDeElementos);
 	fclose(f);
 	f = fopen("dicionario.txt","r");
 	for (int i = 0; i < totalDeElementos; ++i){
 		char novaP[100];
 		fscanf(f,"%s",&novaP);
 		if(strcmp(novaPalavra,novaP)==0){
 			return 1;
 		}
 		return 0;

 	}
 }
  void dificuldade(){
 	int difi;
 	printf("Escolha o nivel de dificuldade: \n 1 = Facil \n 2 = Medio \n 3 = Dificil\n");
 	scanf("%d",&difi);
 	switch(difi){
 	case 1 :
 		 totalDeErros = 8;
 		 break;
  	case 2:
 		totalDeErros = 6;
 		break;
 	case 3 :
 		totalDeErros = 5;
 		break;
 	default :
 		totalDeErros = 8;
 		break;
 	}
 }
 