/** LIBRERIE */

/** Librerie di sistema */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Librerie personalizzate */
#include "./libs/system.h"

/** COSTANTI */
#define DIM 20

/** PROTOTIPI */

/** Funzioni di gestione del menù */
void print_header();
void print_step(int step, char* message);

/** Funzioni base del programma */
int  get_dimension();   
void init_array();

/** MAIN */
int  main (int argc, char **argv)
{
    /** Stampa l'intestazione del programma */
    print_header();

    /** RECUPERO LA DIMENSIONE DEL VETTORE */
    int dimension = get_dimension();

    // Inizializzo il vettore indicando la dimensione
    int array[DIM];
    
    init_array(array);

    // while (array) {
    //     printf("\n%d", array);
    //     array++;
    // }

    
}

/** Funzione usata per stampare l'instazione del programma */
void print_header()
{
    printf("\nGESTIONE DI UN VETTORE\n");
}

/** Funzione usata per stampare i vari passaggi del programma */
void print_step(int step, char* message)
{
    printf("\n%d. %s: ", step, message);
}

// Viene richiesta la dimensione del vettore all'utente (massimo 20 elementi)
int  get_dimension()
{
    /** La dimensione del vettore */
    int  result;
    int  exit;

    do {
        /** Come impostazione predefinita mi aspetto di uscire dal ciclo */
        exit = 0;

        /** Stampa il primo passaggio: il programma richiede la dimensione del vettore */
        print_step(1, "Inserire la dimensione del vettore");
        result = atoi(input());

        /** Se il valore non è un intero lo segnala all'utente */
        if (!result) {
            clear_screen();
            printf("Attenzione! Il valore inserito dev'essere un intero!\n");

            /** Invalida la variabile exit costringendola a ripetere il ciclo */
            exit = 1;
        }

        /** Se il vettore supera la dimensione massima consentita stampa un messaggio di errore */
        if (result > DIM) {
            clear_screen();
            printf("Attenzione! Il vettore non puo' essere piu' grande di %d\n", DIM);

            /** Invalida la variabile exit costringendola a ripetere il ciclo */
            exit = 1;
        }
    } while (exit);

    /** Ritorna il vettore */
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