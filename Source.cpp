
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

#define random(a,b) a+rand()%(b-a+1)

string GetLine(int x, string url) {
	string str;
	ifstream file(url);
	int index = 1;
	while (getline(file, str)) {
		if (index == x) {
			break;
		}
		index++;
	}
	file.close();
	return str;
}


class Npc
{
	string gender;
	string hair;
	string lips_and_eyelashes;
	string torso;
	string closes;
	string shoes;
	string color_skin;
	string color_closes;
	string color_shoes;
	//int count = 1;
public:
	Npc() {
		this->gender = getGender();
		this->hair = getHair();
		this->lips_and_eyelashes = getLips();
		this->torso = gender;
		this->closes = getCloses();
		this->shoes = getShoes();
		this->color_skin = getColorSkin();
		this->color_closes = getColorAnother();
		this->color_shoes = getColorAnother();
		//this->count=count+1;
	};

	void showNPC() {
		//cout << "Npc: " << count << "\nПол: " << gender << "\nВолосы: " << hair << "\nНакрашенные губы и ресницы: "
		//	<< lips_and_eyelashes << "\nТорс: " << torso << "\nОдежда: " << closes << "\nОбувь: " << shoes << "\nЦвет кожи: " << color_skin
		//	<< "\nЦвет одежды: " << color_closes << "\nЦвет обуви: " << color_shoes << endl;

		cout << "===========================\nNpc "<< "\nПол: " << gender << "\nВолосы: " << hair << "\nНакрашенные губы и ресницы: "
			<< lips_and_eyelashes << "\nТорс: " << torso << "\nОдежда: " << closes << "\nОбувь: " << shoes << "\nЦвет кожи: " << color_skin
			<< "\nЦвет одежды: " << color_closes << "\nЦвет обуви: " << color_shoes << endl;

	}

	string getGender() {
		string line = GetLine(random(2, 3), "files\\gender.csv");
		return line;
		
	};
	string getHair() {
		string line = GetLine(random(2, 8), "files\\hair.csv");
		return line;
	};
	string getLips() {
		string line;
		if (gender == "женский") {
			line = GetLine(random(2, 8), "files\\hair.csv");
		}
		else {
			line = "нет"; 
		}
		return line;
	};
	string getTorso() {
		return gender;
	};
	string getCloses() {
		string line = GetLine(random(2, 8), "files\\clothes.csv");
		return line;
	};
	string getShoes() {
		string line = GetLine(random(2, 4), "files\\shoes.csv");
		return line;
	};
	string getColorSkin() {

		string line = GetLine(random(2, 4), "files\\clothes.csv");
		return line;
	};
	string getColorAnother() {
		string line = GetLine(random(2, 4), "files\\clothes.csv");
		return line;
	};

};


class SaveNPC {
public:
	SaveNPC(Npc npc1) {



	}
};



int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <Npc> array;
	for (int i = 0; i < 30; i++) {
		array.push_back(Npc());
	}
	for (int i = 0; i < 30; i++) {
		array[i].showNPC();
	}
}

