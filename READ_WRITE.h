#ifndef READ_WRITE_H_INCLUDED
#define READ_WRITE_H_INCLUDED

#include "PILHAdeBITS.h"//Inclusão do Tipo Abstrato de Dados que recebe o número convertido em binário

char *RetornaValorReg(char *registrador);//Retorna qual o valor do registrador passado como parâmetro
char *RetornaValorFunct(char *instruction);//Retorna qual o valor do Funct da instrução do Tipo R passada como parâmetro
char *RetornaOpCode(char *inst);//Retorna qual o OpCode da instrução do Tipo I passada como parâmetro
int *ComplementoDeDois(int *VetorAConverter, int *Vetor1BIN);//Retorna o vetor em binário convertido para complemento de dois
int *ConverteBinario(int num);//Converte o número passado como parâmetro em binário
int LeituraEscrita();//Realiza a leitura do arquivo de entrada e cria o arquivo de saída com a conversão realizada
#endif
