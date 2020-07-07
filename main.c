/*
Universidade Federal de Itajubá
Programa referente a atividade avaliativa 1 - COM110
----------------------------------------------------------
| Mauro Sérgio Ribeiro de Souza - 2020020935              |
| André Marcos Ferreira - 2020026106                      |
----------------------------------------------------------

Jogo do 15

Objetivo: O objetivo do jogo é organizar as peças em ordem, da esquerda para a direita,
de cima a baixo fazendo a menor quantidade movimentos possível utilizando o
espaço vazio para mover as peças.

*/

//INCLUDES

// Os includes servem para importar bibliotecas já existentes no direório do C ou criadas pelo desenvolvedor
#include <stdio.h>   //Biblioteca padrão
#include <string.h>  //Biblioteca string
#include <stdlib.h>  //Biblioteca de propósito geral padrão
#include <stdbool.h> //Biblioteca de variáveis lógicas
#include <time.h>    //Biblioteca de manipulação de tempo
#include <math.h>    //Biblioteca de manipulação de números, será utilizada para realizar o sorteio dos números no tabuleiro

//FIM DOS INCLUDES

//STRUCT do usuário 
typedef struct Jogador{
    char nome[50]; //Nome
    int jogadas; //Pontuação
} Jogador; //Nome da STRUCT


//Função implementada para enfeitar a inicialização do jogo e apresentar uma mensagem de boas vindas 
void CarregarJogo(){
  for(int i = 0; i < 1 ; i++){ // For para apresentar a tela de Carregamento - VISUAL
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo .");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo ..");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo ...");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela    
  } // Final do for
  printf("\n"); //Pular linha
  system("clear"); //Limpar tela
  system("sleep 01"); //Delay de 1 segundo
  //Impriminto tela de Boas Vindas - Deixar o jogo mais bonito - VISUAL
  printf("|--------------------------------|\n");
  printf("|                                |\n");
  printf("|         BEM VINDO AO           |\n");
  printf("|          JOGO DO 15            |\n");
  printf("|             :)                 |\n");
  printf("|--------------------------------|\n");
} //------------------------------------------ PRONTO

//Função implementada para embelezar a opção SAIR - VISUAL
void SairDoJogo(){
  printf("\n"); //Pular linha
  printf("\n Salvando configurações... ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); // Limpar tela
  printf("\n Finalizando o jogo... ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); //Limpa a tela
  printf("\n Nós vemos por ai! ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); //Limpa a tela
  printf("\n Obrigado por ter jogado! ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); //Limpa a tela
}//------------------------------------------ PRONTO

//Funçao implementada para a impressão do Menu Principal
int ImprimeMenu(){
  printf("|----------- MENU ---------------|\n");
  printf("|                                |\n");
  printf("| 1 - JOGAR                      |\n");
  printf("| 2 - RANKING                    |\n");
  printf("| 3 - REGRAS                     |\n");
  printf("| 4 - SAIR                       |\n");
  printf("|                                |\n");
  printf("|---- Opção Escolhida: ");
} //------------------------------------------ PRONTO

//Função criada para dar uma pausa, para que o usuário possa ter o tempo que precisar para a leitura das REGRAS, RANKING e COMO JOGAR
void Pausa(){
  printf("\n"); //Pula linha
  char tecla[5]; //Variável criada para realizar a leitura de um caractere após a leitura 
  printf("Aperte qualquer letra para continuar...");
  scanf("%s",&tecla); //Captura da variável para prosseguir o programa
  printf("\n"); //Pula linha
  system("clear"); //Limpa a tela
} //------------------------------------------ PRONTO

//Função implementada para exibir as REGRAS
void Regras(){
  printf("\n"); //Pular linha
  system("clear"); //Limpar tela
  FILE *regra; //Criando arquivo
  char LinhaRegra[100]; //Vetor para impressão das linhas do arquivo
  char *resultadoRegra; //Ponteiro para leitura do arquivo
  regra = fopen("regras.txt", "rt"); //Abrindo arquivo para leitura
  if(regra == NULL){ //Verificando se o arquivo possui informações
    printf("-----------------------------------\n");
    printf("Não foi possível carregar as regras\n");
    printf("-----------------------------------\n");
  } //Fim IF verifica informações
  printf("\n"); //Pular linha
  while(!feof(regra)){
    resultadoRegra = fgets(LinhaRegra, 100, regra); //Ponteiro captura a linha que está sendo lida
    if(resultadoRegra != NULL){ //Se a última posição do ponteiro não for nula
      printf("  %s", LinhaRegra);
    }
  }
  Pausa(); //Chama a função de pausa no código
  fclose(regra); //Fecha arquivo regras
}
//------------------------------------------ PRONTO

//Função implementada para exibir o RANKING
void Ranking(){
  system("clear"); //Limpar tela
  FILE *rank; //Declarando o arquivo
  char Linha [100]; //Variável para pegar a linha do ranking
  char *resultadoranking; //Receber resultado (ponteiro)
  rank = fopen("ranking.txt", "rt"); //Abrir documento
  if(rank == NULL){ //Verificando se foi feita a abertura
    printf("\n--------------------------------");
    printf("\n FALHA AO CARREGAR O RANKING ");
    printf("\n--------------------------------");
  } //Fim IF
  printf("\n ---------------- ");
  printf("\n     PLACAR       \n");
  while(!feof(rank)){ //Verificando se está nulo para frente
    resultadoranking = fgets(Linha, 100, rank); //Ponteiro captura a linha que está sendo lida
    if(resultadoranking != NULL){ //Se a ultima posição do ponteiro não for nulo
      printf("    %s", Linha); //Imprime a linha
    }
  }
  printf("\n \n"); //Pular duas linha
  printf(" ---------------- \n");
  Pausa(); //Chama a função de pausa no código
  fclose(rank); //Fecha arquivo ranking
}
//------------------------------------------ PRONTO

//Função implementada para imprimir tabuleiro
void ImprimeTabuleiro (int tabu[4][4]){ //Recebe uma matriz de inteiros como parametro
  printf("TABULEIRO: \n"); //Cabeçalho do tabuleiro
  printf("\n"); //Pular linha
  printf("|-------------|\n"); //Borda superior
  for(int i = 0; i < 4; i++){ //Linha
    for(int j = 0; j < 4; j++){ //Coluna
      if(j==0){ //Verifica se é o primeiro número da coluna para inserir a borda
        printf("| "); //Borda lateral esquerda
      }
      if(tabu[i][j] < 10){ //Verifica se o número da natriz é menor que 10
        printf("0%d ",tabu[i][j]); //Imprime um 0 na frente do número (ex: o número 1 vira 01)
        //implementado para deixar a matriz alinhada
      }else{
        printf("%d ",tabu[i][j]); //Imprime o número da matriz
      }
      if(j==3){ //Verifica se é o último número da coluna para inserir a borda
        printf("|"); //Borda lateral direita
        if(i==0){ //Verifica se é a primeira linha da matriz
          printf("    A casa em branco");
        } //Fim IF primeira linha
        if(i==1){ //Verifica se é a segunda linha da matriz
          printf("    se refere ao número 00");
        } //Fim IF segunda linha 
      } //Fim IF último coluna 
    } //Fim FOR Coluna
    printf("\n"); //Pular linha
  } //Fim FOR Linha
  printf("|-------------|\n"); //Borda inferior
  printf("\n"); //Pular linha
}

//Função implementada para fazer testes enquanto é gerado o Tabuleiro
int testeVariavel(int numero, int tabu[4][4], int i, int j){
   // 1 - VERDADEIRO | 0 - FALSO
  if( j == 3){ //Se está na ultima coluna
    if(i == 3){ //Se está na ultima linha
      return 1; //Retorna verdadeiro
    }else{ // Se não estiver na última linha 
      for(int i = 0; i < 4; i++){ //Roda linha
        for(int j = 0; j < 4; j++){ //Roda coluna
          if(numero == tabu[i][j]){ //Testa se o número gerado já existe no tabuleiro
            return 0; //Retorna falso
          } //Fim IF
        } //Fim FOR coluna
      } //Fim FOR linha
    } //Fim ELSE
  }else{  //Se não estiver na última coluna
    for(int i = 0; i < 4; i++){ //Roda linha
      for(int j = 0; j < 4; j++){ //Roda coluna
        if(numero == tabu[i][j]){ //Testa se o número gerado já existe no tabuleiro
          return 0; //Retorna falso
        } //Fim IF
      } //Fim FOR coluna
    } //Fim FOR linha
  } //Fim ELSE
  return 1; //Retorna verdadeiro
} //------------------------------------------------- PRONTO

//Função implementada para explicar ao usuário a maneira como jogar e qual o objetivo dele - VISUAL e EXPLICATIVA
void ComoJogar(){
  system("clear"); //Limpa tela
  printf("|------------- COMO JOGAR -------------------|\n");
  printf("| Para ganhar você deverá ordenar os         |");
  printf("\n| números em ordem crescente da esquerda     |");
  printf("\n| para direita e de cima para baixo          |");
  printf("\n| Para jogar você deverá digitar o número    |");
  printf("\n| que deseja mover para a posição 00 (vazia) |");
  printf("\n| quando for solicitado                      |");
  printf("\n|--------------------------------------------|");
  printf("\n"); //Pula linha
  Pausa(); //Chama a função de dar uma pausa na repodução do código
  system("clear"); //Limpa tela
} //---------------------------------------------------- PRONTO

//Função implementada para verificar a finalizção do tabuleiro
int testaFinalTabuleiro(int tabu[4][4], int tabucerto[4][4]){
  //0 - FALSO | 1 - VERDADEIRO
  for(int i = 0; i < 4; i++){ //Testa linha
    for(int j = 0; j < 4; j++){ //Testa coluna
      if(tabu[i][j] != tabucerto[i][j]){ //Condição se não são iguais
        return 0; //Se não forem iguals
     } //Fim IF
    } //Fim FOR coluna
  } //Fim FOR linha
  return 1; //Se forem iguais
} //-------------------------------------------------- PRONTO

//Função criada para retornar a posição da linha do número que será movido no tabuleiro 
int RetornaLinha(int numero, int tabu[4][4]){
  int posicao; //Váriavel par salvar a linha
  for(int i = 0; i < 4; i++){ //Pecorre linhas
    for(int j = 0; j < 4; j++){ //Pecorre colunas
      if(numero==tabu[i][j]){ //Condição se a linha tem o número desejado
        posicao = i; //Salva a linha
      } //Fim IF
    } //Fim FOR coluna
  } //Fim FOR linha
  return posicao; //Retorna a posição
} //-------------------------------------------------- PRONTO

//Função criada para retornar a posição da coluna do número que será movido no tabuleiro 
int RetornaColuna(int numero, int tabu[4][4]){
  int posicao; //Váriavel par salvar a coluna
  for(int i = 0; i < 4; i++){ //Pecorre linhas
    for(int j = 0; j < 4; j++){ //Pecorre colunas
      if(numero==tabu[i][j]){ //Condição se a coluna tem o número desejado
        posicao = j; //Salva a coluna
      } //Fim IF
    } //Fim FOR coluna
  } //Fim FOR linha
  return posicao; //Retorna a posição
} //-------------------------------------------------- PRONTO

//Função implementada para verificar se o número pode ser movido para a posição 00 no tabuleiro
bool PosicaoCorreta(int numero, int tabu[4][4], int posicao [2]){
  int linha = posicao[0]; //Recebe a posição da linha do nímero
  int coluna = posicao[1]; //Recebe a posição da coluna do número
  if(linha == 0){ //Se o número estiver na primeira linha
    if(coluna == 0){ //Se o número estiver na primeira coluna
      //Número na posicao (0,0)
      if(tabu[linha][coluna+1] == 0){ //Verifica se está a Direita
        return true; //Retorna verdadeiro
      }else{ //Se não estiver na direita
        if(tabu[linha+1][coluna] == 0){ //Verifica se está a Baixo
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a baixo
          return false; //Retorna falso
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se não estiver na primeira linha e primeira coluna
    if(coluna == 1 || coluna == 2){ //Se o número estiver na segunda ou terceira coluna
      //Número na posição (0,1) ou (0,2)
      if(tabu[linha][coluna+1] == 0){ //Verifica se está a Direita
        return true; //Retorna verdadeiro
      }else{ //Se não estiver na direita
        if(tabu[linha][coluna-1] == 0){ //Verifica se está a Esquerda
          return true; //Retorna verdadeiro
        }else{ //Se não estiver na esquerda 
          if(tabu[linha+1][coluna]==0){ //Verifica se está a Baixo
            return true; //Retorna verdadeiro
          }else{ //Se não estiver a baixo
            return false; //Retorna falso
          } //Fim IF ELSE
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se não estiver na segunda ou terceira coluna e primeira linha
    if(coluna == 3){ //Se estiver na última coluna
      //Número na posição (0,3)
      if(tabu[linha][coluna-1] == 0){ //Verifica se está a Esquerda
        return true; //Retorna verdadeiro
      }else{ //Se não estiver na esquerda
        if(tabu[linha+1][coluna] == 0){ //Verifica se está a Baixo
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a baixo
          return false; //Retorna falso
        } //Fim IF ELSE
      } //FIm IF ELSE
    } //Fim IF se não estiver na terceira coluna e na primeira linha
  } //FIM IF se não estiver na primeira linha
  if(linha == 1 || linha == 2){ //Se o número estiver na linha segunda ou terceira linha
    if(coluna == 0){ //Se o número estiver na primeira coluna
      //Número na posição (1,0) ou (2,0)
      if(tabu[linha][coluna+1] == 0){ //Verifica se está a Direita
        return true; //Retorna verdadeiro
      }else{ //Se não estiver a direita
        if(tabu[linha-1][coluna] == 0){ //Verifica se está a Cima
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a cima
          if(tabu[linha+1][coluna] == 0){ //Verifica se está a Baixo
            return true; // Retorna verdadeiro
          }else{ //Se não estiver a baixo
            return false; //Retorna falso
          } //Fim IF ELSE
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se não estiver na primeira coluna da primeira ou segunda linha
    if(coluna == 1 || coluna == 2){ //Se o número estiver na segunda ou terceira coluna
      //Número na posição (1,1) | (1,2) | (2,1) | (2,2)
      if(tabu[linha][coluna+1] == 0){ //Verifica se está a Direita
        return true; //Retorna verdadeiro
      }else{ //Se não estiver a Cima
        if(tabu[linha][coluna-1] == 0){ //Verifica se está a Esquerda
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a esquerda
          if(tabu[linha-1][coluna] == 0){ //Verifica se está a Cima
            return true; //Retorna verdadeiro
          }else{ //Se não estiver a cima
            if(tabu[linha+1][coluna] == 0){ //Verifica se está a Baixo
              return true; //Retorna verdadeiro
            }else{ //Se não estiver a baixo
              return false; //Retorna falso
            } //Fim IF ELSE
          } //Fim IF ELSE
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se o número não estiver na segunda ou terceira coluna da segunda e terceira linha
    if(coluna == 3){ //Se o número estiver na terceira coluna
      //Número na posicao (1,3) ou (2,3)
      if(tabu[linha][coluna-1] == 0){ //Verifica se está a Esquerda
        return true; //Retorna verdadeiro
      }else{ //Se não estiver a esquerda
        if(tabu[linha-1][coluna] == 0){ //Verifica se está a Cima
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a cima
          if(tabu[linha+1][coluna] == 0){ //Verifica se está a Baixo
            return true; //Retorna verdadeiro
          }else{ //Se não estiver a baixo
            return false; //Retorna falso
          } //Fim IF ELSE
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se o número não estiver na última coluna da segunda ou terceira linha
  } //Se o número não estiver na primeira ou segunda linha
  if(linha == 3){ //Se o número estiver na ultima linha
    if(coluna == 0){ //Se o número estiver na primeira coluna
      //Número na posição (3,0)
      if(tabu[linha][coluna+1] == 0){ //Verifica se está a Direita
        return true; //Retorna verdadeiro
      }else{ //Se não estiver a direita
        if(tabu[linha-1][coluna] == 0){ //Verifica se está a Cima
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a cima
          return false; //Retorna falso
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se o número não estiver na primeira coluna da última linha
    if(coluna == 1 || coluna == 2){ //Se estiver na segunda ou terceira coluna
      //Número na posição (3,1) ou (3,2)
      if(tabu[linha][coluna+1] == 0){ //Verifica se está a Direita
        return true; //Retorna verdadeiro
      }else{ //Se não estiver a direita
        if(tabu[linha][coluna-1] == 0){ //Verifica se está a Esquerda
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a esquerda
          if(tabu[linha-1][coluna] == 0){ //Verifica se está a Cima
            return true; //Retorna verdadeiro
          }else{ //Se não estiver a cima
            return false; //Retorna falso
          } //Fim IF ELSE
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se o número não estiver na segunda ou terceira coluna da última linha
    if(coluna == 3){ //Se estiver na última coluna
      //Número na posição (3,3)
      if(tabu[linha][coluna-1] == 0){ //Verifica se está a Esquerda
        return true; //Retorna verdadeiro
      }else{ //Se não estiver a direita
        if(tabu[linha-1][coluna] == 0){ //Verifica se está a Cima
          return true; //Retorna verdadeiro
        }else{ //Se não estiver a cima
          return false; //retorna falso
        } //Fim IF ELSE
      } //Fim IF ELSE
    } //Fim IF se não estiver na última coluna e na última linha
  } //Fim IF se não estiver na última linha
  return false; //Caso não seja possível realizar a troca pois o número 00 não está ao redor do número
} //-------------------------------------------------- PRONTO

//Função criada para inserir o ganhador no arquivo RANKING.TXT
void SalvarResultado(int pontos){
  Jogador j1; //Criando a struct do jogador para armazenar seus dados
  j1.jogadas = pontos; //Recebendo a quantidade de jogadas foi necessário para ganhar o jogo
  printf("\n PARABÉNS VOCÊ GANHOU !!"); 
  printf("\n\n Número de jogadas: %d",pontos); //Exibindo pontuação
  printf("\n Insira seu nome para o ranking: "); 
  scanf("%s", &j1.nome); //Recebendo o nome do jogador ganhador
  FILE *rank; //Declarando o arquivo
  rank = fopen("ranking.txt", "a"); //Abrindo o documento
  char espaco [] = " "; //Variável para inserir espaçamento no documento
  char enter [] = "\n"; //Variável para pular linha do documento
  fputs(enter, rank); //Pulando linha no arquivo aberto rank
  fputs(j1.nome, rank); //Inserindo o nome no arquivo aberto rank
  fputs(espaco, rank); //Inserindo espaço no arquivo aberto rank
  fprintf(rank, "%d", j1.jogadas); //Inserindo o número de jogadas no arquivo aberto rank
  fclose(rank); //Fechando o rank
} //-------------------------------------------------- PRONTO

//Função implementada para iniciar o MODO DE JOGO
void Jogar(){
  system("clear"); //Limpar tela
  int tabuaux [64]; //Vetor criado para pegar números aleatorios para o tabuleiro
  int tabu[4][4]; //Matriz criada para ser utilizada como tabuleiro
  int tabucerto[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0}; //Gerando tabuleiro certo
  int cont = 0; //Contador da posição do vetor
  int teste = 0; //Variável de teste para poder sair do "DO" caso tenha dado certo a operação da função "testeVariavel"
  int numero; //Número que a pessoa deseja mover
  int auxiliar; //Recebe o valor do número e troca de posição com o 00
  int pontos =0; //Conta o número de jogadas
  int posicao [2]; //Posicao do número no tabuleiro
  int posicaozero [2]; //Posição do número 0 no tabuleiro
  int retornoFinal = 0; //FVariável criada para receber o retorno da função testaFinalTabuleiro, se é verdadeira ou falsa
  srand((unsigned)time(NULL)); //Gerando seed aleátoria para o rand() - funçao que gera números aleatorios
  for(int i = 0; i < 64; i++){ //Gerando 64 números aleatorios de 1 a 15
    tabuaux[i]= 1 + (rand() % 15); //Gerando números aleatorios de 1 a 15 para o vetor auxiliar
  } //Fim FOR
  printf("\n"); //Pula linha
  //Gerando o tabuleiro com os números aleatorios gerados
  for(int i = 0; i < 4; i++){ //Percorre Linha
    for(int j = 0; j < 4; j++){ //Percorre Coluna
      do{
        if(testeVariavel(tabuaux[cont], tabu, i, j)==1){ //Verifica se o número não será repetido no tabuleiro que será jogado
          teste = 1; //Se o número puder ser inserido o teste será igual a 1 para sair ddo loop
          tabu[i][j] = tabuaux[cont]; //Insere o número já gerado no tabuleiro
        }else{ //Se o número que está na posição atual do vetor não puder ser inserido
          cont++; //Adiciona +1 na posição do vetor onde foi gerado os números
        } //Fim IF ELSE
      }while(teste != 1); //Roda o código até o número ser inserido 
      teste = 0; //Reinincia a variável teste
      cont ++; //Adiciona +1 na posição do vetor onde foi gerado os números
    } //Fim FOR coluna
  } //Fim FOR linha
  tabu[3][3]=0; //Colocando a posição zero no tabuleiro
  numero = 0;
  retornoFinal = 0; 
  //Verifica se a pessoa pressionou o número para saida OU se completou o tabuleiro
  while((numero != 16) && (retornoFinal != 1)){ //Se o número for diferente de 16 (que é o número para sair do jogo) ou diferente de 1 (que é verdadeiro para o tabuleiro completo) segue o jogo
    system("clear"); //limpa tela
    ImprimeTabuleiro(tabu); //imprime tabuleiro
    printf("\n Informe qual número deseja mover para o espaço vazio: ");
    scanf("%d", &numero); //Lê número a ser trocado de posição
    if((numero < 16) && (numero > 0)){ //O número deve estar entre 0 e 16
      posicao[0] = RetornaLinha(numero, tabu);  //Recebe a linha que se encontra o número
      posicao[1] = RetornaColuna(numero, tabu); //Recebe a coluna que se encontra o número
      if(PosicaoCorreta(numero, tabu, posicao) == true){ //Verifica se o número pode trocar de posição com o 00
      //Receber a posicao do 00 (vazio) no tabuleiro
        for(int i = 0; i < 4; i++){ //Roda linha
          for(int j = 0; j < 4; j++){ //Roda coluna
            if(tabu[i][j] == 0){ //Testa se a posição contem o número 0
              posicaozero[0] = i; //Recebe e salva linha
              posicaozero[1] = j; //Recebe e salva coluna
            } //Fim IF
          } //Fim FOR coluna
        } //Fim FOR linha
        auxiliar = tabu[posicao[0]][posicao[1]]; //Utiliza a variável auxiliar para guardar o número que será trocado
        tabu[posicao[0]][posicao[1]] = 0; //Insere o 00 (vazio) na posição antiga do número
        tabu[posicaozero[0]][posicaozero[1]] = auxiliar;  //Insere o número na posição antiga do 00 (vazio)
        pontos++; //Insere +1 na variável que armazena o número de jogadas que foram realizadas
      }else{ //Se o número não puder ser trocado com o 00
        printf("\n O número informado não pode trocar de casa com a posição 0\n\n");
        system("sleep 01"); //Delay de 1 segundo
      } //Fim IF ELSE
    }else{ //Se o número for maior que 15 ou menor que 1
      if(numero != 16){  //Se o número for diferente de 16 (que é o número para sair do jogo)
        printf("\n Número informado é incorreto, se deseja sair, por favor, digite o número 16 \n");
        system("sleep 01"); //Delay 1 segundo
      } //Fim IF
    } //Fim IF ELSE
    retornoFinal = testaFinalTabuleiro(tabu,tabucerto); //Verifica se o tabuleiro está completo
  } //Fim while
  printf("\n"); //Pula linha
  system("clear"); //Limpa tela
  if(retornoFinal == 1){ //Verificando se a pessoa saiu por ter ganhado
    SalvarResultado(pontos);
    printf("\n"); //Pula linha
    system("clear"); //Limpa tela
    printf("\n Salvando seus dados...");
    system("sleep 01"); //Delay 1 segundo
    printf("\n"); //`Pula linha
    system("clear"); //Limpa tela
  } //Fim IF
} //-------------------------------------------------- PRONTO

//Função Principal do Jogo (main)
int main(void) {
  CarregarJogo(); //Inicializando o JOGO com as Boas Vindas
  int opcao; //Variável criada para receber a opção escolhida pelo jogador
  do{
    ImprimeMenu(); //Imprime o Menu
    scanf("%d", &opcao); //Lê a opção
    switch(opcao){
      case 1: // Escolha JOGAR
        ComoJogar();  //Exibe as informações de como jogar
        Jogar(); //Inicia a função do MODO DE JOGO
        break; 
      case 2: // Escolha RANKING
        Ranking(); //Exibe o ranking
        break;
      case 3: // Escolha REGRAS
        Regras(); //Exibe as regras
        break;
      case 4: // Escolha SAIR
        SairDoJogo(); // Finalizando Jogo
        break;
      default: //Número fora do menu digitado
        printf("\n INFORME UMA OPÇÃO VÁLIDA \n");
        system("sleep 1"); //Delay de 1 segundo
        system("clear"); //Limpar a tela
    }
  }while(opcao != 4); //Se a opção escolhida for diferente de 4 o loop continuar para mostrar o MENU
  return 0; //Retorno padrão do main
} //Fim do programa