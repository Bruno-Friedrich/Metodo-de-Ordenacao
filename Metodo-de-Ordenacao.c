//Bibliotecas utilizadas:
#include <stdio.h>
#include <stdlib.h> //Necessário para a utilização das funções rand, srand e malloc.
#include <time.h>   //Necessário para a utilização da função time
#include <locale.h> //Necessário para utilizar a pontução de forma correta
//#include <windows.h>//Adiciona ferramentas do windows
#include <time.h>



void PassarValor (int Arranjo[], int NumeroElementos)
{
    printf ("Digite os valores que deseja adicionar separados por um espaço: ");
    for (int i = 0; i < NumeroElementos; i++)
    {
        scanf ("  %i", &Arranjo[i]);
    }
}


void GerarValor (int Arranjo[], int NumeroElementos)
{
    printf ("Será gerado uma sequência com %i elementos.\n", NumeroElementos);
    srand (time(NULL));
    for (int i = 0; i < NumeroElementos; i++)
    {
        Arranjo[i] = rand();
    }
}


void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}


int partition(int* Arranjo, int tamanho) {
    int pivo = Arranjo[tamanho-1];
    int i = -1;
    int j;
    
    for(j = 0; j < tamanho-1; j++)
    if(Arranjo[j] <= pivo)
    troca(&Arranjo[++i], &Arranjo[j]);
    troca(&Arranjo[i+1], &Arranjo[j]);

  return i + 1;
}

void quicksort(int* Arranjo, int tamanho) {
  int q;
  if (tamanho > 0) {
    q = partition(Arranjo, tamanho);

    quicksort(Arranjo, q);
    quicksort(&Arranjo[q+1], tamanho - (q + 1));
  }
}

//Ordena (int Arranjo[], int NumeroElementos)
int main()
{
    //SetConsoleTitle("Selecao1"); // Define o nome do processo
    setlocale(LC_ALL, "Portuguese");

    int NumeroElementos = 0; //Quantidade de elementos na sequencia
    int indice = 0;
    char resposta;           //Variavel utilizada para receber resposta do usuario
    double tempo_gasto = 0.0000;
    printf("Esse programa visa resolver o problema da seleção!\n");
    printf ("Primeiramente, você deseja uma sequência com quantos elementos? ");
    scanf (" %i", &NumeroElementos);

    int *A = (int *) malloc(NumeroElementos*sizeof(int)); //Cria um arranjo de tamanho igual a quantidade NumeroElementos

    printf ("Digite o n-ésimo menor número da sequência que deseja: ");
    scanf (" %i", &indice);

    printf ("Além disso, você deseja passar os valores da sequência ou gerar valores de forma aleatória?\n");
    printf ("P - Passar os valores.\n");
    printf ("G - Gerar aleatoriamente.\n");
    do
    {
        scanf (" %c", &resposta);
    }while (resposta != 'P' && resposta != 'G');

    //Switch necessário para popular o arranjo A
    switch (resposta)
    {
        case 'P': PassarValor (A, NumeroElementos);
        break;

        case 'G': GerarValor (A, NumeroElementos);
        break;
    }
    clock_t begin = clock();
    quicksort(A, NumeroElementos);
    printf ("%i\n", A[indice]);
    clock_t end = clock();

    tempo_gasto += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto é %f segundos", tempo_gasto);
    //for (int j = 0; j<NumeroElementos; j++) printf (" %i", A[j]);
    return 0;
}
