//ESTRUTURA TIPO ÁRVORE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//Criando o nodo(registro) que pertencerá a minha árvore
typedef struct nodo{
	struct nodo *esquerda;
	int numero;
	struct nodo *direita;
}Nodo;


//Criando um ponteiro que aponta para minha árvore
typedef struct{
	Nodo *raiz;
}Arvore;


//Criando a árvore, o subprograma abaixo retornará um ponteiro tree que aponta para a árvore campo raiz, apontando para NULL(vazio/nulo)
Arvore * criando(){
	Arvore *tree = (Arvore *)malloc(sizeof(Arvore));
	tree -> raiz = NULL;
	return tree;
}

//Criando um ponteiro que aponta exclusivamente para um nodo (será útil para soluções recursivas);
Nodo *criando_ponteiro(){
	Nodo *ponteiro_nodo = (Nodo *)malloc(sizeof(Nodo));
	return ponteiro_nodo;
}


//Inserindo um novo numero (nodo) a minha arvore
void inserindo (Arvore *tree, int num){
	//num = numero informado pelo usuário
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	novo -> numero = num;
	novo -> esquerda = NULL;
	novo -> direita = NULL;
	Nodo *aux = tree -> raiz;
	if (tree -> raiz == NULL){
		tree -> raiz = novo;
	}
	else{
		while (aux -> esquerda != novo && aux ->direita != novo){
			if (aux -> esquerda != novo || aux ->direita != novo){
				if (num > aux -> numero){
					if (aux -> direita == NULL){
						aux -> direita = novo;
					}
					else{
						aux = aux -> direita;
					}
				}
				else{
					if (aux -> esquerda == NULL){
						aux -> esquerda = novo;
					}
					else{
						aux = aux -> esquerda;
					}
				}
			}
			else{
				if (num > aux -> numero){
					aux -> direita = novo;
				}
				else{
					aux -> esquerda = novo;
				}
			}
		}
	}
}


//Subprograma que localiza um numero na árvore
int localizar_numero (Arvore * tree, int num){
	Nodo *aux = tree -> raiz;
	while (aux != NULL){
		if (aux -> numero == num){
			return 1;
		}
		else if (num > aux -> numero){
			aux = aux -> direita;
		}
		else{
			aux = aux -> esquerda;
		}
	}
	return 0;
}


//Subprograma recursivo que identifica o maior numero da árvore
int maior_numero(Nodo *ponteiro_nodo){
	if (ponteiro_nodo == NULL){
		return 0;
	}
	if (ponteiro_nodo -> direita == NULL){
		return ponteiro_nodo -> numero;
	}
	return maior_numero(ponteiro_nodo = ponteiro_nodo -> direita);
}


//Subprograma recursivo que identiica o menor numero da árvore
int menor_numero(Nodo *ponteiro_nodo){
	if (ponteiro_nodo == NULL){
		return 0;
	}
	if (ponteiro_nodo -> esquerda == NULL){
		return ponteiro_nodo -> numero;
	}
	return maior_numero(ponteiro_nodo = ponteiro_nodo -> esquerda);
}


//    MAIN    //
void main(){
	int numero;
	char fazer, continuar = 's';
	
	//Criando minha árvore
	Arvore *tree = criando();
	
	//Criando um ponteiro que aponta para um nodo para realizar a chamada recursiva
	Nodo *ponteiro_nodo = criando_ponteiro();
	
	//Saber se o usuário deseja realizar mais alguma operação
	while (continuar == 's'){
		//Menu que informa as operações disponíveis para o usuário
		printf ("Informe a operacao: \n\n");
		
		printf ("Adiconar numero(a)\n");
		printf ("Encontrar numero (e)\n");
		printf ("Ver maior numero: (m)\n");
		printf ("Ver menor numero: (n)\n");
		scanf ("%c", &fazer);
		fflush(stdin);
		
		switch(fazer){
			case 'a':
			case 'A':
					printf ("Informe o numero que sera adicionado: \n");
					scanf ("%d", &numero);
					fflush(stdin);
					inserindo(tree, numero);
						break;
					
			case 'e':
			case 'E': 
					printf ("Informe o valor que dejesa encontrar: \n");
					scanf ("%d", &numero);  
					fflush(stdin);
					
					int valor = localizar_numero(tree, numero);
					if (valor == 1){
						printf ("Pertence a arvore\n");
					}
					else{
						printf ("Nao pertence a arvore\n");
					}
						break;
						
			case 'm':
			case 'M':
					ponteiro_nodo = tree -> raiz;
					int maior_valor = maior_numero(ponteiro_nodo);
					printf ("O maior numero da arvore eh %d\n", maior_valor);
						break;
			
			case 'n':
			case 'N':
					ponteiro_nodo = tree -> raiz;
					int menor_valor = menor_numero(ponteiro_nodo);
					printf ("O menor numero da arvore eh %d\n", menor_valor);
						break;
					
			default: ;
		}
		printf ("Deseja realizar algo mais?: Sim (s); Nao (n):\n");
		scanf ("%c", &continuar);
		fflush(stdin);	
	}
	getch();
}
