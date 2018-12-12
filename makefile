SOURCEDIR = src
BINDIR = bin
BUILDDIR = build
INCLUDEDIR = include

all: $(BUILDDIR)/util.o $(BUILDDIR)/errormsg.o $(BUILDDIR)/absyn.o $(BUILDDIR)/y.tab.o $(BUILDDIR)/lex.yy.o $(BUILDDIR)/parser.o
	cc -g -o blox  $^

$(SOURCEDIR)/y.tab.c: $(SOURCEDIR)/blox.y
	yacc -dyv --output="$(SOURCEDIR)/y.tab.c" $(SOURCEDIR)/blox.y

$(SOURCEDIR)/y.tab.h: $(SOURCEDIR)/y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

$(SOURCEDIR)/lex.yy.c: $(SOURCEDIR)/blox.lex
	lex -o $(SOURCEDIR)/lex.yy.c $(SOURCEDIR)/blox.lex

$(BUILDDIR)/lex.yy.o: $(SOURCEDIR)/lex.yy.c $(BUILDDIR)/y.tab.o
	cc -g -c -o $@ $<

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c 
	cc -g -c -o $@ $<

test:
	bash tools/run_tests.sh

clean: 
	rm -fR $(BUILDDIR)/* $(SOURCEDIR)/y.tab.* $(SOURCEDIR)/*.output $(SOURCEDIR)/lex.yy.c
