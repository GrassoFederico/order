# Order - Gestore di vettore

### Compilazione

Per compilarlo occorre avere installato il compilatore GCC ed eseguire il seguente comando:

```
gcc order.c -o order.exe
```

In questo modo il compilato prende il nome di `order.exe` che è più coerente.

### Avvio

Per avviarlo occorre portarsi con il terminale nella base della cartella e scrivere:

```
order
```

A questo punto verrà avviata la procedura di avvio in cui si chiederà di indicare il numero di elementi da caricare e i singoli valori da inserire.

**Attenzione!** Il vettore non può superare i 20 elementi!

Terminata la fase di installazione verrà presetato un semplice menù che permette di:

- *Ordinare in modo decrescente il vettore*: l'ordinamento è implementato attraverso algoritmo ricorsivo
- *Cercare un elemento all'interno del vettore*: la ricerca è sempre ricorsiva e sfrutta il metodo della ricerca dicotomica (particolarmente performante)
- *Uscire dal programma*: semplicemente uscire dal programma

### Gestione degli errori

Il programma è in grado di riconoscere con una validazione molto basilare i dati inseriti, pertanto se i valori inseriti non sono corretti il software è in grado di riconoscerlo e di riproporre all'utente un nuovo inserimento.