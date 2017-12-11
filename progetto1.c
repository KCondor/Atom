#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_ESERCIZIO 20 // prova diversi valori di queste due costanti
#define MAX_CHIAVE 100 // MAX_ESERCIZIO è la lunghezza della lista massima, MAX_CHIAVE è il valore massimo \
                          // non puoi fare ipotesi su questi valori. Non sai quali costanti useró io.

struct tipo_risultato
{
    int numero;
    int memoria;
};

typedef struct tipo_risultato tipo_risultato; // la tua funzione deve restituire un valore di questo tipo

struct tipo_nodo
{
    int chiave;
    struct tipo_nodo *next;
};

typedef struct tipo_nodo nodo; // la lista di input della tua funzione

struct tipo_lista
{
    int cardinalita;
    nodo *testa;
};

typedef struct tipo_lista lista;
/***************************************************************************************************************/
void CreaLista(lista *l)
{
    l->cardinalita = 0;
    l->testa = NULL;
}

nodo *CreaNodo(int chiave)
{
    nodo *nuovonodo = malloc(sizeof(nodo));
    nuovonodo->chiave = chiave;
    nuovonodo->next = NULL;
    return nuovonodo;
}

void Aggiungi(int chiave, lista *l)
{
    nodo *nuovonodo = CreaNodo(chiave);
    nuovonodo->next = l->testa;
    l->testa = nuovonodo;
    l->cardinalita++;
}

void StampaLista(lista l)
{
    nodo *tempnodo = l.testa;
    while (tempnodo)
    {
        printf("%d\n", tempnodo->chiave);
        tempnodo = tempnodo->next;
    }
}

void RiempiLista(lista *l) // questa è solo di prova. Non sai se useró una generazione diversa da questa
{
    for (int i = 0; i < MAX_ESERCIZIO; i++)
        Aggiungi(rand() % MAX_CHIAVE, l);
}

/***************************************************************************************************************/

tipo_risultato ContaRipetizioni(lista l) // guarda questa soluzione di esempio: se la completi, sarà abbastanza efficiente in tempo,
                                         // e tra le meno efficienti in spazio
{                                        // se presenti questa stessa soluzione sarà molto probabile che tu prenda un voto molto basso
    tipo_risultato risultato;
    int memoria = 0;
    int hash[MAX_CHIAVE];
    nodo *tempnodo = l.testa;


    int max;

    // usa hash come tabella HASH ad accesso diretto per contare quante volte si presenta una certa chiave

    // esplora tutta la tabella alla fine per trovare il massimo numero di occorrenze di qualche chiave

    memoria = sizeof(hash) + sizeof(nodo) + sizeof(risultato) + sizeof(memoria);
    risultato.memoria = memoria;
    risultato.numero = max;
    return risultato;

    // osserva: non è necessario liberare spazio, qui. Se avessi utilizzato strutture dinamiche, avrei dovuto liberarle alla fine dell'esecuzione.
}

int main()
{
    lista l;
    CreaLista(&l);
    RiempiLista(&l);
    StampaLista(l);
}