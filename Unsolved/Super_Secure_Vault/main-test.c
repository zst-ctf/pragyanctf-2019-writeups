int main() {
    var_8 = *0x28;
    rax = 0x0;
    var_C4 = 0x0;
    var_C0 = 0x0;
    var_BC = 0x0;
    var_B8 = "27644437104591489104652716127";
    var_B0 = 0xd5;
    var_AC = 0x8;
    var_A8 = 0xe5;
    var_A4 = 0x5;
    var_A0 = 0x19;
    var_9C = 0x4;
    var_98 = 0x53;
    var_94 = 0x7;
    var_90 = 0x87;
    var_8C = 0x5;
    rax = 0x0;

    /*
    0000000000000c95         mov        dword [rbp+var_B0], 0xd5
    0000000000000c9f         mov        dword [rbp+var_AC], 0x8
    0000000000000ca9         mov        dword [rbp+var_A8], 0xe5
    0000000000000cb3         mov        dword [rbp+var_A4], 0x5
    0000000000000cbd         mov        dword [rbp+var_A0], 0x19
    0000000000000cc7         mov        dword [rbp+var_9C], 0x4
    0000000000000cd1         mov        dword [rbp+var_98], 0x53
    0000000000000cdb         mov        dword [rbp+var_94], 0x7
    0000000000000ce5         mov        dword [rbp+var_90], 0x87
    0000000000000cef         mov        dword [rbp+var_8C], 0x5
    */



    rax = printf("Enter the key: ");
    rax = 0x0;
    rax = __isoc99_scanf(0x1117, &var_80);

    // input of 30 chars max
    if (strlen(&var_80) > 0x1e) {
        return fail(0x0);
    }


    // 0xffffffffffffff54 = -172
    // 0xffffffffffffff50

    // -> getNum()
    // starting index: var_BC
    // ending index: (var_C0+1) * 8

    // -> if statement
    // if (getNum(start, end) == cmp)

    // -> lhs sequence
    // rbp-172+0  = 8
    // rbp-172+8  = 5
    // rbp-172+16 = 4
    // rbp-172+24 = 7
    // rbp-172+32 = 5

    // start =  0,  8, 13, 17, 24
    // end   =  8, 13, 17, 24, 29

    // -> rhs sequence
    // rbp-176+0  = 0xd5 = 213
    // rbp-176+8  = 0xe5
    // rbp-176+16 = 0x19
    // rbp-176+24 = 0x53
    // rbp-176+32 = 0x87
    // cmp   = 213, 229, 25, 83, 135

    var_BC = 0;
    var_C0 = 0;
    if (mod(&var_80, getNum("27644437104591489104652716127", 0x0, *(int32_t *)(rbp + (0x0) * 0x8 - 172))) == *(int32_t *)(rbp + (0x0) * 0x8 - 176)) {
        var_BC = 0x0 + *(int32_t *)(rbp + (0x0) * 0x8 - 172);
        var_C0 = var_C0 + 0x1;
        if (mod(&var_80, getNum("27644437104591489104652716127", var_BC, *(int32_t *)(rbp + (var_C0) * 0x8 - 172))) == *(int32_t *)(rbp + (var_C0) * 0x8 - 176)) {
            var_BC = var_BC + *(int32_t *)(rbp + (var_C0) * 0x8 - 172);
            var_C0 = var_C0 + 0x1;
            if (mod(&var_80, getNum("27644437104591489104652716127", var_BC, *(int32_t *)(rbp + (var_C0) * 0x8 - 172))) == *(int32_t *)(rbp + (var_C0) * 0x8 - 176)) {
                var_BC = var_BC + *(int32_t *)(rbp + (var_C0) * 0x8 - 172);
                var_C0 = var_C0 + 0x1;
                if (mod(&var_80, getNum("27644437104591489104652716127", var_BC, *(int32_t *)(rbp + (var_C0) * 0x8 - 172))) == *(int32_t *)(rbp + (var_C0) * 0x8 - 176)) {
                    var_BC = var_BC + *(int32_t *)(rbp + (var_C0) * 0x8 - 172);
                    var_C0 = var_C0 + 0x1;

                    if (mod(&var_80, getNum("27644437104591489104652716127", var_BC, *(int32_t *)(rbp + (var_C0) * 0x8 - 172))) == *(int32_t *)(rbp + (var_C0) * 0x8 - 176)) {
                            rax = 0x0;
                            rax = printf("Enter password: ");
                            rax = 0x0;
                            rax = __isoc99_scanf(0x1117, &var_40);
                            rax = func2(&var_40, &var_80, "27644437104591489104652716127");
                            return 1; // pass
                    }
                }
            }
        }
    }
    return fail(0x0);
}