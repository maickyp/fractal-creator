CPPXX := g++ -std=c++11

INCLUDE_DIR := include
SRC_DIR := src
OUT_DIR := out

# LINKER_FLAGS := 
INCLUDE_FLAGS := -I${INCLUDE_DIR}/
CPP_FLAGS := -Wall -Werror

EXE_FILE :=	fractal-creator.exe

main: main.o 
	${CPPXX} ${OUT_DIR}/main.o \
			 ${OUT_DIR}/bitmap.o \
			 ${OUT_DIR}/mandelbrot.o \
			 ${OUT_DIR}/zoomList.o \
			 ${OUT_DIR}/fractalCreator.o \
			 ${INCLUDE_FLAGS} -o ${EXE_FILE}  ${CPP_FLAGS}

main.o: bitmap.o mandelbrot.o zoomList.o fractalCreator.o
	${CPPXX} ${INCLUDE_FLAGS} -c ${SRC_DIR}/main.cpp -o ${OUT_DIR}/main.o ${CPP_FLAGS}

bitmap.o: ${SRC_DIR}/bitmap.cpp ${INCLUDE_DIR}/bitmap.h
	${CPPXX} ${INCLUDE_FLAGS} -c ${SRC_DIR}/bitmap.cpp -o ${OUT_DIR}/bitmap.o ${CPP_FLAGS}

mandelbrot.o: ${SRC_DIR}/mandelbrot.cpp ${INCLUDE_DIR}/mandelbrot.h
	${CPPXX} ${INCLUDE_FLAGS} -c ${SRC_DIR}/mandelbrot.cpp -o ${OUT_DIR}/mandelbrot.o ${CPP_FLAGS}

zoomList.o: ${SRC_DIR}/zoomList.cpp ${INCLUDE_DIR}/zoomList.h
	${CPPXX} ${INCLUDE_FLAGS} -c ${SRC_DIR}/zoomList.cpp -o ${OUT_DIR}/zoomList.o ${CPP_FLAGS}

fractalCreator.o: ${SRC_DIR}/fractalCreator.cpp ${INCLUDE_DIR}/fractalCreator.h 
	${CPPXX} ${INCLUDE_FLAGS} -c ${SRC_DIR}/fractalCreator.cpp -o ${OUT_DIR}/fractalCreator.o ${CPP_FLAGS}

.PHONY: clean
clean:
	del /F out\*.o
	del /F out\*.bmp
	del /F ${EXE_FILE}
