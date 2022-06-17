## Kernel debugging:

```
run `bcdedit -debug on` then reboot.
```
## Some helpfull commands:
```
!tasklist | will show running apps.
!tasklist -cpu | will show cpu time as well.

!mex.p app_address
!us | show unique stacks.
!chkimg -d kdcsvc | will get image from remote server and compare with
the one in memory and show diff.    
if there is any difference then that means that those functions have
been patched(hijacked).
```

