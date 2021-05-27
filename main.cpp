#include<iostream>
using namespace std;

int bank(int Max[5][4]);

int main() {
	int Max[5][4] = { { 6,0,1,2 }, { 1,7,5,0 }, { 2,3,5,6 }, { 1,6,5,3 }, { 1,6,5,6 } };

	bank(Max);

	cout << endl << "Request for (1, 2, 0, 0) by P4" << endl << endl;

	Max[4][0] += 1;
	Max[4][1] += 2;

	bank(Max);
	return 0;
}


int bank(int Max[5][4]) {
	int  Allocation[5][4] = { {4,0,0,1},{1,1,0,0},{1,2,5,4},{0,6,3,3},{0,2,1,2} };
	int  Available[4] = { 3,2,1,1 };
	int Need[5][4];
	int answer[5];
	int finished[5];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			Need[i][j] = Max[i][j] - Allocation[i][j];
		}
		finished[i] = 0;
	}
	int index = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (finished[j] == 0) {
				bool check = false;
				for (int k = 0; k < 4; k++) {
					if (Need[j][k] > Available[k]) {
						check = true;
						break;
					}
				}
				if (!check) {
					answer[index++] = j;
					for (int l = 0; l < 4; l++)
						Available[l] += Allocation[j][l];

					finished[j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (finished[i] == 0) {
			cout << "Not Safe" << endl;
			return 0;
		}
	}

	cout << "Safe" << endl;
	for (int i = 0; i < 5; i++) {
		if (i == 4)
			cout << "P" << answer[i] << endl;
		else
			cout << "P" << answer[i] << "  ->  ";
	}
	return 0;
}