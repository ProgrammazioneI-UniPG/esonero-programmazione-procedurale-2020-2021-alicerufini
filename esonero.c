#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int n=0, i=0;
char M[130], K [130], C[130], D[130];
int lunghezza_M=0, lunghezza_K=0;


int main() {

  //L'utente inserisce la stringa
  printf("Inserisci stringa:\n");
  fgets(M, 130, stdin);
  if (!strchr(M, '\n')) {
    while (fgetc(stdin) != '\n');
    printf("La stringa inserita è troppo lunga! La parte in eccesso verrà omessa\n");//: %s\n", M);
    }

  printf("La lunghezza della stringa è: %d\n", lunghezza_M=strlen(M)-1);


  //L'utente sceglie se inserire la chiave manualmente o generarne una casuale
  printf("Per inserire la chiave manualmente premere 1\n"
          "Per generare una chiave casuale premere 2\n"
          "Per uscire dal programma premere un tasto qualsiasi che non sia 1 o 2\n");

  scanf("%d", &n);


  //1=L'utente inserisce manualmente la chiave:
  if (n==1) {
    printf("Inserici la chiave:\n");
    while (getchar() != '\n');
    fgets(K, 130, stdin);
    printf("Lunghezza chiave: %d\n", lunghezza_K=strlen(K)-1);

            //Se la chiave inserita è più corta della stringa da cifrare
            //l'utente deve reinserire la chiave:
            while (lunghezza_K<lunghezza_M) {
                printf("La stringa inserita è troppo corta, reinserire:\n");
                fgets(K, 130, stdin);
                printf("Lunghezza chiave: %d\n", lunghezza_K=strlen(K)-1);
                }

    //Viene generata una stringa cifrata che poi viene a sua volta decifrata:
    printf("La stringa cifrata è:\n");
    for (i=0; i<lunghezza_M; ++i) {
        C[i]= M[i] ^ K[i];
        D[i]= C[i] ^ K[i];
        C[i]+=32;
        }
    printf("%s\n", C);
    printf("La stringa decifrata è:\n");
    printf("%s\n", D);
    }


  //2=Viene generata una chiave casuale:
  if (n==2) {
        time_t t;
        srand((unsigned) time(&t));
        for(i=0; i<lunghezza_M; ++i) {
            K[i]=(32+rand() %98);}
    printf("La chiave generata automaticamente è:\n%s\n", K);

    //Viene generata una stringa cifrata che poi viene a sua volta decifrata:
    printf("La stringa cifrata è:\n");
    for (i=0; i<lunghezza_M; ++i) {
        C[i]= M[i] ^ K[i];
        D[i]= C[i] ^ K[i];
        }
    printf("%s\n", C);
    printf("La stringa decifrata è:\n");
    printf("%s\n", D);
    }

  //L'utente sceglie di uscire dal programma:
  if (n!=1 && n!=2){
      printf("A presto!\n");
      }


return 0;
}
