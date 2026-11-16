class Solution {
    /** 1524. Number of Sub-arrays With Odd Sum
     * https://leetcode.cn/problems/number-of-sub-arrays-with-odd-sum/
     */
public:
    int numOfSubarrays(vector<int>& arr) {
        const int N = arr.size();
        long long res = 0;
        vector<int> oc(N), ec(N);
        for (int i = 1; i < N; ++i) {
            arr[i] += arr[i - 1];
            if (arr[i - 1] % 2) {
                oc[i] += oc[i - 1] + 1;
                ec[i] = ec[i - 1];
            } else {
                oc[i] = oc[i - 1];
                ec[i] += ec[i - 1] + 1;
            }
            if (arr[i] % 2) res += ec[i] + 1;
            else res += oc[i];
        }
        if (arr[0] % 2) ++res;
        // for (auto x: arr) { cout << x << ','; } cout << endl;
        // for (auto x: oc) { cout << x << ','; } cout << endl;
        // for (auto x: ec) { cout << x << ','; } cout << endl;
        return res % (1000000007);
    }
};

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int N = arr.size();
        long long res = 0;
        int oc = 0, ec = 1;
        int psum = 0;
        for (int a: arr) {
            psum += a;
            if (psum % 2) {
                res += ec;
                ++oc;
            } else {
                res += oc;
                ++ec;
            }
        }
        return res % (1000000007);
    }
};

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int N = arr.size();
        int oc = 0, ec = 1;
        int psum = 0;
        for (int a: arr) {
            psum += a;
            if (psum % 2) ++oc;
            else ++ec;
        }
        return (long long) oc * ec % (1000000007);
    }
};