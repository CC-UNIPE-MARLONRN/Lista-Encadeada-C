#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
} Lista;

Lista *lista_cria() { return NULL; };
Lista *lista_insere(Lista *l, int i);
Lista *lista_retira(Lista *l, int elemento);
void lista_imprime(Lista *l);
int lista_vazia(Lista *l);
int lista_busca(Lista *l, int v);
void lista_libera(Lista *l);
void limpa_tela();

int lista_busca(Lista *l, int v) {
  Lista *p;

  for (p = l; p != NULL; p = p->prox) {
    if (p->info == v) {
      return p->info;
    }
  }
  return -1;
}

Lista *lista_insere(Lista *l, int i) {
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

Lista *lista_retira(Lista *l, int elemento) {
  Lista *lista_ant = NULL;
  Lista *li_atual = l;
  while (li_atual != NULL && li_atual->info != elemento) {
    lista_ant = li_atual;
    li_atual = li_atual->prox;
  }
  if (li_atual == NULL) {
    return l;
  }
  if (lista_ant == NULL) {
    l = li_atual->prox;
  } else {
    lista_ant->prox = li_atual->prox;
  }
  free(li_atual);
  return l;
}

void lista_imprime(Lista *l) {
  Lista *p;
  printf("LISTA: [ ");
  for (p = l; p != NULL; p = p->prox) {
    printf("%d, ", p->info);
  }
  printf("\b\b ]\n");
}

int lista_vazia(Lista *l) { return l == NULL; }

int main(void) {
  int opcao, valor, retorno;
  Lista *lista;
  lista = lista_cria();
  do {
    printf("\n");
    printf("1 - Inserir Elemento\n");
    printf("2 - Remover Elemento\n");
    printf("3 - Buscar Elemento\n");
    printf("4 - Imprimir Lista\n");
    printf("5 - Sair\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);

    if (opcao == 1) {
      printf("\nDigite o valor a ser inserido:");
      scanf("%d", &valor);
      lista = lista_insere(lista, valor);
      if(lista != NULL){
        printf("\nValor inserido com sucesso!\n");
      }
    }

    if (opcao == 2) {
      if (lista == lista_cria()) {
        printf("\nLista vazia\n");
      } else {
        printf("\nDigite o valor a ser removido:");
        scanf("%d", &valor);
        lista = lista_retira(lista, valor);
        if (lista == NULL)
          printf("\nValor %d removido\n", valor);
        if (lista != NULL)
          printf("\nValor %d não encontrado\n", valor);
      }
    }

    if (opcao == 3) {
      int i;
      printf("\nDigite o valor a ser buscado: ");
      scanf("%d", &i);
      int busca = lista_busca(lista, i);
      if (busca != -1) {
        printf("\nElemento encontrado: %d \n", busca);
      } else {
        printf("\nElemento não encontrado \n");
      }
    }

    if (opcao == 4) {
      if (lista == lista_cria()) {
        printf("\nLista vazia\n");
      } else {
        printf("\n");
        lista_imprime(lista);
      }
    }

    if (opcao < 1 || opcao > 5)
      printf("\nOpção inválida\n");

  } while (opcao != 5);
  if (opcao == 5)
    printf("\nSaindo...");

  return 0;
}