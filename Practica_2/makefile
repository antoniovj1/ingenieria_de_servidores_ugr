.PHONY: Practica2.pdf all clean

all: Practica2.pdf


%.tex: %.raw
	./raw2tex $< > $@

%.tex: %.dat
	./dat2tex $< > $@


Practica2.pdf: Practica2.tex
	latexmk -f -quiet -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Practica2.tex

clean:
	latexmk -CA