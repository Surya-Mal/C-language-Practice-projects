#include <stdio.h> //Function declaration

int chooseOp(int first, char op, int second);

int main() {
    printf("Welcome to the calculator! \nPlease input your first number: ");
    int firstNum, secondNum;
    scanf("%d", &firstNum);
    getchar();
    printf("What operator would you like to do (+, -, *, /, mod): ");
    char operator;
    scanf("%c", &operator);
    printf("what is 2nd number: ");
    scanf("%d", &secondNum);

    printf("Your selected operation result is: %d\n", chooseOp(firstNum, operator, secondNum));

    printf("%.2f\n", 2.546);
    printf("%lu\n", sizeof('w'));

    return 0;
}

int chooseOp(int first, char op, int second){ //function definition, can also be written before the main method
    switch (op)
    {
        case '+':
            return first + second;
            break;
        case '-':
            return first - second;
            break;
        case '*':
            return first * second;
            break;
        case '/':
            return first / second;
            break;
        default:
            return -1;
            break;
    }
}
