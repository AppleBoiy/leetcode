KOTLINC = kotlinc
KOTLIN = kotlin
SRC_DIR = src
BUILD_DIR = build
MAIN_CLASS = MainKt

all: compile run

compile:
	@mkdir -p $(BUILD_DIR)
	$(KOTLINC) $(SRC_DIR)/*.kt -d $(BUILD_DIR)

run:
	$(KOTLIN) -cp $(BUILD_DIR) $(MAIN_CLASS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all compile run clean
