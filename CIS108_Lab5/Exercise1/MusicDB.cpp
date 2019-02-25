#include "Song.h"
#include<fstream>
#include<string>
#include <sstream>

//create an instance or object of structure
song::songDetail s;  
string FileName = "SongDatabase.txt";

// Function to Display the Menu
void song::displayMenu() 
{
	cout << " add : Add a new song to the music database\n save : Save the music database \n list : List the songs in the music database \n total: Display Total number of songs \n info: Get song Information for given song number \n help : Display this menu  \n exit : Exit the program" << endl;
}

void openInputFile(ifstream &inFile, string inFileName)
{
	//Open the file
	inFile.open(inFileName);

	//Input validation
	if (!inFile)
	{
		cout << "Error to open file." << endl;
		cout << endl;
		return;
	}
}

//Function to add the song
void song::add()
{
	try {
		//Take input from user 
		cout << "Enter the song title: ";
		cin.getline(s.title, 64);
		cout << "Enter artist: ";
		cin.getline(s.artist, 32);
		cout << "Enter album name: ";
		cin.getline(s.album, 64);
		cout << "Enter track#: ";
		cin >> s.trackNumber;
		cout << "Enter year: ";
		cin >> s.releasedYear;
		// cout << "Enter genre: ";
			//cin >> s.x;		
	}
	catch (int a) {
		throw;
	}

}


// Function to List the number of song
void song::list()
{
	song::songDetail arr[8];
	ifstream inFile;
	
	// Call function to read data in file
	openInputFile(inFile, FileName);
	int count = 0;
	string line;
	string data;
	while (std::getline(inFile, line)) 
	{
		std::istringstream iss(line);
		/*arr[count].title = getline(iss, data, '|');
		arr[count].artist = getline(iss, data, '|');
		arr[count].album = getline(iss, data, '|');
		arr[count].trackNumber = getline(iss, data, '|');
		arr[count].releasedYear = getline(iss, data, '|');*/
		iss >> arr[count].title >> arr[count].artist >> arr[count].album >> arr[count].trackNumber >> arr[count].releasedYear;
		count++;
	}
	// Close input file
	inFile.close();

	cout << "There are "<< count <<" songs in the database" << endl;
	for (int i = 0; i < count ; i++)
	{
		cout << "Song #" << (i+1) <<": " << endl;
		cout << "   " << "Title:" << arr[i].title << endl;
		cout << "   " << "Artist:" << arr[i].artist << endl;
		cout << "   " << "Album:" << arr[i].album << endl;
		cout << "   " << "Track#:" << arr[i].trackNumber << endl;
		cout << "   " << "Year:" << arr[i].releasedYear << endl;
		cout << endl;
	}
}


//Function to Save the Song
void song::save()
{

	//read data from structure
	string file_name = "SongDatabase.txt";
	ofstream myFile;
	myFile.open(file_name, std::ios_base::in | std::ios_base::app);
	
	if (myFile.is_open())
	{
		myFile << s.title << " ";
		myFile << s.artist << " ";
		myFile << s.album << " ";
		myFile << s.trackNumber << "  ";
		myFile << s.releasedYear;
		myFile << "\n";
		myFile.close();
	}	
}

// Function to Get Help 

void song::help()
{
	displayMenu();
}

//Function to Get the Total Number of Song

int song::getTotalSong()
{
	ifstream inFile;
	// Call function to read data in file
	openInputFile(inFile, FileName);
	int count = 0;
	string line;

	//Read the data and increment the count to get the total songs
	while (std::getline(inFile, line))
	{
		count++;
	}
	// Close input file
	inFile.close();
	return count;
}


// Function to Get the information about song

void song::getsongInformation(int songNum)
{
	song::songDetail arrInfo[1];
	ifstream inFile;
	// Call function to read data in file
	openInputFile(inFile, FileName);
	int count = 0;
	string line;

	//Read the data and increment the count to get the total songs
	while (std::getline(inFile, line))
	{
		count++;
		if (songNum == count) {
			std::istringstream iss(line);
			iss >> arrInfo[0].title >> arrInfo[0].artist >> arrInfo[0].album >> arrInfo[0].trackNumber >> arrInfo[0].releasedYear;
			cout << "Song #" << count << ": " << endl;
			cout << "   " << "Title:" << arrInfo[0].title << endl;
			cout << "   " << "Artist:" << arrInfo[0].artist << endl;
			cout << "   " << "Album:" << arrInfo[0].album << endl;
			cout << "   " << "Track#:" << arrInfo[0].trackNumber << endl;
			cout << "   " << "Year:" << arrInfo[0].releasedYear << endl;
			cout << endl;
			break;
		}

	}
	// Close input file
	inFile.close();
}