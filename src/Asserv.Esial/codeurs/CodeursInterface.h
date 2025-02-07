#ifndef ASSERV_E_CODEURS_INTERFACE
#define ASSERV_E_CODEURS_INTERFACE



//Interface pour la gestion de deux codeurs
class CodeursInterface
{

public:
    virtual ~CodeursInterface() { }
    virtual void getCounts(int32_t* deltaCountG, int32_t* deltaCountD) = 0;

};

#endif
