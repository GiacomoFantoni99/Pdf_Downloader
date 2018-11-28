//#include "deFranceschiDownloader.hpp"
#include "rSebaDownloader.hpp"
/*string intToStr(int numero){												//variazione da numero a stringa
  stringstream ss;
  ss << numero;
  return ss.str();
}*/
int main(){
  rSebaFirstTime();
  /*string link="http://disi.unitn.it/~rseba/DIDATTICA/prog1_2019/";
  string fileName="rseba";
  string pathOfFile="./Indexes";
  string pathOfPdf="./rSeba";
  vector<string> htmlHeader;
  vector<string> lsParsed;
  saveHtmltoFile(link, fileName, pathOfFile);
  getHtmlHeader(htmlHeader, pathOfFile.append("/").append(fileName));
  modifyHtmlHeader(htmlHeader);
  cout<<"Link\t\t\t\t\tIs pdf\t\t\t\t\tIs compressed file\t\t\t\t\tIs Directory\t\t\t\t\tIs text file\n";
  for(int i=0;i<htmlHeader.size();i++){
    cout<<htmlHeader[i]<<"\t\t\t\t\t";
    cout<<isPdf(getFileExtention(htmlHeader[i]))<<"\t\t\t\t\t";
    cout<<isCompressedFile(getFileExtention(htmlHeader[i]))<<"\t\t\t\t\t";
    cout<<isDirectory(getFileExtention(htmlHeader[i]))<<"\t\t\t\t\t";
    cout<<isTextFile(getFileExtention(htmlHeader[i]))<<endl;
  }
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
  /******************************************/
  /******************************************/
  /******************************************/
  /******************************************/
  /******************************************/
  /******************************************/
  /******************************************/
  /*deFranceschiFirstTime();
  deFranceschiAgg();*/
  return 0;
}
