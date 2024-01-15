#CFLAGS = -std=c++17 -O2
#LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
#
#VulkanTest: main.cpp Vorpal.cpp Vorpal.h
#    g++ $(CFLAGS) -o VulkanTest main.cpp Vorpal.cpp $(LDFLAGS)  # Compilation command corrected
#
#.PHONY: test clean
#
#test: VulkanTest
#    ./VulkanTest
#

CFLAGS = -std=c++17 -O2
VULKAN_FLAGS = Vorpal.cpp Vorpal.h  -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

clean:
	rm -f *.o

all: main.cpp
	g++ main.cpp $(CFLAGS) $(VULKAN_FLAGS) -o main.o
	./main.o