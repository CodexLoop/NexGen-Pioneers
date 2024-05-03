//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "pugixml.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;
using namespace pugi;


class XML_READER{
		string correct;
		xml_node v;
public:

		XML_READER(string c,xml_node s){
			correct = c;
			v = s;
		}
		void read(){
			for(xml_node i: v){
				cout<<i.text().as_string()<<endl;
			}
			cout<<"Correct Answer : "<<correct<<endl;
		}

};

int main() {
	xml_document doc;
	doc.load_file("XMLQuestions1.xml");

	vector<xml_node> v;
	vector<string> correct;
	vector<XML_READER> XR;
//	vector<xml_node> vHigh;
//	vector<xml_node> vLow;
//	vector<xml_node> vMed;

	xpath_node_set node = doc.select_nodes("/quiz/question/option[@correct ='true']");
//	xpath_node_set node1 = doc.select_nodes("/quiz/question[@level='hard']");
//	xpath_node_set node2 = doc.select_nodes("/quiz/question[@level='medium']");
//	xpath_node_set node3 = doc.select_nodes("/quiz/question[@level='easy']");
//	for(xpath_node hard: node1){
//		vHigh.push_back(hard.node());
//	}
//	for(xpath_node medium: node2){
//		vMed.push_back(medium.node());
//	}
//	for(xpath_node easy: node3){
//		vLow.push_back(easy.node());
//	}
//
//	//for(xml_node i : vLow){
//		//cout<<i.child("text").text().as_string()<<endl;
//		xml_node i = vLow[0];//.child("option");
//		for(xml_node j: i){
//		cout<<j.text().as_string()<<endl;}
//	//}

	for(xpath_node i: node){
		correct.push_back(i.node().text().as_string());
	}
	xml_node s = doc.child("quiz");
	//string correct;

	for(xml_node i : s){
		v.push_back(i);
	}
	//cout<<correct[0]<<endl;
//	XML_READER xr;
	for(int i = 0; i<v.size();i++){
		XML_READER xr(correct[i],v[i]);
		XR.push_back(xr);
	}
	set<int> st;
	int lower=0,high=v.size();
	int random;

	while(st.size()<4){
		random = lower+(rand() % high - lower + 1);
		cout <<random <<endl;
		st.insert(random);
	}

	for(int i:st){
		XR[i].read();
		cout<<endl;
	}

	//cout<<text<<endl;
	//xml_node option = v[0];
//	for(xml_node i : option){
//		cout<<i.text().as_string()<<endl;
//	}



	return 0;
}
