#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testLessThanOperator() {
    Bar a("Chicago", 9234324, "US");
    Bar b("New York", 9234324, "US");
    Bar c("San Diego", 123, "US");
    Bar d("San Francisco", 12345, "US");
    Bar e("LA", 123, "US");
    
    if(c < b){
    cout << "testLessThanOperator: passed!" << endl;
    return true;
    }else{
        return false;
    }
}

bool testLessThanEqualOperator() {
    Bar a("Chicago", 9234324, "US");
    Bar b("New York", 9234324, "US");
    Bar c("San Diego", 123, "US");
    Bar d("San Francisco", 12345, "US");
    Bar e("LA", 123, "US");
    
    if(c <= b && a <= b){
    cout << "testLessThanEqualOperator: passed!" << endl;
    return true;
    }else{
        return false;
    }
}

bool testGreaterThanOperator() {
    Bar a("Chicago", 9234324, "US");
    Bar b("New York", 9234324, "US");
    Bar c("San Diego", 123, "US");
    Bar d("San Francisco", 12345, "US");
    Bar e("LA", 123, "US");
    
    if(d > e){
    cout << "testGreaterThanOperator: passed!" << endl;
    return true;
    }else{
        return false;
    }
}

bool testGreaterThanEqualOperator() {
    Bar a("Chicago", 9234324, "US");
    Bar b("New York", 9234324, "US");
    Bar c("San Diego", 123, "US");
    Bar d("San Francisco", 12345, "US");
    Bar e("LA", 123, "US");
    
    if(a >= b && d >= e){
    cout << "testGreaterThanEqualOperator: passed!" << endl;
    return true;
    }else{
        return false;
    }
}

bool testBarChartDefaultConstructor() {
	BarChart b;
	
	if (b.getSize() != 0) {
    	cout << "testBarChartDefaultConstructor: getSize failed" << endl;
    	return false;
    } else if (b.getFrame() != "") {
    	cout << "testBarChartDefaultConstructor: getFrame failed" << endl;
    	return false;
    }
    cout << "testBarChartDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarChartOverConstructor() {
	BarChart b(4);
	
	if (b.getSize() != 0) {
    	cout << "testBarChartOverConstructor: getSize failed" << endl;
    	return false;
    } else if (b.getFrame() != "") {
    	cout << "testBarChartOverConstructor: getFrame failed" << endl;
    	return false;
    }
    cout << "testBarChartOverConstructor: all passed!" << endl;
    return true;
}

void testAddBarAndDump() {
    cout << "testAddBarAndDump:" << endl;
    BarChart c(5);
    c.setFrame("1990");
    cout << c.addBar("Chicago", 1234, "US") << endl;
    cout << c.addBar("Milwaukee", 345222, "US")<< endl;
    cout << c.addBar("NYC", 3264758, "US") << endl;
    cout << c.addBar("Atlanta", 222, "US") << endl;
    cout << c.addBar("LA", 4758, "US") << endl;    
    c.dump(cout);
    
}

bool testCopyConstructorAndAtOperator() {
    BarChart d(2);
    BarChart e(4);
    d.addBar("Chicago", 1234, "US");
    d.addBar("Milwaukee", 345222, "US");    
    e = d;
    
    if(e[0].getCategory() != "US"){
        cout << "testCopyConstructorAndAtOperator: category failed!" << endl;
        return false;
    } else if(e[0].getValue() != 1234){
        cout << "testCopyConstructorAndAtOperator: value failed" << endl;
        return false;
    } else if(e[0].getName() != "Chicago"){
        cout << "testCopyConstructorAndAtOperator: Name failed" << endl;
        return false;
    }
    
    if(e[1].getCategory() != "US"){
        cout << "testCopyConstructorAndAtOperator: category failed!" << endl;
        return false;
    } else if(e[1].getValue() != 345222){
        cout << "testCopyConstructorAndAtOperator: value failed" << endl;
        return false;
    } else if(e[1].getName() != "Milwaukee"){
        cout << "testCopyConstructorAndAtOperator: Name failed" << endl;
        return false;
    }
    cout << "testCopyConstructorAndAtOperator: Passed" << endl;
    return true;
}

bool testClear() {
    BarChart f(2);
    f.addBar("Chicago", 1234, "US");
    f.addBar("Milwaukee", 345222, "US"); 
    f.clear();
    
    if(f.getSize() != 0 ){
        cout << "testClear: size failed" << endl;
        return false;
    }else if(f.getFrame() != ""){
        cout << "testClear: frame failed" << endl;
        return false;        
    }
    cout << "testClear: passed" << endl;
    return true;
}

bool testSetAndGetFrame() {
    BarChart h;
    h.setFrame("frame");
    
    if(h.getFrame() != "frame"){
        cout << "testSetAndGetFrame: Failed" << endl;
        return false;
    }
    cout << "testSetAndGetFrame: Passed!" << endl;
    return true;
}

void testGraph(){
    BarChart bc(4);
	string red("\033[1;36m");
    string blue("\033[1;33m");
    map<string, string> colorMap;
     colorMap["US"] = RED;
     colorMap["France"] = BLUE;

    bc.addBar("Milwaukee", 1200, "US");
    bc.addBar("Chicago", 1300, "US");
    bc.addBar("Paris", 1200, "France");
    bc.addBar("Ontario", 800, "Canada");
    bc.graph(cout, colorMap, 4);
}

bool testBarChartAnimateConstructor() {
    BarChartAnimate bc("The most populous cities in the world from 1500 to 2018", "Population (thousands)", "Sources: SEDAC; United Nations; Demographia");
    //bc.addFrame();
    if (bc.getSize() != 0){
    cout << "testBarChartAnimateCons: failed!" << endl;
        return false;
    }
    cout << "testBarChartAnimateCons: passed!" << endl;
    return true;
}

bool testGetSize() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	bca.addFrame(inFile);
	
	if (bca.getSize() == 1){
	    cout << "testGetSize: passed!" << endl;
	    return true;
	}
	return false;
}

void testAtOperator() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	bca.addFrame(inFile);
    
    for (int i = 0; i < bca.getSize(); i++){
        cout << "testAtOperator: " << bca[i].getSize() << endl;
    }
}

void testAddFrame() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
    map<string, string> colorMap;
    colorMap["US"] = RED;
    colorMap["France"] = BLUE;
	BarChartAnimate bca(title, xlabel, source);
	
	bca.addFrame(inFile);
	
	for (int i =0; i < bca.getSize(); i++) {
	   bca[i].graph(cout, colorMap, 12);
	  // cout << bca[i].getFrame() << endl;
	}
}

void testAnimate() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	int i = 0;

	BarChartAnimate bca(title, xlabel, source);
	while(i < 10){
	    bca.addFrame(inFile);
	    i++;
	}
	bca.animate(cout, 12, -1);
	
}



int main() {
    
    // bar.h 
	testBarDefaultConstructor();
	testBarParamConstructor();
	testLessThanOperator();
	testLessThanEqualOperator();
	testGreaterThanOperator();
	testGreaterThanEqualOperator();
	
	// barchart.h 
	testBarChartDefaultConstructor();
	testBarChartOverConstructor();
	testAddBarAndDump();
	testCopyConstructorAndAtOperator();
	testClear();
	testSetAndGetFrame();
	
	// barchartanimate.h 
// 	testBarChartAnimateConstructor();
  	testAddFrame();
//  	testAnimate();
//  	testAtOperator();
//  	testGetSize();
 	
	// graph function
    testGraph();
    
	
	

    return 0;
}