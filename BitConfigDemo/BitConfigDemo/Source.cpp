#include <iostream>
#include <bitset>
using namespace std;

#define BIT_SET(a,b)   ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b)  ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) &  (1<<(b)))

void BitOperationFunc1() {

	unsigned char ucTmp = 255;
	bitset<8> bitvec;

	bitvec = ucTmp;

	cout << "BitOperationFunc1" << endl << endl;
	cout << "Original value : " << endl;
	cout << bitvec << endl << endl;

	int nRet = BIT_CHECK(ucTmp, 1);
	cout << "Result of BIT_CHECK(ucTmp, 1) : " << endl;
	cout << nRet << endl << endl;

	BIT_CLEAR(ucTmp, 1);
	bitvec = ucTmp;
	cout << "After BIT_CLEAR(ucTmp, 1) : " << endl;
	cout << bitvec << endl << endl;

	nRet = BIT_CHECK(ucTmp, 1);
	cout << "Result of BIT_CHECK(ucTmp, 1) : " << endl;
	cout << nRet << endl << endl;

	BIT_SET(ucTmp, 1);
	bitvec = ucTmp;
	cout << "After BIT_SET(ucTmp, 1) : " << endl;
	cout << bitvec << endl << endl;

	BIT_FLIP(ucTmp, 1);
	bitvec = ucTmp;
	cout << "After BIT_FLIP(ucTmp, 1) : " << endl;
	cout << bitvec << endl << endl;

	BIT_FLIP(ucTmp, 1);
	bitvec = ucTmp;
	cout << "After BIT_FLIP(ucTmp, 1) : " << endl;
	cout << bitvec << endl << endl;
}

void BitOperationFunc2() {

	unsigned char ucTmp = 255;
	bitset<8> bitvec;

	bitvec = 255;
	cout << "1's count : " << endl << bitvec.count() << endl << endl;

	bool bRet = bitvec.test(1);
	cout << "Result of bitvec.test(1) : " << endl << bRet << endl << endl;

	bitvec.flip(1);
	cout << "After bitvec.flip(1) : " << endl << bitvec << endl << endl;

	bitvec.flip();
	cout << "After bitvec.flip() : " << endl << bitvec << endl << endl;
	bitvec.flip();
	cout << "After bitvec.flip() : " << endl << bitvec << endl << endl;

	bitvec.set(1);
	cout << "After bitvec.set(1) : " << endl << bitvec << endl << endl;

	bitvec.reset(1);
	cout << "After bitvec.reset(1) : " << endl << bitvec << endl << endl;

	bitvec.set();
	cout << "After bitvec.set(1) : " << endl << bitvec << endl << endl;

	bitvec.reset();
	cout << "After bitvec.reset(1) : " << endl << bitvec << endl << endl;
}

int main() {

	BitOperationFunc1();
	BitOperationFunc2();

	system("Pause");

	return 0;
}