#!/bin/bash
#
# Cool Alias
# em @ RST
#

if [ `whoami` = "root" ]; then
	echo "INFO: uid 0; fine";
else
	echo "WARNING: not root; exiting";
	exit 3;
fi;
	

for path in `cat /etc/passwd | grep /bin/bash | cut -d ":" -f 6`
do
    cp -v .bash_aliases $path
    chmod o+x $path/.bash_aliases
done
    
