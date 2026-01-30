#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define JOGADORES 4
#define QTD_MATERIAS 5
#define QTD_CARTAS 7


void inicializaMao( int mao_jogador[JOGADORES][QTD_CARTAS] ) {
    for ( int i = 0; i < JOGADORES; i++) {
        for ( int j = 0; j < QTD_CARTAS; j++ ) {
            mao_jogador[i][j] = ( rand() % 5 ) + 1;
        }
    }
}

void incializaFormacaoJogador( int formacao_jogador[JOGADORES][QTD_MATERIAS] ) {
    for ( int i = 0; i < JOGADORES; i++ ) {
        for ( int j = 0; j < QTD_MATERIAS; j++ ) {
            formacao_jogador[i][j] = 0;
        }
    }
}

int verificaVencedor( int pontuacao_jogador[JOGADORES] ) {
    for(int j = 0; j < JOGADORES; j++ ) {
        if ( pontuacao_jogador[j] == 5 ) {
            return j;
        }
    }
    return -1;
}


void calcula_pontos( int mao_jogador[JOGADORES][QTD_CARTAS], int formacao_jogador[JOGADORES][QTD_MATERIAS], int pontuacao_jogador[JOGADORES], int j ) {
    int contador = 0;

    for ( int m = 0; m < QTD_MATERIAS; m ++ ) {
        contador = 0;
        for ( int c = 0; c < QTD_CARTAS; c++ ) {
            if ( mao_jogador[j][c] == ( m + 1 ) ) {
                contador++;
            }
        }

        if ( contador >= 3 && formacao_jogador[j][m] == 0) {
            pontuacao_jogador[j]++;
            formacao_jogador[j][m] = m+1 ;
        }
    }
}

int main() {
     
    setlocale(LC_ALL, "Portuuese");

    int pontuacao_jogador[JOGADORES] = {0,0,0,0}; //Variavel de pontuação de jogadores

    // int coringas[2] = {6}

    int mao_jogador[JOGADORES][QTD_CARTAS];

    int formacao_jogador[JOGADORES][QTD_MATERIAS];

    inicializaMao(mao_jogador);

    incializaFormacaoJogador(formacao_jogador);
    int resp;
    int t = 0;
    while ( t == 0 ) {
    
        for ( int j = 0; j < JOGADORES; j++ ) {
            printf("Jogador %i",j + 1);
            printf("\t- Pontos: %i", pontuacao_jogador[j] );


            printf("\t- Matérias formadas: ");
            for ( int f = 0; f < QTD_MATERIAS; f++ ) {
                printf(" %i",formacao_jogador[j][f] );
            }
            printf("\n");

            printf("Deck:");

            for(int d = 0; d < QTD_CARTAS; d++) {
                printf(" %i", mao_jogador[j][d]);
            }
            printf("\n");

            printf("Escolha um pra trocar (1,2,3,4,5,6,7):\n");
            scanf("%i",&resp);

            int nova_carta = ( rand() % 5 ) + 1;
            mao_jogador[j][resp - 1] = nova_carta;

            printf("você recebeu a carta %i\n", nova_carta);

            for(int d = 0; d < QTD_CARTAS; d++) {
                printf(" %i", mao_jogador[j][d]);
            }
            

            calcula_pontos(mao_jogador, formacao_jogador, pontuacao_jogador, j);


            printf("\nVEZ do proximo jogador\n");
            

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        }


        int moreno = verificaVencedor(pontuacao_jogador);

        if ( moreno != -1 ) {
            printf("Parabens, o Moredo %i ganhou...\n", moreno );
            t = 1;
        }

    }
    
    return 0;
}
