BIN 	= bin
SRC 	= src
OBJ 	= obj
LIB 	= lib
INCLUDE = include

CXX = g++

CXXFLAGS=  -I/usr/include -I$(INCLUDE)
LDFLAGS=  -lGLU -lGL -lglut



TARGETS = practica3


all: clean $(TARGETS)

$(TARGETS):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cc $(CXXFLAGS) $(SRC)/escena.cc $(SRC)/ejes.cc $(SRC)/objeto.cc $(SRC)/file_ply_stl.cc $(SRC)/objeto_rev.cc $(SRC)/bounding_box.cc $(SRC)/cubo.cc $(SRC)/base.cc $(SRC)/foco.cc $(SRC)/amplificador.cc $(SRC)/lampara.cc $(SRC)/cilindro.cc $(LDFLAGS)
	#$(CXX) -o $(BIN)/$@ $(SRC)/$@.cc $(CXXFLAGS) $(SRC)/model.cpp $(SRC)/model_lanzadera.cpp $(LDFLAGS)


.PHONY: clean
clean:
	@echo "Limpiando..."
	@rm -f $(OBJ)/*\
        $(BIN)/*\
