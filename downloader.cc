#include "downloaderFunction.hpp"
using namespace std;
/*string intToStr(int numero){												//variazione da numero a stringa
  stringstream ss;
  ss << numero;
  return ss.str();
}*/
int main(){
  string link="http://latemar.science.unitn.it/segue_userFiles/2018Analisi1/";
  string fileName="defraIndex";
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
  return 0;
}
