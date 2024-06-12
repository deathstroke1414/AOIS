#include <iostream>
#include "HT.h"

int main() {
    HashTable hashTable;
    int choice;
    string key, value;

    hashTable.insert("Algebra", "A branch of mathematics that deals with symbols and the rules for manipulating those symbols");
    hashTable.insert("Geometry", "A branch of mathematics concerned with questions of shape, size, relative position of figures, and the properties of space");
    hashTable.insert("Trigonometry", "A branch of mathematics that studies relationships involving lengths and angles of triangles");
    hashTable.insert("Differential", "An operator in mathematics, representing the derivative of a function");
    hashTable.insert("Integral", "An operator in mathematics, the reverse of differentiation");
    hashTable.insert("Matrix", "A rectangular array of numbers");
    hashTable.insert("Vector", "A quantity having direction as well as magnitude");
    hashTable.insert("Scalar", "A quantity that is fully described by a magnitude alone");
    hashTable.insert("Limit", "The value that a function or sequence approaches as the input or index approaches some value");
    hashTable.insert("Derivative", "A measure of how a function changes as its input changes");
    hashTable.insert("Differential Equation", "An equation involving derivatives of a function or functions");
    hashTable.insert("Linear Algebra", "The branch of mathematics concerning vector spaces and linear mappings between such spaces");
    hashTable.insert("Statistics", "The practice or science of collecting and analyzing numerical data in large quantities");
    hashTable.insert("Probability Theory", "A branch of mathematics concerned with probability");
    hashTable.insert("Complex Number", "A number that can be expressed in the form a + bi, where a and b are real numbers, and i is a solution of the equation x² = −1");
    hashTable.insert("Factorial", "The product of an integer and all the integers below it");
    hashTable.insert("Variable", "A symbol representing a quantity that may change");
    hashTable.insert("Constant", "A quantity that does not change");
    hashTable.insert("Function", "A relation between a set of inputs and a set of permissible outputs with the property that each input is related to exactly one output");
    hashTable.display();
    return 0;
}