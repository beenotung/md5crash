CC=gcc
CFLAGS=-I.

SRCDIR = src
BUILDDIR = build

EXE = md5crash
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))


all: $(BUILDDIR) $(BUILDDIR)/$(EXE)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXE): $(OBJ)
	$(CC) -o $@ $^

$(OBJ): $(BUILDDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BUILDDIR)/*.o $(BUILDDIR)/$(EXE)
	find -type d -empty -name $(BUILDDIR) -delete
