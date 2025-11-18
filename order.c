/** LIBRERIE */

#include <stdio.h>
#include <stdlib.h> // librerie di sistema

#include "./libs/system.h"

/** COSTANTI */

#define DIM 20

/** PROTOTIPI */

void print_header();
int  get_dimension();   
void init_array();

/** MAIN */
int  main (int argc, char **argv)
{
    // Stampa l'intestazione del programma
    print_header();

    // Viene richiesta la dimensione del vettore all'utente (massimo 20 elementi)
    int dimension = get_dimension();

    // Inizializzo il vettore indicando la dimensione
    int array[DIM];
    
    init_array(array);

    // while (array) {
    //     printf("\n%d", array);
    //     array++;
    // }

    
}

// Stampa l'intestazione del programma
void print_header()
{
    // Stampo a video un titolo sommario del programma
    printf("\nGESTIONE DI UN VETTORE\n");
}

// Viene richiesta la dimensione del vettore all'utente (massimo 20 elementi)
int  get_dimension()
{
    int result;

    do {
        printf("\nInserisci la dimensione del vettore: ");
        scanf("%d", &result);

        if (result > DIM) {
            clear_screen();
            printf("Attenzione! Il vettore non puo' essere piu' grande di %d", result);
        }
    } while (result > DIM);

    return result;
}

// Inizializza il vettore
void init_array(int result)
{
    int i = 0;

    while (i < DIM) {
        printf("Inserisci il %d^ valore: ", (i + 1));
        scanf("%d", &result);

        i++;
    }
}