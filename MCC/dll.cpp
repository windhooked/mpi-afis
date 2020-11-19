#include <stdio.h>
#include <iostream>
#include "MCC.h"
#include <string.h>

/* You should define ADD_EXPORTS *only* when building the DLL. */
#ifdef ADD_EXPORTS
  #define ADDAPI __declspec(dllexport)
#else
  #define ADDAPI __declspec(dllimport)
#endif

/* Define calling convention in one place, for convenience. */
#define ADDCALL __cdecl

/* Make sure functions are exported with C linkage under C++ compilers. */
#ifdef __cplusplus
extern "C"
{
#endif

/* Declare our Add function using the above definitions. */
ADDAPI int ADDCALL Mcc(int argc, char * argv[]);

/* Exported variables. */
//extern ADDAPI int bar;

#ifdef __cplusplus
} // __cplusplus defined.
#endif


int ADDCALL Mcc(int argc, char * argv[])
{
    MCC a1;
	MCC a2;

	if(argc < 3){
			cout << "Usage: MCC <fingerprint1> <fingerprint2> -N {8|16} -C {LSS|LSSR|LSA|LSAR|LGS|NHS} [-H] [-B]" << endl;
			return 0;
	}

	MCC::configureAlgorithm(argc, argv);

	if(a1.readFile(argv[1])!=0){
			cout << "Error opening fingerprint files: " << argv[1] << endl;
			return 0;
	}

	if(a2.readFile(argv[2])!=0){
			cout << "Error opening fingerprint files: " << argv[2] << endl;
			return 0;
	}

	a1.initialize();
	a2.initialize();
	
	cout << "First fingerprint: " << endl;
	a1.printCylinders(cout);

	cout << a1.match(a2) << endl;

	return 0;
}