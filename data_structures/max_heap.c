#include <stdio.h>
#include <stdlib.h>
#define COMPRIMENTO 50

/* Em um heap, todos os níveis devem estar preenchidos, exceto provavelmente o último.
 * Um heap máximo é aquele em que para todo nó diferente da raiz, o seu pai é maior que ele.
 
 * A função MaxHeapify será usada quando se tiver um heap como entrada mas alguma sub-árvore foge às suas propriedades,
 * então a função é chamada e os nós são ajustados de forma que a chave do pai seja maior que a de seus filhos. E ocorre em tempo O(log(n)).
 
 * BuildHeap é responsável por construir um heap independente da entrada. Para cada sub-árvore até a raiz, é chamada a funcao MaxHeapify
 * para reestabelecer as propriedades de um heap máximo. Como a chamada é feita O(n) vezes e o tempo de execução de MaxHeapify é O(log(n)),
 * BuildHeap ocorre em tempo O(n(log(n))). Embora isso seja verdade, Percebe-se que o tempo de execução de MaxHeapify varia de acordo com 
 * a altura do nó na árvore, e na maiora das vezes, a altura dessas sub-árvores é mínima, o que implica que a operacao BuildHeap pode 
 * ocorrer em tempo linear (O(n)). (MaxHeapify não pode ser analisada dessa forma mais restrita em qualquer caso).
 
 * HeapSort é um algoritmo de ordenação que depende da construção do heap (BuildHeap) (O(n)) e da maximizacao a cada loop (MaxHeapify)
 * (O(log(n))) (Neste caso as sub-árvores podem não ter uma altura mínima). Logo, a operação HeapSort tem tempo O(n(log(n)). */


typedef struct{
	int chave[COMPRIMENTO],tam_heap;
}HeapInt;

void Inicializar(HeapInt *h);
void MaxHeapify(HeapInt *h,int indice);
void BuildHeap(HeapInt *h);
void PrintHeap(HeapInt *h);
void HeapSort(HeapInt *h);

int main(int argc,char **argv){
	HeapInt heap;
	int i,indice,opcao,tamanho;
	for(;;){
		printf("1 - initialize heap\n");
		printf("2 - max heap\n");
		printf("3 - build heap\n");
		printf("4 - heapsort\n");
		printf("5 - print heap\n");
		printf("0 - exit\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 0:
				exit(1);
			break;
			case 1:
				Inicializar(&heap);
			break;
			case 2:
				printf("Tamanho do heap: ");
				scanf("%d",&tamanho);
				if(heap.tam_heap == COMPRIMENTO || tamanho > (COMPRIMENTO - heap.tam_heap))
					printf("ERRO: Heap cheio\n");
				else{
					printf("Entre com o heap: ");
					for(i = 0;i < tamanho;i++){
						heap.tam_heap ++;
						scanf("%d",&heap.chave[i]);
					}
					printf("Entre com o indice de maximizacao: "); 
					scanf("%d",&indice);
					MaxHeapify(&heap,indice-1);
				}
			break;
			case 3:
				printf("Tamanho do heap: ");
				scanf("%d",&tamanho);
				if(heap.tam_heap == COMPRIMENTO || tamanho > (COMPRIMENTO - heap.tam_heap))
					printf("ERRO: Heap cheio\n");
				else{
					printf("Entre com o heap: ");
					for(i = 0;i < tamanho;i++){
						heap.tam_heap++;
						scanf("%d",&heap.chave[i]);
					}
					BuildHeap(&heap);
				}
			break;
			case 4:
				if(heap.tam_heap == COMPRIMENTO || tamanho > (COMPRIMENTO - heap.tam_heap))
					printf("ERRO: Heap cheio\n");
				else{
					printf("Entre com o heap: ");
					for(i = 0;i < tamanho;i++){
						heap.tam_heap++;
						scanf("%d",&heap.chave[i]);
					}
					BuildHeap(&heap);
				}
				HeapSort(&heap);
				for(i = 0;i < tamanho;i++)
					printf("%d ",heap.chave[i]);
				printf("\n");
			break;
			case 5:
				PrintHeap(&heap);
			break;
		}
	}
	return 0;
}

void MaxHeapify(HeapInt *h,int indice){
	int maior,aux,esq = ((2*indice) + 1),dir = ((2*indice) + 2);
	if((esq < h->tam_heap) && (h->chave[esq] > h->chave[indice]))
		maior = esq;
	else
		maior = indice;
	if((dir < h->tam_heap) && (h->chave[dir] > h->chave[maior]))
		maior = dir;
	if(indice != maior){
		aux = h->chave[indice];
		h->chave[indice] = h->chave[maior];
		h->chave[maior] = aux;
		MaxHeapify(h,maior);
	}
}

void Inicializar(HeapInt *h){
	h->tam_heap = 0;
}

void BuildHeap(HeapInt *h){
	int i;
	for(i = ((h->tam_heap)/2);i >= 0;i--)
		MaxHeapify(h,i);
}

void PrintHeap(HeapInt *h){
	int i;
	for(i = 0;i < h->tam_heap;i++)
		printf("%d ",h->chave[i]);
	printf("\n");
}

void HeapSort(HeapInt *h){
	int i,aux;
	BuildHeap(h);
	for(i = h->tam_heap - 1;i > 0;i--){
		aux = h->chave[i];
		h->chave[i] = h->chave[0];
		h->chave[0] = aux;
		h->tam_heap--;
		MaxHeapify(h,0);
	}
}