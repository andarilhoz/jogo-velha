#include <iostream>
#define N 3

bool verificaCombinacoes( int velha[N][N], int jogadorDaVez,bool acabou ) {
//verifica linhas
		int cl;
	
		for(int i = 0; i< N; i++){
			cl = 0;
			for(int j = 0; j < N; j++){
				cl = velha[i][j] == jogadorDaVez ? cl + 1 : cl;
			}
			if(cl == N)
				acabou = true;
		}

		// verifica colunas

		int cc;
		
		for(int i = 0; i< N; i++){
			cc = 0;
			for(int j = 0; j < N; j++){
				cc = velha[j][i] == jogadorDaVez ? cc + 1 : cc;
			}
			if(cc == N)
				acabou = true;
		}

		// verifica diagonais

		int cd = 0;

		for(int i =0; i < N; i++){
			cd = velha[i][i] == jogadorDaVez ? cd + 1 : cd;
		}
		if(cd == N)
			acabou = !acabou;
		
	
		cd = 0;

		for(int i =0; i < N; i++){
			cd = velha[i][N -(i+1)] == jogadorDaVez ? cd + 1 : cd;
		}
		if(cd == N)
			acabou = true;

		return acabou;
}

int imprimeTabuleiro(int velha[N][N]){
	for(int i =0; i < N; i++){
		for(int j = 0; j < N; j++ ){
			std::cout<<velha[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int main(int argc, char **argv){
	int velha[N][N] = {0};
	int jogadorDaVez = 1;
	bool acabou = false;

	do {
		imprimeTabuleiro(velha);
		int linha, coluna;
		int tentativas = 0;

		do{
			
			std::cout<<"Jogador da vez:"<< jogadorDaVez<<" Digite uma linha e uma coluna"<<(tentativas++ > 0 ? " Tente de 0 a 2" : " " )<< std::endl;
			std::cin>> linha;
			std::cin>> coluna;
		}while(((linha < 0 || linha > 3) || (coluna < 0 || coluna > 2)) ||  velha[linha][coluna] != 0);
		
		velha[linha][coluna] = jogadorDaVez;



		acabou = verificaCombinacoes(velha,jogadorDaVez,acabou);	
		
		int total = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				total = velha[i][j] > 0  ? total + 1 : total ;
			}
		}

		if(total == N * N)
			acabou = true;
	
		jogadorDaVez = (jogadorDaVez == 1 ? 2 : 1);

	
	}while(!acabou);
	std::cout<<"Jogo Acabou"<<std::endl;
	imprimeTabuleiro(velha);


	return 0;
}
