#include<iostream>
#include "htmlHandler.hpp"
#include "fileHandler.hpp"
void pdfToKeep(vector<string> &htmlHeader){           //polishes the links keeping only 'Nota' and 'Peanuts'
  for(int i=0;i<htmlHeader.size();i++){
    if(htmlHeader[i].find("Nota")==string::npos && htmlHeader[i].find("Peanuts")==string::npos){
      htmlHeader.erase(htmlHeader.begin()+i);
      i--;
    }
  }
}


void deFranceschiFirstTime(){         //If The directory is empty downloads all the relevant pdf
  string link="http://latemar.science.unitn.it/segue_userFiles/2018Analisi1/";
  string fileName="defra";
  string pathOfFile="./Indexes";
  string pathOfPdf="./defra";
  vector<string> htmlHeader;
  vector<string> lsParsed;
  saveHtmltoFile(link, fileName, pathOfFile);
  getHtmlHeader(htmlHeader, pathOfFile.append("/").append(fileName));
  modifyHtmlHeader(htmlHeader);
  pdfToKeep(htmlHeader);
  for(int i=0;i<htmlHeader.size();i++){
    string linkOfPdf=link;
    linkOfPdf.append(htmlHeader[i]);
    saveHtmltoFile(linkOfPdf, htmlHeader[i], pathOfPdf);
  }
  lsParser(lsParsed, pathOfPdf);
  for(int i=0;i<lsParsed.size();i++){
    cout<<lsParsed[i]<<endl;
  }
}

void deFranceschiAgg(){             //check the element in the directory and in the site and updates the directory
  string link="http://latemar.science.unitn.it/segue_userFiles/2018Analisi1/";
  string fileName="defra";
  string pathOfFile="./Indexes";
  string pathOfPdf="./defra";
  vector<string> htmlHeader;
  vector<string> lsParsed;
  saveHtmltoFile(link, fileName, pathOfFile);
  getHtmlHeader(htmlHeader, pathOfFile.append("/").append(fileName));
  modifyHtmlHeader(htmlHeader);
  pdfToKeep(htmlHeader);
  lsParser(lsParsed, pathOfPdf);
  for(int i=0;i<htmlHeader.size();i++){
    bool isSaved=false;
    for(int j=0;j<lsParsed.size();j++){
      if(lsParsed[j]==htmlHeader[i])
        isSaved=true;
    }
    if(!isSaved){
      string linkOfPdf=link;
      linkOfPdf.append(htmlHeader[i]);
      saveHtmltoFile(linkOfPdf, htmlHeader[i], pathOfPdf);
    }
  }
}
