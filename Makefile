# Makefile for competitive programming C++ setup

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic -Wno-unused-const-variable
TARGET = main
SOURCE = main.cpp
INPUT = input.txt
OUTPUT = output.txt

# Default target: compile and run
all: run

# Compile the program
compile: $(TARGET)

$(TARGET): $(SOURCE)
	@echo "[STEP] Compiling..."
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)
	@if [ $$? -eq 0 ]; then \
		echo "[STEP] Compilation successful!"; \
	else \
		echo "[STEP] Compilation failed!"; \
		exit 1; \
	fi

# Run the program with input.txt
run: compile
	@echo "[STEP] Running the program"
	@touch $(INPUT) $(OUTPUT)
	@start_time=$$(date +%s%N); \
	if [ -f "$(INPUT)" ]; then \
		./$(TARGET) < $(INPUT) > $(OUTPUT); \
	else \
		./$(TARGET) > $(OUTPUT); \
	fi; \
	end_time=$$(date +%s%N); \
	elapsed=$$((end_time - start_time)); \
	elapsed_us=$$((elapsed / 1000)); \
	elapsed_ms=$$((elapsed / 1000000)); \
	echo "[TIME] Execution time: $${elapsed_ms}ms ($${elapsed_us}µs)"; \
	$(MAKE) clean

# Clean up executable
clean:
	@rm -f $(TARGET)
	@echo "[STEP] Executable cleaned up."

# Create new solution: save current main.cpp and reset from template
new:
	@mkdir -p solutions
	@echo -n "Enter solution name (without .cpp): "; \
	read solution_name; \
	if [ -z "$$solution_name" ]; then \
		echo "[ERROR] Solution name cannot be empty!"; \
		exit 1; \
	fi; \
	cp $(SOURCE) "solutions/$${solution_name}.cpp"; \
	echo "[STEP] Saved current solution to solutions/$${solution_name}.cpp"; \
	cp config/template.cpp $(SOURCE); \
	echo "[STEP] Reset $(SOURCE) from template"; \
	> $(INPUT); \
	echo "[STEP] Cleared $(INPUT)"; \
	echo "[DONE] Ready for new problem!"

# Phony targets
.PHONY: all compile run clean new

