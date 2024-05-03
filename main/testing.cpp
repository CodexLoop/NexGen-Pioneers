#include <iostream> 
#include <random>

using namespace std;

int main() {
    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Define the range for the random number
    int lowerBound = 1;
    int upperBound = 100;
    
    vector<int> vec;

    // Create a distribution for the random number within the range
    uniform_int_distribution<int> distribution(lowerBound, upperBound);
    int randomNumber = 0;
    // Generate a random number
    while (vec.size() <  4){
        randomNumber = distribution(gen);
        cout << randomNumber << endl;
        vec.push_back(randomNumber);
    }
    

    // Output the random number
    //cout << "Random number between " << lowerBound << " and " << upperBound << ": " << randomNumber << endl;

    return 0;
}
