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
int* get_array(int dimension);
void print_array(int *array, int dimension);

/** MAIN */
int  main (int argc, char **argv)
{
    /** Stampa l'intestazione del programma */
    print_header();

    /** RECUPERO LA DIMENSIONE DEL VETTORE */
    int dimension = get_dimension();

    /** VALORIZZO IL VETTORE */
    int *array = get_array(dimension);

    /** STAMPO IL CONTENUTO DEL VETTORE */
    print_array(array, dimension);
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

/** Viene richiesta la dimensione del vettore all'utente (massimo 20 elementi) */
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

/** Inizializza il vettore con i valori inseriti dall'utente */
int* get_array(int dimension)
{
    /** 
     * Non posso ritornare direttamente il riferimento a 'result'!
     * E' una variabile locale i cui riferimenti sparirebbero al termine della funzione.
     * Ritorno invece un puntatore 'int*' che punta ad una porzione di memoria allocata grande quanto
     * la dimensione indicata per lo spazio occupato dai singoli bytes di tipo "int".
     */
    int* result = (int *)malloc(dimension * sizeof(int));

    /** 
     * Il puntatore usato per iterare e popolare il vettore:
     * in questo modo "result" punta sempre alla prima cella allocata.
     */
    int* iter = result;

    int i;
    int exit;

    /** Stampa il secondo passaggio: il programma richiede l'inserimento dei dati */
    print_step(2, "Inserire i dati nel vettore");

    printf("\n\n");

    for (i = 0; i < dimension; i++, iter++) {
        do {
            printf("Inserire il %d^ valore: ", (i + 1));

            /** Imposto l'uscita dal ciclo come comportamento predefinito */
            exit = 0;

            *iter = atoi(input());

            if (!*iter) {
                clear_screen();
                printf("Attenzione! Il valore inserito dev'essere un intero!\n");

                /** Invalida la variabile exit costringendola a ripetere il ciclo */
                exit = 1;
            }
        } while (exit);
    }

    return result;
}

/** Stampa a video il contenuto del vettore */
void print_array(int *array, int dimension)
{
    int i;

    printf("\n\nStampa vettore:\n\n");

    for (i = 0; i < dimension; i++) {
        printf("%d", array[i]);

        /** Se non sto ciclando sull'ultimo elemento inserisco lo spazio per dividere i valori */
        if (i != (dimension - 1)) {
            printf(" ");
        }
    }

    /** Aggiungo un po' di spazio sul fonto */
    printf("\n\n");
}