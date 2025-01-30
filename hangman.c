#include <stdio.h>
#include <stdlib.h> //for the rand function
#include <string.h>
#include <time.h> //for the seed function to actually make it give random numbers, seed determines the sequence of psudo random numebrs so if no srand then same sequence all the time

char* selectedWord();
void checkLetter(char aLetter, char* chosenWord, char* current, int size, int* remaining);

int main(){
    srand(time(NULL)); //time function with NULL returns time as seconds since january 1, 1970, so seed of rand set to a new second each time
    char* chosenWord = selectedWord(); //The word chosen that the user has to guess, has a default size of 8 bytes
    int lives = 6; //The number of lives the user has to guess the word
    char usersLetter; //The array that houses 
    int size = strlen(chosenWord); //Size of the chosen word array
    int lettersRemaining = size; //Keeps track of the number of letters needed for the user to guess

    char correctLetters[size]; //Shows the user the letters that have been discovered so far
    for(int i = 0; i < size; i++){
        correctLetters[i] = '_';
    }

    printf("Welcome to Hangman!\n");
    while(lettersRemaining != 0 && lives > 0){
        for(int i = 0; i < size; i++){
            printf("%c", correctLetters[i]);
        }

        printf("\nEnter your chosen letter: ");
        scanf("%c", &usersLetter);
        getchar();

        checkLetter(usersLetter, chosenWord, correctLetters, size, &lettersRemaining);
    }

    printf("The word was: ");
    for(int i = 0; i < size; i++){
        printf("%c", correctLetters[i]);
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

/*
*Checks if the user's letter that was inputed is part of the chosen word adding that letter to the display and reducing the number of letters remaining by the number of matches
*/
void checkLetter(char aLetter, char* chosenWord, char* current, int size, int* remaining){
    for(int i = 0; i < size; i++){
        if(aLetter == *(chosenWord + i)){
            *(current + i) = aLetter;
            (*remaining)--; //reduces the number of letters that the user needs to guess
        }
    }
}