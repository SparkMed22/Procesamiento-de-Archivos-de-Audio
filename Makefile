#  Copyright (c) 2025 SparkMed. All Rights Reserved.
# Alumno: Francisco David Medina
# Objetivo: Ejecutar en Linux/Mac de manera comoda y borrar archivos basura


# Compilador y banderas
CC = gcc
CFLAGS = -g -Wall -Iinclude

# Directorios
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN = proyecto2.exe
DAT = *.dat
RAV = *.wav

# Archivos fuente y objeto
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Regla por defecto
all: $(BIN)

# Linkeo final
$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilación de cada .c a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BIN) $(DAT) $(RAV) 
	

.PHONY: all clean
