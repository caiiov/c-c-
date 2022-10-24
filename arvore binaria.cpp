/*	       ALGORITMO BASE DA ÁRVORE AVL			 */
/*        DISCIPLINA: ESTRUTURA DE DADOS         */
/*           ANO/SEMESTRE: 2022.1                */
/*  FUNÇÕES IMPLEMENTADAS: INSERÇÃO E PERCURSOS  */
/*   O QUE FALTA? REMOÇÃO, ALTURA E QUANTIDADE   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct no{
          int dado, bal;
          struct no *dir, *esq;};
          
int h;
          
void pre(struct no *r)
  {
  printf("%d ", r->dado);
  if(r->esq != NULL)
    pre(r->esq);
  if(r->dir != NULL)
    pre(r->dir);
  }
  
void sim(struct no *r)
  {
  if(r->esq != NULL)
    sim(r->esq);
  printf("%d ", r->dado);
  if(r->dir != NULL)
    sim(r->dir);
  }
  
void pos(struct no *r)
  {
  if(r->esq != NULL)
    pos(r->esq);
  if(r->dir != NULL)
    pos(r->dir);
  printf("%d ", r->dado);
  }    
  
struct no *caso1(struct no *r)
  {
  struct no *ptu, *ptv;
  ptu = r->esq;
  if(ptu->bal == -1)
    {
    r->esq = ptu->dir;
    ptu->dir = r;
    r->bal = 0;
    r=ptu;
    }
  else
    {
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    r->esq = ptv->dir;
    ptv->dir = r;
    if(ptv->bal == -1)
      r->bal = 1;
    else
      r->bal = 0;
    if(ptv->bal == 1)
      ptu->bal = -1;
    else
      ptu->bal = 0;
    r = ptv;
    }
  r->bal = 0;
  h = 1;
  return(r);
  }
  
struct no *caso2(struct no *r)
  {
  struct no *ptu, *ptv;
  ptu = r->dir;
  if(ptu->bal == 1)
    {
    r->dir = ptu->esq;
    ptu->esq = r;
    r->bal = 0;
    r=ptu;
    }
  else
    {
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    r->dir = ptv->esq;
    ptv->esq = r;
    if(ptv->bal == 1)
      r->bal = -1;
    else
      r->bal = 0;
    if(ptv->bal == -1)
      ptu->bal = 1;
    else
      ptu->bal = 0;
    r = ptv;
    }
  r->bal = 0;
  h = 1;
  return(r);
  }  
  
struct no *inserir(struct no *r, int n)
  {
  if(r == NULL)
    {
    r = (struct no *) malloc(sizeof(struct no));
    r->dado = n;
    r->esq = NULL;
    r->dir = NULL;
    r->bal = 0;
    h = 0;
    }
  else if(n == r->dado) 
    {
    printf("\nELEMENTO JA EXISTE\n");
    }
  else if(n < r->dado)
    {
    r->esq = inserir(r->esq,n);
    printf("\nEsquerdo - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
    if(h == 0)
      {
      switch(r->bal)
        {
        case 1: r->bal = 0;
                h = 1;
                break;
        case 0: r->bal = -1;
                break;
        case -1: r = caso1(r);
                break;
        }
      printf("\nEsquerdo - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
      }
    }
  else
    {
    r->dir = inserir(r->dir,n);
    printf("\nDireito - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
    if(h == 0)
      {
      switch(r->bal)
        {
        case -1: r->bal = 0;
                 h = 1;
                 break;
        case 0: r->bal = 1;
                break;
        case 1: r = caso2(r);
                break;
        }
      printf("\nDireito - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
      }    
    }
  return (r);
  }

struct no *remover(struct no *r, int n)
{
	if(r == NULL){
		printf("Valor nao encontrado!\n");
		return NULL;
	} else {
		//procura o nó a remover
		if(r->dado == n){
			//remove no folhas(nós sem filhos)
			if(r ->esq == NULL && r ->dir == NULL){
				free(r);
				printf("Elemento folha removido: %d !\n", n);
				return NULL;
			} 
			else{
				//remove nós que possuem 2 filhos
				if(r ->esq != NULL && r->dir != NULL){
					no *aux = r ->esq;
					while(aux ->dir != NULL){
						aux = aux ->dir;
					}
					r ->dado = aux ->dado;
					aux ->dado = n;
					r ->esq = remover(r ->esq, n);
					return r;
						
					
				}
				else{
					//remover nós que possuem 1 filho
					no *aux;
					if(r ->esq != NULL)
						aux = r ->esq;
					else
						aux = r ->dir;
					free(r);
					printf("Elemento com 1 filho removido: %d !\n", n);
					return aux;
				}
			}
		} else{
			if(n < r ->dado)
				r ->esq = remover(r -> esq, n);
			else
				r ->dir = remover(r ->dir, n);
			printf("\n Direito - Valor: %d - Balanceamento: %d - h: %d\n", r ->dado, r ->bal, h);
			if (h == 0){
				switch(r ->bal)
				{
				case -1: r ->bal =0;
				h = 1;
					break;
				case 0: r ->bal =1;
					break;
				case 1: r = caso2(r);
				     break;
				}
				printf("\nDireito - Valor: %d - Balanceamento: %d - h: %d\n", r ->dado, r ->bal, h);
			} else if(n > r ->dado)
			{
				r ->dir = remover(r ->dir, n);
				printf("\nEsquerdo - Valor: %d - Balanceamento: %d - h: %d\n", r ->dado, r ->bal, h);
				if(h == 0){
					switch(r ->bal)
					{
					case 1: r ->bal =0;
                        h = 1;
						break;
					case 0: r ->bal = -1;
						break;
					case -1: r = caso1(r);
					    break;
					}
					printf("\nEsquerdo - Valor: %d - Balanceamento: %d - h: %d\n", r ->dado, r ->bal, h);
				}
			}
			else
			     printf("\n Elemento nao encontrado \n");
			return r;
		}
	}
}

int altura(struct no *r)
{
    if(r == NULL){
        return -1;
    }
    else{
        int Esquerda = altura(r->esq);
        int Direita = altura(r->dir);
        if(Esquerda > Direita)
            return Esquerda + 1;
        else
            return Direita + 1;
    }
}

int quantidadeno(struct no *r)
{
 int qr;
 if(r!=NULL){	
 	 qr = quantidadeno(r->esq) + quantidadeno(r->dir);
	  return 1 + qr;
 	 
 }
 else{
 	return 0;
 	
 }
}

main()
  {
  struct no *raiz = NULL;
  int novo, opcao=0; //h=0 => V  h=1 => F
  while(opcao != 8)
    {
    printf("\nDigite a opcao:\n1- Inserir\n2- Remover\n3- Percurso em Pre Ordem\n4- Percurso em Ordem Simetrica\n5- Percurso em pos Ordem\n6- Altura da arvore\n7- Quantidade de elementos\n8- Sair\n");
    scanf("%d",&opcao);
    switch(opcao)
      {
      case 1: printf("\nQUAL O ELEMENTO A SER INSERIDO?\n");
              scanf("%d", &novo);
              raiz = inserir(raiz,novo);
              break;
      case 2: raiz = remover(raiz, 2);
              break;
      case 3: if(raiz == NULL)
                printf("\nARVORE NAO EXISTE!\n");
              else
                pre(raiz);
              break;
      case 4: if(raiz == NULL)
                printf("\nARVORE NAO EXISTE!\n");
              else
                sim(raiz);
              break;
      case 5: if(raiz == NULL)
                printf("\nARVORE NAO EXISTE!\n");
              else
                pos(raiz);
              break;
      case 6: altura(raiz);
        cout<<" A ALTURA E: "<<altura(raiz); 
        cout<<"\n\n";
      		  break;
      case 7: 
        cout<<" A quantidade de elementos e: "<<quantidadeno(raiz); 
        cout<<"\n\n";
              break;
      case 8: printf("\nSAIR\n");
              break;
      default: printf("\nOPCAO INVALIDA\n");
      }
    system("pause");
    system("cls");
	}
  }