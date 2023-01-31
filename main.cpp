#include <iostream> 
#include <string>
#include <fstream>
#include <sstream> 


using namespace std;


void letterProcessing_Morse(string morseCode[], int size);
string processFile_Morse(ifstream& inFile, ofstream& outFile, string, int, string); 
string conversion_Morse (char value, string morseValue);
void openFile(std::fstream& File, std::string fname);
void processFile_English(ifstream& inFile, ofstream& outFile, string, int ); 


int main() {
    const int size = 91; 
    int count = 0;
    string Answer1, Answer2, Answer3, stringTotal; 
    string convertText = " "; 
    int total = 0;
    string stringEnglish = ""; 
  
  


    ofstream outFile; 
    outFile.open("English.txt"); 

 

    std::cout << "What is your favorite color?" << endl; 
    getline(cin, Answer1); 


    outFile << Answer1 << endl; 

    std::cout << "What is the last thing you do before sleeping?" << endl; 
    getline(cin, Answer2); 

    

    outFile << Answer2 << endl; 

    std::cout << "What is one thing on your bucket list" << endl; 
    getline(cin, Answer3); 

    

    outFile << Answer3 << endl; 



    stringTotal = Answer1 + " " +  Answer2 + " " + Answer3 + " "; 

    
    for (int i=0; i< stringTotal.size(); i++) {
     if (stringTotal[i]  == ' ') {
        count++;
     }
      count++; 
    }

  while (convertText != "end") {
    std::cout << "Do want to convert from morse to English text (type -t) or" <<
    "convert from English text to morse (type -m)?" << endl; 
    std::cin >> convertText; 

    if (convertText == "-m") {
      //morse.txt being written to 
      ofstream outputMorse;
      outputMorse.open("Morse.txt");
      //english.txt is being read from
      ifstream inputEnglish; 
      inputEnglish.open("English.txt");

      	if(outputMorse.is_open() && inputEnglish.is_open()) {
		      processFile_Morse(inputEnglish, outputMorse, stringEnglish, total, convertText);
	      } else {
		      cout << "Failed to open file" << endl;  
		      exit(-1); 
        }

      
      
      
        outputMorse.close(); 
        inputEnglish.close();

}
  
  
  if (convertText == "-t") {
          //morse.txt being written to 
      ofstream outputEnglish;
      outputEnglish.open("English.txt");
      //english.txt is being read from
      ifstream inputMorse; 
      inputMorse.open("Morse.txt");

      	if(outputEnglish.is_open() && inputMorse.is_open()) {
		      processFile_English(inputMorse, outputEnglish, stringEnglish, total);
	      } else {
		      cout << "Failed to open file" << endl;  
		      exit(-1); 
        }
  }

  

}

  }



string processFile_Morse(ifstream& inFile, ofstream& outFile, string stringEnglish, int totalChar, string userInput) {
  string line, word; 
	istringstream iss; 
  string morseValue; 
  //int total = 0; 
  const int size = 91; 
  char inputChar; 
  char currChar;
  string englishChar = "";  
  int letterNumber;
  string output = "";
  int index = 48;
  int valueCount = 0;
  char outputChar = ' ';
   
    
     
    

    std::string morseStrings[size]; 
    morseStrings[10] = " \n";
    morseStrings[48] = "-----";
    morseStrings[49] = ".----";
    morseStrings[50] = "..---";
    morseStrings[51] = "...--";
    morseStrings[52] = "....-";
    morseStrings[53] = ".....";
    morseStrings[54] = "-...."; 
    morseStrings[55] = "--...";
    morseStrings[56] = "---.."; 
    morseStrings[57] = "----.";
    morseStrings[65] = ".-"; 
    morseStrings[66] = "-...";
    morseStrings[67] ="-.-."; 
    morseStrings[68] = "-..";
    morseStrings[69]= "."; 
    morseStrings[70] = "..-."; 
    morseStrings[71] = "--."; 
    morseStrings[72] = "...."; 
    morseStrings[73] = ".."; 
    morseStrings[74] = ".---"; 
    morseStrings[75] = "-.-"; 
    morseStrings[76] = ".-.."; 
    morseStrings[77] = "--";
    morseStrings[78] = "-.";
    morseStrings[79] = "---";
    morseStrings[80] = ".--.";
    morseStrings[81] = "--.-";
    morseStrings[82] = ".-.";
    morseStrings[83] = "...";
    morseStrings[84] = "-";
    morseStrings[85] = "..-";
    morseStrings[86] = "...-";
    morseStrings[87] = ".--";
    morseStrings[88] = "-..-";
    morseStrings[89] = "-.--";
    morseStrings[90] = "--..";
  
  
    while (!inFile.eof()) {
		
   
    
        currChar = toupper(inputChar);
        outFile << morseStrings[currChar];
        outFile << " ";
        inFile.get(inputChar); 

        stringEnglish = stringEnglish + inputChar;
    
      
   
      totalChar = totalChar + 1;
      
  }
  
  
    
  std::cout << "Total Characters converted successfully: " << totalChar << endl;
  return stringEnglish;
  
  }

  void processFile_English(ifstream& inFile, ofstream& outFile, string  stringEnglish, int totalChar) {
  int size = 91; 
  string line, word;
  istringstream iss; 
  char singleValue;
  char spaces_characters = ' '; 
  string morseValue = "";
  string morseStrings_convert = ""; 
  int letterNumber;
  string output = "";
  int index = 48;
  int valueCount = 0; 
  

  char outputChar = ' ';

    std::string morseStrings[size];
    morseStrings[32] = " "; 
    morseStrings[48] = "-----";
    morseStrings[49] = ".----";
    morseStrings[50] = "..---";
    morseStrings[51] = "...--";
    morseStrings[52] = "....-";
    morseStrings[53] = ".....";
    morseStrings[54] = "-...."; 
    morseStrings[55] = "--...";
    morseStrings[56] = "---.."; 
    morseStrings[57] = "----.";
    morseStrings[65] = ".-"; 
    morseStrings[66] = "-...";
    morseStrings[67] ="-.-."; 
    morseStrings[68] = "-..";
    morseStrings[69]= "."; 
    morseStrings[70] = "..-."; 
    morseStrings[71] = "--."; 
    morseStrings[72] = "...."; 
    morseStrings[73] = ".."; 
    morseStrings[74] = ".---"; 
    morseStrings[75] = "-.-"; 
    morseStrings[76] = ".-.."; 
    morseStrings[77] = "--";
    morseStrings[78] = "-.";
    morseStrings[79] = "---";
    morseStrings[80] = ".--.";
    morseStrings[81] = "--.-";
    morseStrings[82] = ".-.";
    morseStrings[83] = "...";
    morseStrings[84] = "-";
    morseStrings[85] = "..-";
    morseStrings[86] = "...-";
    morseStrings[87] = ".--";
    morseStrings[88] = "-..-";
    morseStrings[89] = "-.--";
    morseStrings[90] = "--..";
  



    while (!inFile.eof()) {


     		  int count1 = 0;
		  getline(inFile, line); 
		  if (inFile.good()) {
			  //cout << line << endl; 
		    //read word by word from the line
			  iss.clear(); //clear out state
			  iss.str(line); 
      while (iss.good()) {
		  iss >> word;
        while(word != morseStrings[index] && index < size) {
          ++index;
        }
        //std::cout << index; 

        

      if (word != " " && word != "\n") {
        
        output = outputChar + index; 
        }

      
      valueCount++; 
      if (stringEnglish[valueCount] == ' ') {
        output = output + ' ';
        std::cout << output;
      }

      if (stringEnglish [valueCount] == '\n') {
        output = output + '\n';
      }
        }
      
     
   
  
      }
  }

  }






