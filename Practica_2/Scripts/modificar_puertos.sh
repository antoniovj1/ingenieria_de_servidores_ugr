#!/bin/bash

echo -n "Nuevo puerto para SSH: "
read port


if [ "$port" -eq "$port" ] #Comprueba que el puerto es un numero.
then
   sed -i  "s/Port .*/Port $port/" /etc/ssh/sshd_config 
   service ssh restart
   echo "SSH cambiado al puerto " $port 

else
   echo  $port ": El puerto debe ser un número"
fi

#Tras 60 segundos se vuelve a la configuración inicial
sleep 60 && sed -i "s/Port .*/Port 22/" /etc/ssh/sshd_config && service ssh restart &
