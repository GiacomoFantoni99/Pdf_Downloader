#include<string>
#include<vector>
#include<fstream>
using namespace std;

void saveHtmltoFile(string link, string fileName, string pathOfFile){ //uses wget to save the link in an html file in directory pathOfFile named fileName
  string command="wget -O ";
  command.append(pathOfFile);
  command+='/';
  command.append(fileName);
  command+=' ';
  command.append(link);
  system(command.c_str());
}

void getHtmlHeader(vector<string> &htmlHeader, string fileLettura){ //given an html files, saves in a vector of strings the tags contaning a link
  ifstream filmList(fileLettura.c_str());
  string line;
  while (getline(filmList, line)) {
    if (line.find("href=\"")!=string::npos) {
      bool test=true;
      for(int i =0;i<htmlHeader.size();i++){
        if(htmlHeader[i]==line)
          test=false;
      }
      if(test){
        size_t startOfCut=line.find("<a href");
        int cutLenght=0;
        bool test=true;
        for(int i=startOfCut;i<line.size() && test==true;i++){
          if(i-3>0&&line[i]=='>'&&line[i-1]=='a'&&line[i-2]=='/'&&line[i-3]=='<'){
            cutLenght=i+1;
            test=false;
          }
        }
        cutLenght-=startOfCut;
        htmlHeader.push_back(line.substr(startOfCut,cutLenght));
      }
    }
  }
  filmList.close();
}


string searchLink(string htmlLine){                     //given a line with inside a link, returns the link
  string temp="";
  for(int i=0;i<htmlLine.size();i++){
    if(htmlLine[i]=='\"' && htmlLine[i-1]=='=' &&  htmlLine[i-2]=='f' &&  htmlLine[i-3]=='e' &&  htmlLine[i-4]=='r' &&  htmlLine[i-5]=='h'){
      for(int j=i+1;htmlLine[j]!='\"';j++){
        temp+=htmlLine[j];
      }
    }
  }
  return temp;
}

void modifyHtmlHeader(vector<string> &htmlHeader){    //given a vector containing the a tags it extracts from them the link
  for(int i=0;i<htmlHeader.size();i++){
    htmlHeader[i]=searchLink(htmlHeader[i]);
  }
}
