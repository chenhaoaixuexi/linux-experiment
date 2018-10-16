# theme
set_color purple
set fish_greeting 'Talk is cheap. Show me the code.'

#variable
set linux_c ~/linux_c
set fish ~/.config/fish/config.fish
set vim ~/.vimrc


#alias
alias cman 'man -M /usr/share/man/zh_CN' 
alias cao fuck
alias s 'sudo screen'


#function
function cdc
	cd /mnt/c/
end
function cdd
	cd /mnt/d/
end
function cdf
	cd /mnt/f/
end

thefuck --alias | source

function pl
	ps -l 
end

function man
  /usr/bin/man $argv | col -b | /usr/bin/vim -R -c 'set ft=man nomod nolist' -
end


