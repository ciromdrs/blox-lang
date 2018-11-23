a.out: parsetest.o y.tab.o lex.yy.o errormsg.o util.o
	cc -g parsetest.o y.tab.o lex.yy.o errormsg.o util.o

parsetest.o: parsetest.c errormsg.h util.h
	cc -g -c parsetest.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: blox.grm
	yacc -dvtW blox.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

#lex.yy.c: blox.lex # (add this to clean:)
#	lex blox.lex

util.o: util.c util.h
	cc -g -c util.c

test:
	bash tools/run_tests.sh

clean: 
	rm -f a.out util.o parsetest.o lex.yy.o errormsg.o y.tab.c y.tab.h y.tab.o
