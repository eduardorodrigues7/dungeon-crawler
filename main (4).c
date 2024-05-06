#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defini��o do tamanho do labirinto
#define LINHAS 12
#define COLUNAS 12

// Declara��o das vari�veis globais
int jogadorX, jogadorY;
int chaveX, chaveY;
int portaX, portaY;
char labirinto[LINHAS][COLUNAS];
int possuichave = 0;
int fim1 = 0; // Adicionando ponto e v�rgula
int eminemY2, eminemX2;

// Fun��o para inicializar o labirinto
void inicializarLabirinto() {
    int i, j;
    // Preencher o labirinto com espa�os em branco
    for(i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            if(i==0 || i==11 || j==0 || j==11){
                labirinto[i][j] = '*';
            } else {
                labirinto[i][j] = ' ';
            }
        }
    }
    // Colocar o jogador na posi��o inicial
    jogadorX = 1;
    jogadorY = 1;
    labirinto[jogadorY][jogadorX] = '&'; // '&' representa o jogador

    // Colocar a chave em uma posi��o aleat�ria
    srand(time(NULL));
    chaveX = rand() % (COLUNAS - 2) + 1;
    chaveY = rand() % (LINHAS - 2) + 1;
    labirinto[chaveY][chaveX] = '@'; // '@' representa a chave

    // Colocar a porta fechada em uma posi��o aleat�ria
    portaX = rand() % (COLUNAS - 2) + 1;
    portaY = rand() % (LINHAS - 2) + 1;
    labirinto[portaY][portaX] = 'D'; // 'D' representa a porta fechada
    // Colocar o inimigo em uma posi��o aleat�ria
    eminemX2 = rand() % (COLUNAS - 2) + 1;
    eminemY2 = rand() % (LINHAS - 2) + 1;
    labirinto[eminemY2][eminemX2] = 'E'; // 'E' representa o inimigo
}

// Fun��o para imprimir o labirinto na tela
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

// Fun��o para mover o jogador
void moverJogador(char direcao) {
    int novoX = jogadorX;
    int novoY = jogadorY;
    // Calcular a nova posi��o do jogador
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
    // Verificar se a nova posi��o � v�lida
    if (novoX >= 0 && novoX < COLUNAS && novoY >= 0 && novoY < LINHAS && labirinto[novoY][novoX] != '*') { // Corrigindo a condi��o
        // Atualizar a posi��o do jogador
        labirinto[jogadorY][jogadorX] = ' ';
        jogadorX = novoX;
        jogadorY = novoY;
        labirinto[jogadorY][jogadorX] = '&';
        // Verificar se o jogador pegou a chave
        if (possuichave == 1) {
            printf("Voce pegou a chave!\n");
            labirinto[chaveY][chaveX] = ' ';
            labirinto[portaY][portaX] = '='; // 'D' se torna '=' indicando que a porta est� aberta
        } else {
            labirinto[chaveY][chaveX] = '@';
            labirinto[portaY][portaX] = 'D';
        }
        // Verificar se o jogador chegou � porta com a chave
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
    if (novoEX >= 0 && novoEX < COLUNAS && novoEY >= 0 && novoEY < LINHAS && labirinto[novoEY][novoEX] != '*') { // Corrigindo a condi��o
        // Atualizar a posi��o do jogador
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
    scanf(" %c", &menu); // Adicionei um espa�o antes do %c para ignorar espa�os em branco

    if(menu == '1') {
        system("cls");
        iniciar = 1;
    }
    else if(menu == '2') {
        while(iniciar != 1){
        	system("cls");
        	printf("O jogador possui os seguintes comandos:\n\nW: O jogador movimenta uma unidade para cima;\nA: O jogador movimenta uma unidade para esquerda;\nS: O jogador movimenta uma unidade para baixo;\nD: O jogador movimenta uma unidade para direita;\nI: O jogador interage com o objeto que est� em cima.\n\nO jogo possui os seguintes elementos nas fases:\n\n&: S�mbolo que representa o jogador.\n*: S�mbolo que representa uma parede, o jogador ao se movimentar n�o pode passar pela parede.\n@: S�mbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\nD: S�mbolo que representa a porta fechada.\n=: S�mbolo que representa a porta aberta quando o jogador interage com a chave.\nO: S�mbolo que representa um bot�o que o usu�rio pode interagir, o bot�o fica no ch�o e o jogador deve ficar em cima dele para poder interagir.\n#: S�mbolo que representa um espinho. A fase � reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada tr�s vezes, o jogo volta para o menu principal.\n>: S�mbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele � transportado para o outro e vice-versa.\nX: S�mbolo que representa o monstro n�vel 1. Esse monstro tem um movimento aleat�rio para cima, para esquerda, para baixo e para direita. Caso o monstro toque no jogador, a fase � reiniciada.\nV: S�mbolo que representa o monstro n�vel 2. Esse monstro tem uma intelig�ncia para seguir o jogador (h� v�rias maneiras de implementar isso). Caso o monstro toque no jogador, a fase � reiniciada.\n\nPrecione 1 para iniciar o jogo:");
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
    	while (!fim1) { // Utilizando a vari�vel de controle de fim do jogo
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
