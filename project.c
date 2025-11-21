#include <stdio.h>
#include <string.h>

char board[3][3];

char player1[30], player2[30];

int scoreX = 0, scoreO = 0;

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n  Current Board:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("   %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("  ---|---|---\n");
    }
    printf("\n");
}

int isValidMove(int r, int c) {
    if (r < 0 || r > 2 || c < 0 || c > 2)
        return 0;
    if (board[r][c] != ' ')
        return 0;
    return 1;
}

int checkWin(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return 1;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return 1;
    }

    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return 1;

    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return 1;

    return 0;
}

int boardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}


void showScore() {
    printf("\n  ----- SCOREBOARD -----\n");
    printf("  %s (X) : %d\n", player1, scoreX);
    printf("  %s (O) : %d\n", player2, scoreO);
    printf("  ----------------------\n\n");
}

void rules() {
    printf("\n----- GAME RULES -----\n");
    printf("1. Game is played on a 3x3 grid.\n");
    printf("2. Player 1 uses X and Player 2 uses O.\n");
    printf("3. Enter row and column numbers (0-2).\n");
    printf("4. First player to get 3 in a row wins.\n");
    printf("5. If board is full and no winner, it's a draw.\n");
    printf("-----------------------\n\n");
}


int playAgain() {
    char ch;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &ch);
    return (ch == 'y' || ch == 'Y');
}

void playGame() {
    int r, c;
    char player = 'X';

    initBoard();

    while (1) {
        printBoard();

        printf("%s (%c), enter row and column: ",
            (player == 'X' ? player1 : player2), player);
        scanf("%d %d", &r, &c);

        if (!isValidMove(r, c)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[r][c] = player;

        if (checkWin(player)) {
            printBoard();
            printf("\n*** %s (%c) WINS! ***\n",
                   (player == 'X' ? player1 : player2), player);

            if (player == 'X') scoreX++;
            else scoreO++;

            showScore();
            break;
        }

        if (boardFull()) {
            printBoard();
            printf("\n*** MATCH DRAW! ***\n");
            showScore();
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }
}

int menu() {
    int ch;
    printf("----- MAIN MENU -----\n");
    printf("1. Play Game\n");
    printf("2. View Rules\n");
    printf("3. Scoreboard\n");
    printf("4. Exit\n");
    printf("----------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

int main() {
    int choice;

    printf("Enter Player 1 name (X): ");
    scanf("%s", player1);

    printf("Enter Player 2 name (O): ");
    scanf("%s", player2);

    while (1) {
        choice = menu();

        switch (choice) {
            case 1:
                do {
                    playGame();
                } while (playAgain());
                break;

            case 2:
                rules();
                break;

            case 3:
                showScore();
                break;

            case 4:
                printf("\nThank you for playing Tic Tac Toe!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}