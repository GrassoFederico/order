/**
 * Se non è definita la costante __SYSTEM__ vuol dire che la libreria non è stata ancora inclusa
 * e la include
 */

#ifndef __SYSTEM__
#define __SYSTEM__

/**
 *  Funzione di pulizia dello schermo
 *
 */
void clear_screen()
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

#endif