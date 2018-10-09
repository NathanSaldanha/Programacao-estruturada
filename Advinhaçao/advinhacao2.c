#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NUMERO_DE_TENTATIVAS 5

int i=1;

int main(){
	// imprime o cabecalho do nosso jogo
	printf("******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhacao *\n");	
	printf("******************************************\n");
	srand(time(0));
	int numerosecreto = rand()%99;
	printf("numero secreto eh:%i \n",numerosecreto );
	
	int chute;
	int pontos=1000;
	int tentativas = 1;
	int nivel;

	printf("Qual o nivel vc deseja escolher:\n");
	printf("1-Facil\n2-Medio\n3-Dificil\n");
	scanf("%i",&nivel);
	system("cls");

	switch (nivel){
		case 1:
		tentativas = 20;
		break;

		case 2:
		tentativas = 15;
		break;

		case 3:
		tentativas = 6;
		break;

		default:
		tentativas = 2;
		break;
	}


	do {
		
	    printf("Numeros de pontos:%d\n",pontos );
		printf("Tentativa %d\n", i);
		printf("Qual e o seu chute?");

		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);
        system("cls");
		if(chute < 0) {
			printf("Voce nao pode chutar numeros negativos\n");
			

			continue;
		}

		int acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;

		if(acertou) {
			printf("Parabens! Voce acertou! em %i tentativas\n",i);
			printf("Jogue de novo, voce e um bom jogador!!\n");

			break;
		}
			
		else if(maior) {
			printf("Seu chute foi maior que o numero secreto\n");
		}

		else {
			printf("Seu chute foi menor que o numero secreto\n");
		}


		pontos-=abs(numerosecreto-chute)/2;
		i++;
	}while(i!=tentativas);

	printf("Fim de jogo.\n");
	printf("Total de pontos:%d\n",pontos );
}