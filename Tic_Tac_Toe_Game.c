#define EASY 1
#define MEDIUM 2
#define IMPOSSIBLE 3

int check_win(char board[3][3], char player); // forward declaration

int find_winning_move(char board[3][3], char player)
{
    for (int pos = 1; pos <= 9; pos++)
    {
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        if (board[row][col] == ' ')
        {
            board[row][col] = player;
            int win = check_win(board, player);
            board[row][col] = ' ';
            if (win)
            {
                return pos;
            }
        }
    }
    return 0;
}

int minimax(char board[3][3], int depth, int isMaximizing)
{
    if (check_win(board, 'O'))
    {
        return 10 - depth;
    }
    if (check_win(board, 'X'))
    {
        return depth - 10;
    }
    int draw = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                draw = 0;
            }
        }
    }
    if (draw)
    {
        return 0;
    }

    int best;
    if (isMaximizing)
    {
        best = -1000;
        for (int pos = 1; pos <= 9; pos++)
        {
            int row = (pos - 1) / 3;
            int col = (pos - 1) % 3;
            if (board[row][col] == ' ')
            {
                board[row][col] = 'O';
                int score = minimax(board, depth + 1, 0);
                board[row][col] = ' ';
                if (score > best)
                {
                    best = score;
                }
            }
        }
    }
    else
    {
        best = 1000;
        for (int pos = 1; pos <= 9; pos++)
        {
            int row = (pos - 1) / 3;
            int col = (pos - 1) % 3;
            if (board[row][col] == ' ')
            {
                board[row][col] = 'X';
                int score = minimax(board, depth + 1, 1);
                board[row][col] = ' ';
                if (score < best)
                {
                    best = score;
                }
            }
        }
    }
    return best;
}

int best_move_minimax(char board[3][3])
{
    int bestScore = -1000, move = 0;
    for (int pos = 1; pos <= 9; pos++)
    {
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        if (board[row][col] == ' ')
        {
            board[row][col] = 'O';
            int score = minimax(board, 0, 0);
            board[row][col] = ' ';
            if (score > bestScore)
            {
                bestScore = score;
                move = pos;
            }
        }
    }
    return move;
}
#include <stdlib.h>
#include <time.h>
// TIC-TAC-TOE GAME IN C

#include <stdio.h>

void display_board(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int pos = i * 3 + j + 1;
            if (board[i][j] == ' ')
            {
                printf(" %d ", pos);
            }
            else
            {
                printf(" %c ", board[i][j]);
            }
            if (j != 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int check_win(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }
    return 0;
}

int check_draw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char play_again = 'Y';
    srand(time(NULL));
    do
    {
        // Welcome banner and instructions
        printf("==============================\n");
        printf("      TIC-TAC-TOE GAME!\n");
        printf("==============================\n");
        printf("Instructions:\n");
        printf("- Enter the number (1-9) for your move as shown on the board.\n");
        printf("- First to get 3 in a row wins!\n");
        printf("- You can play against a friend or the computer.\n");
        printf("\n");

        char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        char player = 'X';
        int game_over = 0;
        int pos, mode, difficulty = EASY;

        printf("1. Single Player (You vs Computer)\n");
        printf("2. Play with Friend\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &mode);

        while (mode != 1 && mode != 2)
        {
            printf("Invalid choice. Enter 1 or 2: ");
            scanf("%d", &mode);
        }

        if (mode == 1)
        {
            printf("Select difficulty level:\n");
            printf("1. Easy\n2. Medium\n3. Impossible\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &difficulty);
            while (difficulty < 1 || difficulty > 3)
            {
                printf("Invalid choice. Enter 1, 2, or 3: ");
                scanf("%d", &difficulty);
            }
        }

        while (!game_over)
        {
            display_board(board);
            printf("(Enter 0 at any time to restart the game)\n");
            if (mode == 1 && player == 'O')
            {
                printf("Computer's turn (O).\n");
                int choice = 0;
                if (difficulty == EASY)
                {
                    // Easy: random
                    int empty[9], count = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (board[i][j] == ' ')
                            {
                                empty[count++] = i * 3 + j + 1;
                            }
                        }
                    }
                    if (count > 0)
                    {
                        choice = empty[rand() % count];
                    }
                }
                else if (difficulty == MEDIUM)
                {
                    // Medium: win if possible, block user, else random
                    choice = find_winning_move(board, 'O');
                    if (!choice)
                    {
                        choice = find_winning_move(board, 'X');
                    }
                    if (!choice)
                    {
                        int empty[9], count = 0;
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (board[i][j] == ' ')
                                {
                                    empty[count++] = i * 3 + j + 1;
                                }
                            }
                        }
                        if (count > 0)
                        {
                            choice = empty[rand() % count];
                        }
                    }
                }
                else if (difficulty == IMPOSSIBLE)
                {
                    // Impossible: minimax
                    choice = best_move_minimax(board);
                }
                if (choice)
                {
                    int row = (choice - 1) / 3;
                    int col = (choice - 1) % 3;
                    board[row][col] = 'O';
                    printf("Computer chose position %d\n", choice);
                }
            }
            else
            {
                // Human player's turn
                printf("Player %c's turn. Enter position (1-9, or 0 to restart): ", player);
                scanf("%d", &pos);

                if (pos == 0)
                {
                    printf("Restarting the game...\n");
                    game_over = 2; // special value to indicate restart
                    break;
                }

                if (pos < 1 || pos > 9)
                {
                    printf("Invalid position. Try again.\n");
                    continue;
                }
                int row = (pos - 1) / 3;
                int col = (pos - 1) % 3;
                if (board[row][col] != ' ')
                {
                    printf("Position already taken. Try again.\n");
                    continue;
                }
                board[row][col] = player;
            }

            // Check for win/draw after each move
            char current = (mode == 1 && player == 'O') ? 'O' : player;
            if (check_win(board, current))
            {
                display_board(board);
                if (mode == 1 && player == 'O')
                {
                    printf("Computer (O) wins!\n");
                }
                else
                {
                    printf("Player %c wins!\n", current);
                }
                game_over = 1;
            }
            else if (check_draw(board))
            {
                display_board(board);
                printf("It's a draw!\n");
                game_over = 1;
            }

            // Switch player
            if (!game_over)
            {
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        // If user chose to restart, skip the replay prompt and restart immediately
        if (game_over == 2)
        {
            continue;
        }

        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &play_again);
    } while (play_again == 'Y' || play_again == 'y');
    return 0;
}
