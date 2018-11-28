#include<string>
#include<vector>
#include<fstream>
using namespace std;

void lsParser(vector<string> &newFile, string directory){ //Returns all files contained in the directory saving them in the vector newFile
  string command="ls ";
  string fileOfLs="lsFile";
  command.append(directory);
  command.append(">> ");
  command.append(fileOfLs);
  system(command.c_str());
  ifstream lsFile(fileOfLs.c_str());
  string line;
  while(getline(lsFile, line)){
    newFile.push_back(line);
  }
  lsFile.close();
  ofstream scrittura(fileOfLs.c_str(), std::ofstream::out | std::ofstream::trunc);
  scrittura.close();
}

string getFileExtention(string fileName){
  bool test=false;
  string res="";
  for(int i=0;i<fileName.length();i++){
    if(fileName[i]=='.')
      test=true;
    if(test)
      res+=fileName[i];
  }
  return res;
  }

bool isPdf(string fileName){
  bool res=false;
  if(getFileExtention(fileName)==".pdf")
    res=true;
  return res;
}

bool isCompressedFile(string fileName){
  bool res=false;
  if(getFileExtention(fileName)==".tar.gz"||getFileExtention(fileName)==".zip")
    res=true;
  return res;
}

bool isDirectory(string fileName){
  bool res=false;
  if(getFileExtention(fileName).empty())
    res=true;
  return res;
}

bool isTextFile(string fileName){
  bool res=false;
  if(getFileExtention(fileName)==".txt")
    res=true;
  return res;
}
