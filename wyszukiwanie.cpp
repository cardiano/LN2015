#include "wyszukiwanie.hpp"
#include <errno.h>
#include <stdio.h> 




dirent listujPliki(std::string dir)
{


	
  	DIR * sciezka;
  	dirent * plik;

	using std::cout;
    	
   


  
  sciezka = opendir( dir.c_str() );
	if (sciezka== NULL)
    	{	
        switch( errno ) {
        case EACCES: perror( "! (problem w OPENDIR) brak dostepu do czytanej sciezki" ); break;
        case ELOOP: perror( "! (problem w OPENDIR) zbyt wiele symbolicznych powiązań napotkanych w ścieżce" ); break;
        case ENAMETOOLONG: perror( "! (problem w OPENDIR) długość ścieżki przekracza PATH_MAX, lub długość nazw jej komponentów przekracza NAME_MAX" ); break;
        case ENOENT: perror( "! (problem w OPENDIR) ścieżka jest pustym stringiem, lub (problem w OPENDIR lub READDIR) składnik ścieżki nie jest nazwą istniejącej ścieżki\n" ); break;
        case ENOTDIR: perror( "! (problem w OPENDIR) komponent lub nazwa ścieżki nie jest ścieżką" ); break;
        case EMFILE: perror( "! (problem w OPENDIR) jest otwarta liczba plików równa OPEN_MAX" ); break;
        case ENFILE: perror( "! (problem w OPENDIR) zbyt wiele plików jest obecnie otwartych przez system" ); break;
        case EOVERFLOW: perror( "! (problem w READDIR) jedna z wartości w strukturze nie może być zwrócona poprawnie" ); break;
        case EBADF: perror( "! (problem w READDIR lub CLOSEDIR) argument funkcji readdir nie odnosi się do otwartego strumienia ścieżki" ); break;
        case EINTR: perror( "! (problem w CLOSEDIR) funkcja jest przerwana przez sygnał" ); break;
        		};
        errno = 0;
        printf( "\n" );
   		}
    	
 	while ((plik = readdir( sciezka )))
	{
		
		if(strstr(plik->d_name, ".mp3")!=NULL)	
		break;
	}
	
	closedir( sciezka ); 

	return *plik;
}
