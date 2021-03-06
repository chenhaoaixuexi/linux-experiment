"============================================================|fold |====================================================
set foldmethod=marker "set default foldmethod

"=====================================================| highlight search|====================================================
" 当光标一段时间保持不动了，就禁用高亮
autocmd cursorhold * set nohlsearch
" 当输入查找命令时，再启用高亮
noremap n :set hlsearch<cr>n
noremap N :set hlsearch<cr>N
noremap / :set hlsearch<cr>/
noremap ? :set hlsearch<cr>?
noremap * *:set hlsearch<cr>*
noremap # #:set hlsearch<cr>#
set ic

""====================================================|indent config |====================================================
set tabstop=4              "设置tab长度为4 
set shiftwidth=4           "设置自动对齐的缩进级别 
set cindent                "自动缩进,以c语言风格，例如从if进入下一行，会自动缩进shiftwidth大小 
set smartindent            "改进版的cindent,自动识别以#开头的注释，不进行换行 
set autoindent              "autoindent配合下面一条命令根据不同语言类型进行不同的缩进操作，更加智能 

"====================================================| man doc |====================================================
"" 查看方法输入:Man api_name
source $VIMRUNTIME/ftplugin/man.vim
"" 映射之后就可以少按一下 Shift 键。
"cmap man Man
"" 在普通模式下按下 K （大写）即可启动 man 查看光标下的函数。
nmap K :Man 3 <cword><CR>
nmap <space>K :Man 




set relativenumber
map <C-q> :<esc>!shell<CR>
set guifont=YaHei\ Consolas\ Hybrid\ 11.5

"====================================================| paste|====================================================
set pastetoggle=<F11>

"====================================================| leader  map |====================================================
let mapleader="\\"

map <leader>s <esc>:wa!<cr>zz
map <leader>w <esc>:wq!<cr>
map <leader>q <esc>:wqa!<cr>
map <leader><esc> <esc>:qa!<cr>
map <space><space> gg=G``zz<esc>:wa!<cr> 
map <space>o o<esc>
map <space>s <esc>:wa!<cr>zz
map <space>w <esc>:wq!<cr>
map <space>q <esc>:wqa!<cr>
map <space>v <esc>:reg<cr>

"====================================================| win move |====================================================
nmap  -  <Plug>(choosewin)
" if you want to use overlay feature
let g:choosewin_overlay_enable = 1
map <space>x <C-w>q
map <space>= <C-w>w
map <space><tab> gt


set nobackup
"不要生成swap文件，当buffer被丢弃的时候隐藏它
setlocal noswapfile
set bufhidden=hide
"自动格式化
set formatoptions=tcrqn
set autoindent


autocmd BufWritePost $MYVIMRC source $MYVIMRC
set number
set nocompatible              " 去除VI一致性,必须要添加
syntax enable
set background=dark
set encoding=utf-8	"使用utf-8编码
set showcmd "显示输入命令
"set paste
set mouse=a "可以在buffer的任何地方使用鼠标

set hlsearch "显示高亮搜索
set ruler                 "显示行号和列号（默认打开) 
set encoding=utf-8

filetype plugin indent on 


"==========================|comment|=====================================o
" Add spaces after comment delimiters by default
let g:NERDSpaceDelims = 1

" Use compact syntax for prettified multi-line comments
let g:NERDCompactSexyComs = 1

" Align line-wise comment delimiters flush left instead of following code indentation
let g:NERDDefaultAlign = 'left'

" Set a language to use its alternate delimiters by default
let g:NERDAltDelims_java = 1

" Add your own custom formats or override the defaults
let g:NERDCustomDelimiters = { 'c': { 'left': '/**','right': '*/' } }

" Allow commenting and inverting empty lines (useful when commenting a region)
let g:NERDCommentEmptyLines = 1

" Enable trimming of trailing whitespace when uncommenting
let g:NERDTrimTrailingWhitespace = 1

" Enable NERDCommenterToggle to check all selected lines is commented or not 
let g:NERDToggleCheckAllLines = 1






let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
" 设置错误符号
let g:syntastic_error_symbol='✗'
" 设置警告符号
let g:syntastic_warning_symbol='!'
" 是否在打开文件时检查
let g:syntastic_check_on_open=0
" 是否在保存文件后检查
let g:syntastic_check_on_wq=1

set conceallevel=2

filetype off                  " 必须要添加
" 设置包括vundle和初始化相关的runtime path
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" 另一种选择, 指定一个vundle安装插件的路径
"call vundle#begin('~/some/path/here')

Plugin 'VundleVim/Vundle.vim'

"====================================================|translate |====================================================
Plugin 'ianva/vim-youdao-translater'
vnoremap <silent> yd :<C-u>Ydv<CR>
nnoremap <silent> yd :<C-u>Ydc<CR>
noremap <space>yd :<C-u>Yde<CR>
"====================================================| help doc|====================================================
Plugin 'asins/vimcdoc'
" 设定 doc 文档目录
let helptags=$VIM."/vimfiles/doc"
set helplang=cn

"====================================================| chinese input |====================================================
Plugin 'VimIM'
let g:vimim_cloud = 'google,sogou,baidu,qq'
let g:vimim_map = 'tab_as_gi'
let g:vimim_mode = 'dynamic'
let g:vimim_mycloud = 0
let g:vimim_plugin = 'C:/var/mobile/vim/vimfiles/plugin'
let g:vimim_punctuation = 2
let g:vimim_shuangpin = 0
let g:vimim_toggle = 'pinyin,google,sogou'

Plugin 'airblade/vim-gitgutter'
Plugin 't9md/vim-choosewin'
Plugin 'tpope/vim-fugitive'
Plugin 'raingo/vim-matlab'
Plugin 'shougo/neocomplete.vim'
Plugin 'shougo/neosnippet-snippets'
Plugin 'lokaltog/vim-powerline'
Plugin 'terryma/vim-multiple-cursors'
Plugin 'sirver/ultisnips'
Plugin 'shougo/neosnippet.vim'
"语法检查
Plugin 'wavded/vim-stylus'
Plugin 'a.vim'
Plugin 'honza/vim-snippets'
Plugin 'tpope/vim-commentary'
Plugin 'enricobacis/vim-airline-clock'

"====================================================|syntastic |====================================================
Plugin 'scrooloose/syntastic'
syntax enable
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
" 设置错误符号
let g:syntastic_error_symbol='✗'
" 设置警告符号
let g:syntastic_warning_symbol='!'
" 是否在打开文件时检查
let g:syntastic_check_on_open=0
" 是否在保存文件后检查
let g:syntastic_check_on_wq=1
" Plugin 'w0rp/ale'
" " In ~/.vim/ftplugin/javascript.vim, or somewhere similar.
" " Fix files with prettier, and then ESLint.
" let b:ale_fixers = ['prettier', 'eslint']
" " Equivalent to the above.
" let b:ale_fixers = {'javascript': ['prettier', 'eslint']}
" " In ~/.vim/vimrc, or somewhere similar.
" let g:ale_fixers = {
" \   '*': ['remove_trailing_lines', 'trim_whitespace'],
" \   'javascript': ['eslint'],
" \}
" " Set this variable to 1 to fix files when you save them.
" let g:ale_fix_on_save = 1
" " Enable completion where available.
" " This setting must be set before ALE is loaded.
" let g:ale_completion_enabled = 1
" let g:ale_sign_error = 'x'
" let g:ale_sign_warning = '!'
" " Set this. Airline will handle the rest.
" let g:airline#extensions#ale#enabled = 1
" function! LinterStatus() abort
"     let l:counts = ale#statusline#Count(bufnr(''))
"
"     let l:all_errors = l:counts.error + l:counts.style_error
"     let l:all_non_errors = l:counts.total - l:all_errors
"
"     return l:counts.total == 0 ? 'OK' : printf(
"     \   '%dW %dE',
"     \   all_non_errors,
"     \   all_errors
"     \)
" endfunction
"
" set statusline=%{LinterStatus()}
" " Show 5 lines of errors (default: 10)
" let g:ale_list_window_size = 3


Plugin 'klen/python-mode'
Plugin 'valloric/youcompleteme'
Plugin 'scrooloose/nerdcommenter'
Plugin 'ervandew/supertab'

"====================================================| taglist |====================================================
Plugin 'taglist.vim'
map <space>1 :TlistToggle<CR> 
let Tlist_Show_One_File=1     "不同时显示多个文件的tag，只显示当前文件的    
let Tlist_Exit_OnlyWindow=1   "如果taglist窗口是最后一个窗口，则退出vim   
let Tlist_Ctags_Cmd="/usr/bin/ctags" "将taglist与ctags关联
"let Tlist_Auto_Open=1        "auto open taglist when open file 
let Tlist_GainFocus_On_ToggleOpen=1     "auto focus on toogleOpen
let Tlist_Process_File_Always=1

Plugin 'tomtom/tlib_vim'
Plugin 'raimondi/delimitmate'
Plugin 'townk/vim-autoclose'

"==========================设置键盘映射=================================o
Plugin 'scrooloose/nerdtree'
map <space>2 :NERDTreeToggle<CR>
Plugin 'L9'
Plugin 'c.vim'
Plugin 'mizuchi/stl-syntax'
Plugin 'Cpp11-Syntax-Support'
Plugin 'altercation/vim-colors-solarized'
Plugin 'flazz/vim-colorschemes'
Plugin 'tomasr/molokai'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
"====================================================| motion |====================================================
Plugin 'easymotion/vim-easymotion'
map <space>f <Plug>(easymotion-overwin-f2)

Plugin 'mattn/emmet-vim'
Plugin 'hail2u/vim-css3-syntax'
Plugin 'groenewege/vim-less'
Plugin 'Raimondi/delimitMate'
let g:ycm_semantic_triggers = {
			\   'css': [ 're!^\s{4}', 're!:\s+'],
			\   'html': [ '</' ],
			\ }
Plugin 'pangloss/vim-javascript'
let javascript_enable_domhtmlcss = 1
Plugin 'nathanaelkane/vim-indent-guides'
Plugin 'marijnh/tern_for_vim'
"Plugin 'nathanaelkane/vim-indent-guides'
"" 以下范例用来支持不同格式的插件安装.{{{
"" 请将安装插件的命令放在vundle#begin和vundle#end之间.
"" Github上的插件
"" 格式为 Plugin '用户名/插件仓库名'
"Plugin 'tpope/vim-fugitive'
"" 来自 http://vim-scripts.org/vim/scripts.html 的插件
"" Plugin '插件名称' 实际上是 Plugin 'vim-scripts/插件仓库名' 只是此处的用户名可以省略
"Plugin 'L9'
"" 由Git支持但不再github上的插件仓库 Plugin 'git clone 后面的地址'
"Plugin 'git://git.wincent.com/command-t.git'
"" 本地的Git仓库(例如自己的插件) Plugin 'file:///+本地插件仓库绝对路径'
"Plugin 'file:///home/gmarik/path/to/plugin'
"" 插件在仓库的子目录中.
"" 正确指定路径用以设置runtimepath. 以下范例插件在sparkup/vim目录下
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
"" 安装L9，如果已经安装过这个插件，可利用以下格式避免命名冲突
"Plugin 'ascenator/L9', {'name': 'newL9'}

" 你的所有插件需要在下面这行之前}}}
call vundle#end()            " 必须
filetype plugin indent on    " 必须 加载vim自带和插件相应的语法和文件类型相关脚本
" 忽视插件改变缩进,可以使用以下替代:{{{
"filetype plugin on
"
" 常用的命令
" :PluginList       - 列出所有已配置的插件
" :PluginInstall     - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
" :PluginClean      - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件
"
" 查阅 :h vundle 获取更多细节和wiki以及FAQ
" 将你自己对非插件片段放在这行之后}}}
nnoremap <F5>   <Esc>:w<CR>:!gcc % -o /tmp/a.out && /tmp/a.out<CR>
nnoremap <F6>   <Esc>:w<CR>:!gcc % <CR>
nnoremap <C-F5> <Esc>:w<CR>:!gcc -g % -o /tmp/a.out && gdb /tmp/a.out<CR>
let g:Powerline_colorscheme='solarized256'
