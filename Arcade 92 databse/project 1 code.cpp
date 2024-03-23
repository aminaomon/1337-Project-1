//OXO22016
//Ominakhon Omonullaeva
#include <iostream>
#include<fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

const string database = "database.dat";

//your filestream for the database will connect to this variable
  
//add record function
void addRecord (string data, fstream & file){
 
 //variables 
long unsigned int start;
long unsigned int end;
string name;
string highScore;
string initials;
string plays;
string revenue;
 
//finds index of all necessary variables
start = data.find ('"')+ 1;
end = data.find ('"', start);
name = data.substr (start, end - start);
  
start = end + 2;
end = data.find (' ', start);
highScore = data.substr (start, end - start);
  
start = end + 1;
end = data.find (' ', start);
initials = data.substr (start, end - start);
  
start = end + 1;
end = data.find (' ', start);
plays = data.substr (start, end - start);
  
start = end + 2;
revenue = data.substr (start);
  
//outputs to console
cout << "RECORD ADDED" << endl;
cout << "Name: " << name << endl;
cout << "High Score: " << highScore << endl;
cout << "Initials: " << initials << endl;
cout << "Plays: " << plays << endl;
cout << "Revenue: $" << revenue << endl << endl;
  

//turns into it and double 
stoi (highScore);
stoi (plays);
stod (revenue);

//outputs to file
file << name << ", ";
file << setfill ('0') << setw (9) << highScore << ", ";
file << initials << ", ";
file << setfill ('0') << setw (4) << plays << ", $";
file << fixed << setprecision (2);
file << setfill ('0') << setw (7) << revenue << endl;
} //close add record function
 
 //search record function
void searchRecord (string data, fstream & file){
  
  //variables
string name = data.substr(2);
string fileLine;
string fileName;
long unsigned int comma;
long unsigned int nextComma;
int count = 0;
string score;
string initials;
string plays;
string revenue;
  
 
// while loop
while(!file.eof()){
 
 //gets line from file and finds name per line 	  
getline (file, fileLine);
comma = fileLine.find (',');
fileName = fileLine.substr (0, comma);

long unsigned int found = fileName.find (name);

//if name is found	  
if (found < 100){

//counter		  
count++;

//puts into variable
nextComma = fileLine.find (',', comma + 1);
score = fileLine.substr (comma + 1, nextComma - comma - 1);

comma = fileLine.find (',', nextComma + 1);
initials = fileLine.substr (nextComma + 2, comma - nextComma - 2);

nextComma = fileLine.find (',', comma + 1);
plays = fileLine.substr (comma + 2, nextComma - comma - 1);
int play = stoi(plays);

comma = fileLine.find (',', nextComma + 1);
revenue = fileLine.substr (nextComma + 3, comma - nextComma - 1);
double rev = stod(revenue);
 
 //outputs to console
cout << fileName << " FOUND" << endl;
cout << "High Score: " << stoi (score) << endl;
cout << "Initials: " << initials << endl;
cout << "Plays: " << play << endl;
cout << "Revenue: $" << fixed << setprecision(2) << rev << endl << endl;
		
}//close if
	}//close while

//if count = 0 name is not found  
if (count == 0){
	  
cout << name << " NOT FOUND" << endl;
	
}// close if
}// close functions

//edit function
void editRecord (string data, fstream &file){
 
 //variables 
string name;
string num;
string value;
int val;
string initial;
string fileLine;
string fileName;
long unsigned int comma;
long unsigned int start;
long unsigned int end;
long unsigned int index = 0;
	
 
//stores name and fieldnum 
start = data.find ('"');
end = data.find ('"', start + 1);
name = data.substr (start + 1, end - start - 1);
 
start = end + 2;
end = data.find (' ', start);
num = data.substr(start, end- start);
  
 //while file is not at end 
while(!file.eof()){
 
 //gets line from file and stores name   
getline (file, fileLine);
comma = fileLine.find (',');
fileName = fileLine.substr (0, comma);
	  
 
 //file = name
if (fileName == name){

//seeks index		  
file.seekg (index);

//if field num = 1 edits high score	
if (stoi(num) == 1){
			  
 
start = end + 1;
value = data.substr (start);
val = stoi(value);
	
file << name << ", ";
			 
start = 0;
end = fileLine.find (',', start);
			  
start = end + 1;
end = fileLine.find (',', start);
			  
file << setfill ('0') << setw (9) << val << ", ";
			  
start = end + 2;
end = fileLine.find (',', start);
			  
 
file << fileLine.substr (start) << endl;
	
string initials = fileLine.substr (start, end - start);
			  
start = end + 2;
end = fileLine.find (',', start);
			  
 
string plays = fileLine.substr (start, end - start);

			  
start = end + 3;
			  
 
string rev = fileLine.substr(start);
			  
 
cout << name << " UPDATED" << endl;
cout << "UPDATE TO high score - VALUE " << val << endl;
cout << "Name: " << name << endl;
cout << "High Score: " << val << endl;
cout << "Initials: " << initials << endl;
cout << "Plays: " << stoi(plays) << endl;
cout << "Revenue: $" << fixed << setprecision(2) << stod(rev) << endl;
cout << endl;
			

}
//if fieldnum = 2 edits initials
else if (stoi(num) == 2){
			  
 
start = end + 1;
initial = data.substr (start);
			  
 
file << name << ",";
			  
start = 0;
end = fileLine.find (',', start);
			  
 
start = end + 1;
end = fileLine.find (',', start);
			  
 
value = fileLine.substr (start, end - start);
file << value << ", ";
			  
file << initial;

start = end + 5;
end = fileLine.find (',', start);
			  
 
file << fileLine.substr (start) << endl;
			  
start = end + 2;
end = fileLine.find (',', start);
			  
 
string plays = fileLine.substr (start, end - start);
			  
start = end + 3;
string rev = fileLine.substr (start);
			  
 
cout << name << " UPDATED" << endl;
cout << "UPDATE TO initials - VALUE " << initial << endl;
cout << "Name: " << name << endl;
cout << "High Score: " << stoi(value) << endl;
cout << "Initials: " << initial << endl;
cout << "Plays: " << stoi (plays) << endl;
cout << "Revenue: $" << fixed << setprecision(2) << stod (rev) << endl;
cout << endl;

}//if field num == 3 edits plays and revenue
else if (stoi(num) == 3){
			
                start = end + 1;
                string play = data.substr(start);
                   
                file << name << ", ";
                
                start = 0;
                end = fileLine.find(',', start);
                
                start = end+2;
                end = fileLine.find(',', start);
                
                string value = fileLine.substr(start, end- start);
                file << value << ",";
                
                start = end+1;
                end = fileLine.find(',', start);
                initial = fileLine.substr(start, end - start);
                file << initial << ", ";
                
                int newPlays = stoi(play);
                
                file << setw(4) << setfill('0') << fixed << newPlays << ", ";
                
                
                double rev = stod(play) *0.25;
                
                file << "$" << setprecision(2) << setw(7) << setfill('0') << rev << endl;

                
                cout << name << " UPDATED" << endl;
                cout << "UPDATE TO plays - VALUE " << newPlays << endl;
                cout << "Name: " << name << endl;
                cout << "High Score: " << stoi(value) << endl;
                cout << "Initials:" << initial << endl;
                cout << "Plays: " << newPlays << endl;
                cout << "Revenue: $" <<fixed << setprecision(2) << rev << endl;
                cout << endl;
                   
 }
 
}//close match if
   //keeps track of index
	  index = file.tellg ();
	
}//close while
}//close edit function

//delete record function
void deleteRecord(string data, fstream &file){

   //variables
    string name = data.substr(2);
    string fileLine;
    string fileName;
    string removeLine;
    long unsigned int start;
    long unsigned int end;
    
    //clears where pointer is in file
    file.clear();
    file.seekg(0, ios::beg);
    
    //new output file
    ofstream newfile("replace.txt", ios:: out);
    
    //while file is open gets line
    while(getline (file, fileLine)){
        
        start = 0;
        end = fileLine.find(',', start);
        fileName = fileLine.substr(start, end - start);
       
       //compares file name to name wanting to be deleted
       if(fileName != name){
           newfile << fileLine << endl;
       }else{
            removeLine = fileLine;// keeps record of file wanting to be deleted
       }
    }
    
     
        //closes file and renames new file
       file.close();
       remove(database.c_str());
       rename("replace.txt", database.c_str());
       
       //stores information that was deleted into variables
       start = 0;
       end = removeLine.find(',', start);
       string removeName = removeLine.substr(start, end - start);
       
       
       start = end + 2;
       end = removeLine.find(',', start);
       string score = removeLine.substr(start, end - start);
      
       
       start = end + 2;
       end = removeLine.find(',', start);
       string initial = removeLine.substr(start, end - start);
       
       
       start = end + 2;
       end = removeLine.find(',',  start);
       string play = removeLine.substr(start, end - start);
       
       
       start = end + 3;
       string rev = removeLine.substr(start);
       
       //outputs to console info that was deleted
       cout << "RECORD DELETED" << endl;
       cout << "Name: " << removeName << endl;
       cout << "High Score: " << stoi(score) << endl;
       cout << "Initials: " << initial << endl;
       cout << "Plays: " << stoi(play) << endl;
       cout << "Revenue: $" <<fixed << setprecision(2) << stod(rev) << endl;
       cout << endl;
    
}//close deleteRecord
 
 //validation function
bool validateCommand (string check){
  //variables
string name;
string revenue;
int count = 0;
long unsigned int space1;
long unsigned int space2;
long unsigned const invalid = -1;
 
 
 //checks validity for add record function
if (check[0] == '1'){	  
 
space1 = check.find ('"');
space2 = check.find ('"', space1 + 1);
	  
 
if (space1 == invalid || space2 == invalid){
return false;
}
	  
	  
space1 = space2 + 2;
	  
while (check[space1] != ' '){
		  
    if (isdigit (check[space1]) == false || count >= 10){
    return false;
    }
		  
        space1++;
        count++;
}
//close while	  
 
space1++;
count = 0;
	  
 
while (check[space1] != ' '){
		  
        if (isprint (check[space1]) == false){
        return false;
        }
		  
        count++;
        space1++;
}//close while
	  
 
if (count != 3){
return false;
}
	  
space1++;
count = 0;
	  
while (check[space1] != ' '){
		  
    if (isdigit (check[space1]) == false){
    return false;
    }
		  
space1++;
count++;
		
}//close while
	  
 
if (count >= 5){
return false;
}
	  
 
space1++;
count = 0;
	
if (check[space1] != '$'){
return false;
}
	  
 
space1++;
revenue = check.substr (space1);
long unsigned int hasDot = revenue.find (".");
	  
 
if (hasDot == invalid){
return false;

}else{
		  
    while (revenue[count] != '.'){
    count++;
			
    }
		  
 
    if (count >= 5){
        return false;
        }
    		  
count++;
long unsigned int cents = revenue.substr (count).length ();
		  
 
    if (cents != 2){
    return false;
			}//close cents if
		}//close if/else
return true;

}//checks validitiy for edit record function
else if (check[0] == '3'){
	  
 
space1 = check.find ('"');
space2 = check.find ('"', space1 + 1);
	  
 
if (space1 == invalid || space2 == invalid){
return false;
}
	  	  
space1 = space2 + 2;
	  
if (check[space1] == '1'){
		  
space1 += 2;

while (check[space1]){
			  
        if (isdigit(check[space1])){
            
        }else{
            return false;
        }
		
		if( count >= 10 ){
		 
		    return false;
		}	  
space1++;
count++;
    }//close while
		
 }else if (check[space1] == '2'){
		  
          space1+=2;
          
while (check[space1]){
			  
        if (isprint(check[space1]) == false){
            return false;
        }else{
        count++;
        space1++;
            
        }
}
		  
        if (count != 3){
        return false;
        }
	    	
    }else if (check[space1] == '3'){
		  
space1 += 2;
		  
 
while (check[space1]){
			  
        if (isdigit(check[space1])){
            
		}else{
		   return false;
		   }//if
		
		if (count >= 5){
                return false;
            }//if counter
            
        space1++;
        count++;
			
    }//while
		  
      }
      else{
		   return false;
		    }//if num ==1,2,3
		    
        return true;
    }//close check 3;
    
    
    return true;
}//close valid function

int main (){
/* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */ 
	string temp;				//variable for database filename
  string batch;					//variable for batch filename
  
cout << "Enter Database Name: ";
  
cin >> temp;
  
 
ifstream infile (temp, ios::binary);
  
ofstream outfile (database, ios::binary);
  
string line;
  
if (infile)
	
while (infile.good ())
	  
	  {
		
getline (infile, line);
		
if (line != "")
		  
outfile << line << "\n";
	  
}
  
 
infile.close ();
  
outfile.close ();
  
/* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */ 
	
	//add your code for main here
string dataLine;

//user input  
cout << endl;
cout << "Enter Batchfile Name: " << endl;;
cin >> batch;
  
 
infile.open (batch);
fstream file;
 
 //while file is not at end
while (!infile.eof ()){
	  
bool valid;
getline (infile, dataLine);
valid = validateCommand (dataLine);
	  
//if valid function is true goes to each function that was called 
if (valid == true){
		  
 
            if (dataLine[0] == '1'){
			  
            file.open (database, ios::out | ios::app);
            addRecord (dataLine, file);
            file.close ();
			
            }
		  else if (dataLine[0] == '2'){
			  
            file.open (database, ios::in | ios::app);
            searchRecord (dataLine, file);
            file.close ();
			
            }
		  else if (dataLine[0] == '3'){
			  
            file.open (database, ios::in | ios::out);
            editRecord (dataLine, file);
            file.close ();
			}
		  else if (dataLine[0] == '4'){
		      
			file.open(database, ios::in | ios::out);
			deleteRecord(dataLine, file);
			file.close();
            }//close ifs for functions
		
       }//close validity if
           
    }//close while
infile.close(); //closes file, output file was closed in each functions if statement

}//close main
