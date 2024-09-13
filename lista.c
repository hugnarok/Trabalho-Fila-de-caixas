#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#include <stdbool.h>

    void legenda(){
        printf("\n\n 1. inserir pessoa na lista");
        printf("\n 2. Imprimir lista");
        printf("\n 3. Opções de caixa");
        printf("\n 0. Sair");
        printf("\n\n");
    }

    void criarLista(struct ListaSimplesEnc *pList){
        pList->prim = NULL;
    }


    void mostrarLista(struct ListaSimplesEnc *pList){
    
        struct Nodo *p;

        printf("\n-------------Fila-------------");
        for (p = pList->prim; p != NULL; p = p->prox)
        {
            printf("\n Nome: %s", p->nome);
            printf("\n Cpf: %lld\n", p->cpf);
            printf("\n Prioridade: %d", p->prioridade);
            printf("\n Produtos: %d\n", p->produtos);
            printf("_________________________\n");
        }
        printf("_________________________\n");
    }

    void mostrarNomeFila(struct ListaSimplesEnc *pList) {
        struct Nodo *p;
        for (p = pList->prim; p != NULL; p = p->prox) {
            printf("  %s ->", p->nome);
        }
        printf(" NULL");
    }

    void inserirPrioridade(struct ListaSimplesEnc *pList, char nome[20], long long cpf, int prioridade, int produtos){
        struct Nodo *priorit;
        struct Nodo *aux = pList->prim;
        priorit = malloc(sizeof(nodo));

        strcpy(priorit->nome, nome);
        priorit->cpf = cpf;
        priorit->prioridade = prioridade;
        priorit->produtos = produtos;

        if (pList->prim == NULL){
            priorit->prox = pList->prim;
            pList->prim = priorit;
        }else if(prioridade == 1){
            if (pList->prim->prioridade != 1){
                priorit->prox = pList->prim;
                pList->prim = priorit;
            }else{
                while (aux->prox && aux->prox->prioridade == 1){
                    aux = aux->prox;
                }
                priorit->prox = aux->prox;
                aux->prox = priorit; 
            }
        }else if(prioridade == 2){
            if (pList->prim->prioridade > 2){
                priorit->prox = pList->prim;
                pList->prim = priorit;
            }else{
                while (aux->prox && aux->prox->prioridade == 1){
                    aux = aux->prox;
                }
                
                while (aux->prox && aux->prox->prioridade == 2){
                    aux = aux->prox;
                }
                priorit->prox = aux->prox;
                aux->prox = priorit;   
            }
        }else{
            while (aux->prox){
                aux = aux->prox;
            }
            aux->prox = priorit;
        }
        
    }

void esvaziarFila(struct ListaSimplesEnc *pList) {
    struct Nodo *pFila, *pAux;

    pFila = pList->prim;

    while (pFila != NULL) {
        pAux = pFila->prox;
        free(pFila);
        pFila = pAux;
    }

    pList->prim = NULL;
}

void removerPrimeiro(struct ListaSimplesEnc *pList){
    struct Nodo *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
}

    //Feito Por Hugo Henrique Marques - 1° Preriodo Eng. Comp CAEFET - MG
        //  (^-^)