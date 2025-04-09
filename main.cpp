//include statements
#include <iostream>
#include <vector>
#include <iomanip>

//function prototypes
void printRods(const std::vector<std::vector<int>>& rods, int numRings);
void moveRing(std::vector<std::vector<int>>& rods, int n, char start, char destination, char temp, int numRings);

//main function
int main() {
    int N;
    std::cout << "Enter the number of rings (N > 2): ";
    std::cin >> N;

    //ensure n is >2
    while (N <= 2) {
        std::cout << "Number of rings must be greater than 2.\n";
        std::cout << "Enter the number of rings (N > 2): ";
        std::cin >> N;
    }

    //initialize the rods
    std::vector<std::vector<int>> rods(3);
    for (int i = N; i >= 1; --i) {
        rods[0].push_back(i); //all rings start on rod A
    }

    //display the initial state of the rods
    printRods(rods, N);

    //start the process of moving N rings from rod 'A' to rod 'C' using rod 'B' as auxiliary
    moveRing(rods, N, 'A', 'C', 'B', N);

    return 0;
}

//function to print the rods and visualize
void printRods(const std::vector<std::vector<int>>& rods, int numRings) {
    for (int i = numRings - 1; i >= 0; --i) { //iterate from the top to the bottom
        for (int j = 0; j < 3; ++j) { //iterate over the three rods
            if (i < rods[j].size()) {
                std::cout << std::setw(4) << rods[j][i]; //print the ring at the current level
            } else {
                std::cout << std::setw(4) << "|"; //print "|" if the current level is empty
            }
        }
        std::cout << "\n";
    }
    std::cout << "---- ---- ----\n";
    std::cout << "  A    B    C\n\n";
}

//function to move a ring and update the visualization
void moveRing(std::vector<std::vector<int>>& rods, int n, char start, char destination, char temp, int numRings) {
    if (n == 1) {
        //find the source and destination rod indices
        int startIndex = start - 'A';
        int destIndex = destination - 'A';

        //move the top ring from the start rod to the destination rod
        int ring = rods[startIndex].back();
        rods[startIndex].pop_back();
        rods[destIndex].push_back(ring);

        //display the move and the updated rods
        std::cout << "Move ring " << ring << " from " << start << " to " << destination << "\n";
        printRods(rods, numRings);
        return;
    }

    //recursive case: move n-1 rings from start to temp rod
    moveRing(rods, n - 1, start, temp, destination, numRings);

    //move the nth ring to the destination rod
    moveRing(rods, 1, start, destination, temp, numRings);

    //move the n-1 rings from temp rod to the destination rod
    moveRing(rods, n - 1, temp, destination, start, numRings);
}

