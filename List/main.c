#include <stdio.h>
#include <stdlib.h>

typedef struct Listenelement_s{
    int wert;
    struct Listenelement_s *next_Element;
}Listenelement;

Listenelement *einfuegen(Listenelement *anfang, unsigned int pos, int wertN);
void listeAusgeben(Listenelement *anfang);
void listeSort(Listenelement *anfang);

int main() {
    int anzahl = 0;
    int wert = 0;

    Listenelement *anfang = NULL;

    printf("ANzahl eingeben \n");
    scanf("%d", &anzahl);

    for(unsigned int i = 0; i < anzahl; i++){
        printf("Wert: \n");
        scanf("%d", &wert);
        anfang = einfuegen(anfang, i, wert);
    }

    listeAusgeben(anfang);

    listeSort(anfang);

    listeAusgeben(anfang);

    return 0;
}

Listenelement* einfuegen(Listenelement *anfang, unsigned int pos, int wertN){
    Listenelement *neuesElement  = (Listenelement *) malloc(sizeof(Listenelement));
    neuesElement->wert = wertN;

        if(pos == 0){
            neuesElement->next_Element = anfang;
            return neuesElement;
        }else{

            Listenelement *previous = anfang;
            while(pos > 1 && previous != NULL){
                previous = previous->next_Element;
                pos--;
            }

            neuesElement->next_Element = previous->next_Element;
            previous->next_Element = neuesElement;
            return anfang;
        }
    }

void listeAusgeben(Listenelement *anfang){
    if(anfang != NULL) {
        printf("\n Liste: %d", anfang->wert);
        while (anfang->next_Element != NULL) {
            printf("-> %d", anfang->next_Element->wert);
            anfang = anfang->next_Element;
        }
    }else{
        printf("liste ist leer amk");
    }
}

void listeSort(Listenelement *anfang){
    int speicher;
    Listenelement *x;

    while(anfang != NULL) {
        x = anfang->next_Element;
        while (x != NULL) {
            if (anfang->wert > x->wert) {
                speicher = anfang->wert;
                anfang->wert = x->wert;
                x->wert = speicher;
            }
            x = x->next_Element;
        }
        anfang = anfang->next_Element;
    }
}