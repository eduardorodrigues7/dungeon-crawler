#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição do tamanho do labirinto
#define LINHAS 12
#define COLUNAS 12

// Declaração das variáveis globais
int jogadorX, jogadorY;
int chaveX, chaveY;
int portaX, portaY;
char labirinto[LINHAS][COLUNAS];
int possuichave = 0;
int fim1 = 0; // Adicionando ponto e vírgula
int eminemY2, eminemX2;

// Função para inicializar o labirinto
void inicializarLabirinto() {
    int i, j;
    // Preencher o labirinto com espaços em branco
    for(i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            if(i==0 || i==11 || j==0 || j==11){
                labirinto[i][j] = '*';
            } else {
                labirinto[i][j] = ' ';
            }
        }
    }
    // Colocar o jogador na posição inicial
    jogadorX = 1;
    jogadorY = 1;
    labirinto[jogadorY][jogadorX] = '&'; // '&' representa o jogador

    // Colocar a chave em uma posição aleatória
    srand(time(NULL));
    chaveX = rand() % (COLUNAS - 2) + 1;
    chaveY = rand() % (LINHAS - 2) + 1;
    labirinto[chaveY][chaveX] = '@'; // '@' representa a chave

    // Colocar a porta fechada em uma posição aleatória
    portaX = rand() % (COLUNAS - 2) + 1;
    portaY = rand() % (LINHAS - 2) + 1;
    labirinto[portaY][portaX] = 'D'; // 'D' representa a porta fechada
    // Colocar o inimigo em uma posição aleatória
    eminemX2 = rand() % (COLUNAS - 2) + 1;
    eminemY2 = rand() % (LINHAS - 2) + 1;
    labirinto[eminemY2][eminemX2] = 'E'; // 'E' representa o inimigo
}

// Função para imprimir o labirinto na tela
void imprimirLabirinto() {
    int i, j;
    system("cls");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%c ", labirinto[i][j]);
        }
        printf("\n");
    }
}

// Função para mover o jogador
void moverJogador(char direcao) {
    int novoX = jogadorX;
    int novoY = jogadorY;
    // Calcular a nova posição do jogador
    switch (direcao) {
        case 'w':
            novoY--;
            break;
        case 's':
            novoY++;
            break;
        case 'a':
            novoX--;
            break;
        case 'd':
            novoX++;
            break;
        case 'i':
            if(jogadorX == chaveX && jogadorY == chaveY){
                possuichave = 1;
            }
            break;
    }
    // Verificar se a nova posição é válida
    if (novoX >= 0 && novoX < COLUNAS && novoY >= 0 && novoY < LINHAS && labirinto[novoY][novoX] != '*') { // Corrigindo a condição
        // Atualizar a posição do jogador
        labirinto[jogadorY][jogadorX] = ' ';
        jogadorX = novoX;
        jogadorY = novoY;
        labirinto[jogadorY][jogadorX] = '&';
        // Verificar se o jogador pegou a chave
        if (possuichave == 1) {
            printf("Voce pegou a chave!\n");
            labirinto[chaveY][chaveX] = ' ';
            labirinto[portaY][portaX] = '='; // 'D' se torna '=' indicando que a porta está aberta
        } else {
            labirinto[chaveY][chaveX] = '@';
            labirinto[portaY][portaX] = 'D';
        }
        // Verificar se o jogador chegou à porta com a chave
        if (jogadorX == portaX && jogadorY == portaY && possuichave == 1) {
            system("cls");
            printf("VOCE PASSOU DE FASE!!!\n");
            fim1 = 1;
        }
    }
}
void eminemMove2(){
	int eminem2;
	int novoEX = eminemX2;
    int novoEY = eminemY2;
	srand(time(NULL));
	eminem2 = 1 + (rand() % 4);
	
	switch (eminem2) 
	{
		case 1:
			if(eminemY2==1) 
			{} 
			else 
			{
				novoEY--;
			}
			break;
		case 2:
			if(eminemY2==28) 
			{} 
			else 
			{
				novoEY++;

			}
			break;
		case 3:
			if(eminemX2==1) 
			{} 
			else 
			{
				novoEX--;
			}
			break;
		case 4:
			if(eminemX2==28) 
			{} 
			else 
			{
				novoEX++;
			}
			break;
	}
    if (novoEX >= 0 && novoEX < COLUNAS && novoEY >= 0 && novoEY < LINHAS && labirinto[novoEY][novoEX] != '*') { // Corrigindo a condição
        // Atualizar a posição do jogador
        labirinto[eminemY2][eminemX2] = ' ';
        eminemX2 = novoEX;
        eminemY2 = novoEY;
        labirinto[eminemY2][eminemX2] = 'E';
	}
}
int main() {
	char menu;
	int iniciar = 0;
    printf("Menu Inicia:\n\n[1] Jogar\n[2] Tutorial\n[3] Sair\n\nEscolha:");
    scanf(" %c", &menu); // Adicionei um espaço antes do %c para ignorar espaços em branco

    if(menu == '1') {
        system("cls");
        iniciar = 1;
    }
    else if(menu == '2') {
        while(iniciar != 1){
        	system("cls");
        	printf("O jogador possui os seguintes comandos:\n\nW: O jogador movimenta uma unidade para cima;\nA: O jogador movimenta uma unidade para esquerda;\nS: O jogador movimenta uma unidade para baixo;\nD: O jogador movimenta uma unidade para direita;\nI: O jogador interage com o objeto que está em cima.\n\nO jogo possui os seguintes elementos nas fases:\n\n&: Símbolo que representa o jogador.\n*: Símbolo que representa uma parede, o jogador ao se movimentar não pode passar pela parede.\n@: Símbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\nD: Símbolo que representa a porta fechada.\n=: Símbolo que representa a porta aberta quando o jogador interage com a chave.\nO: Símbolo que representa um botão que o usuário pode interagir, o botão fica no chão e o jogador deve ficar em cima dele para poder interagir.\n#: Símbolo que representa um espinho. A fase é reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada três vezes, o jogo volta para o menu principal.\n>: Símbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele é transportado para o outro e vice-versa.\nX: Símbolo que representa o monstro nível 1. Esse monstro tem um movimento aleatório para cima, para esquerda, para baixo e para direita. Caso o monstro toque no jogador, a fase é reiniciada.\nV: Símbolo que representa o monstro nível 2. Esse monstro tem uma inteligência para seguir o jogador (há várias maneiras de implementar isso). Caso o monstro toque no jogador, a fase é reiniciada.\n\nPrecione 1 para iniciar o jogo:");
        	scanf("%d", &iniciar);
		}
    }
    else {
        system("cls");
        exit(0);
    }
	if(iniciar == 1){
    	char movimento;
    	// Inicializar o labirinto
    	inicializarLabirinto();
    	// Loop principal do jogo
    	while (!fim1) { // Utilizando a variável de controle de fim do jogo
  	      // Imprimir o labirinto
  	      imprimirLabirinto();
  	      // Ler o movimento do jogador
  	      movimento = getch();
  	      // Mover o jogador
  	      moverJogador(movimento);
  	      eminemMove2();
   		}
	}
    return 0;
}
