#include "wyszukiwanie.hpp"
#include <iostream>
#include <cstring>
#include <mpegfile.h>
#include <fileref.h>
#include <id3v2tag.h>
#include <vector>


using namespace TagLib;
using namespace std;
int main()
{ 	string dirp, filepath; 
  	dirent plikaudio;
	cout << "podaj ścieżkę do biblioteki: " << flush;
  	getline( cin, dirp );  
	plikaudio=listujPliki(dirp);
	filepath = dirp + "/" + plikaudio.d_name;
	cout << "wczytano plik : "<<filepath << endl;
	
	MPEG::File file(std::string filepath);
	file.ID3v2Tag()->setTrack(37);
  	
//if(!l.isEmpty())
	//if(file.ID3v2Tag()) 
	//ID3v2::FrameList l = file.ID3v2Tag()->frameListMap()["APIC"];
  	//if(!l.isEmpty())
    	//cout << l.front()->toString()<< endl;
	
 
}
