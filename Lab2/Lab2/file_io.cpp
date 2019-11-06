#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{

	std::vector<std::vector<double> > matrix;
	double v1;
	double v2; 
	double v3;
	double v4;
	std::stringstream ss;
	std::string input;


	std::string filename = "file.txt";

	std::ofstream ofs(filename.c_str(), std::ios::app);
	std::ifstream ifs("input.txt");
	//ofs.open("file.txt", std::ios::app);

	std::cout << "Hello world!" << std::endl;
	ofs << "Hello file, line 2!" << std::endl;
	
	
	// for(int i = 0; i < 4; ++i){
	// 	std::vector<double> v;
	// 	for(int j = 0; j < 4; ++j){
	// 		ifs >> input;
	// 		v.push_back(input);
	// 	}
	// 	matrix.push_back(v);
	// }

	// while(ifs >> v1 >> v2 >> v3 >> v4){
	// 	std::vector<double> v;
	// 	v.push_back(v1);
	// 	v.push_back(v2);
	// 	v.push_back(v3);
	// 	v.push_back(v4);
	// 	matrix.push_back(v);
	// }


	while(std::getline(ifs, input)){	
		std::vector<double> v;
		std::stringstream ss2;
		ss2 << input;
		while(ss2 >> v1){
			v.push_back(v1);
		}

		matrix.push_back(v);
	}

	// std::cout.unsetf(std::ios::dec);
	// std::cout.setf(std::ios::hex);
	// std::cout.setf(std::ios::showbase);

	std::cout.setf(std::ios::showpos);
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.setf(std::ios::left);

	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			std::cout << std::setw(20) << std::setprecision(5) 
			          << matrix[i][j];
		}
		std::cout << std::endl;
	}
	
	
	// char c = ifs.get();
	// ofs.put(c);


	std::cout.unsetf(std::ios::showpos);
	std::cout.unsetf(std::ios::fixed);
	std::cout.unsetf(std::ios::showpoint);
	std::cout.unsetf(std::ios::left);

	//build -12.72
	// ss << '-' << 1 << 2 << ' ' << 7 << 2;
	// ss >> out;

	// std::cout << "out = " << out << std::endl;
	// ss >> out;
	// std::cout << "out = " << out << std::endl;

	// ifs.close();
	// ifs.open("input.txt");
	
	


	return 0;
}
