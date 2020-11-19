# The compiler to use.
CC = g++
RC = windres

# Directories for Includes and Common clases
IDIR =../include/
CDIR =../commons/

# Compiler options
CFLAGS= -Wall -O2 -I$(IDIR) 
DLL_CFLAGS= -shared -s -Wl,--subsystem,windows,--out-implib,libmcc.a

# Sources and Common clases sources
SOURCES= main.cpp MCC.cpp Cylinder.cpp dll.cpp
CSOURCES= $(CDIR)Fingerprint.cpp $(CDIR)Functions.cpp $(CDIR)Minutia.cpp $(CDIR)GrahamScanConvexHull.cpp $(CDIR)File19794.cpp $(CDIR)Munkres.cpp


# Objects
OBJECTS=$(SOURCES:.cpp=.o)
COBJECTS=$(CSOURCES:.cpp=.o)

# Name of the executable
EXECUTABLE=mcc.exe
DLL=mcc.dll

all: $(SOURCES) $(CSOURCES) $(EXECUTABLE)

dll: $(DLL) dllres.o
	$(CC) $(CFLAGS) dll.o dllres.o MCC.o Cylinder.o $(COBJECTS) $(DLL_CFLAGS) -o $@

# Build the resource files
dllres.o: dllres.rc
	${RC} -Iinclude -Jrc -v -i "$<" -o "$@"

$(EXECUTABLE): $(OBJECTS) $(COBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(COBJECTS) -o $@

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(COBJECTS) $(EXECUTABLE)
