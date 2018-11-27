SOURCEDIR = src
BINDIR = bin
BUILDDIR = build

blox: $(BUILDDIR)/parser.o $(BUILDDIR)/y.tab.o $(BUILDDIR)/lex.yy.o $(BUILDDIR)/errormsg.o $(BUILDDIR)/util.o
	cc -g -o blox  $(BUILDDIR)/parser.o $(BUILDDIR)/y.tab.o $(BUILDDIR)/lex.yy.o $(BUILDDIR)/errormsg.o $(BUILDDIR)/util.o

$(BUILDDIR)/parser.o: $(SOURCEDIR)/lex.yy.c $(SOURCEDIR)/errormsg.h $(SOURCEDIR)/util.h
	cc -g -c -o $(BUILDDIR)/parser.o $(SOURCEDIR)/parser.c

$(BUILDDIR)/y.tab.o: $(SOURCEDIR)/y.tab.c
	cc -g -c -o $(BUILDDIR)/y.tab.o $(SOURCEDIR)/y.tab.c

$(SOURCEDIR)/y.tab.c: $(SOURCEDIR)/blox.y
	yacc -dyv --output="$(SOURCEDIR)/y.tab.c" $(SOURCEDIR)/blox.y

$(SOURCEDIR)/y.tab.h: $(SOURCEDIR)/y.tab.c
	echo "$(SOURCEDIR)/y.tab.h was created at the same time as $(SOURCEDIR)/y.tab.c"

$(BUILDDIR)/errormsg.o: $(SOURCEDIR)/errormsg.c $(SOURCEDIR)/errormsg.h $(SOURCEDIR)/util.h
	cc -g -c -o $(BUILDDIR)/errormsg.o $(SOURCEDIR)/errormsg.c

$(BUILDDIR)/lex.yy.o: $(SOURCEDIR)/lex.yy.c $(SOURCEDIR)/y.tab.h $(SOURCEDIR)/errormsg.h $(SOURCEDIR)/util.h
	cc -g -c -o $(BUILDDIR)/lex.yy.o $(SOURCEDIR)/lex.yy.c

$(SOURCEDIR)/lex.yy.c: $(SOURCEDIR)/blox.lex $(SOURCEDIR)/y.tab.h
	lex -o $(SOURCEDIR)/lex.yy.c $(SOURCEDIR)/blox.lex

$(BUILDDIR)/util.o: $(SOURCEDIR)/util.c $(SOURCEDIR)/util.h
	cc -g -c -o $(BUILDDIR)/util.o $(SOURCEDIR)/util.c

test:
	bash tools/run_tests.sh

clean: 
	rm -fR $(BUILDDIR)/* $(SOURCEDIR)/y.tab.c $(SOURCEDIR)/y.tab.h $(SOURCEDIR)/.output $(SOURCEDIR)/lex.yy.c
