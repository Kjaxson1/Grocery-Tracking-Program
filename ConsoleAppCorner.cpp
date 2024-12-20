#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Function to load data from the input file into a map
void LoadData(map<string, int>& itemFrequency, const string& filename) {
    ifstream inputFile(filename);
    string item;

    if (!inputFile) {
        cerr << "Error: Unable to open input file!" << endl;
        exit(1);
    }

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

// Function to write frequency data to a file
void WriteFrequencyData(const map<string, int>& itemFrequency, const string& filename) {
    ofstream outputFile(filename);

    if (!outputFile) {
        cerr << "Error: Unable to create output file!" << endl;
        exit(1);
    }

    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

// Function to display the menu
void DisplayMenu() {
    cout << "\nCorner Grocer Menu:\n";
    cout << "1. Search for an item's frequency\n";
    cout << "2. Display all items and frequencies\n";
    cout << "3. Display a histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to search for an item's frequency
void SearchItem(const map<string, int>& itemFrequency) {
    string item;
    cout << "Enter the item to search for: ";
    cin >> item;

    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        cout << item << " was purchased " << it->second << " time(s).\n";
    }
    else {
        cout << item << " was not found in the records.\n";
    }
}

// Function to display all items and their frequencies
void DisplayFrequencies(const map<string, int>& itemFrequency) {
    cout << "\nItem Frequencies:\n";
    for (const auto& pair : itemFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Function to display a histogram
void DisplayHistogram(const map<string, int>& itemFrequency) {
    cout << "\nItem Histogram:\n";
    for (const auto& pair : itemFrequency) {
        cout << setw(10) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    map<string, int> itemFrequency;
    const string inputFilename = "CS210_Project_Three_Input_File.txt";
    const string outputFilename = "frequency.dat";

    // Load data from the input file
    LoadData(itemFrequency, inputFilename);

    // Write data to the frequency file
    WriteFrequencyData(itemFrequency, outputFilename);

    int choice;
    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            SearchItem(itemFrequency);
            break;
        case 2:
            DisplayFrequencies(itemFrequency);
            break;
        case 3:
            DisplayHistogram(itemFrequency);
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
