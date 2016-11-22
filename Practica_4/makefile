.PHONY: Practica4.pdf all clean

all: Practica4.pdf


%.tex: %.raw
	./raw2tex $< > $@

%.tex: %.dat
	./dat2tex $< > $@


Practica4.pdf: Practica4.tex
	latexmk -f -quiet -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Practica4.tex

clean:
	latexmk -CA