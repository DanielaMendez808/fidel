#include <iostream>
using namespace std;
#include "string.h"


struct JBSTNodeStr {
    string name;         // Nombre de la persona
    JBSTNodeStr* left;   // Empleados con nombre menor a name
    JBSTNodeStr* right;  // Empleados con nombre mayor a name
    JBSTNodeStr* parent; // Superior jerárquico directo de name
};
struct JBSTStr {
    JBSTNodeStr* root;
};
typedef JBSTStr* JerarquíaBST;
