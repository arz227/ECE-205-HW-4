// Problem #2: Diving competition
#include <iostream>   // needed for cout and cin
using namespace std;  // allows direct use of cout and cin

// Function prototypes
// This function gets the degree of difficulty from the user.
double get_difficulty();

// This function gets the 7 judges' scores and stores them in an array.
void get_scores(double scores[], int size);

// This function finds the highest score in the array.
double find_highest(double scores[], int size);

// This function finds the lowest score in the array.
double find_lowest(double scores[], int size);

// This function finds the total of all 7 scores.
double find_sum(double scores[], int size);

// This function calculates the final diving score.
double calculate_final_score(double scores[], int size, double difficulty);

int main()
{
    // Array for 7 judges' scores
    double scores[7];

    // Variable for difficulty level
    double difficulty;

    // Get difficulty from user
    difficulty = get_difficulty();

    // Get 7 judges' scores
    get_scores(scores, 7);

    // Calculate final result
    double final_score = calculate_final_score(scores, 7, difficulty);

    // Display final score
    cout << endl;
    cout << "Final diving score is: " << final_score << endl;

    return 0;
}

// Function definition to get difficulty level
double get_difficulty()
{
    double difficulty;

    // Ask user for difficulty
    cout << "Enter degree of difficulty (1.2 to 3.8): ";
    cin >> difficulty;

    // Validate input
    while (difficulty < 1.2 || difficulty > 3.8)
    {
        cout << "Invalid difficulty. Enter a value from 1.2 to 3.8: ";
        cin >> difficulty;
    }

    return difficulty;
}

// Function definition to input judges' scores
void get_scores(double scores[], int size)
{
    // Loop through 7 judges
    for (int i = 0; i < size; i++)
    {
        // Ask for a score
        cout << "Enter score for judge #" << i + 1 << " (0 to 10): ";
        cin >> scores[i];

        // Validate score
        while (scores[i] < 0 || scores[i] > 10)
        {
            cout << "Invalid score. Enter a value from 0 to 10: ";
            cin >> scores[i];
        }
    }
}

// Function definition to find highest score
double find_highest(double scores[], int size)
{
    // Assume first score is highest initially
    double highest = scores[0];

    // Compare with remaining scores
    for (int i = 1; i < size; i++)
    {
        if (scores[i] > highest)
        {
            highest = scores[i];
        }
    }

    return highest;
}

// Function definition to find lowest score
double find_lowest(double scores[], int size)
{
    // Assume first score is lowest initially
    double lowest = scores[0];

    // Compare with remaining scores
    for (int i = 1; i < size; i++)
    {
        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }

    return lowest;
}

// Function definition to find total sum of all scores
double find_sum(double scores[], int size)
{
    double sum = 0;

    // Add all scores together
    for (int i = 0; i < size; i++)
    {
        sum = sum + scores[i];
    }

    return sum;
}

// Function definition to calculate final score
double calculate_final_score(double scores[], int size, double difficulty)
{
    // Find highest score
    double highest = find_highest(scores, size);

    // Find lowest score
    double lowest = find_lowest(scores, size);

    // Find total of all scores
    double sum = find_sum(scores, size);

    // Remove highest and lowest from total
    double adjusted_sum = sum - highest - lowest;

    // Apply diving formula:
    // remaining total * difficulty * 0.6
    double final_score = adjusted_sum * difficulty * 0.6;

    return final_score;
}
