#include <iostream>   // needed for cout and cin
using namespace std;  // allows us to use cout, cin without std::

// Function prototypes
// This function gets all integers from the user and stores them in the array.
void get_input(int arr[], int size);

// This function finds the largest value in the array.
// We use it to determine how many bins we need.
int find_max(int arr[], int size);

// This function sets all bin counts to 0.
void initialize_bins(int bins[], int size);

// This function updates the histogram bin counts based on user data.
void build_histogram(int arr[], int size, int bins[], int bin_count);

// This function displays the histogram.
void display_histogram(int bins[], int bin_count);

int main()
{
    int size;   // number of integers the user wants to enter

    // Ask user for size of the list
    cout << "Enter the number of integers: ";
    cin >> size;

    // Create an array of that size
    // This stores the user input values.
    int arr[size];

    // Call function to fill the array
    get_input(arr, size);

    // Find the maximum value in the array
    // This helps us know how many bins are needed.
    int max_val = find_max(arr, size);

    // Since each bin has size 10:
    // 0-9 is bin 0
    // 10-19 is bin 1
    // ...
    // If max is 37, then we need 4 bins: 0-9, 10-19, 20-29, 30-39
    int bin_count = (max_val / 10) + 1;

    // Create array to store frequency count of each bin
    int bins[bin_count];

    // Initialize all bins to 0 before counting
    initialize_bins(bins, bin_count);

    // Build histogram by counting how many values fall in each bin
    build_histogram(arr, size, bins, bin_count);

    // Display the histogram
    display_histogram(bins, bin_count);

    return 0;
}

// Function definition to get input values from the user
void get_input(int arr[], int size)
{
    // Loop through each position of the array
    for (int i = 0; i < size; i++)
    {
        // Ask user for a non-negative integer
        cout << "Enter non-negative integer #" << i + 1 << ": ";
        cin >> arr[i];

        // Validate input
        // If user enters a negative value, keep asking.
        while (arr[i] < 0)
        {
            cout << "Invalid input. Enter a non-negative integer: ";
            cin >> arr[i];
        }
    }
}

// Function definition to find the maximum value in the array
int find_max(int arr[], int size)
{
    // Assume first value is the maximum initially
    int max_val = arr[0];

    // Loop through array starting from index 1
    for (int i = 1; i < size; i++)
    {
        // If current value is larger than current max, update max
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    // Return the maximum value found
    return max_val;
}

// Function definition to set all bin counts to 0
void initialize_bins(int bins[], int size)
{
    // Go through every bin index
    for (int i = 0; i < size; i++)
    {
        // Set each bin count to zero
        bins[i] = 0;
    }
}

// Function definition to count values into bins
void build_histogram(int arr[], int size, int bins[], int bin_count)
{
    // Loop through each input value
    for (int i = 0; i < size; i++)
    {
        // Determine which bin this number belongs to
        // Example:
        // 7 / 10 = 0  -> bin 0
        // 15 / 10 = 1 -> bin 1
        // 28 / 10 = 2 -> bin 2
        int bin_index = arr[i] / 10;

        // Increase the count of that bin by 1
        bins[bin_index]++;
    }
}

// Function definition to display the histogram
void display_histogram(int bins[], int bin_count)
{
    cout << endl;
    cout << "Histogram:" << endl;

    // Display each bin range and its count
    for (int i = 0; i < bin_count; i++)
    {
        // Lower bound of the bin
        int lower = i * 10;

        // Upper bound of the bin
        int upper = i * 10 + 9;

        // Print the bin range and number of values in it
        cout << lower << "-" << upper << " : " << bins[i] << endl;
    }
}
