#include <iostream>

using namespace std;

int main() {
    int hours;
    cin >> hours;
    int inp;
//    int *timeZones = new int[hours];
    int timeZones[hours];
    for (int i = 0; i < hours; i++) {
        cin >> inp;
        timeZones[i] = (i == 0 ? inp : timeZones[i - 1] + inp);
    }
    int s;
    int f;
    cin >> s >> f;

    int k = f - s - 1;          //time window
    int bestTimeZone = 1;
    int nonWorking;
    int maxWorking = timeZones[hours - 1];
    int minNonWorking = timeZones[hours - 1] + 1;

    for (int i = 0; i < hours; i++) {
        if (i < k) nonWorking = maxWorking - timeZones[k] + (i == 0 ? 0 : timeZones[i - 1]);
            else nonWorking = timeZones[i - 1] - timeZones[k];

        if (nonWorking < minNonWorking) {
            minNonWorking = nonWorking;
            bestTimeZone = i;
        }
        k++;
        if (k >= hours) {
            k -= hours;
        }
    }

    int shift  = s - bestTimeZone;
    if (shift > 0) cout << shift;
        else cout << hours + shift;
    return 0;
}
