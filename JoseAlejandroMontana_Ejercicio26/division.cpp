#include<iostream>
#include<fstream>
#include<string>
#include <chrono>
#include<vector>
int main(int argc, char **argv)
{
  std::ifstream inFile;
  inFile.open(argv[1]);
  if(inFile.fail())
    {
      std::cerr << " Error Opening file"<<std::endl;
      exit(1);
    }
  std::string line;
  
  while(!inFile.eof())
    {
      inFile >> line;
    }
  
  // std::vector<int> d_list = {10,20,30,40,50,60,70,80,90,100};
  std::string intento;
  // for (auto division : d_list)
    // {
      // Dividir el string
  int division = 10;
  int r=line.size()/division;
  for(int kk=0; kk<division;kk++)
    {
      for(int ii = kk*r;ii<(kk+1)*r;ii++)
	{
	  intento +=line[ii];
	}
      std::cout<<intento<<"\n"<<std::endl;
      intento.clear();
      }
    // }
  return 0;
}
