Objective: Study elua development environment

Check out: https://github.com/Shengliang/elua.git

Please use gitk to review those change logs. 
  - apt-get install gitk

- a new shell command in elua shell.
- a new API that can be called from elua.

This script requires some well-known Lua libraries to run.
To install them on Ubuntu/Debian, go (as root):
apt-get install luarocks
luarocks install luafilesystem
luarocks install lpack
luarocks install md5
 
Then, type "./build.sh" to compile.

Study Notes:
How to create a cscope?
   find . -name "*.[chS]" > cscope.files
   vi cscope.files
   cscope

How to create & appy a git patch?
 git ls-remote https://github.com/shengliang/e4357.git 

# git: create a patch from top cl
   git show [hashID]
   git format-patch HEAD~

   # extract 2 topmost commits
   git format-patch -2

# apply a patch
   git am <...patch>

# add files
   git diff
   git status
   git add build.sh
   git add src/shell/shell_mem.c
   git commit -a -m 'shell: add md'
   git commit -a -m 'lua: add md'
   git commit -a --amend 

# checkin local branch to remote branches
   git remote -v
   git push origin local_branch_name:remote_branch_name
   git push origin master:master
   git push origin :remtoe_branch_name  //delete a remote branhc

# change remote url
   git remote set-url origin git://new.url.here
   git push origin master:master
