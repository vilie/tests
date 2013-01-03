# EM

alias p='ps'
alias t='top'
alias h='htop'
alias u='uname -a; w'
alias v='vim'
alias e='exit'
alias ex='exit'
alias nv_on="echo ON > /sys/kernel/debug/vgaswitcheroo/switch"
alias nv_of="echo OFF > /sys/kernel/debug/vgaswitcheroo/switch"
function m() { mkdir $1; cd $1; }
function c() {
	case "$#" in
	0) clear
	;;
	1) cd $1; ls;
	;;
	2) cp -vr $1 $2;
	;;
	*) echo "Undefined"
	;;
esac
}
