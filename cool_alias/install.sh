#!/bin/bash
#
# Cool Alias
# em @ RST
#


function install_user() {
    cp -v bash_aliases $HOME/.bash_aliases
}

function install_root() {
    for path in `cat /etc/passwd | grep /bin/bash | cut -d ":" -f 6`
    do
        cp -v bash_aliases $path/.bash_aliases
        chmod o+x $path/.bash_aliases
    done
}

function activate() {
    source ~/.bash_aliases
}

if [ `whoami` = "root" ]; then
    echo "INFO: I'm root. Installed for all users.";
    install_root
else
	echo "WARNING: I'm not root. Installing just for the local user!";
    install_user
    activate
fi;

