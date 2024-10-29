songo : main_yomen.c fonction_yomen.c fonction_yomen.h
	gcc -o songo main_yomen.c fonction_yomen.c

run:
	./songo

clean:
	rm songo