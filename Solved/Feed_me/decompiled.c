int main() {
    srand(time(0x0));
    rcx = rand();
    var_90 = ((SAR(HIDWORD(rcx * 0x68db8bad), 0xc)) - (SAR(rcx, 0x1f))) * 0x2710 + (0x0 - rcx) + ((SAR(HIDWORD(rcx * 0x68db8bad), 0xc)) - (SAR(rcx, 0x1f))) * 0x2710 + (0x0 - rcx);
    rcx = rand();
    var_8C = ((SAR(HIDWORD(rcx * 0x68db8bad), 0xc)) - (SAR(rcx, 0x1f))) * 0x2710 + (0x0 - rcx) + ((SAR(HIDWORD(rcx * 0x68db8bad), 0xc)) - (SAR(rcx, 0x1f))) * 0x2710 + (0x0 - rcx);
    rcx = rand();
    var_88 = ((SAR(HIDWORD(rcx * 0x68db8bad), 0xc)) - (SAR(rcx, 0x1f))) * 0x2710 + (0x0 - rcx) + ((SAR(HIDWORD(rcx * 0x68db8bad), 0xc)) - (SAR(rcx, 0x1f))) * 0x2710 + (0x0 - rcx);
    puts("Can you cook my favourite food using these ingredients :)");
    printf("%d ; %d ; %d ;\n", var_90, var_8C, var_88);
    __isoc99_scanf(0xde2, &var_6E);
    var_94 = 0x0;
    goto loc_ba7;

loc_ba7:
    if (sign_extend_64(var_94) < strlen(&var_6E)) goto loc_b57;

loc_bc1:
    var_84 = atoi(&var_6E);
    var_80 = atoi(&var_64);
    var_7C = atoi(&var_5A);
    if (var_90 != var_80 + var_84) goto loc_cbe;

loc_c08:
    if (var_8C != var_7C + var_80) goto loc_cb2;

loc_c1c:
    if (var_88 != var_84 + var_7C) goto loc_ca6;

loc_c2f:
    var_78 = fopen("flag.txt", 0xdf7);
    if (var_78 != 0x0) goto loc_c77;

loc_c4d:
    fwrite("\nflag.txt doesn't exist.\n", 0x1, 0x19, *stderr@@GLIBC_2.2.5);
    rax = exit(0x0);
    return rax;

loc_c77:
    fgets(&var_50, 0x32, var_78);
    printf("That's yummy.... Here is your gift:\n%s", &var_50);
    goto loc_cc8;

loc_cc8:
    rax = 0x0;
    goto loc_ccd;

loc_ccd:
    rbx = *0x28 ^ *0x28;
    if (rbx != 0x0) {
            rax = __stack_chk_fail();
    }
    return rax;

loc_ca6:
    fail();
    goto loc_cc8;

loc_cb2:
    fail();
    goto loc_cc8;

loc_cbe:
    fail();
    goto loc_cc8;

loc_b57:
    if (((*(int8_t *)(rbp + sign_extend_32(var_94) + 0xffffffffffffff92) & 0xff) <= 0x2f) || ((*(int8_t *)(rbp + sign_extend_32(var_94) + 0xffffffffffffff92) & 0xff) > 0x39)) goto loc_b79;

loc_ba0:
    var_94 = var_94 + 0x1;
    goto loc_ba7;

loc_b79:
    if ((*(int8_t *)(rbp + sign_extend_32(var_94) + 0xffffffffffffff92) & 0xff) == 0x2d) goto loc_ba0;

loc_b8a:
    puts("Invalid input :( ");
    rax = 0x0;
    goto loc_ccd;
}