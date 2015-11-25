import sys
import subprocess

init_conf = open('/etc/ssh/sshd_config').read()
final_conf = open('/etc/ssh/sshd_config', 'w')

rootLog=raw_input("Permitir login como root (S/N): ")
rootLog = rootLog.upper()

if rootLog == 'S':
	init_conf = init_conf.replace("PermitRootLogin no", "PermitRootLogin yes",1 )

elif rootLog == 'N':
	init_conf = init_conf.replace("PermitRootLogin yes", "PermitRootLogin no",1 )

else:
	print ( "No es una valor válido")
	exit(-1)

final_conf.write(init_conf)
final_conf.close

subprocess.call("service ssh restart", shell=True)
