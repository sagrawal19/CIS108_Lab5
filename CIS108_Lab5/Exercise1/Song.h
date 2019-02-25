#include <iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
namespace song
{
	typedef enum
	{
		Blues,
		Country,
		Electronic,
		Folk,
		HipHop,
		Jazz,
		Latin,
		Pop,
		Rock,
	}genre;

	struct songDetail
	{
		char title[64];
		char artist[32];
		char album[64];
		int trackNumber;
		int releasedYear;
		static genre x;

	};

	void add();
	void list();
	void help();
	void save();
	int getTotalSong();
	int song::getTotalSong();
	void getsongInformation(int num);
	void displayMenu();
}

