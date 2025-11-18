/**
 * Se non è definita la costante __SYSTEM__ vuol dire che la libreria non è stata ancora inclusa
 * e la include
 */

#ifndef __SYSTEM__
#define __SYSTEM__

/** Massimo numero di caratteri leggibili */
#define MAX_CHARS  1024

/** Valore in ASCII del carattere 0 */
#define ASCII_ZERO 48
#define ASCII_NINE 57

/** Prototipi */
void  clear_screen();
char* input();

/**
 *  Funzione di pulizia dello schermo
 *
 */
void  clear_screen()
{
    /** 
     * Può tornare molto utile ma evitiamo di utilizzare funzioni di sistema in quanto renderebbe
     * questa funzionalità non utilizzabile su tutti i sistemi operativi.
     * Usiamo quindi una specifica sequenza di caratteri:
     * 
     * \e[2J sequenza di caratteri che pulisce lo schermo completamente
     * \r    porta il cursore del testo a inizio riga, in questo modo i messaggi compaiono sempre a inizio riga
     */

    printf("\e[2J\r");
}

/**
 * Funzione per la lettura di input da parte dell'utente.
 */
char* input()
{
    /** 
     * Non posso ritornare direttamente il riferimento a 'result'!
     * E' una variabile locale i cui riferimenti sparirebbero al termine della funzione.
     * Ritorno invece un puntatore 'char*' che punta ad una copia allocata di 'result'.
     */
    char* result_tmp;

    /** Il vettore risultante */
    char  result[MAX_CHARS];

    /** 
     * Utilizzando fgets() funziona bene anche nei cicli. 
     * stdin è il buffer che vogliamo usare per leggere l'input da riga di comando.
     */
    fgets(result, MAX_CHARS, stdin);

    /** Alloco una copia del vettore di caratteri */
    result_tmp = (char *)malloc(strlen(result) * sizeof(char));

    /** Copia la stringa contenuta in 'result' nello spazio appena allocato e ne resistuisce il puntatore */
    strcpy(result_tmp, result);

    return result_tmp;
}

#endif