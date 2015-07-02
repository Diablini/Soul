

#pragma once


#include <string>
#include <fstream>

#include "Soul.h"

using namespace std;

const string jobfile = "jobs.txt";

STAT toStat (string what)
{
	// ibaaaasi pisaneto
	if (what == "ANA") return analytical;
	if (what == "ART") return artistic;
	if (what == "TEM") return temperament;
	if (what == "SPI") return spiritual;
	if (what == "LEAD") return leadership;
	if (what == "EGO") return egoism;
	if (what == "OUT") return outgoing;
	if (what == "DIS") return discipline;
	return NumofAtt;
};

struct Job
{
	Job()
	{
		for (size_t i = 0; i < NumofAtt; i++)
		{
			bestAtt[i] = goodAtt[i] = badAtt[i] = worstAtt[i] = false;
		}
	}

	bool bestAtt [NumofAtt];
	bool goodAtt [NumofAtt];
	bool badAtt [NumofAtt];
	bool worstAtt [NumofAtt];

	size_t startYear;
	size_t endYear;
	vector<string> messages;

	string name;
};

static class JobManager
{
public:
	JobManager()
	{
		if (jobfile == "") return;
		fstream file;
		file.open(jobfile, ios::in);
		if (!file) throw "error opening jobs file";
		string buffer;
		string start;
		string end;

		while (!file.eof())
		{
			Job current;
			getline(file, buffer);
			if (buffer == "") getline(file,buffer);
			current.name = buffer;
			getline(file, buffer);

			for (size_t i = 0; i < buffer.size(); i++)
			{
				if (buffer[i] == '-')
				{
					start = buffer.substr(0,i);
					end = buffer.substr(i+1, buffer.size() );
				}
			}
			if (end == "INF") current.endYear = SIZE_MAX;
			else current.endYear = atoi(end.c_str() );
			current.startYear = atoi(start.c_str() );


			getline(file,buffer);
			// read positives and negatives
			if (buffer == "++")
			{
				getline(file,buffer);
				do
				{
					current.bestAtt[toStat(buffer)] = true;
					getline(file,buffer);
				}
				while(buffer != "MSG:" && toStat(buffer)!= NumofAtt );
			}

			if (buffer == "+")
			{
				getline(file,buffer);
				do
				{
					current.goodAtt[toStat(buffer)] = true;
					getline(file,buffer);
				}
				while(buffer != "MSG:" && toStat(buffer)!= NumofAtt );
			}

			if (buffer == "-")
			{
				getline(file,buffer);
				do
				{
					current.badAtt[toStat(buffer)] = true;
					getline(file,buffer);
				}
				while(buffer != "MSG:" && toStat(buffer)!= NumofAtt );
			}

			if (buffer == "--")
			{
				getline(file,buffer);
				do
				{
					current.worstAtt[toStat(buffer)] = true;
					getline(file,buffer);
				}
				while(buffer != "MSG:" && toStat(buffer)!= NumofAtt );
			}

			getline(file,buffer);
			while(buffer != "END")
			{
				current.messages.push_back(buffer.substr(1,buffer.size() - 2) );
				getline(file,buffer);
			}

			joblist.push_back(current);
		}
	}
	
private:
	vector<Job> joblist;
}job;

