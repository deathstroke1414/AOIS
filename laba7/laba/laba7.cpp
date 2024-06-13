#include <iostream>
#include "CM.h"

using namespace std;

int main() {
    ConstMatrix matrix;
    cout << "Initial Matrix:" << endl;
    matrix.printMatrix();

    int row = 2;
    int col = 3;
    cout << "Value at position (" << row << ", " << col << "): " << matrix.getValue(row, col) << endl;

    int newValue = 1;
    matrix.setValue(row, col, newValue);
    cout << "Matrix after setting value at (" << row << ", " << col << ") to " << newValue << ":" << endl;
    matrix.printMatrix();

    int index = 5;
    string word = matrix.getWordFromMatrix(index);
    cout << "Word from matrix at index " << index << ": " << word << endl;

    string addressRowWord = matrix.getAddressRowWord(index);
    cout << "Address row word at index " << index << ": " << addressRowWord << endl;

    string newWord = "1100110011001100";
    matrix.setWord(index, newWord);
    cout << "Matrix after setting new word at index " << index << ":" << endl;
    matrix.printMatrix();

    string searchedWord = "1100110011001100";
    bool condition = true;  
    int position = matrix.findWordPosition(searchedWord, condition);
    if (position != -1) {
        cout << "Position of the word " << searchedWord << " with condition " << condition << ": " << position << endl;
    }
    else {
        cout << "Word " << searchedWord << " not found with condition " << condition << endl;
    }

    string key = "110";
    string sumResult = matrix.summAB(key);
    cout << "Result after summation operation with key " << key << ": " << sumResult << endl;
    matrix.printMatrix();

    return 0;
}
