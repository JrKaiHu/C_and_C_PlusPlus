#include <list>
#include <string>

using namespace std;

class StudentProfie {

public:
	StudentProfie(string strName, string strSex, int nFirstScore, int nSecondScore, int nThirdScore);

	string GetstrName();
	string GetstrSex();
	int GetstrFirstScore();
	int GetstrSecondScore();
	int GetstrThirdScore();

public:
	string m_strName;
	string m_strSex;
	int m_nFirstScore;
	int m_nSecondScore;
	int m_nThirdScore;
};

list <StudentProfie*> pScoreList1;
list <StudentProfie*> pScoreList2;
list <StudentProfie*> pScoreList3;

class AttributeType{

public:
	AttributeType(string strName, string strVal);
	string m_strName;
	string m_strVal;
};