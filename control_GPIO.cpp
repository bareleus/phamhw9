/*
control_GPIO.cpp takes 3 arguments

The program takes three command-line arguments:
	1. gpio number (this pin is used for output).
	2. hi or low
	3. gpio number (this pin is used for input)
Example invocations:
./control_GPIO 60 hi 46
*/

#include<iostream>
#include<sstream>
#include<fstream>

#define GPIO_PATH "/sys/class/gpio/"
using namespace std;

// writeGPIO function to read and write in GPIO_PATH
void writeGPIO(string filename, string value){
	fstream fs;
	string path(GPIO_PATH);
	fs.open((path + filename + "/value").c_str(), fstream::out);
	fs << value;
	fs.close();
}

// readGPIO function to read GPIO_PATH
void readGPIO(string filename){
	fstream fs;
	string path(GPIO_PATH);
	fs.open((path + filename + "/value").c_str(), fstream::in);
	string line;
	while(getline(fs, line)){
		cout << "The value of the input is: " << line << endl;} 
	fs.close();
}


int main(int argc, char * argv[]){
	// Usage
	if(argc != 4){
		cout << "Usage is: control_GPIO gpio_number state gpio_number" << endl;
		cout << "gpio number: GPIO number to contro" << endl;
		cout << "state: hi or low" << endl;
		return 4;
	}
	ostringstream s;
	s << "gpio" << argv[1]; // concatenates a number to gpio; e.g. gpio60
	string gpio1 = string(s.str()); // converts stream to string. 
	
	ostringstream ss;
	ss << "gpio" << argv[3]; // concatenates a number to gpio
	string gpio2 = string(ss.str()); // converts stream to string
	
	// Converts argument to string
	string cmd(argv[2]);
	// Check if the arguments is "hi" or "low"
	if (cmd == "hi"){writeGPIO(gpio1, "1");}
	else if (cmd == "low"){writeGPIO(gpio1, "0");}
	// Read a GPIO_number
	readGPIO(gpio2);

}
