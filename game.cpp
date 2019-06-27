#include <iostream>
#include <time.h>
using namespace std;

enum AI_MODE {
	AI_EASY=1,
	AI_HARD
};


int main() {
	srand((unsigned int)time(NULL));

	int pn[25] = {}; //����
	int an[25] = {}; //AI

	for (int i = 0; i < 25; i++) {
		pn[i] = i + 1;
		an[i] = i + 1;
	}

	int tmp, id1, id2; //���þ˰������� �߼����ش�
	for (int i = 0; i < 100; i++) {
		id1 = rand() % 25;
		id2 = rand() % 25;

		tmp = pn[id1]; //������ 
		pn[id1] = pn[id2];
		pn[id2] = tmp;

		id1 = rand() % 25;
		id2 = rand() % 25;

		tmp = an[id1]; //AI��
		an[id1] = an[id2];
		an[id2] = tmp;

	}
	int mode;
	int none[25] = {};
	int noneselect = 0; //AI ����������������

	while (1) {
		system("cls");
		cout << "=============PLAYER VS AI ================" << endl<<endl<<endl;
		cout << "============= BINGO  GAME ================" << endl;
		cout << endl << endl;
		cout << "AI���̵��� ������.(1.EASY 2.HARD):";
		cin >> mode;

		if (mode == AI_EASY || mode == AI_HARD)
			break;
		else
			continue;
	}

	int pBin = 0;
	int aBin = 0;

	while (1) {

		int pInput; //�����Է�
		system("cls");
		
		cout << "==============PLAYER==============" << endl << endl;

		for (int i = 0; i < 5; i++) { //���� �迭�� ȭ�鿡ǥ��
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
			cout << "AI���̵�:EASY" << endl;
		else if (mode == AI_HARD)
			cout << "AI���̵�:HARD" << endl;

		cout << "================AI================" << endl << endl;
		for (int i = 0; i < 5; i++) { //AI �迭�� ȭ�鿡ǥ��
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
			cout << "PLAYER�ǽ¸�!";
			break;
		}

		else if (aBin > 4) {
			cout << endl;
			cout << "AI�ǽ¸�!";
			break;
		}
		cout << endl;
		cout << "����(PLAYER:)Bingo��:" << pBin << endl;
		cout << "����(AI:)Bingo��:" << aBin << endl << endl;
		cout << "���ڸ��Է��ϼ���(0:�Է½� ����)" << endl;
		cin >> pInput;



		if (pInput < 0 || pInput>25)
			continue;

		else if (pInput == 0)
			break;

		bool jungbok = true;

		for (int i = 0; i < 25; i++) { //�Է��Ѱ���ã�Ƽ� �����ʿ� INT_MAX����
			if (pn[i] == pInput) {
				jungbok = false;

				pn[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; i++) { //�Է��Ѱ���ã�Ƽ� AI�ʿ� INT_MAX����
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

		for (int i = 0; i < 25; i++) { //�Է��Ѱ���ã�Ƽ� �����ʿ� INT_MAX����
			if (pn[i] == aInput) {
				jungbok = false;

				pn[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; i++) { //�Է��Ѱ���ã�Ƽ� AI�ʿ� INT_MAX����
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
				if (pn[i * 5 + j] == INT_MAX) //���������� ����
					++star1;
				
				if (pn[j * 5 + i] == INT_MAX) //���������ٺ���
					++star2;
				
				if (an[i * 5 + j] == INT_MAX) //AI������ ����
					++aista1;

				if (an[j * 5 + i] == INT_MAX) //AI�����ٺ���
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
		for (int i = 0; i < 25; i += 6) { // �ٹ��� ����
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
		for (int i = 4; i < 21; i += 4) { // �׹��� ����
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