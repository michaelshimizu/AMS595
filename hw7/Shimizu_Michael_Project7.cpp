#include <iostream>
using namespace std;

// 2. Printing a Vector
//      Prints out a given vector
void print_vector(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i < v.size() -1){
            cout << ", ";
        }
    }
    cout << endl;
}

// 4.1 If Prime
bool isprime(int n) {

    bool result;
    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false; // if divisor return false
        }
    }
    return true; // if no divisor return true
}
void test_isprime() {
    std::cout << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';
}

// 4.2 Factorize
std::vector<int> factorize(int n) {
    std::vector<int> answer;

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {         // Check if a factor
            answer.push_back(i);
        }
    }

    return answer;
}

void test_factorize() {
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}

// 4.3 Prime Factorize
std::vector<int> prime_factorize(int n) {
    std::vector<int> answer;
    std::vector<int> factors = factorize(n);

    for (int factor : factors){
        if (isprime(factor)){ // Check if factor is prime
            answer.push_back(factor); // add to result
        }
    }
    
    return answer;
}
void test_prime_factorize() {
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
}

// 5 Pascals Triangle
void print_pascal(int n){
    vector<int> row = {1};

    for (int i = 0; i < n; i++){
        print_vector(row);
        // Find the next row
        row.push_back(1);
        for (int j = row.size() - 2; j > 0; j--){
            row[j] += row[j-1];
        }
    }
}

int main() {

    cout << "Task 1" << endl;
    // 1. Conditional Statements
    int n;

    cout << "Enter a number: ";
    cin >> n;
    // If statement equivalent
    switch (n) {
        case -1:
            cout << "negative one" << endl;
            break;
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "positive one" << endl;
            break;
        default:
            cout << "other value" << endl;
            break;
    }

    cout << "Task 3" << endl;
    // 3. While Loops
    int a = 1;
    int b = 2;
    cout << a; // Print first value
    while (b < 4000000) {
        cout << ", " << b;
        int c = a + b;
        a = b;
        b = c;
    }
    cout << endl;

    cout << "Task 4.1" << endl;
    // 4.1 If Prime Test
    test_isprime();

    cout << "Task 4.2" << endl;
    // 4.2 Factorize test
    test_factorize();

    cout << "Task 4.3" << endl;
    // 4.3 Factorize test
    test_prime_factorize();

    cout << "Task 5" << endl;
    // 5 Pascal Test
    print_pascal(6);
}