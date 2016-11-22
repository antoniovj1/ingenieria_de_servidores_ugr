.PHONY: Practica3.pdf all clean

all: Practica3.pdf


%.tex: %.raw
	./raw2tex $< > $@

%.tex: %.dat
	./dat2tex $< > $@


Practica3.pdf: Practica3.tex
	latexmk -f -quiet -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Practica3.tex

clean:
	latexmk -CA