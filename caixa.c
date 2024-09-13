#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#include <stdbool.h>


    void legendacaixa(){
        printf("\n");
        printf("  1. Inserir pessoa na fila do caixa");
        printf("\n  2. Remover primeiro da fila");
        printf("\n  3. Ver caixas ");
        printf("\n  4. Abrir caixa");
        printf("\n  5. Fechar caixa ");
        printf("\n  9. Mostrar fila de um determinado caixa ");
        printf("\n  0. Sair \n");
    }

    void inserirCaixa(struct listaCaixa *pCaixa, int numCaixa){
        Caixa *novo = malloc(sizeof(Caixa));
        novo->num_caixa = numCaixa;
        novo->prox = pCaixa->pirm;
        pCaixa->pirm = novo; 
    }

    void criaCaixas(struct listaCaixa *pCaixa, int qtdCaixas){
        pCaixa->pirm = NULL;

        for (int i = 0; i <= CX; i++){
            inserirCaixa(pCaixa, i);
        }
    }

    void abrirAll(struct listaCaixa *pCaixa){
        Caixa *abrir = pCaixa->pirm;

        while (abrir != NULL){
                abrir->abreto = 1;
                abrir->primFila = (struct ListaSimplesEnc*) malloc(sizeof(struct ListaSimplesEnc));
                criarLista(abrir->primFila);
            
                abrir = abrir->prox;   
        }
    }

    void abrircaixa(struct listaCaixa *pCaixa, int numCaixa){
        Caixa *abrir = pCaixa->pirm;

        while (abrir != NULL){
            if (abrir->num_caixa == numCaixa){
                abrir->abreto = 1;
                abrir->primFila = (struct ListaSimplesEnc*) malloc(sizeof(struct ListaSimplesEnc));
                criarLista(abrir->primFila);
                return;
            }else{
                abrir = abrir->prox;
            }   

        }
    }

    int verificaCaixaAberto(struct listaCaixa *pCaixa, int numCaixa){
        Caixa *p = pCaixa->pirm;

        while (p != NULL){
            if (p->num_caixa == numCaixa){
                if (p->abreto == 1)
                    return 1;
                else
                    return 0;
            }
            p = p->prox;
        }
    }

    void FilaCaixas(struct listaCaixa *pCaixa){
        Caixa *caixa = pCaixa->pirm;
        char situacao[10] = {" "};
        printf("\n");

        while (caixa != NULL){
            
            if (caixa->abreto == 1){
                struct Nodo *pFila = caixa->primFila->prim;
                if (pFila == NULL){
                   strcpy(situacao, "vazio"); 
                   printf("\n Caixa %d -> %s", caixa->num_caixa, situacao);
                }else{
                    printf("\n Caixa %d ->", caixa->num_caixa);
                    mostrarNomeFila(caixa->primFila);
                }
            }else{
                strcpy(situacao, "fechado");
                printf("\n Caixa %d -> %s", caixa->num_caixa, situacao);
            }
            
            caixa = caixa->prox;
        }
        printf("\n");
    }

    void inserirPessoaFila(struct listaCaixa *pCaixa, int numCaixa, char nome[20], long long cpf, int prioridade, int produtos){
        Caixa *caixa = pCaixa->pirm;
        
        if (verificaCaixaAberto(pCaixa, numCaixa) == 0){
            printf("\n Caixa fechado, escolha outro caixa");
            return;
        }else{

            while (caixa != NULL){
                if (caixa->num_caixa == numCaixa){
                    if (verificaCaixaAberto(pCaixa, numCaixa) == 1)
                        inserirPrioridade(caixa->primFila, nome, cpf, prioridade, produtos);
                    else
                        printf("\n Caixa fechado, escolha outro caixa");
                    return;
                }
                else
                    caixa = caixa->prox;
            }
        }
        
    }

    void mostrarFiladoCaixa(struct listaCaixa *pCaixa, int numCaixa){
        Caixa *caixa = pCaixa->pirm;
        
        while (caixa != NULL){
            if (caixa->num_caixa == numCaixa){
                if (verificaCaixaAberto(pCaixa, numCaixa) == 1){
                    printf("\n    -FILA DO CAIXA %d-", numCaixa);
                    mostrarLista(caixa->primFila);
                }else
                    printf("\n Caixa fechado, escolha outro caixa");
                return;
            }
            else
                caixa = caixa->prox;
        }
    }

    void RemoverPrimeiroCaixa(struct listaCaixa *pCaixa, int numCaixa){
        Caixa *caixa = pCaixa->pirm;
        struct Nodo *pFila = caixa->primFila->prim;
        
        while (caixa != NULL){
            if (caixa->num_caixa == numCaixa){
                if (verificaCaixaAberto(pCaixa, numCaixa) == 1){
                    if (pFila == NULL){
                        printf("\n Fila ja esta vaizia\n ");
                        return;
                    }
    
                    removerPrimeiro(caixa->primFila);
                }else
                    printf("\n Caixa fechado, escolha outro caixa");
                return;
            }
            else
                caixa = caixa->prox;
        }
    }


    void fecharCaixa(struct listaCaixa *pCaixa, int numCaixa) {
        Caixa *fechar = pCaixa->pirm;
        int vetCaixa[CX];
        int i = 0;
        int contadorPessoa = 0;
        int caixa = 0;

        while (fechar != NULL) {
            if (fechar->num_caixa != numCaixa && fechar->abreto == 1) {
                if (i < CX) {
                    vetCaixa[i++] = fechar->num_caixa;
                }
            }
            fechar = fechar->prox;
        }

        fechar = pCaixa->pirm;

        while (fechar != NULL) {
            if (fechar->num_caixa == numCaixa) {
                if (fechar->abreto == 0) {
                    printf("\n Caixa já está fechado\n");
                    return;
                }

                struct Nodo *pFila = fechar->primFila->prim;

                if (pFila == NULL) {
                    fechar->abreto = 0;
                    printf("\n Caixa %d Fechado\n", fechar->num_caixa);
                    return;
                }

                while (pFila != NULL) {
                    contadorPessoa++;
                    pFila = pFila->prox;
                }

                pFila = fechar->primFila->prim;

                if (i == 1) {
    
                    caixa = vetCaixa[0];
                    
                    while (pFila != NULL) {
                        struct Nodo pessoa;
                        pessoa.cpf = pFila->cpf;
                        strcpy(pessoa.nome, pFila->nome);
                        pessoa.prioridade = pFila->prioridade;
                        pessoa.produtos = pFila->produtos;
        
                        inserirPessoaFila(pCaixa, caixa, pessoa.nome, pessoa.cpf, pessoa.prioridade, pessoa.produtos);

                        pFila = pFila->prox;
                    }
                }else {
    
                    for (int j = 0; j < contadorPessoa && pFila != NULL; j++) {
                        struct Nodo pessoa;
                        pessoa.cpf = pFila->cpf;
                        strcpy(pessoa.nome, pFila->nome);
                        pessoa.prioridade = pFila->prioridade;
                        pessoa.produtos = pFila->produtos;

                        caixa = vetCaixa[j % i];
                        inserirPessoaFila(pCaixa, caixa, pessoa.nome, pessoa.cpf, pessoa.prioridade, pessoa.produtos);

                        pFila = pFila->prox;
                    }
                }

                esvaziarFila(fechar->primFila);

                fechar->abreto = 0;
                printf("\n Caixa %d Fechado\n", fechar->num_caixa);
                return;
            }

            fechar = fechar->prox;
        }

        printf("\n Caixa inexistente\n");
    }

    //Feito Por Hugo Henrique Marques - 1° Preriodo Eng. Comp CAEFET - MG
        //  (^-^)

