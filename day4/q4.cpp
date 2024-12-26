#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int computeSi(int M1, int M2) {
    return ((M1 ^ M2) ^ (M1 | M2)) * (M1 ^ M2);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int maxSi = INT_MIN;
    
    for (int L = 0; L < N; L++) {
        int M1 = INT_MAX, M2 = INT_MAX;
        
        for (int R = L; R < N; R++) {
            if (A[R] < M1) {
                M2 = M1;
                M1 = A[R];
            } else if (A[R] < M2) {
                M2 = A[R];
            }

            if (M2 != INT_MAX) {
                maxSi = max(maxSi, computeSi(M1, M2));
            }
        }
    }
    
    cout << maxSi << endl;
    return 0;
}