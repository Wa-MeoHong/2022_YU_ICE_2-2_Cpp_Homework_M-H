#ifndef MY_VOCA_LIST_H
#define MY_VOCA_LIST_H

#include "MyVoca.h"
#define NUM_MY_TOEIC_VOCA 20

MyVoca myToeicVocaList[] =
{
	MyVoca(1,"access", NOUN, {"admission", "entry", "passage","ingress"}, {" access potnt", " Do not Access this area"}),
	MyVoca(2,"independent", ADJ, {"separate"}, { "Two independent studies have been carried out."}),
	MyVoca(3,"interact", ADJ, {"unrelated"}, {"irrelevant details"}),
	MyVoca(4,"access", VERB, { "get", "acquire", "obtain"}, { "We can access the Internet wherever we are with our smart phone."}),
	MyVoca(5,"ensure", VERB, { "make sure", "confirm", "certify"}, {"The company's sole concern is to ensure the safety of its employees" }),
	MyVoca(6,"markedly", ADJ, {"noticeably", "obviously"}, {"The quality of their relationship improved markedly."}),
	MyVoca(7,"name", NOUN, {"title"}, {"I don't even know if Sullivan is his real name."}),
	MyVoca(8,"name", VERB, {"call", "christen"} ,{"My mother insisted on naming me Horace."}),
	MyVoca(9,"handle", NOUN, {"opprotunity", "chance", "occasion"}, {"That's some handle to go through life with!"}),
	MyVoca(10, "handle", VERB, {"manage", "deal with"} ,{"A new man was appointed to handle the crisis."}),
	MyVoca(11, "ideal", NOUN , { "principle", "standard"} ,{"The party has drifted too far from its socialist ideals"}),
	MyVoca(12, "ideal",ADJ, {"imaginary", "impractical", "poetic"} ,{"Their ideal society collapsed around them in revolution."}),
	MyVoca(13, "knowledgeable", ADJ, {"well-informed", "acquainted", "aware"}, {"school-age children who were very knowledgeable about soccer"}),
	MyVoca(14,"locate", VERB, {"find", "discover"}, {"We've simply been unable to locate him."}),
	MyVoca(15,"overall", ADJ, {"total", "whole", "general"}, {"The council needs to cut down its overall spending."}),
	MyVoca(16,"overall", ADV, {"generally", "mostly"}, {"Overall, I was disappointed with the result."}),
	MyVoca(17,"precious", ADJ, {"valuable", "prized"}, {"jewellery and precious objects belonging to her mother"}),
	MyVoca(18,"radical", ADJ, {"extreme"}, {"periods of radical change"}),
	MyVoca(19, "universal", ADJ, {"widespread", "general"}, {"proposals for universal health care"}),
	MyVoca(20, "decline", VERB, {"fall", "contract"}, {"a declining birth rate"})
};
#endif // !MY_VOCA_LIST_H


