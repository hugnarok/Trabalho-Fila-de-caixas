//gcc caixa.c lista.c lista.h main.c -o apt -lm

#ifndef LISTA_H
#define LISTA_H
#define TAM 100
#define CX 3

    typedef struct Nodo {
        char nome[TAM];
        long long cpf;
        int prioridade;
        int produtos;
        struct Nodo *prox;
    
    }nodo;

    typedef struct caixa{
        int num_caixa;
        int abreto;//[1 - aberto / 0 - fechado]
        struct ListaSimplesEnc *primFila;
        struct caixa *prox;
    }Caixa;
    
    struct listaCaixa{
        Caixa *pirm;
    };
    

    struct ListaSimplesEnc {
        struct Nodo *prim;
    };



    void legenda();
    void criarLista(struct ListaSimplesEnc *pList);
    void mostrarLista(struct ListaSimplesEnc *pList);
    void inserirPrioridade(struct ListaSimplesEnc *pList, char nome[20], long long cpf, int prioridade, int produtos);
    void esvaziarFila(struct ListaSimplesEnc *pList);
    void mostrarNomeFila(struct ListaSimplesEnc *pList);
    void removerPrimeiro(struct ListaSimplesEnc *pList);

    //caixas.c
    void criaCaixas(struct listaCaixa *pCaixas, int qtdCaixas);
    int verificaCaixaAberto(struct listaCaixa *pCaixa, int numCaixa);
    void inserirCaixa(struct listaCaixa *pCaixa, int numCaixa);
    void abrircaixa(struct listaCaixa *pCaixa, int numCaixa);
    void abrirAll(struct listaCaixa *pCaixa);
    void legendacaixa();
    void inserirPessoaFila(struct listaCaixa *pCaixa, int numCaixa, char nome[20], long long cpf, int prioridade, int produtos);
    void mostrarFiladoCaixa(struct listaCaixa *pCaixa, int numCaixa);
    void fecharCaixa(struct listaCaixa *pCaixa, int numCaixa);
    void FilaCaixas(struct listaCaixa *pCaixa);
    void RemoverPrimeiroCaixa(struct listaCaixa *pCaixa, int numCaixa);
#endif

    //Feito Por Hugo Henrique Marques - 1° Preriodo Eng. Comp CAEFET - MG
        //  (^-^)