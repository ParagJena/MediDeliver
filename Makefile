CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

TARGET = build/medideliver

SOURCES = src/main.cpp \
          src/Medicine.cpp \
          src/Customer.cpp \
          src/Pharmacy.cpp \
          src/Cart.cpp \
          src/Order.cpp \
          src/Payment.cpp \
          src/Delivery.cpp \
          src/DeliveryQueue.cpp \
          src/FileManager.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
