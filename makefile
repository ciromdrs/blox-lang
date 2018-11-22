SRCDIR = .

lextest: $(SRCDIR)/driver.o $(SRCDIR)/lex.yy.o $(SRCDIR)/errormsg.o $(SRCDIR)/util.o
	cc -g -o $(SRCDIR)/lextest $(SRCDIR)/driver.o $(SRCDIR)/lex.yy.o $(SRCDIR)/errormsg.o $(SRCDIR)/util.o

driver.o: $(SRCDIR)/driver.c $(SRCDIR)/tokens.h $(SRCDIR)/errormsg.h $(SRCDIR)/util.h
	cc -g -c $(SRCDIR)/driver.c

errormsg.o: $(SRCDIR)/errormsg.c $(SRCDIR)/errormsg.h $(SRCDIR)/util.h
	cc -g -c $(SRCDIR)/errormsg.c

lex.yy.o: $(SRCDIR)/lex.yy.c $(SRCDIR)/tokens.h $(SRCDIR)/errormsg.h $(SRCDIR)/util.h
	cc -g -c $(SRCDIR)/lex.yy.c

lex.yy.c: $(SRCDIR)/blox.lex
	lex $(SRCDIR)/blox.lex

util.o: $(SRCDIR)/util.c $(SRCDIR)/util.h
	cc -g -c $(SRCDIR)/util.c

clean: 
	rm -f a.out $(SRCDIR)/util.o $(SRCDIR)/driver.o $(SRCDIR)/lex.yy.o $(SRCDIR)/lex.yy.c $(SRCDIR)/errormsg.o
