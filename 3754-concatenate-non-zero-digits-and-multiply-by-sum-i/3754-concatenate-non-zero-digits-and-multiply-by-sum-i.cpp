class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        string xx = "";

        while (n > 0) {
            int ld = n % 10;
            n /= 10;

            if (ld != 0) {
                sum += ld;
                xx = to_string(ld) + xx;
            }
        }

        if (xx.empty())
            return 0;

        return stoll(xx) * sum;
    }
};