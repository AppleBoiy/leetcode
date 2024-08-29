JAVAC = javac
JAVA = java
SRC_DIR = java/src
CLASS_DIR = java/classes

SRC_FILES = $(wildcard $(SRC_DIR)/*.java)
CLASS_FILES = $(SRC_FILES:$(SRC_DIR)/%.java=$(CLASS_DIR)/%.class)

all: $(CLASS_FILES)

$(CLASS_DIR)/%.class: $(SRC_DIR)/%.java
	@mkdir -p $(CLASS_DIR)
	$(JAVAC) -d $(CLASS_DIR) $(SRC_DIR)/ListNode.java $(SRC_DIR)/Solution.java $(SRC_DIR)/Main.java

run: all
	$(JAVA) -cp $(CLASS_DIR) src.Main

clean:
	rm -rf $(CLASS_DIR)

.PHONY: all run clean
