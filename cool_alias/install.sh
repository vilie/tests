#!/bin/bash
for path in `cat /etc/passwd | grep /bin/bash | cut -d ":" -f 6`
do
    cp -v .bash_aliases $path
    chmod o+x $path/.bash_aliases
done
    
