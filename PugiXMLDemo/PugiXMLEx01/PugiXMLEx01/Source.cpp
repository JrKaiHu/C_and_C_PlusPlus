
#include "Source.h"

#include <iostream>

#include "pugiconfig.hpp"
#include "pugixml.hpp"


StudentProfie::StudentProfie(string strName, string strSex, int nFirstScore, int nSecondScore, int nThirdScore) {

	m_strName = strName;
	m_strSex  = strSex;
	m_nFirstScore  = nFirstScore;
	m_nSecondScore = nSecondScore;
	m_nThirdScore  = nThirdScore;
}

string StudentProfie::GetstrName() {

	return m_strName;
}

string StudentProfie::GetstrSex() {

	return m_strSex;
}

int StudentProfie::GetstrFirstScore() {
	
	return m_nFirstScore;
}

int StudentProfie::GetstrSecondScore() {

	return m_nSecondScore;
}

int StudentProfie::GetstrThirdScore() {

	return m_nThirdScore;
}

AttributeType::AttributeType(string strName, string strVal) {

	m_strName = strName;
	m_strVal  = strVal;
}

void WriteToRootChild(list<StudentProfie*> pClass, pugi::xml_document *pDoc, string rootTag) {

	pugi::xml_node root_node = pDoc->append_child(rootTag.c_str());
	pugi::xml_node students_node = root_node.append_child("students");

	for (auto pStudentProfile : pClass)
	{

		pugi::xml_node student_node = students_node.append_child("student");

		student_node.append_attribute("name") = pStudentProfile->GetstrName().c_str();
		student_node.append_attribute("sex")  = pStudentProfile->GetstrSex().c_str();

		pugi::xml_node firstScoreNode = student_node.append_child("firstscore");
		firstScoreNode.append_child(pugi::node_pcdata).set_value((to_string(pStudentProfile->GetstrFirstScore())).c_str());

		pugi::xml_node secnodcoreNode = student_node.append_child("secondscore");
		secnodcoreNode.append_child(pugi::node_pcdata).set_value((to_string(pStudentProfile->GetstrSecondScore())).c_str());

		pugi::xml_node thirdcoreNode = student_node.append_child("thirdscore");
		thirdcoreNode.append_child(pugi::node_pcdata).set_value((to_string(pStudentProfile->GetstrThirdScore())).c_str());
	}
}

void WriteToXML(string strPath) {

	pugi::xml_document doc;

	WriteToRootChild(pScoreList1, &doc, "Class1ScoreList");
	WriteToRootChild(pScoreList2, &doc, "Class2ScoreList");
	WriteToRootChild(pScoreList3, &doc, "Class3ScoreList");

	doc.save_file(strPath.c_str());
}

struct simple_walker : pugi::xml_tree_walker
{
	virtual bool for_each(pugi::xml_node& node)
	{
		for (int i = 0; i < depth(); ++i) std::cout << "  "; // indentation

		//std::cout << ": name='" << node.name() << "', value='" << node.value() << "'\n";
		string strXmlEleName = node.name();
		string strXmlEleValue = node.value();
		
		cout << strXmlEleName << " ";
		list <AttributeType*> attrList;
		for (auto attr = node.first_attribute(); attr; attr = attr.next_attribute()) {

			attrList.push_back(new AttributeType(attr.name(), attr.value()));
			cout << attr.name() << " : ";
			cout << attr.value() << " ";
		}
		cout << strXmlEleValue << endl;

		return true; // continue traversal
	}
};

void ReadFromXML(string strPath) {

	pugi::xml_document doc;

	doc.load_file(strPath.c_str());

	// tag::traverse[]
	simple_walker walker;
	doc.traverse(walker);
	// end::traverse[]

	//for (auto root = doc.first_child(); root; root = root.next_sibling()) {

	//	cout << root.name() << endl;

	//	for (auto child = root.first_child(); child; child = child.next_sibling()) {

	//		cout << child.name() << endl;
	//	}
	//}
}

void FillStudentProfile() {

	pScoreList1.push_back(new StudentProfie("A", "Male", 82, 95, 100));
	pScoreList1.push_back(new StudentProfie("B", "Female", 95, 99, 87));
	pScoreList1.push_back(new StudentProfie("C", "Male", 98, 88, 80));

	pScoreList2.push_back(new StudentProfie("D", "Male", 98, 100, 78));
	pScoreList2.push_back(new StudentProfie("E", "Female", 85, 95, 99));
	pScoreList2.push_back(new StudentProfie("F", "Male", 58, 98, 88));
	pScoreList2.push_back(new StudentProfie("G", "Female", 89, 100, 87));

	pScoreList3.push_back(new StudentProfie("H", "Male", 99, 89, 78));
	pScoreList3.push_back(new StudentProfie("I", "Female", 74, 85, 95));
}

int main() {

	FillStudentProfile();

	WriteToXML("students.xml");

	ReadFromXML("students.xml");

	system("Pause");

	return 0;
}