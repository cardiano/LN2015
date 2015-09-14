#include "wyszukiwanie.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <mpegfile.h>
#include <fileref.h>
#include <id3v2tag.h>
#include <vector>


using namespace TagLib;
using namespace std;
int main()
{ 	
	string dirp, filepath; 
  	dirent plikaudio;
	cout << "podaj ścieżkę do biblioteki: " << flush;
  	getline( cin, dirp );  
	plikaudio=listujPliki(dirp);
	filepath = dirp + "/" + plikaudio.d_name;
	cout << "wczytano plik : "<<filepath << endl;
	
	MPEG::File file(filepath.c_str());
	if(file.ID3v2Tag())
	{
  		ID3v2::FrameList l = file.ID3v2Tag()->frameListMap()["RVAD"];
  		if(l.isEmpty())
    			cout << "plik nie posiada tagu replaygain"<< endl;
	}
	file.save();
	
 
}
