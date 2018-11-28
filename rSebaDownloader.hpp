#include<iostream>
#include "htmlHandler.hpp"
#include "fileHandler.hpp"

struct rSebaFile{
  string name;
  string subdirectory;
  string date;
};

void pdfToKeepRSeba(vector<string> &htmlHeader){
  htmlHeader.erase(htmlHeader.begin());
  htmlHeader.erase(htmlHeader.begin());
  htmlHeader.erase(htmlHeader.begin()+htmlHeader.size()-1);
  htmlHeader.erase(htmlHeader.begin()+htmlHeader.size()-2);
}

void polishPdfRSeba(vector<rSebaFile> fileForSaving, vector<string> &htmleader, string link, string htmlFile){

}

void rSebaFirstTime(){
  string link="http://disi.unitn.it/~rseba/DIDATTICA/prog1_2019/";
  string fileName="rseba";
  string pathOfFile="./Indexes";
  string pathOfPdf="./rSeba";
  vector<string> htmlHeader;
  vector<string> lsParsed;
  saveHtmltoFile(link, fileName, pathOfFile);
  getHtmlHeader(htmlHeader, pathOfFile.append("/").append(fileName));
  modifyHtmlHeader(htmlHeader);
  pdfToKeepRSeba(htmlHeader);
  for(int i=0;i<htmlHeader.size();i++){
    cout<<htmlHeader[i]<<endl;
  }
  /*for(int i=0;i<htmlHeader.size();i++){
    string linkOfPdf=link;
    linkOfPdf.append(htmlHeader[i]);
    saveHtmltoFile(linkOfPdf, htmlHeader[i], pathOfPdf);
  }*/
  /*lsParser(lsParsed, pathOfPdf);*/
  for(int i=0;i<lsParsed.size();i++){
    cout<<lsParsed[i]<<endl;
  }
}
