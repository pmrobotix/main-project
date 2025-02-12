#ifndef ASSERV_E_CONFIG_H
#define ASSERV_E_CONFIG_H

#define PI 3.14159265358979


#include "parameter.h"

//Débug ou pas ?
//#define DEBUG

class Config
{
public:
    // On définit un attribut pour chaque paramètre (cf params.h)
#   define PARAM(type, nom) static type nom;
#   include "params.h"

    static const Parameter *getParam(std::string name);
    static void loadFile(const char *filename);
    static void saveToFile(const char *template_filename, const char *filename);
    static std::string dumpConfig();
    //static const PinName pinNameList[];

private:
    static const Parameter params[];
    static const Parameter *parseConfigLine(std::string line, std::string &name, std::string &val);
};

#endif
