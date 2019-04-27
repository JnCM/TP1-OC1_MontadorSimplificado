#include <stdio.h>
#include <stdlib.h>
#include "PILHAdeBITS.h"//Inclusão do cabeçalho do Tipo Abstrato de Dados

void FPVazia(TipoPilha* Pilha){//Realiza a criação de uma pilha vazia
  Pilha->Topo = NULL;//Apontador do topo da pilha vai para NULL (sem bits adicionados)
  Pilha->iTamanho = 0;//Se a pilha é vazia, seu tamanho é 0
}

int PEhVazia(TipoPilha* Pilha){//Retorna 1 se a pilha for vazia ou 0 se não for
  return (Pilha->Topo == NULL);//Caso o topo apontar para NULL, a pilha é vazia, caso contrário, não é vazia
}

int Empilha(TipoPilha* Pilha, int NovoBit){//Adiciona um bit na pilha
  TipoApontador Aux;//Apontador auxiliar para receber a nova célula com o bit recebido
  Aux = (TipoApontador) malloc(sizeof(TipoCelula));//Alocando um espaço na memória para a nova célula a ser preenchida com o bit
  if (Aux == NULL){//Caso não haja memória suficiente:
    return 0;//Retorna 0 indicando que houve um erro
  }
  Aux->Bit = NovoBit;//Atribuíndo o bit convertido
  Aux->Prox = Pilha->Topo;//Mantendo a referência entre as células
  Pilha->Topo = Aux;//Atualizando o novo topo da pilha
  Pilha->iTamanho++;//Incrementando 1 no tamanho da pilha
  return 1;//Retornando 1 indicando que o empilhamento teve sucesso
}

int Desempilha(TipoPilha* Pilha, int *RecebeBit){//Remove o bit do topo da pilha
  TipoApontador Aux;//Apontador auxiliar para receber a célula a ser removida
  if (PEhVazia(Pilha)){//Caso a pilha for vazia:
    return 0;//Retorna 0 indicando que não há nada a ser removido
  }
  Aux = Pilha->Topo;//Apontador auxiliar aponta para o topo da pilha
  Pilha->Topo = Aux->Prox;//Atualiza o novo topo da pilha
  *RecebeBit = Aux->Bit;//Guardando o bit que será removido da pilha
  free(Aux);//Liberando espaço na memória ao remover a célula com o bit
  Pilha->iTamanho--;//Decrementando 1 no tamanho da pilha
  return 1;//Retornando 1 indicando que houve um desempilhamento
}

int RetornaTamanho(TipoPilha* Pilha){//Retorna o tamanho da pilha
  return (Pilha->iTamanho);//Retorna o tamanho atual da pilha
}
