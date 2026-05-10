#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

/**
 * Counts subarrays [i, j] such that max(a[i...j]) - min(a[i...j]) <= k.
 * Uses a sliding window with two monotonic deques for O(n) performance.
 */
long long countSubarrays(int n, const vector<int>& a, int k) {
    long long count = 0;
    deque<int> max_dq, min_dq;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        while (!max_dq.empty() && a[max_dq.back()] <= a[right]) max_dq.pop_back();
        while (!min_dq.empty() && a[min_dq.back()] >= a[right]) min_dq.pop_back();
        max_dq.push_back(right);
        min_dq.push_back(right);

        while (a[max_dq.front()] - a[min_dq.front()] > k) {
            left++;
            if (max_dq.front() < left) max_dq.pop_front();
            if (min_dq.front() < left) min_dq.pop_front();
        }
        
        // Number of subarrays ending at 'right' with length >= 2
        // Subarrays are [left, right], [left+1, right], ..., [right-1, right]
        if (right - left >= 1) {
            count += (right - left);
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n < 2) {
        cout << "unstable" << endl;
        return 0;
    }

    bool stable = true;
    // We only need to check k values where the condition might fail.
    // Since countSubarrays(k) is monotonic, we can optimize.
    // For n=10^6, checking every k is O(n^2). Instead, we can check 
    // critical points or use the fact that if count(k) >= k, then
    // it's likely stable for larger k as well.
    for (int k = 1; k <= n; ++k) {
        if (countSubarrays(n, a, k) < k) {
            stable = false;
            break;
        }
        // Heuristic: If count is already huge, we can skip some k
        if (k > 1000 && countSubarrays(n, a, k) > 2LL * n) {
            // For large n, the condition count >= k becomes trivial 
            // once we have enough small-range subarrays.
            break;
        }
        if(k%100==0) cerr<<k<<"\n";
    }

    cout << (stable ? "stable" : "unstable") << endl;
    return 0;
}
