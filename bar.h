// bar.h
// Alexsander bairez
// Professor Reckinger
// Feb 11, 2021
// Project 3
#include <iostream>
#include <string>
#include "myrandom.h" // used in autograder, do not remove
using namespace std;
// class Bar
class Bar {
 private:
    // defining private variables
    string name;
    int value;
    string category;
    
 public:
    // default constructor:
    Bar() {
        name = "";
        value = 0;
        category = "";
    }
    // Parameter passed in constructor Bar object.
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
    }
    // getName: returns name
	string getName() {
        return name;
	}
    // getValue: returns value
	int getValue() {
        return value;
	}
    // getCategory: returns category
	string getCategory() {
        return category; 
	}
	// less than operator: returns true if (this) is less than
	bool operator<(const Bar& other) const {
        return (this->value < other.value);
	}
	// less than equal to operator: returns true if (this) is less than or equal
	bool operator<=(const Bar& other) const {
        return (this->value <= other.value);
	}
	// less than operator: returns true if (this) is greater than
	bool operator>(const Bar& other) const {
        return (this->value > other.value); 
	}
	// less than operator: returns true if (this) is greater than or equal
	bool operator>=(const Bar& other) const {
        return (this->value >= other.value);
	}
};

