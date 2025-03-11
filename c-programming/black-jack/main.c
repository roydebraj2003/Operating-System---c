#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 52

typedef struct {
	char *rank;
	char suite;
	int value;
} Card;

typedef struct {
    Card hand[12];
    int handSize;
    int isBusted;  
    int revealCard; 
} Dealer;

typedef struct {
    Card hand[12];  
    int handSize;   
    int balance;     
    int currentBet;  
    int hasSplit;    
    int isBusted;    
} Player;
Card deck[MAX];

void buildDeck(Card deck[]) {
    char suites[] = {'H', 'S', 'C', 'D'}; 
    char *ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int idx = 0;

    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 13; j++) {  
            deck[idx].suite = suites[i];
            deck[idx].rank = ranks[j];  

            if (strcmp(ranks[j], "A") == 0) {
                deck[idx].value = 11;
            } else if (strcmp(ranks[j], "K") == 0 || strcmp(ranks[j], "Q") == 0 || strcmp(ranks[j], "J") == 0) {
                deck[idx].value = 10;
            } else {
                deck[idx].value = atoi(ranks[j]);
            }

            idx++;  
        }
    }
}

void show(Card deck[]) {
	for(int i = 0; i< MAX; i++) {
		printf("(%s-%s) -> ", deck[i].rank, &deck[i].suite );
	}
}



int main() {
	buildDeck(deck);
	show(deck);
	return 0;
}
