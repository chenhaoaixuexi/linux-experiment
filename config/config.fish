# theme
set_color purple
set fish_greeting 'Talk is cheap. Show me the code.'

#variable
set linux_c ~/linux_c
set fish ~/.config/fish/config.fish
set vim ~/.vimrc
set cgdb ~/.cgdb/cgdbrc


#alias
alias cman 'man -M /usr/share/man/zh_CN' 
alias cao fuck
alias s 'sudo screen'
alias in 'sudo screen -r'
# alias ls 'ls -1l'


#function

function cl
cd $argv;ls -1
end

function desk
export DISPLAY=localhost:0
sudo ccsm
sudo compiz
end

function tk
kill -9 (ps -ef |grep $argv |awk '{print $2}')
end

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


