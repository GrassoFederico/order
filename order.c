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
int  print_menu();
void sort_desc(int *array, int start, int end);
void find(int needle, int *array, int dimension);

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

    /** STAMPO IL MENU PER LE OPERAZIONI DA FARE SUL VETTORE */
    int option;
    
    do {
        option = print_menu();

        if (option == 1) {
            sort_desc(array, 0, (dimension - 1));
            print_array(array, dimension);
        }

    } while (option != 3);

    printf("\n\nBYE BYE!\n\n");

    return 0;
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

/** Stampa il menu con le opzioni disponibili */
int print_menu()
{
    int result;
    int exit;

    do {
        printf("\n\nMENU\n\n");
        printf("1. Ordinamento decrescente\n");
        printf("2. Ricerca di un valore inserito da tastiera\n");
        printf("3. Esci\n\n");

        /** Come comportamento predefinito imposto l'uscita dal ciclo */
        exit = 0;

        result = atoi(input());

        if ((result < 1) || (result > 3)) {
            clear_screen();
            printf("Attenzione! L'opzione selezionata non e' valida! Riprova");

            exit = 1;
        }

    } while (exit);

    return result;
}

/** Ordina in senso decrescente il vettore */
void sort_desc(int *array, int start, int end)
{
    /* L'idea è quella di partire agli estremi del vettore e scambiare i valori se non ordinati
     * stringendo man mano l'intervallo
     */
    int swap;
    int ordered = 1;

    /** Se gli indici di posizione si incrociano ho terminato il controllo di ordinamento */
    if (start > end) {
        return;
    }

    /** Se gli elementi agli estremi dell'intervallo non sono ordinati li inverto */
    if (array[start] < array[end]) {
        swap = array[end];
        array[end] = array[start];
        array[start] = swap;

        /** Invalido l'ordinamento */
        ordered = 0;
    }

    /** Rieseguo l'ordinamento stringendo l'intervallo */
    sort_desc(array, start, (end - 1));
    sort_desc(array, (start + 1), end);

    /** Se non è risultato ordinato divido a metà il vettore e ripeto l'ordinamento */
    if (!ordered) {
        sort_desc(array, start, end);
    }
}

/** Cerca un elemento all'interno del vettore */
void find(int needle, int *array, int dimension)
{

}