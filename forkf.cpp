#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(void) {
    int arr[5] = {1, 4, 2, 3, 5};
    pid_t id, pid, cid, ppid; // declearation 

    cout << "array before sorting: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "array after sorting: " << endl;
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    pid = getpid();
    id = fork();

    if (id == 0) { // Child process displays sorted array
    
        cout << "Sorted array in child process:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cid = getpid();
        cout << "\nChild id is: " << cid << endl;
        ppid = getppid();
        cout << "Parent id is: " << ppid << endl;
    } else if (id > 0) { // Parent process
        cout << "Parent id is: " << pid << endl;
    } else { // Error in fork()
        cerr << "Fork failed." << endl;
        return 1;
    }

    return 0;
}

