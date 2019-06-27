#include <iostream>
#include <time.h>
using namespace std;

enum AI_MODE {
	AI_EASY=1,
	AI_HARD
};


int main() {
	srand((unsigned int)time(NULL));

	int pn[25] = {}; //유저
	int an[25] = {}; //AI

	for (int i = 0; i < 25; i++) {
		pn[i] = i + 1;
		an[i] = i + 1;
	}

	int tmp, id1, id2; //셔플알고리즘으로 잘섞어준다
	for (int i = 0; i < 100; i++) {
		id1 = rand() % 25;
		id2 = rand() % 25;

		tmp = pn[id1]; //유저쪽 
		pn[id1] = pn[id2];
		pn[id2] = tmp;

		id1 = rand() % 25;
		id2 = rand() % 25;

		tmp = an[id1]; //AI쪽
		an[id1] = an[id2];
		an[id2] = tmp;

	}
	int mode;
	int none[25] = {};
	int noneselect = 0; //AI 선택하지않은갯수

	while (1) {
		system("cls");
		cout << "=============PLAYER VS AI ================" << endl<<endl<<endl;
		cout << "============= BINGO  GAME ================" << endl;
		cout << endl << endl;
		cout << "AI난이도를 고르세요.(1.EASY 2.HARD):";
		cin >> mode;

		if (mode == AI_EASY || mode == AI_HARD)
			break;
		else
			continue;
	}

	int pBin = 0;
	int aBin = 0;

	while (1) {

		int pInput; //유저입력
		system("cls");
		
		cout << "==============PLAYER==============" << endl << endl;

		for (int i = 0; i < 5; i++) { //유저 배열을 화면에표시
			for (int j = 0; j < 5; j++) {
				if (pn[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << pn[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << endl << endl;
		if (mode == AI_EASY)
			cout << "AI난이도:EASY" << endl;
		else if (mode == AI_HARD)
			cout << "AI난이도:HARD" << endl;

		cout << "================AI================" << endl << endl;
		for (int i = 0; i < 5; i++) { //AI 배열을 화면에표시
			for (int j = 0; j < 5; j++) {
				if (an[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << an[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		if (pBin > 4) {
			cout << endl;
			cout << "PLAYER의승리!";
			break;
		}

		else if (aBin > 4) {
			cout << endl;
			cout << "AI의승리!";
			break;
		}
		cout << endl;
		cout << "현재(PLAYER:)Bingo수:" << pBin << endl;
		cout << "현재(AI:)Bingo수:" << aBin << endl << endl;
		cout << "숫자를입력하세요(0:입력시 종료)" << endl;
		cin >> pInput;



		if (pInput < 0 || pInput>25)
			continue;

		else if (pInput == 0)
			break;

		bool jungbok = true;

		for (int i = 0; i < 25; i++) { //입력한값을찾아서 유저쪽에 INT_MAX대입
			if (pn[i] == pInput) {
				jungbok = false;

				pn[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; i++) { //입력한값을찾아서 AI쪽에 INT_MAX대입
			if (an[i] == pInput) {
				jungbok = false;

				an[i] = INT_MAX;
				break;
			}
		}


		if (jungbok)
			continue;

		int aInput;

		switch (mode)
		{
		case AI_EASY:
			noneselect = 0;
			for (int i = 0; i < 25; i++) {
				if (an[i] != INT_MAX)
					none[noneselect] = an[i];
				++noneselect;
			}

			aInput = none[rand() % noneselect];

			break;
			

		case AI_HARD:
			break;
		}

		for (int i = 0; i < 25; i++) { //입력한값을찾아서 유저쪽에 INT_MAX대입
			if (pn[i] == aInput) {
				jungbok = false;

				pn[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; i++) { //입력한값을찾아서 AI쪽에 INT_MAX대입
			if (an[i] == aInput) {
				jungbok = false;

				an[i] = INT_MAX;
				break;
			}
		}
	

		pBin = 0;
		aBin = 0;
		int star1 = 0, star2 = 0;
		int aista1 = 0, aista2 = 0;

		for (int i = 0; i < 5; i++) { 
			int star1 = star2 = 0;
			int aista1 = aista2 = 0;
			for (int j = 0; j < 5; j++) {
				if (pn[i * 5 + j] == INT_MAX) //유저가로줄 빙고
					++star1;
				
				if (pn[j * 5 + i] == INT_MAX) //유저세로줄빙고
					++star2;
				
				if (an[i * 5 + j] == INT_MAX) //AI가로줄 빙고
					++aista1;

				if (an[j * 5 + i] == INT_MAX) //AI세로줄빙고
					++aista2;
				
			}
			if (star1 == 5) {
				++pBin;
			}

			if (star2 == 5) {
				++pBin;
			}	

			if (aista1 == 5) {
				++aBin;
			}
			if (aista2 == 5) {
				++aBin;
			}
		}

		star1 = aista1 = 0;
		for (int i = 0; i < 25; i += 6) { // ↘방향 빙고
			if (pn[i] == INT_MAX)
				++star1;
			if (an[i] == INT_MAX)
				++aista1;
			if (star1 == 5)
				++pBin;
			if (aista1 == 5)
				++aBin;
		}


		star2 = aista2=0;
		for (int i = 4; i < 21; i += 4) { // ↙방향 빙고
			if (pn[i] == INT_MAX)
				++star2;
			if (an[i] == INT_MAX)
				++aista2;
			if (star2 == 5)
				++pBin;
			if (aista2 == 5)
				++aBin;
		}
	
	}
	cout << endl;

}