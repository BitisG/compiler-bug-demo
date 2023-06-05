# compiler-bug-demo


# GCC versions where it works:
`9.2-9.5`
`10.1-10.2`

# Bug showoff:
https://godbolt.org/z/8qsveEv9G

# Assembly code
Taken from:
https://godbolt.org/z/4sdnrsM6v

```
main:
        mov     DWORD PTR [rsp-12], 0
        mov     eax, DWORD PTR [rsp-12]
        mov     DWORD PTR [rsp-5], 1667391744
        test    eax, eax
        mov     BYTE PTR [rsp-1], 0
        sete    al
        movzx   eax, al
        neg     eax
        ret

Before/after affected versions:
.LC0:
        .string ""
        .string ""
        .string ""
        .string ""
        .string ""
main:
        sub     rsp, 24
        mov     edx, 4
        mov     esi, OFFSET FLAT:.LC0
        lea     rdi, [rsp+11]
        mov     DWORD PTR [rsp+11], 1667391744
        mov     BYTE PTR [rsp+15], 0
        call    memcmp
        mov     DWORD PTR [rsp+4], eax
        mov     eax, DWORD PTR [rsp+4]
        test    eax, eax
        sete    al
        add     rsp, 24
        movzx   eax, al
        neg     eax
        ret
```
