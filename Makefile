CFLAGS=-Wall -Werror -I.
DEPS=utils.h
ODIR=obj
BINDIR=bin

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

BasicCaller: $(ODIR)/BasicCaller.o $(ODIR)/utils.o
	$(CC) $(CFLAGS) -o $(BINDIR)/BasicCaller $^

main: $(ODIR)/main.o $(ODIR)/utils.o
	$(CC) $(CFLAGS) -o $(BINDIR)/main $^

treelist: treelist.c
	$(CC) $(CFLAGS) -o $(BINDIR)/treelist $^

.PHONY: clean

clean:
	rm $(ODIR)/*.o $(BINDIR)/*
