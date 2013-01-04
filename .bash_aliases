# EM

alias r="rm"
alias p='ps'
alias t='top'
alias h='htop'
alias u='uname -a; w'
alias v='vim'
alias e='exit'
alias ex='exit'
alias nv_on="echo ON > /sys/kernel/debug/vgaswitcheroo/switch"
alias nv_of="echo OFF > /sys/kernel/debug/vgaswitcheroo/switch"

function c() {
	case "$#" in
	0) clear
	;;
	1) if [[ -f $1 ]]; then
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
