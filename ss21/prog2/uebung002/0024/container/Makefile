#source_paths
SRC:=./src/
CPP_SOURCE_DIR:=./src/cpp/
C_SOURCE_DIR:=./src/c/
INCLUDE_DIR:=./src/include/

BUILD_DIR:=./build/
OUT_DIR:=./out/

#SRC/OBJECT files to compile for project
CPP_OBJECTS:=\
	ShaderInterface\
	Shape\
	StringHelper\
	ViewPortGL\
	WindowInterface\
	Square\
	Disk\
	EquiliteralTriangle\
	PulsatingAnimation\
	BinaryVisuals\
	bitmagic\
	main\

LINUX_CPP_OBJECTS:=$(addprefix $(BUILD_DIR)linux/,$(CPP_OBJECTS))
LINUX_CPP_OBJECTS:=$(addsuffix .o,$(LINUX_CPP_OBJECTS))
WIN32_CPP_OBJECTS:=$(addprefix $(BUILD_DIR)windows32/,$(CPP_OBJECTS))
WIN32_CPP_OBJECTS:=$(addsuffix .o,$(WIN32_CPP_OBJECTS))
WIN64_CPP_OBJECTS:=$(addprefix $(BUILD_DIR)windows64/,$(CPP_OBJECTS))
WIN64_CPP_OBJECTS:=$(addsuffix .o,$(WIN64_CPP_OBJECTS))

C_OBJECTS:=\
	glad\

LINUX_C_OBJECTS:=$(addprefix $(BUILD_DIR)linux/,$(C_OBJECTS))
LINUX_C_OBJECTS:=$(addsuffix .o,$(LINUX_C_OBJECTS))
WIN32_C_OBJECTS:=$(addprefix $(BUILD_DIR)windows32/,$(C_OBJECTS))
WIN32_C_OBJECTS:=$(addsuffix .o,$(WIN32_C_OBJECTS))
WIN64_C_OBJECTS:=$(addprefix $(BUILD_DIR)windows64/,$(C_OBJECTS))
WIN64_C_OBJECTS:=$(addsuffix .o,$(WIN64_C_OBJECTS))

#CC which compiler
#linux
LCC=g++
LC=gcc
#win32
WCC32=i686-w64-mingw32-g++
WC32=i686-w64-mingw32-gcc
#win64
WCC64=x86_64-w64-mingw32-g++
WC64=x86_64-w64-mingw32-gcc

#compiler flags
COMPILER_FLAGS=-g -Wall

#linker flags specifies which libraries
LINKER_FLAGS=
LINUX_LINKER_FLAGS=-lglfw -lGL -lX11 -lpthread -lXrandr -ldl
WIN_LINKER_FLAGS=-Wl,-subsystem,windows -static -static-libgcc -static-libstdc++ -lpthread -lmingw32 -lglfw3dll -lopengl32 -lgdi32 -luser32 -lkernel32 -ladvapi32 -lshell32 -luser32 -lkernel32 -lmingw32 -lgcc -lmoldname -lmingwex -lmsvcrt
#WIN_LINKER_FLAGS=-lmingw32 -lglfw3 -lopengl32

#windows dlls needed
WINDOWS_DLLS=\
	glfw3.dll\

LICENCES=\

WINDOWS_DLLS_32:=$(addprefix $(OUT_DIR)windows/32/,$(WINDOWS_DLLS))
WINDOWS_DLLS_64:=$(addprefix $(OUT_DIR)windows/64/,$(WINDOWS_DLLS))


#NAME name of executable
NAME=uebung

#output path
LINUX_EXECUTABLE="$(OUT_DIR)linux/$(NAME)"
LINUX_PACKAGE="$(OUT_DIR)$(NAME)-linux.zip"
WIN32_EXECUTABLE="$(OUT_DIR)windows/32/$(NAME)32.exe"
WIN32_PACKAGE="$(OUT_DIR)$(NAME)-win32.zip"
WIN64_EXECUTABLE="$(OUT_DIR)windows/64/$(NAME)64.exe"
WIN64_PACKAGE="$(OUT_DIR)$(NAME)-win64.zip"

#-----------------------------------------------------------#
#-----------------------------------------------------------#
#-----------------------------------------------------------#

.PHONY: all clean LINUX WINDOWS WINDLLS FINISHED

all: LINUX WINDOWS

LINUX: $(LINUX_EXECUTABLE) $(LINUX_PACKAGE) FINISHED

#WINDOWS: $(WIN32_EXECUTABLE) $(WIN64_EXECUTABLE) WINDLLS $(WIN32_PACKAGE) $(WIN64_PACKAGE) FINISHED
WINDOWS: $(WIN64_EXECUTABLE) WINDLLS $(WIN64_PACKAGE) FINISHED

#WINDLLS: $(WINDOWS_DLLS_32) $(WINDOWS_DLLS_64) FINISHED
WINDLLS: $(WINDOWS_DLLS_64)

#-----------------------------------------------------------#
#-----------------------------------------------------------#
#-----------------------------------------------------------#
#- LINUX -#
#---------#

#linking executable
$(LINUX_EXECUTABLE): $(LINUX_C_OBJECTS) $(LINUX_CPP_OBJECTS)
	@mkdir -p "$(shell dirname $@)"
	$(LCC) $(COMPILER_FLAGS) -o $@ $^ $(LINUX_LINKER_FLAGS) $(LINKER_FLAGS)

#compiling object files
$(LINUX_C_OBJECTS): $(BUILD_DIR)linux/%.o: $(C_SOURCE_DIR)%.c
	@mkdir -p "$(shell dirname $@)"
	$(LC) $(COMPILER_FLAGS) -c $< -I $(INCLUDE_DIR) -o $@

$(LINUX_CPP_OBJECTS): $(BUILD_DIR)linux/%.o: $(CPP_SOURCE_DIR)%.cpp
	@mkdir -p "$(shell dirname $@)"
	$(LCC) $(COMPILER_FLAGS) -c $< -I $(INCLUDE_DIR) -o $@

$(LINUX_PACKAGE): $(LINUX_EXECUTABLE)
	@cd $(OUT_DIR)linux/ && zip -r ../../$@ *

#-----------------------------------------------------------#
#-----------------------------------------------------------#
#- WIN32 -#
#---------#

#linking executable
$(WIN32_EXECUTABLE): $(WIN32_C_OBJECTS) $(WIN32_CPP_OBJECTS)
	mkdir -p $(shell dirname $@)
	$(WCC32) $(COMPILER_FLAGS) -o $@ $^ -L$(SRC)win-extras/lib-32 $(WIN_LINKER_FLAGS) $(LINKER_FLAGS)

#creating object files
$(WIN32_C_OBJECTS): $(BUILD_DIR)windows32/%.o: $(C_SOURCE_DIR)%.c
	mkdir -p $(shell dirname $@)
	$(WCC32) $(COMPILER_FLAGS) -o $@ -c $< -I $(SRC)win-extras/include-32/ -I $(INCLUDE_DIR) $(WIN_LINKER_FLAGS) $(LINKER_FLAGS)

$(WIN32_CPP_OBJECTS): $(BUILD_DIR)windows32/%.o: $(CPP_SOURCE_DIR)%.cpp
	mkdir -p $(shell dirname $@)
	$(WCC32) $(COMPILER_FLAGS) -o $@ -c $< -I $(SRC)win-extras/include-32/ -I $(INCLUDE_DIR) $(WIN_LINKER_FLAGS) $(LINKER_FLAGS)

#-----------------------------------------------------------#
#- WIN64 -#
#---------#

#linking executable
$(WIN64_EXECUTABLE): $(WIN64_C_OBJECTS) $(WIN64_CPP_OBJECTS)
	mkdir -p $(shell dirname $@)
	$(WCC64) $(COMPILER_FLAGS) -o $@ $^ -L$(SRC)win-extras/lib-64 $(WIN_LINKER_FLAGS) $(LINKER_FLAGS)

#creating object files
$(WIN64_C_OBJECTS): $(BUILD_DIR)windows64/%.o: $(C_SOURCE_DIR)%.c
	mkdir -p $(shell dirname $@)
	$(WC64) $(COMPILER_FLAGS) -o $@ -c $< -I $(SRC)win-extras/include-64/ -I $(INCLUDE_DIR) $(WIN_LINKER_FLAGS) $(LINKER_FLAGS)

$(WIN64_CPP_OBJECTS): $(BUILD_DIR)windows64/%.o: $(CPP_SOURCE_DIR)%.cpp
	mkdir -p $(shell dirname $@)
	$(WCC64) $(COMPILER_FLAGS) -o $@ -c $< -I $(SRC)win-extras/include-64/ -I $(INCLUDE_DIR) $(WIN_LINKER_FLAGS) $(LINKER_FLAGS)

#-----------------------------------------------------------#

$(WINDOWS_DLLS_32): $(OUT_DIR)windows/32/%: $(SRC)win-extras/win-runtime-32/%
	cp $< $@

$(WINDOWS_DLLS_64): $(OUT_DIR)windows/64/%: $(SRC)win-extras/win-runtime-64/%
	cp $< $@

#-----------------------------------------------------------#

$(WIN32_PACKAGE): $(WIN32_EXECUTABLE)
	cd $(OUT_DIR)windows/32 && zip -r ../../../$@ *

$(WIN64_PACKAGE): $(WIN64_EXECUTABLE)
	cd $(OUT_DIR)windows/64 && zip -r ../../../$@ *

#-----------------------------------------------------------#
#-----------------------------------------------------------#
#-----------------------------------------------------------#

clean:
	rm -rf   $(BUILD_DIR)linux $(BUILD_DIR)windows32 $(BUILD_DIR)windows64 $(OUT_DIR)linux $(OUT_DIR)windows/32 $(OUT_DIR)windows/64
	mkdir -p $(BUILD_DIR)linux $(BUILD_DIR)windows32 $(BUILD_DIR)windows64 $(OUT_DIR)linux $(OUT_DIR)windows/32 $(OUT_DIR)windows/64

FINISHED:
	@printf ' ____  ____  _  _  ____  ___  _   _  ____  ____\n( ___)(_  _)( \\( )(_  _)/ __)( )_( )( ___)(  _ \\\n )__)  _)(_  )  (  _)(_ \\__ \\ ) _ (  )__)  )(_) )\n(__)  (____)(_)\_)(____)(___/(_) (_)(____)(____/\n'
