#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int hours;
    cin >> hours;
    long long int inp;
//    int *timeZones = new int[hours];
    long long int timeZones[hours];
    for (int i = 0; i < hours; i++) {
        cin >> inp;
        timeZones[i] = (i == 0 ? inp : timeZones[i - 1] + inp);
    }
    int s;
    int f;
    cin >> s >> f;

    int k = f - s - 1;          //time window
    long long int nonWorking;
    long long int maxWorking = timeZones[hours - 1];
    long long int minNonWorking = timeZones[hours - 1] + 1;
    vector<long long int> bestTimeZones = {1};

    for (int i = 0; i < hours; i++) {
        if (i <= k) nonWorking = maxWorking - timeZones[k] + (i == 0 ? 0 : timeZones[i - 1]);
            else nonWorking = timeZones[i - 1] - timeZones[k];

        if (nonWorking == minNonWorking) {
            bestTimeZones.push_back(i);
        }
        if (nonWorking < minNonWorking) {
            minNonWorking = nonWorking;
            bestTimeZones.clear();
            bestTimeZones.push_back(i);
        }
        k++;
        if (k >= hours) {
            k -= hours;
        }
    }

    int minTime = hours;
    int shift;
    int curTime;
    for(size_t i = 0; i <bestTimeZones.size(); i++) {
        shift  = s - bestTimeZones[i];
        curTime = (shift > 0 ? shift : hours + shift);
        if (minTime > curTime) {
            minTime = curTime;
        }
    }
    cout << minTime;
    return 0;
}
