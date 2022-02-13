cc = g++  
srcs= test.cc
    
LIBS = -lpthread  -std=c++17
  
target = test
  
all: 
	${cc}  -o ${target} ${srcs} ${LIBS}

clean:
	rm ${target} 
  
 