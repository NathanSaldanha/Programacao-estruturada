#include <stdio.h>
#include <stdlib.h>

char mapa[12][13];
int inicio_linha,inicio_coluna,fim_linha,fim_coluna;


void lerMapa(){
	FILE* f;
	f = fopen("m.txt", "r");

	for (int i = 0; i < 12; ++i){
		fscanf(f,"%s",mapa[i]);
	}

	fclose(f);
}


void imprimeMapa(){
	for (int i = 0; i < 12; ++i){
		printf("%s\n", mapa[i]);

	}
}
void encontrarInicio(){
	for(int i = 0; i < 12; i++){
		if(mapa[i][0] == '.'){
			
			mapa[i][0] = 'X';
			inicio_linha = i;
			inicio_coluna = 0;

			return;

		}
	}
}
void encontrarFim(){
	for (int i = 0; i < 11; ++i){
		if (mapa[i][11]=='.'){

			fim_linha = i;
			fim_coluna = 11;

			return;
		}	
	}
}

void travessiaDeLabirinto(){

	if(mapa[inicio_linha][inicio_coluna+1]=='.'){
		mapa[inicio_linha][inicio_coluna+1]='x';
		inicio_coluna++;
		//frente
	}else if(mapa[inicio_linha-1][inicio_coluna]=='.'){
		mapa[inicio_linha-1][inicio_coluna]='x';
		inicio_linha--;
		//abaixo
	}else if(mapa[inicio_linha+1][inicio_coluna]=='.'){
		mapa[inicio_linha+1][inicio_coluna]='x';
		inicio_linha++;
	 	//cima
	}else if(mapa[inicio_linha][inicio_coluna-1]=='.'){
		mapa[inicio_linha][inicio_coluna-1]='x';
		inicio_coluna--;
		//atras
	}
	
}
int achouFinal(){
	if (inicio_linha==fim_linha && inicio_coluna==fim_coluna){

		return 1;
	}
	return 0;
}

int main(){
	lerMapa();
	encontrarInicio();
	encontrarFim();

	while(!achouFinal()){
		imprimeMapa();
		travessiaDeLabirinto();
		
		for (int i = 0; i < 100000000; ++i){}
		system("cls");
	}

	
}