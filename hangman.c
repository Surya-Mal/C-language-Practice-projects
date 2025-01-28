#include <stdio.h>
#include <stdlib.h> //for the rand function
#include <string.h>
#include <time.h> //for the seed function to actually make it give random numbers, seed determines the sequence of psudo random numebrs so if no srand then same sequence all the time

char* selectedWord();

int main(){
    srand(time(NULL)); //time function with NULL returns time as seconds since january 1, 1970, so seed of rand set to a new second each time
    char* chosenWord = selectedWord();
    for(int i = 0; i < 5; i++){
        printf("%c", chosenWord[i]);
    }
    return 0;
}

//Selects the word to be used for the hangman game which have a length of 5
char* selectedWord(){ //Learn arrays first, then strings, memory access/pointers
    int word = (rand() % (2 - 1 + 1)) + 1; //(rand() % max - min + 1 ) + min
    switch (word)
    {
        case 1:
            return "hello";
            break;
        case 2:
            return "fumes";
            break;
        default:
            break;
    }
}