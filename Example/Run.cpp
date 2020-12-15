#include<iostream>
#include <sstream>
#include<vector>
#include <algorithm>

std::string multiplication(int value); // разложение в ряд множителей

bool isPrime(int num); // простое число

static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2);


int main() {
    std::cout << 4;

    return 0;
}


static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2) {
    std::vector<std::string> result;
    for (std::string word1 : array1) {
        for (std::string word2 : array2) {
            if (word2.find(word1) != std::string::npos) {
                result.push_back(word1);
                break;
            }
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}


bool isPrime(int num) {
    if (num < 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return (true);
    return false;
}

std::string multiplication(int value){
    int multiplier = 2;
    int power = 0;
    std::stringstream answer;
    while (value > 1) {
        while (value % multiplier == 0) {
            power++;
            value /= multiplier;
        }
        if (power > 0) {
            answer << '(' << multiplier;
            if (power > 1) {
                answer << "**" << power;
            }
            answer << ')';
            power = 0;
        }
        multiplier++;
    }

	return answer.str();
}

