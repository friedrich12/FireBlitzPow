#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include<map>


enum StringValues{
	evString1,
	evString2,
	evString3,
	evString4
};

std::map<std::string, StringValues> mymap;

void get_input();
void setup();
void initalize();

using namespace std;

int main(){
	initalize();
	int openclose;

	cout << "This is Not A Virus Please Add An Exception In Your Firewall" << endl;
	cout << "Welcome to the command console press F1 to open. " << endl;
	system("PAUSE");

	HWND window = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(window, SW_HIDE);
	while (true) {
		if (GetAsyncKeyState(VK_F1) & 0x8000)
		{
			ShowWindow(window, SW_SHOW);
			break;
		}
	}
	
	setup();
	get_input();
	return 0;

}
void get_input() {
	string pow;
	cout << "Enter Command\n";
	cin >> pow;

	switch (mymap[pow]) {
		case evString1:
			cout << "This will close everything...";

			break;
		default:
			cout << "Didn't get that type help for commands\n";
			break;
	}
}

void initalize() {
	mymap["CloseALL"] = evString1;
	mymap["help"] = evString2;
	mymap["Power"] = evString3;
	mymap["Virus"] = evString4;
}


void setup() {
	string windowsversion;
	ifstream in;

	in.open("data.txt");
	if (in.fail()) {
		cout << "Failed to open file. \n";
	}

	cout << "This Will Setup The Program\n";
	cout << "Enter Windows Version\n";
	in >> windowsversion;

	in.close();
	cout << "Okay thats all we need for now\n";
}