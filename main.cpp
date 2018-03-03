#include <iostream>

using namespace std;

int main() {
    int hours;
    cin >> hours;
    int *timeZones = new int[hours];
    for (int i = 0; i < hours; i++) {
        cin >> timeZones[i];
    }
    int s;
    int f;
    cin >> s >> f;
    int timeWindow = f - s;
    int bestCount = 0;
    int bestTimeZone = 1;
    int currCount;
    for (int i = 0; i < hours; i++) {
        currCount = 0;
        for (int j = 0; j < timeWindow; j++) {
            if ((i + j) < (hours)) currCount += timeZones[i + j];
                else currCount += timeZones[(i + j) - hours];
        }
        if (currCount > bestCount) {
            bestCount = currCount;
            bestTimeZone = i + 1;
        }
    }
    int shift  = 1 + s - bestTimeZone;
    if (shift > 0) cout << shift;
        else cout << hours + shift;
    return 0;
}
