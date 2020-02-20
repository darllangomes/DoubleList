#include<stdio.h>
#include<stdlib.h>


typedef struct reg {
   int         conteudo;
   struct reg* prox;
   struct reg* ant;
} celula;

celula* iniciaLista(){
	celula* lista=(celula*)malloc(sizeof(celula));
	return lista;
}

celula* insereLista(celula* lista, int valor){
  celula* novo=iniciaLista();
  celula* aux=lista;
  novo->conteudo=valor;
	if(lista==NULL){
		lista=novo;
    novo->prox=NULL;
    novo->ant=NULL;
    return novo;
	}else{
    lista->prox=insereLista(lista->prox, valor);
    lista->prox->ant=lista;
    return lista;
	}
	return lista;
}

void imprimeLista(celula* lista){
	celula* novo= lista;
	
	while(novo!=NULL){
		printf("%i ",novo->conteudo);
		novo=novo->prox;
	}
}

void imprimir2(celula* atual)
{
  if(atual != NULL)
  {
    imprimir2(atual->prox);
    printf("%i ", atual->conteudo);
  }
}

celula* remover(celula* lista, int valor){
  if(lista==NULL){
    return NULL;
  }

  if(lista->conteudo==valor){
    celula* aux=lista->prox;
    free(lista);
    return aux;
  }else{
    lista->prox=remover(lista->prox, valor);
    lista->prox->ant=lista;
    return lista;
  }
}



 int main(){
	celula* lista;
	
	lista=insereLista(lista,9);
	lista=insereLista(lista,1);
	lista=insereLista(lista,8);
  lista=insereLista(lista,47);
	
  printf("Lista normal \n");
	imprimeLista(lista);
  printf("\n");
  printf("Lista inversa\n ");
  imprimir2(lista);

  remover(lista,1);

  printf("\ndepois de remover\n");
  imprimeLista(lista);
}