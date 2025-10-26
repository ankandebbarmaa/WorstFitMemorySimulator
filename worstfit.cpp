#include <iostream>
#include <iomanip>
using namespace std;

class MemoryManager {
private:
    int numBlocks, numProcesses;
    int blockSize[50];
    int processSize[50];
    int allocation[50];

public:
    MemoryManager(int nb, int np) {
        numBlocks = nb;
        numProcesses = np;
        for (int i = 0; i < numProcesses; i++)
            allocation[i] = -1;
    }

    void inputBlocks() {
        cout << "Enter sizes of " << numBlocks << " memory blocks:\n";
        for (int i = 0; i < numBlocks; i++) {
            cin >> blockSize[i];
        }
    }

    void inputProcesses() {
        cout << "Enter sizes of " << numProcesses << " processes:\n";
        for (int i = 0; i < numProcesses; i++) {
            cin >> processSize[i];
        }
    }

    void worstFitAllocate() {
        int tempBlocks[50];
        for (int i = 0; i < numBlocks; i++)
            tempBlocks[i] = blockSize[i];

        for (int i = 0; i < numProcesses; i++)
            allocation[i] = -1;

        for (int i = 0; i < numProcesses; i++) {
            int worstIdx = -1;
            for (int j = 0; j < numBlocks; j++) {
                if (tempBlocks[j] >= processSize[i]) {
                    if (worstIdx == -1 || tempBlocks[j] > tempBlocks[worstIdx])
                        worstIdx = j;
                }
            }
            if (worstIdx != -1) {
                allocation[i] = worstIdx;
                tempBlocks[worstIdx] -= processSize[i];
            }
        }
        cout << "\nMemory allocated using Worst Fit algorithm.\n";
    }

    void displayAllocation() {
        cout << "\n" << setw(12) << "Process No."
             << setw(15) << "Process Size"
             << setw(17) << "Block Allocated" << endl;

        for (int i = 0; i < numProcesses; i++) {
            cout << setw(12) << i + 1
                 << setw(15) << processSize[i]
                 << setw(17);
            if (allocation[i] != -1)
                cout << allocation[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }
};

int main() {
    int numBlocks, numProcesses;

    cout << "Enter number of memory blocks: ";
    cin >> numBlocks;
    cout << "Enter number of processes: ";
    cin >> numProcesses;

    MemoryManager mm(numBlocks, numProcesses);
    mm.inputBlocks();
    mm.inputProcesses();

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Allocate using Worst Fit\n";
        cout << "2. Display Allocation\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                mm.worstFitAllocate();
                break;
            case 2:
                mm.displayAllocation();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
} 

// Worst Fit Memory Allocation Simulator
// Copyright (c) 2025 Ankan Debbarma
// Licensed under the MIT License
