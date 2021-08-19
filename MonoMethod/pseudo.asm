push _rootDomain
mov eax,[mono_thread_attach]
call eax
add esp,4

loop:
push args[cx]
inc cx      
cmp cx,arg.Length    
jle loop1   

mov eax,functionPtr
call eax
add esp,arglen * sizeof(int)
mov eax,retvalptr
ret


