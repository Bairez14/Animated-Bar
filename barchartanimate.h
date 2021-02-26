// Alexsander bairez
// Professor Reckinger
// Feb 11, 2021
// Project 3
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"
using namespace std;
//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    int counter = 0;

 public:
    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = new BarChart[4];
        size = 0;
        capacity = 4;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
    }

    // destructor:
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    virtual ~BarChartAnimate() {
        if(barcharts != nullptr){
            delete[] barcharts;
        }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
        string garbage = "";
        // size of bars
        string strSize;
        int size1;
        // info for each bar 
        string name = "";
        string v;
        int value = 0;
        string category = "";
        string frame = "";
        // checking for room
    	if (size == capacity) {
    	    int newCapacity = capacity * 2;
    	    BarChart* newBarChart = new BarChart[newCapacity];
    	    // copying everything to new array
    	    for(int i = 0; i < size; i++) {
    	        newBarChart[i] = barcharts[i];
    	    }
    	    // deleting old array and pointing variables to new array
    	    delete[] barcharts;
    	    barcharts = newBarChart;
    	    capacity = newCapacity;
    	}
    	// there is space available in array
        getline(file,garbage);
        if( file.eof() ) {
            return;
        }
        getline(file,strSize);
        size1 = stoi(strSize);
        BarChart bc(size1);
        // getting info for each frame
        for(int i= 0; i < size1; i++) {
            getline(file, frame, ',');
            getline(file, name, ',');
            getline(file,garbage, ',');
            getline(file, v, ',');
            getline(file, category);
            value = stoi(v);
             if (colorMap.count(category) == 0 && counter < 7) {
                colorMap[category] = COLORS[counter];
                counter++;
             } else if (colorMap.count(category) == 0 && counter == 7) {
                counter = 0;
                colorMap[category] = COLORS[counter];
                counter++;
                }
            bc.setFrame(frame);
            //cout << "Frame: " << bc.getFrame() << endl;
            bc.addBar(name, value, category);
        }
        //add to barchart array 
        barcharts[size] = bc; 
        size++;
    }
    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
		
		// checking to see if we are looping through the whole file
        if (endIter == -1){
            endIter = size;
        }
        cout << size << endl;
        // looping and animating using graph(); 
        for ( int i =0; i < endIter; i++) {
            usleep(3*microsecond);
            output << CLEARCONSOLE;
            // cout title and source with newline
            output << BLACK << title << endl;
            output << BLACK << source << endl;
            barcharts[i].graph(output, colorMap, top);
            output << BLACK << xlabel << endl;
            output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
        }
	}

    // Public member function.
    // Returns the size of the BarChartAnimate object.
    int getSize() {
        return size;
    }
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    BarChart& operator[](int i) {
        if(i < 0 || i >= size){
            throw out_of_range("BarChartAnimate: i out of bounds");
        }
        return barcharts[i];
    }
};
