CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

SRCS = main.cpp imp_metodos/corretor.cpp imp_metodos/cliente.cpp imp_metodos/imovel.cpp
TARGET = imobiliaria

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
