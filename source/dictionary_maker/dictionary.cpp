#define TIMEOUT 1000
#define LINE_LIMIT 10000
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int position = 0;
int runtime = 0;

void spinner(){
  char spin[4] = {'\\', '|', '/', '-'};
  if((runtime % TIMEOUT) == 0){
    cout << spin[position % 4] << '\r';
    position++;
  }
  runtime++;
}

int split (ifstream &input){
  int linecount = 0;
  string readline;
  while(!input.eof()){
    spinner();
    input >> readline;
    linecount++;
  }
  return linecount;
}

int main()
{
  ifstream input("WEBSTER.txt", ios::in);
  ifstream input2;
  ofstream output("output.txt", ios::out);

  char chars[10] = {'0','1','2','3','4','5','6','7','8','9'};
  char writechar = '0';
  int i, j, k, len;
  int m = 0;
  string readline;
  string writeline;
  string templine;
  char outfile[] = "output2.txt";

  cout << "Processing: Please Wait!" << endl;
  j = split(input);
  cout << "Linecount: " << j << endl;
  input.close();
  //j = 0;    
 
  input2.open ("WEBSTER.txt", ios::in);
  while(!input2.eof()){ 
    if (m < LINE_LIMIT){
      input2 >> readline;
      output << readline << endl;
      m++;
    }
    else{
      output.close();
      output.open(outfile, ios::out);
      input2 >> readline;
      output << readline << endl;
      m = 0;
    }
    
    //input >> readline;
    //writeline.assign(readline);
    //len = writeline.length() + 1;
    //for (k = 0; k < 10; k++){
    //  spinner();
    //  for (i = 1; i < len; i++){
        //writechar = chars[k];
        //writeline.insert(writeline.begin() + i, writechar);
        //output << writeline << endl;
        //writeline.assign(readline);
     // }
     // output << writeline << endl;
     // templine = writeline + "_";
     // templine = templine + chars[k];
     // output << templine << endl;
    //}
    //j++;
  }
  input.close();
  output.close();
  system("pause");
  return 0;
}
