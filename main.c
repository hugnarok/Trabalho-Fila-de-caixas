#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include <string.h>

int main()
{
    struct listaCaixa listaDeCaixa;
    criaCaixas(&listaDeCaixa, CX);
    abrirAll(&listaDeCaixa);

    int opcao = 1;
    char nome[TAM] = {" "};
    long long cpf = 0;
    int prioridade = 0;
    int produtos = 0;
    int numCaixa = 0;

    while (opcao != 0){
        legendacaixa();
        printf("\n Digite a opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao){

            case 4:
                numCaixa = 0;
                printf("\n Qual caixa deseja abrir: ");
                scanf("%d", &numCaixa);
                getchar();

                abrircaixa(&listaDeCaixa, numCaixa);
                break;
            
            case 1: 
                numCaixa = 0;
                printf("\n -Inserir pessoa na fila do caixa: ");
                scanf("%d", &numCaixa);
                getchar();
                
                if (verificaCaixaAberto(&listaDeCaixa, numCaixa) == 0){
                    printf("\n Caixa fechado, escolha outro caixa\n");
                    break;
                }else{
                    printf("\n Digite o nome de cadastro do Cliente: ");
                    fgets(nome, TAM, stdin);
                    nome[strlen(nome) - 1] = '\0';
                    printf("\n Digite o CPF do cliente: ");
                    scanf("%lld" , &cpf);
                    getchar();
                    printf("\n Digite a prioridade: [1. Alta] [2. Media] [3. Baixa]:  ");
                    scanf("%d", &prioridade);
                    getchar();
                    printf("\n Digite a quantidade de produtos no carrinho do cliente: ");
                    scanf("%d", &produtos);

                    inserirPessoaFila(&listaDeCaixa, numCaixa, nome, cpf, prioridade, produtos);
                }
                break;

            case 3: 
                FilaCaixas(&listaDeCaixa);
                break;

            case 5: 
                numCaixa = 0;
                printf("\n Qaul caixa quer fechar: ");
                scanf("%d", &numCaixa);
                getchar();

                if (verificaCaixaAberto(&listaDeCaixa, numCaixa) == 0){
                    printf("\n Caixa fechado, escolha outro caixa\n");
                    break;
                }else{
                    fecharCaixa(&listaDeCaixa , numCaixa);
                }
                
                break;

            case 2:
                numCaixa = 0;
                printf("\n De qual caixa quer remover: ");
                scanf("%d", &numCaixa);
                getchar();

                if (verificaCaixaAberto(&listaDeCaixa, numCaixa) == 0){
                    printf("\n Caixa fechado, escolha outro caixa\n");
                    break;
                }else{
                    RemoverPrimeiroCaixa(&listaDeCaixa , numCaixa);
                    printf("\n Primerio removido \n");
                }
                break;

            case 0:
                printf("\n Programa Encerrado\n");
                break;

            case 9:
                numCaixa = 0;
                printf("\n Qaul caixa quer verifiacar a Fila: ");
                scanf("%d", &numCaixa);
                getchar();

                if (verificaCaixaAberto(&listaDeCaixa, numCaixa) == 0){
                    printf("\n Caixa fechado, escolha outro caixa\n");
                    break;
                }else{
                    mostrarFiladoCaixa(&listaDeCaixa , numCaixa);
                }
                
                break;
                break;

            default:
                printf("\n Opção invalida");
                break;
        }

    }
    
    return 0;
}

    //Feito Por Hugo Henrique Marques - 1° Preriodo Eng. Comp CAEFET - MG
        //  (^-^)
