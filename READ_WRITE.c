#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "READ_WRITE.h"//Inclusão do cabeçalho do Tipo Abstrato de Dados

char *RetornaValorReg(char *registrador){//Retorna qual o valor do registrador passado como parâmetro
  if(registrador[1] == 's'){//Verifica se o registrador é do tipo 's'
    if(registrador[2] == '0'){//Caso seja o registrador $s0:
      return "10000";//Retorna o valor 16 em binário
    }
    else if(registrador[2] == '1'){//Caso seja o registrador $s1:
      return "10001";//Retorna o valor 17 em binário
    }
    else if(registrador[2] == '2'){//Caso seja o registrador $s2:
      return "10010";//Retorna o valor 18 em binário
    }
    else if(registrador[2] == '3'){//Caso seja o registrador $s3:
      return "10011";//Retorna o valor 19 em binário
    }
    else if(registrador[2] == '4'){//Caso seja o registrador $s4:
      return "10100";//Retorna o valor 20 em binário
    }
    else if(registrador[2] == '5'){//Caso seja o registrador $s5:
      return "10101";//Retorna o valor 21 em binário
    }
    else if(registrador[2] == '6'){//Caso seja o registrador $s6:
      return "10110";//Retorna o valor 22 em binário
    }
    else if(registrador[2] == '7'){//Caso seja o registrador $s7:
      return "10111";//Retorna o valor 23 em binário
    }
  }
  else{//Caso o registrador seja do tipo 't'
    if(registrador[2] == '0'){//Caso seja o registrador $t0:
      return "01000";//Retorna o valor 8 em binário
    }
    else if(registrador[2] == '1'){//Caso seja o registrador $t1:
      return "01001";//Retorna o valor 9 em binário
    }
    else if(registrador[2] == '2'){//Caso seja o registrador $t2:
      return "01010";//Retorna o valor 10 em binário
    }
    else if(registrador[2] == '3'){//Caso seja o registrador $t3:
      return "01011";//Retorna o valor 11 em binário
    }
    else if(registrador[2] == '4'){//Caso seja o registrador $t4:
      return "01100";//Retorna o valor 12 em binário
    }
    else if(registrador[2] == '5'){//Caso seja o registrador $t5:
      return "01101";//Retorna o valor 13 em binário
    }
    else if(registrador[2] == '6'){//Caso seja o registrador $t6:
      return "01110";//Retorna o valor 14 em binário
    }
    else if(registrador[2] == '7'){//Caso seja o registrador $t7:
      return "01111";//Retorna o valor 15 em binário
    }
  }
}

char *RetornaValorFunct(char *instruction){//Retorna qual o valor do Funct da instrução do Tipo R passada como parâmetro
  if(strcmp(instruction,"add")==0){//Se a instrução for 'add':
    return "100000";//Retorna o funct 32 em binário
  }
  else if(strcmp(instruction,"sub")==0){//Se a instrução for 'sub':
    return "100010";//Retorna o funct 34 em binário
  }
  else if(strcmp(instruction,"and")==0){//Se a instrução for 'and':
    return "100100";//Retorna o funct 36 em binário
  }
  else if(strcmp(instruction,"or")==0){//Se a instrução for 'or':
    return "100101";//Retorna o funct 37 em binário
  }
  else if(strcmp(instruction,"nor")==0){//Se a instrução for 'nor':
    return "100111";//Retorna o funct 39 em binário
  }
}

char *RetornaOpCode(char *inst){//Retorna qual o OpCode da instrução do Tipo I passada como parâmetro
  if(strcmp(inst,"addi")==0){//Se a instrução for 'addi':
    return "001000";//Retorna o OpCode 8 em binário
  }
  else if(strcmp(inst,"andi")==0){//Se a instrução for 'andi':
    return "001100";//Retorna o OpCode 12 em binário
  }
  else if(strcmp(inst,"ori")==0){//Se a instrução for 'ori':
    return "001101";//Retorna o OpCode 13 em binário
  }
  else if(strcmp(inst,"sll")==0){//Se a instrução for 'sll':
    return "000000";//Retorna o OpCode 0 em binário
  }
  else if(strcmp(inst,"srl")==0){//Se a instrução for 'srl':
    return "000010";//Retorna o OpCode 2 em binário
  }
}

int *ComplementoDeDois(int *VetorAConverter, int *Vetor1BIN){//Retorna o vetor em binário convertido para complemento de dois
  int i, VaiUm = 0;//Váriaveis para funcionamento do procedimento
  for(i=0; i<16; i++){//Invertendo bit a bit
    if(VetorAConverter[i] == 0){//Se o bit for 0:
      VetorAConverter[i] = 1;//Passa a ser 1
    }
    else if(VetorAConverter[i] == 1){//Se o bit for 1:
      VetorAConverter[i] = 0;//Passa a ser 0
    }
  }
  for(i=15; i>=0; i--){//Somando 1 no número em binário invertido
    if(Vetor1BIN[i] == 1 && VetorAConverter[i] == 0){// 1+0 = 1
      VetorAConverter[i] = 1;//Resultado 1
      VaiUm = 0;//Sem vai um
    }
    else if(Vetor1BIN[i] == 1 && VetorAConverter[i] == 1){// 1+1 = 0
      VetorAConverter[i] = 0;//Resultado 0
      VaiUm = 1;//Vai um para a próxima soma
    }
    if(VaiUm == 1 && i<15){//Caso o Vai um seja 1 e não seja a primeira soma:
      VetorAConverter[i] ++;//Soma 1 no bit da posição i
      VaiUm = 0;//Vai um retorna como 0
    }
    if(VetorAConverter[i] >= 2){//Caso a soma no bit passe de um, ou seja, a soma realizada seja 1+1:
      VetorAConverter[i] = 0;//Bit na posição i fica como 0 (resultado da soma 1+1)
      VaiUm = 1;//Vai um para a próxima soma
    }
  }
  return VetorAConverter;//Retorna o vetor final convertido em complemento de dois
}

int *ConverteBinario(int num){//Converte o número passado como parâmetro em binário
  int i, *VetorBinario;//Vetor que guardará o número convertido em binário
  TipoPilha pilha;//Estrutura de dados que guardará cada bit convertido
  FPVazia(&pilha);//Cria uma pilha de bits vazia
  VetorBinario = (int *)calloc(16,sizeof(int));//inicializa o vetor com 0 em todas as suas posições
  if(num >= 0){//Caso o número seja maior ou igual a 0, a conversão é realizada
    while(num >= 2){//Condição de parada: o número ser menor que 2, (divisão inteira não ser possível)
      Empilha(&pilha, num%2);//Guarda o resto da divisão do número por 2
      num = num/2;//Atualiza o número realizando a divisão por 2
      if(num < 2){//Se o número é menor que 2 (final das divisões inteiras)
        Empilha(&pilha, num);//Guarda o último bit convertido
      }
    }//Fim while
    for(i=16-RetornaTamanho(&pilha); i<16; i++){//Transfere os bits na ordem correta da pilha de bits para o vetor
      Desempilha(&pilha, &VetorBinario[i]);//Desempilhando bit a bit
    }
    return VetorBinario;//Retorna o vetor em binário do número convertido
  }
  else{//Caso o número seja menor que 0, a conversão para binário utilizará complemento de dois
    int Vetor1[16];//Vetor contendo o número 1 em binário
    num = num*(-1);//Retirando o sinal negativo do número a ser convertido
    for(i=0; i<16; i++){//Preenchendo o vetor com 1 em binário
      if(i==15){//Se for a última posição do vetor:
        Vetor1[i] = 1;//Bit 1 para essa posição
      }
      else{//Se for qualquer outra posição:
        Vetor1[i] = 0;//Bit 0 para essa posição
      }
    }//Fim for
    if(num == 1){//Se o número a ser convertido for (-1):
      for(i=0; i<16; i++){//Basta preencher o vetor final com o vetor com 1 em binário
        VetorBinario[i] = Vetor1[i];//Realizando a atribuição
      }//Fim for
    }
    else{//Se for qualquer outro número diferente de -1:
      while(num >= 2){//Realiza a conversão desse número sem o sinal da mesma forma de um número positivo
        Empilha(&pilha, num%2);//Guarda o resto da divisão do número por 2
        num = num/2;//Atualiza o número realizando a divisão por 2
        if(num < 2){//Se o número é menor que 2 (final das divisões inteiras)
          Empilha(&pilha, num);//Guarda o último bit convertido
        }
      }//Fim while
      for(i=16-RetornaTamanho(&pilha); i<16; i++){//Transfere os bits na ordem correta da pilha de bits para o vetor
        Desempilha(&pilha, &VetorBinario[i]);//Desempilhando bit a bit
      }//Fim for
    }
    return ComplementoDeDois(VetorBinario, Vetor1);//Retorna o número em binário convertido em complemento de dois
  }
}

int LeituraEscrita(){//Realiza a leitura do arquivo de entrada e cria o arquivo de saída com a conversão realizada
  FILE *ArquivoEntrada, *ArquivoSaida;
  char temp[4], instrucao[5], reg1[4], reg2[4], reg3[4];
  char opCode[7], regBIN1[6], regBIN2[6], regBIN3[6];
  char NomeArq[12];
  printf("Digite o nome do arquivo em linguagem Assembly:\nNota: Nome do arquivo deve ser da forma = entrada.asm\n");
  scanf("%s", NomeArq);
  ArquivoEntrada = fopen(NomeArq,"r");
  ArquivoSaida = fopen("saida.txt","w");
  if(ArquivoEntrada == NULL){
    printf("Houve um erro na abertura desse arquivo!\n");
    return 1;
  }
  else{
    printf("Arquivo Aberto com Sucesso!\n");
  }
  while(!feof(ArquivoEntrada)){
    fscanf(ArquivoEntrada, "%s", instrucao);
    if(strcmp(instrucao,"add")==0 || strcmp(instrucao,"sub")==0 || strcmp(instrucao,"and")==0 || strcmp(instrucao,"or")==0 || strcmp(instrucao,"nor")==0){
      strcpy(opCode, "000000");
      fscanf(ArquivoEntrada, "%s", temp);
      if(temp[3] == ','){
        temp[3] = '\0';
      }
      strcpy(reg1, temp);
      strcpy(regBIN1, RetornaValorReg(reg1));
      fscanf(ArquivoEntrada, "%s", temp);
      if(temp[3] == ','){
        temp[3] = '\0';
      }
      strcpy(reg2, temp);
      strcpy(regBIN2, RetornaValorReg(reg2));
      fscanf(ArquivoEntrada, "%s", temp);
      //if(temp[3] == ','){
      temp[3] = '\0';
      //}
      strcpy(reg3, temp);
      strcpy(regBIN3, RetornaValorReg(reg3));
      fprintf(ArquivoSaida,"%s%s%s%s%s%s\n", opCode, regBIN2, regBIN3, regBIN1, "00000", RetornaValorFunct(instrucao));
    }
    else{
      int num, *Constante, i;
      Constante = (int *)malloc(16*sizeof(int));
      strcpy(opCode, RetornaOpCode(instrucao));
      fscanf(ArquivoEntrada, "%s", temp);
      if(temp[3] == ','){
        temp[3] = '\0';
      }
      strcpy(reg1, temp);
      strcpy(regBIN1, RetornaValorReg(reg1));
      fscanf(ArquivoEntrada, "%s", temp);
      if(temp[3] == ','){
        temp[3] = '\0';
      }
      strcpy(reg2, temp);
      strcpy(regBIN2, RetornaValorReg(reg2));
      fscanf(ArquivoEntrada, "%d", &num);
      Constante = ConverteBinario(num);
      //Chamar função que converte numero para binário
      fprintf(ArquivoSaida,"%s%s%s", opCode, regBIN2, regBIN1);
      for(i=0; i<16; i++){
        fprintf(ArquivoSaida,"%d", Constante[i]);
      }
      fprintf(ArquivoSaida,"\n");
    }
  }
  fclose(ArquivoEntrada);
  fclose(ArquivoSaida);
  printf("Conversao realizada com sucesso!\nNovo arquivo: saida.txt\n");
  return 0;
}
