
#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

using namespace std;

chrono::time_point<chrono::high_resolution_clock> beg = chrono::high_resolution_clock::now();

enum STAT
{
	// objective
	analytical, // math and science skill 
	artistic,   // creativity skill
	leadership,  
	discipline,

	// subjective
	temperament, // more = more violent temper
	spiritual, // more = believes in supernatural more
	egoism,       // high ego means he values himself more than others
	outgoing, // more = likes to be around people more and get along with them

	NumofAtt
};

string statToString (STAT what)
{
	switch (what)
	{
	case analytical: return "ANA";
		break;
	case artistic: return "ART";
		break;
	case leadership: return "LEAD";
		break;
	case temperament: return "TEM";
		break;
	case outgoing: return "OUT";
		break;
	case spiritual: return "SPI";
		break;
	case egoism: return "EGO";
		break;
	case discipline: return "DIS";
		break;
	case NumofAtt: return "";
		break;
	default:
		break;
	}

};


string capitalize (string& s)
{
	string n = s;
	n[0] -= ('a' - 'A');
	return n;
}

string statText(STAT what, int v)
{
	switch (what)
	{
	case analytical:
		{
			if (v >= 95) return "is an intellectual prodigy";
			if (v >= 80) return "has a great technical mind";
			if (v >= 65) return "is fairly smart";
			if (v <= 5) return "is a complete idiot";
			if (v <= 20) return "is pretty stupid";
			if (v <= 35) return "isn't very bright";
		}
		break;
	case artistic:
		{
			if (v >= 95) return "is an artistic maestro";
			if (v >= 80) return "posseses great creativity";
			if (v >= 65) return "is a good artist";
			if (v <= 5) return "hates art";
			if (v <= 20) return "has no artistict talent";
			if (v <= 35) return "hasn't got the creative spark";
		}
		break;
	case leadership:
		{
			if (v >= 95) return "is a great inspiring leader";
			if (v >= 80) return "is truly a leader";
			if (v >= 65) return "can coordinate people well";
			if (v <= 5) return "can't capture the hearts of the people";
			if (v <= 20) return "can follow orders,but not give them";
			if (v <= 35) return "is a team player rather than a leader";
		}
		break;
	case temperament:
		{
			if (v >= 95) return "has an uncontrollable wrath";
			if (v >= 80) return "is a very passionate person";
			if (v >= 65) return "has trouble keeping cool";
			if (v <= 5) return "is always calm and collected";
			if (v <= 20) return "has a good emotional discipline";
			if (v <= 35) return "rarely looses temper";
		}
		break;
	case outgoing:
		{
			if (v >= 95) return "is a cult of personality";
			if (v >= 80) return "is a center of attention";
			if (v >= 65) return "is a people person";
			if (v <= 5) return "is an outcast";
			if (v <= 20) return "is shy";
			if (v <= 35) return "prefers to be alone";
		}
		break;
	case spiritual:
		{
			if (v >= 95) return "is devoted to the gods and their magic";
			if (v >= 80) return "has a strong supernatural faith";
			if (v >= 65) return "believes in the supernatural";
			if (v <= 5) return "is a die-hard sceptic";
			if (v <= 20) return "is a realist";
			if (v <= 35) return "believes in logic";
		}
		break;
	case egoism:
		{
			if (v >= 95) return "will sacrifice anything and anyone to feel good";
			if (v >= 80) return "is an egoist";
			if (v >= 65) return "values oneself highly";
			if (v <= 5) return "will sacrifice self for others";
			if (v <= 20) return "is a kind person";
			if (v <= 35) return "is considerate";
		}
		break;
	case discipline:
		{
			if (v >= 95) return "is a perfectionist";
			if (v >= 80) return "is extremely disciplined";
			if (v >= 65) return "strives to be prepared for everything";
			if (v <= 5) return "has absolutely no discipline";
			if (v <= 20) return "is always disorganised";
			if (v <= 35) return "lacks discipline";
		}
		break;
	}
	return "";
}

struct Appearance
{
	Appearance (string name, bool male)
	{
		string heshe = "she";
		if (male) {heshe = "he";}

		string hisher = "her";
		if (male) {hisher = "his";}

		// height and build
		string height;
		size_t heightroll = rand() % 7;
		string build;
		size_t buildroll;
		if (male)
		{
			buildroll = rand() % 7;
		}
		else buildroll = rand() % 5;

		switch (heightroll)
		{
		case 5: height = "extremely tall"; break;
		case 6: height = "very tall"; break;
		case 4: height = "fairly tall"; break;
		case 3: height = "of average height"; break;
		case 2: height = "a little shorter than most"; break;
		case 1: height = "short"; break;
		case 0: height = "very short"; break;
		default: height = "of average height"; break;
		}

		switch (buildroll)
		{
		case 6: build = "gigantic and with perfectly toned muscles"; break;
		case 5: build = "huge, with large muscles"; break;
		case 4: build = "bigger than most people"; break;
		case 3: build = "average in size"; break;
		case 2: build = "thin and slender"; break;
		case 1: build = "very thin"; break;
		case 0: build = "of a skeletal build"; break;
		default:
			break;
		}

		string haircol;
		size_t haircolroll = rand() % 11;
		string hairtype;
		size_t hairtyperoll = rand() % 10;
		string eyes;
		size_t eyeroll = rand() % 10;

		switch (haircolroll)
		{
		case 0: haircol = "perfectly black"; break;
		case 1: haircol = "dark brown"; break;
		case 2: haircol = "light brown"; break;
		case 3: haircol = "blonde"; break;
		case 4: haircol = "golden"; break;
		case 5: haircol = "ginger"; break;
		case 6: haircol = "bright red"; break;
		case 7: haircol = "auburn" ; break;
		case 8: haircol = "dark blonde"; break;
		case 9: haircol = "brown"; break;
		case 10: haircol = "black"; break;
		default:
			break;
		}

		switch (hairtyperoll)
		{
		case 0: hairtype = "long and straight"; break;
		case 1: hairtype = "short and straight"; break;
		case 2: hairtype = "short"; break;
		case 3: hairtype = "long"; break;
		case 4: hairtype = "curly"; break;
		case 5: hairtype = "long curly"; break;
		case 6: hairtype = "messy"; break;
		case 7: hairtype = "beehive"; break;
		case 8: hairtype = "mostly bald"; break;
		case 9: hairtype = "extravagantly styled"; break;
		default:
			break;
		}

		switch (eyeroll)
		{
		case 0: eyes = "perfectly black"; break;
		case 1: eyes = "black"; break;
		case 2: eyes = "brown"; break;
		case 3: eyes = "grey" ; break;
		case 4: eyes = "shiny blue"; break;
		case 5: eyes = "blue"; break;
		case 6: eyes = "golden"; break;
		case 7: eyes = "green"; break;
		case 8: eyes = "gleaming green"; break;
		case 9: eyes = "brightly colored"; break;
		default:
			break;
		}

		desc = "This is " + name + ". " + capitalize(heshe) +
			" is " + height + " and " + build + ". " + capitalize(heshe) +
			" has " + haircol + " " + hairtype + " hair, and " + hisher +
			" eyes are " + eyes + ".";
	}

	string desc;
};

struct Stats
{
	Stats()
	{
		normal_distribution<double> dist(50.0, 30.0);
		default_random_engine gen;
		gen.seed(time(NULL));
		for (size_t i = 0; i < NumofAtt; i++)
		{
			int thestat;
			do
			{
				thestat = dist(gen);
			}while(thestat > 100 || thestat < 0);
			soulstat[i] = (STAT)thestat;
		}

		for (size_t i = 0; i < NumofAtt; i++)
		{
			desc[i] = statText( (STAT)i, soulstat[i]);
		}
	}

	STAT soulstat[NumofAtt];
	string desc [NumofAtt];
};

class Relations
{


};


class Life
{


private:
	size_t life_id;
	string name;
	string birthplace;

	Stats start;
	Stats end;
};

class Soul
{

private:
	vector<Life> lifes;
	size_t soul_id;
};

