all:
	lex tema.l
	yacc -d tema.y
	gcc lex.yy.c y.tab.c -o ex
clean:
	rm -f ex lex.yy.c y.tab.c
