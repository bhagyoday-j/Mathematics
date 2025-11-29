#include <iostream>
using namespace std;
 
int calculate_multiplicative_inverse(int M1, int m1) {
    // x such that (M1 * x) % m1 == 1
    for (int x = 1; x < m1; x++) {
        if ((M1 * x) % m1 == 1)
            return x;
    }
    // If no inverse exists (should not happen if m1 and M1 are coprime)
    return -1;
}

int calculate_first_time_all_traffic_light_turn_green(int repating_cycle[], int offset[]) {
    int m1 = repating_cycle[0];
    int m2 = repating_cycle[1];
    int m3 = repating_cycle[2];

    int a1 = offset[0];
    int a2 = offset[1];
    int a3 = offset[2];

    int M = m1 * m2 * m3;

    int M1 = M / m1;
    int M2 = M / m2;
    int M3 = M / m3;

    int M1inverse = calculate_multiplicative_inverse(M1, m1);
    int M2inverse = calculate_multiplicative_inverse(M2, m2);
    int M3inverse = calculate_multiplicative_inverse(M3, m3);

    int t = (a1 * M1 * M1inverse + a2 * M2 * M2inverse + a3 * M3 * M3inverse) % M;

    return t;
}

int main() {
    int repating_cycle[3];
    int offset[3];

    cout << "Enter repeating cycles of each traffic light (space separated): ";
    cin >> repating_cycle[0] >> repating_cycle[1] >> repating_cycle[2];

    cout << "\nEnter offsets: ";
    cin >> offset[0] >> offset[1] >> offset[2];

    int t = calculate_first_time_all_traffic_light_turn_green(repating_cycle, offset);

    cout << "All signals turn green at: " << t << " min" << endl;

    return 0;
}
