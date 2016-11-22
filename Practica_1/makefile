.PHONY: Practica1.pdf all clean

all: Practica1.pdf


%.tex: %.raw
	./raw2tex $< > $@

%.tex: %.dat
	./dat2tex $< > $@


Practica1.pdf: Practica1.tex
	latexmk -f -quiet -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Practica1.tex

clean:
	latexmk -CA