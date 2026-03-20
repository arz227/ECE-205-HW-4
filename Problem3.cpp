// Problem #3: Airplane seat assignment

#include <iostream>
using namespace std;

// function prototypes
void initialize_seats(char seats[10][4]);
void display_seats(char seats[10][4]);
int letter_to_column(char seat_letter);
bool valid_seat(int row, char seat_letter);
bool seat_available(char seats[10][4], int row, char seat_letter);
void reserve_seat(char seats[10][4], int row, char seat_letter);
bool all_taken(char seats[10][4]);

int main()
{
	char seats[10][4];   // 10 rows and 4 seats per row
	int row;             // user input for row
	char seat_letter;    // user input for seat letter
	char response;       // to continue or stop

	// initialize all seats as A, B, C, D
	initialize_seats(seats);

	// mark example taken seats from homework prompt
	reserve_seat(seats, 1, 'B');
	reserve_seat(seats, 3, 'D');
	reserve_seat(seats, 5, 'A');

	do
	{
		// show current seat chart
		display_seats(seats);

		// stop if all seats are already taken
		if (all_taken(seats))
		{
			cout << "All seats are taken." << endl;
			break;
		}

		// keep asking until user enters a valid and available seat
		do
		{
			cout << "Enter desired row number (1 to 10): ";
			cin >> row;

			cout << "Enter desired seat letter (A to D): ";
			cin >> seat_letter;

			// convert lowercase to uppercase
			if (seat_letter >= 'a' && seat_letter <= 'd')
			{
				seat_letter = seat_letter - 32;
			}

			// check whether row and seat letter are valid
			if (!valid_seat(row, seat_letter))
			{
				cout << "Invalid seat selection. Try again." << endl;
			}
			// check whether seat is already taken
			else if (!seat_available(seats, row, seat_letter))
			{
				cout << "Seat is already taken. Try again." << endl;
			}
			else
			{
				// reserve seat if valid and available
				reserve_seat(seats, row, seat_letter);
				cout << "Seat reserved successfully." << endl;
				break;
			}

		} while (true);

		// ask if user wants another reservation
		cout << "Do you want to reserve another seat? (Y/N): ";
		cin >> response;

	} while (response == 'Y' || response == 'y');

	return 0;
}

// initialize all seats in each row
void initialize_seats(char seats[10][4])
{
	for (int i = 0; i < 10; i++)
	{
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
	}
}

// display current seat chart
void display_seats(char seats[10][4])
{
	cout << endl;
	cout << "Current Seat Chart:" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " ";

		for (int j = 0; j < 4; j++)
		{
			cout << seats[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}

// convert seat letter into column index
int letter_to_column(char seat_letter)
{
	if (seat_letter == 'A')
		return 0;
	else if (seat_letter == 'B')
		return 1;
	else if (seat_letter == 'C')
		return 2;
	else if (seat_letter == 'D')
		return 3;
	else
		return -1;
}

// check whether seat input is within valid range
bool valid_seat(int row, char seat_letter)
{
	if (row < 1 || row > 10)
	{
		return false;
	}

	if (seat_letter != 'A' && seat_letter != 'B' &&
		seat_letter != 'C' && seat_letter != 'D')
	{
		return false;
	}

	return true;
}

// check whether selected seat is free
bool seat_available(char seats[10][4], int row, char seat_letter)
{
	int col = letter_to_column(seat_letter);

	if (seats[row - 1][col] == 'X')
	{
		return false;
	}

	return true;
}

// mark selected seat as taken
void reserve_seat(char seats[10][4], int row, char seat_letter)
{
	int col = letter_to_column(seat_letter);
	seats[row - 1][col] = 'X';
}

// check whether all seats are taken
bool all_taken(char seats[10][4])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (seats[i][j] != 'X')
			{
				return false;
			}
		}
	}

	return true;
}
