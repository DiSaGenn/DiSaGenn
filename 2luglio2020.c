/*
Il Codice C di seguito riportato, verifica se tra le stringhe presenti in char *data[MAX] è presente una stringa (max 100
caratteri) inserita da utente mediante tastiera: se la stringa non è presente il suo indirizzo è inserito in char *data[MAX]
nell’unica posizione libera (l’array ha dimensione 4 ed ha una sola posizione libera). Implementare le seguenti
funzioni:

void leggi_string (char **): acquisisce da tastiera una stringa ed utilizzando l’allocazione dinamica l’associa al
puntatore ptrString, dichiarato nel main e passato per riferimento.

int cerca_str(char *[], char []): UTILIZZANDO LA NOTAZIONE PUNTATORE, verifica se in char *data[MAX] è
presente la stringa puntata da ptrString; la funzione restituisce 1 se la stringa è presente, 0 se non è presente.

void insString(char *[], char *): UTILIZZANDO LA NOTAZIONE PUNTATORE, inserisce in char *data[MAX] la
stringa puntata da ptrString nella posizione libera. La funzione dovrà essere generica nel senso che dovrà essere
utilizzabile a prescindere dall’attuale posizione libera in char *data[MAX] che è, nel caso specifico, la terza (in altre
parole se si cambia la posizione libera, la funzione dovrà comunque produrre il risultato corretto).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 4

void leggi_string(char **); /*IMPLEMENTARE*/
int cerca_str(char *[], char []); /* IMPLEMENTARE*/
void insString(char *[], char *); /* IMPLEMENTARE*/
void stampa_out (char *[]); /* NON IMPLEMENTARE*/

int main()
{
char *data[MAX]={"aba","acbaa",NULL,"axxxxa"}, *ptrString;
leggi_string(&ptrString);
if(!cerca_str(data, ptrString))
{
insString(data,ptrString);
stampa_out(data);
}
else
printf("La stringa è già presente\n");
free (ptrString);
}

void leggi_string(char ** ptr)
{
    char temp[10];

    printf("Inserisci la stringa: \n");
    scanf("%s", temp);

    *ptr=calloc(strlen(temp)+1, sizeof(char));

    strcpy(*ptr, temp);
}

int cerca_str(char *data[], char *ptr)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
    if (!strcmp(ptr, *(data+i)))
        return (1);
    }
    
    return (0);
}
void insString(char *data[], char *ptr)
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        if (*(data+i)==NULL)
        {
            *(data+i)=calloc(strlen(ptr)+1, sizeof(char));
            strcpy(*(data+i), ptr);
        }
        
    }
    
}

void stampa_out (char *data[])
{
    int i;
printf("Stampo l'array: \n");
    for (i = 0; i < MAX; i++)
    {
        printf("\n%s", *(data+i));
    }
    printf(".");
}