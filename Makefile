CC=gcc
CFLAGS=-I. -lm
CFLAG=-I.
BUILDDIR=build
SRCDIR=src
OBJDIR=obj

EXE=password-manager.out

SOURCES = $(wildcard $(SRCDIR)/*.c)
HEADERS = $(wildcard $(SRCDIR)/*.h)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

all: build

build: $(OBJ)
	@echo "================================="
	@echo "Linking the target $@"
	@echo "================================="
	$(CC) -o $(EXE) $^ $(CFLAGS)
	@echo -- Linked Finished --
	@echo "================================================================================"
	@echo "================================================================================"
	@echo ""
	@echo "For more information, open the README.md."
	@echo "If you have any questions, feel free to email me at dlcheung@uwaterloo.ca."

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	mkdir -p $(OBJDIR)
	@echo "================================="
	@echo "Compiling the target $@"
	@echo "================================="
	$(CC) -c -o $@ $< $(CFLAG)

clean:
	rm -rf $(OBJDIR) $(EXE) ABP.csv
