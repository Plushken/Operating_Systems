#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int arSize = 0;
int* arr = nullptr;
int minimum = 0;
int maximum = 0;
int minIdx = 0;
int maxIdx = 0;
int av = 0;

void min_max() {
    minimum = arr[0];
    maximum = arr[0];
    for (int i = 0; i < arSize; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
            minIdx = i;
        }
        this_thread::sleep_for(chrono::milliseconds(7));
        if (arr[i] > maximum) {
            maximum = arr[i];
            maxIdx = i;
        }
        this_thread::sleep_for(chrono::milliseconds(7));
    }
    cout << "MIN element: " << minimum << endl;
    cout << "MAX element: " << maximum << endl;
}

void average() {
    av = 0;
    for (int i = 0; i < arSize; i++) {
        av += arr[i];
        this_thread::sleep_for(chrono::milliseconds(12));
    }
    av /= arSize;
    cout << "Average: " << av << endl;
}