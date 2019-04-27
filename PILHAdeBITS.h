#ifndef PILHAdeBITS_H_INCLUDED
#define PILHAdeBITS_H_INCLUDED

typedef struct TipoCelula* TipoApontador;//Renomeação do ponteiro para struct TipoCelula

typedef struct TipoCelula {//Struct de uma célula da pilha
  int Bit;//Bit convertido
  TipoApontador Prox;//Apontador para a próxima célula
} TipoCelula;

typedef struct {//Struct com os parâmetros de referência da pilha
  TipoApontador Topo;//Apontador para o topo da pilha
  int iTamanho;//Tamanho da pilha
} TipoPilha;

void FPVazia(TipoPilha* Pilha);//Realiza a criação de uma pilha vazia
int PEhVazia(TipoPilha* Pilha);//Retorna 1 se a pilha for vazia ou 0 se não for
int Empilha(TipoPilha* Pilha, int NovoBit);//Adiciona um bit na pilha
int Desempilha(TipoPilha* Pilha, int *RecebeBit);//Remove o bit do topo da pilha
int RetornaTamanho(TipoPilha* Pilha);//Retorna o tamanho da pilha
#endif
