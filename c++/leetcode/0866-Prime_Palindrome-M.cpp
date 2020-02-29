// 866 Prime Palindrome
// https://leetcode.com/problems/prime-palindrome

// version: 1; create time: 2019-12-30 20:21:26;
class Solution {
public:
    /*
    bool isPrime(vector<int>& primes, int num) {
        bool is_prime = true;
        for (const auto& p : primes) {
            if (num % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(num);
        }
        return is_prime;
    }

    bool isPalindrome(int num) {
        std::cout << num << "\n";
        const auto str = std::to_string(num);
        const int n = str.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (str[i] != str[j]) break;
        }
        return i >= j;
    }

    int primePalindrome(int N) {
        vector<int> primes;
        primes.push_back(2);
        for (int i = 3; i < N; i+=2) {
            isPrime(primes, i);
        }
        for (int i = (N / 2) * 2 + 1; ; i+=2) {
            if (!isPrime(primes, i)) continue;
            if (isPalindrome(i)) return i;
        }
        return 0;
    }
    */

    bool isPrime(int n) {
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i +=2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int N) {
        if (N <= 2) {
            return 2;
        }
        if (N <= 11) {
            for (int i = N; i <= 11; ++i) {
                if (isPrime(i)) return i;
            }
        }
        for (int i = 10; ; ++i) {
            auto first = std::to_string(i);
            auto second = first.substr(0, first.size() - 1);
            std::reverse(second.begin(), second.end());
            auto number = std::stoi(first + second);
            if (number < N) continue;
            if (isPrime(number)) return number;
        }
        return 0;
    }
};
