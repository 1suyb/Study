#include<stdio.h>

int mag(int a, int b, int c);
int GetT(int regi[], const int registerSize);
void RightShift(int regi[], const int registerSize);
int  GetKeySteram(int X, int Y, int Z);
void PrintRegister(int regi[], const int registerSize);
void A51Algorithm(int Xregister[], int Yregister[], int Zregister[], int XregisterSize, int YregisterSize, int ZregisterSzie, int KeyStream[], int KeyStreamSize);

int main() {
	const int XregisterSize = 19;
	const int YregisterSize = 22;
	const int ZregisterSzie = 23;
	const int KeyStreamSize = 32;
	int Xregister[19] = { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 };
	int Yregister[22] = { 1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1 };
	int Zregister[23] = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0 };
	int KeyStream[32] = { 0 };
	
	A51Algorithm(Xregister, Yregister, Zregister, XregisterSize, YregisterSize, ZregisterSzie, KeyStream, KeyStreamSize);

	PrintRegister(Xregister, XregisterSize);
	PrintRegister(Yregister, YregisterSize);
	PrintRegister(Zregister, ZregisterSzie);
	printf("KeyStream : \n");
	PrintRegister(KeyStream, KeyStreamSize);

	return 0;
}

int mag(int a, int b, int c) {
	if (a + b + c > 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int GetT(int regi[], const int registerSize) {
	const int Xsize = 19;
	const int Ysize = 22;
	const int Zsize = 23;
	if (registerSize == Xsize) {
		return regi[13] ^ regi[16] ^ regi[17] ^ regi[18];

	}
	else if (registerSize == Ysize) {
		return regi[20] ^ regi[21];
	}
	else if (registerSize == Zsize) {
		return regi[7] ^ regi[20] ^ regi[21] ^ regi[22];
	}
	else {
		return 2;
	}
}

void RightShift(int regi[], const int registerSize) {
	for (int i = registerSize - 1; i > 0; i--) {
		regi[i] = regi[i - 1];
	}
	regi[0] = GetT(regi, registerSize);
}

int  GetKeySteram(int X, int Y, int Z) {
	return X ^ Y ^ Z;
}

void PrintRegister(int regi[], const int registerSize) {
	for (int i = 0; i < registerSize; i++) {
		printf("%d", regi[i]);
	}
	printf("\n");
}

void A51Algorithm(int Xregister[], int Yregister[], int Zregister[], int XregisterSize, int YregisterSize, int ZregisterSzie, int KeyStream[], int KeyStreamSize) {
	int XmagIndex = 8;
	int YmagIndex = 10;
	int ZmagIndex = 10;

	for (int i = 0; i < KeyStreamSize; i++) {
		int ResultMag = mag(Xregister[XmagIndex], Yregister[YmagIndex], Zregister[ZmagIndex]);
		if (ResultMag == Xregister[XmagIndex]) {
			RightShift(Xregister, XregisterSize);
		}
		if (ResultMag == Yregister[YmagIndex]) {
			RightShift(Yregister, YregisterSize);
		}
		if (ResultMag == Zregister[ZmagIndex]) {
			RightShift(Zregister, ZregisterSzie);
		}
		KeyStream[i] = GetKeySteram(Xregister[XregisterSize - 1], Yregister[YregisterSize - 1], Zregister[ZregisterSzie - 1]);
	}
}