#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct{
char *data;
int dim;
}MaxString;

void ordina(char **lista);
int scorri(char **lista);
void swap(char **lista, int i);
void stampaLista(char **lista);

void memStr(MaxString *info, char *ptr);
void stampaFile(MaxString info, File *output);
int main(int argc, char *argv[])
{
char *lista[MAX]={"xxx","yy","ab","bxyz","n"}, *max; 
FILE output;
output=fopen(argv[1], "w");
MaxString info;
ordina(lista);/*Punti 18: Scorri+Swap*/
stampaLista(lista)/*Punti 1*/
max=lista[4];
memStr(&info, max); /*Punti 9*/
stampaFile(info, output); /*Punti 2*/
 return 0;
}

void ordina(char **lista)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (strlen(lista[i])>strlen(lista[i+1]))
        swap(lista[i]);
        scorri(lista[i]);
    }
       
}

int scorri (char **lista)
{
    if (*(lista++)!=NULL)
    return (1);
    else
    return (0);
}

void swap(char **lista)
{
    char temp[10];

    strcpy(temp, *(lista));
    strcpy(*(lista), *(lista+1));
    strcpy(*(lista+1), temp);
}

void stampaLista(char **lista)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%s\n", lista[i])
    }
    
}

void memStr(MaxString *info, char *ptr)
{
    *(info)->data=calloc(strlen(ptr)+1, sizeof(char));
    strcpy(*(info)->data, ptr);
    *(info)->dim=strlen(ptr);
}

void stampaFile (MaxString info, FILE *output)
{
    char nome[10];
    fprintf(output, "%s\n", info.data);

    printf("Inserisci il nome del file: \n");
    scanf("%s", nome);

    rename(output, nome);
}