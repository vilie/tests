# EM

alias s="ssh"
alias r="rm -r"
alias t='top'
alias u='uname -a; w'
alias v='vim'
alias e='exit'
alias ex='exit'
alias nv_on="echo ON > /sys/kernel/debug/vgaswitcheroo/switch"
alias nv_of="echo OFF > /sys/kernel/debug/vgaswitcheroo/switch"
alias hh='history'
alias ll='ls -alhF'

#
# Usage: h - htop
# h <string> - history | grep string
#

function h() {
    case "$#" in
    0) htop
    ;;
    1) history | grep $1
    ;;
    *) echo "Undefined"
    ;;
    esac
}

# p
# Usage: p - ps;
# p <proces> - ps aux | grep proces
# p ip/host - ping ip/host

function p() {
    case "$#" in
    0) ps
    ;;
    1) if [[ $1 =~ [0-9]+\.[0-9]+\.[0-9]+\.[0-9]+ || $1 =~ [a-z]+\.("com"|"net"|"org"|"ro") ]]
       then
           ping $1;
       else
           ps aux | head -1 && ps aux | grep $1;
       fi
    ;;
    *) echo "Undefined"
    ;;
    esac
}

# Usage c - clear; c <sursa> <destinatie>

function c() {
	case "$#" in
	0) 
	if [[ `history | tail -2 | head -1 | awk '{ print $2 $3 }'` = "c" ]]; then
		cd;
	else
		clear;
	fi
	;;
	1) if [[ $1 = "-" ]]; then
        cd -; 
       elif [[ -f $1 ]]; then
        cat $1;
	   elif [[ -d $1 ]]; then
		cd $1 && ls;
       else
        echo "Invalid arg"
	   fi
	;;
	2) cp -vr $1 $2;
	;;
	*) echo "Undefined" 
	;;
    esac
}

# Usage: m = make; m <sursa> <dest>

function m() {
	case "$#" in
	0) make
	;;
	1) mkdir $1 && cd $1;
	;;
	2) mv -v $1 $2
	;;
	*) echo "Undefined"
	;;
esac
}

# Usage: ext archiva.<tar.bz2/tar.gz/bz2/rar/gz>

function ext() {
    if [ -f $1 ] ; then
        case $1 in
            *.tar.bz2)   tar xvjf $1
            ;;
            *.tar.gz)    tar xvzf $1
            ;;
            *.bz2)       bunzip2 $1
            ;;
            *.rar)       unrar x $1
            ;;
            *.gz)        gunzip $1
            ;;
            *.tar)       tar xvf $1
            ;;
            *.tbz2)      tar xvjf $1
            ;;
            *.tgz)       tar xvzf $1
            ;;
            *.zip)       unzip $1
            ;;
            *.Z)         uncompress $1
            ;;
            *.7z)        7z x $1
            ;;
            *)           echo "'$1' Undefined "
            ;;
        esac
    else
        echo "'$1' is not a valid file"
    fi
}
