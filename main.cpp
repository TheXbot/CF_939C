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
	int currCount = 0;
    int bestCount = 0;
    int bestTimeZone = 1;
	int firstPointer = 0;
	int lastPointer = timeWindow;

	for (int i = 0; i < timeWindow; i++) {
		currCount += timeZones[i];
		bestCount = currCount;
		bestTimeZone = 1;
	}

	for (; firstPointer < hours;) {
		if (lastPointer >= hours) lastPointer = 0;
        currCount -= timeZones[firstPointer];
        currCount += timeZones[lastPointer];
        if (currCount > bestCount) {
            bestCount = currCount;
            bestTimeZone = firstPointer + 2;
        }
        firstPointer++;
        lastPointer++;
	}

    int shift  = 1 + s - bestTimeZone;
    if (shift > 0) cout << shift;
        else cout << hours + shift;
    return 0;
}
