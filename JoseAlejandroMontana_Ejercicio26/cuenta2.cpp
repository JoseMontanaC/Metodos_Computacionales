#include<iostream>
#include<fstream>
#include<string>
// #include <sstream>
#include <chrono>
#include<vector>
int main(int argc, char **argv)
{
  std::ifstream inFile;
  // std::ofstream cuenta;
  // std::ofstream tiempo;
  
  inFile.open(argv[1]);
  // cuenta.open(argv[2]);
  // tiempo.open(argv[2]);
  
  //Check error
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
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  std::string patron_1= "1";
  std::string patron_2= "12";
  std::string patron_3= "123";
  std::string patron_4= "1234";
  std::string patron_5= "12345";
  std::string intento;
  int C_1=0.0;
  int C_2=0.0;
  int C_3=0.0;
  int C_4=0.0;
  int C_5=0.0;
  for(int ii=0; ii<line.size();ii++)
    {
      if(ii+patron_1.size()>line.size())
  	{
  	  break;
  	}
      for(int jj=ii;jj<=ii+patron_5.size();jj++)
  	{
  	  intento +=line[jj];
	  
  	  if (intento==patron_1)
  	    {
  	      C_1 += 1;
  	    }
  	  if (intento==patron_2)
  	    {
  	      C_2 += 1;
  	    }
  	  if (intento==patron_3)
  	    {
  	      C_3 += 1;
  	    }
  	  if (intento==patron_4)
  	    {
  	      C_4 += 1;
  	    }
  	  if (intento==patron_5)
  	    {
  	      C_5 += 1;
  	    }
	  
  	}
      intento.clear();
    }
  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
  // double duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
  double duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  // double duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  // cuenta<<C_1<<std::endl;
  // cuenta<<C_2<<std::endl;
  // cuenta<<C_3<<std::endl;
  // cuenta<<C_4<<std::endl;
  // cuenta<<C_5<<std::endl;
  std::cout<<duration<<std::endl;
  // tiempo<<duration<<std::endl;
  inFile.close();
  // cuenta.close();
  // tiempo.close();


  
  return 0;
}
