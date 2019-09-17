#ifndef KROBCMD_H
#define KROBCMD_H

#include <string>
#include <vector>

template <class T>
struct kObject{ //Class for variables
std::string name;
T value;

};

class StrIO{   //Used for output control
protected:
std::string fullContents;
virtual std::string inOp() = 0; //Controls what happens when input is given to the object
virtual std::string outOp() = 0; //Controls what happens when the contents are requested
	
public:
StrIO();
void write(std::string content);
std::string read();
void clear();

};

class MainIO:public StrIO{
protected:
std::string inOp();
std::string outOp();
}; 

namespace vars{ //Any variable declaration that would otherwise be global
	std::vector<kObject<int>> intv;
	std::vector<kObject<std::string>> strv;
	MainIO mainio;
}



//-----------------------inline functions used due to use of templates in this section----------------------------
template <class T>
inline int varLocationInVect(std::string name, std::vector<T> vect){
	for(int i=0; i < vect; i++){
		if(vect[i].name == name) return i;
		else if(i==vect.size - 1) return -1;
	}
}


template<class T>
inline kObject<T> *createVar(std::string name, T &val){
	kObject<T> *tempObj;
	tempObj->name = name;
	tempObj->value = val;
	return tempObj;
}

template<class T>
inline kObject<T> *getVar(std::string name, std::string type){
	int location;
	if(type=="int") location = varLocationInVect<kObject<int>>(name, vars::intv);
	else location = varLocationInVect<kObject<std::string>>(name, vars::strv);
	
	if(location != -1){
		if(type=="int") return &vars::intv[location];
		else return &vars::strv[location];
	} 
} 

//-----------------------------------------------------------------------------------------------------------------



#endif
