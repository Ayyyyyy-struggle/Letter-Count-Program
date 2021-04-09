#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <fstream>
using namespace std;

// Character names initialization
const char vowel_a= 'A', vowel_e = 'E', vowel_i = 'I', vowel_o = 'O', vowel_u = 'U';
const char letter_t = 'T', letter_p = 'P', letter_d = 'D';

int main (int argc, char* argv[])
{
	int num_a = 0;
	int num_e = 0;
	int num_i = 0;
	int num_o = 0;
	int num_u = 0;
	int num_t = 0;
	int num_p = 0;
	int num_d = 0;
	int num =0;
	char character;
	
	
	
	if (argc < 2)
	{
		cout << "Error with input agrs.." << endl;
		return 1;
	}

	// For debugging purposes only
	/*for (int i = 0; i < argc; i++)
	{
		cout << i << ":" << argv[i] << endl;
	}*/

	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile)
	{
		cout << "Error with file name.." << endl;
		return 1;
	}

    
    	// Headlines
   	cout << setfill('*');
   	cout << setw(61) << " " << endl;
   	cout << setw(47) << " Welcome to my Letter Count Program "  << setw(14)  << " " << endl;
    	cout << setw(61) << "\n" << endl;

	cout << "Analyzing file '" << argv[1] << "'...\n" << endl;


	// Read the file, start counting characters
	while (!inFile.eof())
	{
		inFile.get(character);
		character = toupper(character);

		// Start counting vowels
		switch (character)
		{
			
			case vowel_a:
				num_a++;
				break;
			case vowel_e:
				num_e++;
				break;
			case vowel_i:
				num_i++;
				break;
			case vowel_o:
				num_o++;
				break;
			case vowel_u:
				num_u++;
				break;
			case letter_t:
				num_t++;
				break;
			case letter_p:
				num_p++;
				break;
			case letter_d:
				num_d++;
				break;
			default:
				break;
		}

	}


	// Print the counting number of each letter
	string s1="The number of " ;
	string s2 = "'s: ";
	cout << setfill('.');
	
	int arr1[]={num_a,num_e,num_i,num_o,num_u,num_t,num_p,num_d};
	char arr2[]={vowel_a,vowel_e,vowel_i,vowel_o,vowel_u,letter_t,letter_p,letter_d};
	for (int i=0; i<=7;i++) 
	{
		
		cout << left << s1 << arr2[i] << s2 << right << setw(41) << "." << arr1[i] << endl;
		num += arr1[i];
	}
	cout << left << "The vowel count is: " << right << setw(40) << "." << num << endl;
	


	inFile.close();

	// Execution stops
    	cout << "Press any key to continue . . ." << endl;
    	cin.ignore();
    	cin.get();

    	return 0;
}
