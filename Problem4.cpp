// Problem #4: Tic-Tac-Toe game
#include <iostream>   // needed for cout and cin
using namespace std;  // allows direct use of cout and cin

// Function prototypes
// This function initializes the board with characters 1 to 9.
void initialize_board(char board[3][3]);

// This function displays the board.
void display_board(char board[3][3]);

// This function checks whether a move is valid.
bool valid_move(char board[3][3], int position);

// This function places X or O on the board.
void place_move(char board[3][3], int position, char player);

// This function checks if the current player has won.
bool check_winner(char board[3][3], char player);

// This function checks if the board is full.
bool board_full(char board[3][3]);

int main()
{
    // Create 3x3 tic-tac-toe board
    char board[3][3];

    // Player X starts first according to homework
    char player = 'X';

    // Variable to store position entered by user
    int position;

    // Initialize board
    initialize_board(board);

    // Continue game until someone wins or board becomes full
    while (true)
    {
        // Display current board
        display_board(board);

        // Ask current player for move
        cout << "Player " << player << ", enter a position (1 to 9): ";
        cin >> position;

        // Check if move is valid
        if (!valid_move(board, position))
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Place player's mark on the board
        place_move(board, position, player);

        // Check if current player wins
        if (check_winner(board, player))
        {
            display_board(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        // Check if board is full
        if (board_full(board))
        {
            display_board(board);
            cout << "Game is a draw." << endl;
            break;
        }

        // Switch player
        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }

    return 0;
}

// Function definition to initialize board
void initialize_board(char board[3][3])
{
    // Starting character for board positions
    char value = '1';

    // Fill 3x3 board with characters '1' through '9'
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = value;
            value++;
        }
    }
}

// Function definition to display board
void display_board(char board[3][3])
{
    cout << endl;

    // Display each row of the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

// Function definition to check whether a move is valid
bool valid_move(char board[3][3], int position)
{
    // Position must be between 1 and 9
    if (position < 1 || position > 9)
    {
        return false;
    }

    // Convert position to row and column
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    // If board cell already has X or O, it is taken
    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        return false;
    }

    return true;
}

// Function definition to place a move
void place_move(char board[3][3], int position, char player)
{
    // Convert position into row and column
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    // Put player mark in that location
    board[row][col] = player;
}

// Function definition to check winner
bool check_winner(char board[3][3], char player)
{
    // Check all 3 rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    // Check all 3 columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    // Check main diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    // Check other diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    // If no win conditions are met
    return false;
}

// Function definition to check whether board is full
bool board_full(char board[3][3])
{
    // Check every position on the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // If any cell is not X and not O, move is still possible
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    // If all cells are occupied
    return true;
}
