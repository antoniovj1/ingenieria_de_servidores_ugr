BEGIN {
  numeros=0;
  suma=0;
}

{
  if( $3 ~/[0-9]/) #Elementos que esten en la tercera posición y sean un número
  {
	numeros+=1
	suma+=$3
  }
}

END {
    printf "\n\nHay " numeros " numeros que ocupan la tercera posición" 
    printf "de una linea\n y suman " suma "\n\n"
}
