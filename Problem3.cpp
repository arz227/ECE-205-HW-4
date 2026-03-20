// Problem #3: Airplane seat assignment
#include <iostream>   // needed for cout and cin
using namespace std;  // allows direct use of cout and cin

// Function prototypes
// This function initializes the seat chart.
void initialize_seats(char seats[10][4]);

// This function displays the current seat chart.
void display_seats(char seats[10][4]);

// This function converts seat letter to column index.
int letter_to_column(char seat_letter);

// This function checks if a seat input is valid.
bool valid_seat(int row, char seat_letter);

// This function checks if a seat is available.
bool seat_available(char seats[10][4], int row, char seat_letter);

// This function reserves a seat by marking it with 'X'.
void reserve_seat(char seats[10][4], int row, char seat_letter);

// This function checks whether all seats are taken.
bool all_taken(char seats[10][4]);

int main()
{
    // 2D array for 10 rows and 4 seats per row
    char seats[10][4];

    // Variables for user seat choice
    int row;
    char seat_letter;

    // Variable to repeat process
    char response;

    // Initialize seat chart
    initialize_seats(seats);

    // Example taken seats from homework prompt
    reserve_seat(seats, 1, 'B');
    reserve_seat(seats, 3, 'D');
    reserve_seat(seats, 5, 'A');

    do
    {
        // Display current seat arrangement
        display_seats(seats);

        // If all seats are taken, stop
        if (all_taken(seats))
        {
            cout << "All seats are taken." << endl;
            break;
        }

        // Ask user for seat until valid and available seat is chosen
        do
        {
            // Get row number
            cout << "Enter desired row number (1 to 10): ";
            cin >> row;

            // Get seat letter
            cout << "Enter desired seat letter (A to D): ";
            cin >> seat_letter;

            // Convert lowercase to uppercase if needed
            if (seat_letter >= 'a' && seat_letter <= 'd')
            {
                seat_letter = seat_letter - 32;
            }

            // Check if seat input is valid
            if (!valid_seat(row, seat_letter))
            {
                cout << "Invalid seat selection. Try again." << endl;
            }
            // Check if seat is already taken
            else if (!seat_available(seats, row, seat_letter))
            {
                cout << "Seat is already taken. Try again." << endl;
            }
            else
            {
                // Valid and available seat found, reserve it
                reserve_seat(seats, row, seat_letter);
                cout << "Seat reserved successfully." << endl;
                break;
            }

        } while (true);

        // Ask user if they want to reserve another seat
        cout << "Do you want to reserve another seat? (Y/N): ";
        cin >> response;

    } while (response == 'Y' || response == 'y');

    return 0;
}

// Function definition to initialize all seats
void initialize_seats(char seats[10][4])
{
    // Loop through each row
    for (int i = 0; i < 10; i++)
    {
        // Set the 4 seat letters in each row
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }
}

// Function definition to display seat chart
void display_seats(char seats[10][4])
{
    cout << endl;
    cout << "Current Seat Chart:" << endl;

    // Loop through rows
    for (int i = 0; i < 10; i++)
    {
        // Display row number
        cout << i + 1 << " ";

        // Loop through seat columns
        for (int j = 0; j < 4; j++)
        {
            // Display seat character
            cout << seats[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

// Function definition to convert seat letter to column number
int letter_to_column(char seat_letter)
{
    if (seat_letter == 'A')
    {
        return 0;
    }
    else if (seat_letter == 'B')
    {
        return 1;
    }
    else if (seat_letter == 'C')
    {
        return 2;
    }
    else if (seat_letter == 'D')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

// Function definition to validate seat input
bool valid_seat(int row, char seat_letter)
{
    // Check row range
    if (row < 1 || row > 10)
    {
        return false;
    }

    // Check seat letter
    if (seat_letter != 'A' && seat_letter != 'B' &&
        seat_letter != 'C' && seat_letter != 'D')
    {
        return false;
    }

    return true;
}

// Function definition to check if seat is available
bool seat_available(char seats[10][4], int row, char seat_letter)
{
    // Convert seat letter to column index
    int col = letter_to_column(seat_letter);

    // Row number entered by user is 1 to 10
    // Array index is 0 to 9, so use row - 1
    if (seats[row - 1][col] == 'X')
    {
        return false;
    }

    return true;
}

// Function definition to reserve seat
void reserve_seat(char seats[10][4], int row, char seat_letter)
{
    // Convert seat letter to column index
    int col = letter_to_column(seat_letter);

    // Mark seat as taken
    seats[row - 1][col] = 'X';
}

// Function definition to check if all seats are taken
bool all_taken(char seats[10][4])
{
    // Check every seat in the 2D array
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // If any seat is not X, at least one seat is free
            if (seats[i][j] != 'X')
            {
                return false;
            }
        }
    }

    // If loop finishes, every seat is X
    return true;
}
