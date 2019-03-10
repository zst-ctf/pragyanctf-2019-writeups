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
    rax = printf("Enter the key: ");
    rax = 0x0;
    rax = __isoc99_scanf(0x1117, &var_80);
    if (strlen(&var_80) > 0x1e) {
            rax = fail(0x0);
    }
    if (mod(&var_80, getNum("27644437104591489104652716127", 0x0, *(int32_t *)(rbp + sign_extend_32(0x0) * 0x8 + 0xffffffffffffff54))) == *(int32_t *)(rbp + sign_extend_32(0x0) * 0x8 + 0xffffffffffffff50)) {
            var_BC = 0x0 + *(int32_t *)(rbp + sign_extend_32(0x0) * 0x8 + 0xffffffffffffff54);
            var_C0 = 0x1;
            if (mod(&var_80, getNum("27644437104591489104652716127", var_BC, *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff54))) == *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff50)) {
                    var_BC = var_BC + *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff54);
                    var_C0 = var_C0 + 0x1;
                    if (mod(&var_80, getNum("27644437104591489104652716127", var_BC, *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff54))) == *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff50)) {
                            var_BC = var_BC + *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff54);
                            var_C0 = var_C0 + 0x1;
                            if (mod(&var_80, getNum("27644437104591489104652716127", var_BC, *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff54))) == *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff50)) {
                                    if (mod(&var_80, getNum("27644437104591489104652716127", var_BC + *(int32_t *)(rbp + sign_extend_32(var_C0) * 0x8 + 0xffffffffffffff54), *(int32_t *)(rbp + sign_extend_32(var_C0 + 0x1) * 0x8 + 0xffffffffffffff54))) == *(int32_t *)(rbp + sign_extend_32(var_C0 + 0x1) * 0x8 + 0xffffffffffffff50)) {
                                            rax = 0x0;
                                            rax = printf("Enter password: ");
                                            rax = 0x0;
                                            rax = __isoc99_scanf(0x1117, &var_40);
                                            rax = func2(&var_40, &var_80, "27644437104591489104652716127");
                                    }
                                    else {
                                            rax = fail(0x0);
                                    }
                            }
                            else {
                                    rax = fail(0x0);
                            }
                    }
                    else {
                            rax = fail(0x0);
                    }
            }
            else {
                    rax = fail(0x0);
            }
    }
    else {
            rax = fail(0x0);
    }
    rax = 0x0;
    rcx = *0x28 ^ *0x28;
    if (rcx != 0x0) {
            rax = __stack_chk_fail();
    }
    return rax;
}


int getNum(int arg0, int arg1, int arg2) {
    var_18 = arg0;
    var_1C = arg1;
    var_20 = arg2;
    var_8 = 0x0;
    for (var_4 = var_1C; var_4 < var_20 + var_1C; var_4 = var_4 + 0x1) {
            var_8 = sign_extend_64(*(int8_t *)(var_18 + sign_extend_64(var_4)) & 0xff) + (var_8 << 0x2) + var_8 + (var_8 << 0x2) + var_8 - 0x30;
    }
    rax = var_8;
    rsp = rsp + 0x8;
    rbp = stack[2047];
    return rax;
}


int mod(int arg0, int arg1) {
    var_28 = arg0;
    var_2C = arg1;
    var_18 = 0x0;
    var_14 = 0x0;
    while (sign_extend_64(var_14) < strlen(var_28)) {
            rax = *(int8_t *)(var_28 + sign_extend_64(var_14)) & 0xff;
            rdx = sign_extend_64(rax) + (var_18 << 0x2) + var_18 + (var_18 << 0x2) + var_18 - 0x30 & 0x80000000 ? 0xffffffff : 0x0;
            temp_1 = (sign_extend_64(rax) + (var_18 << 0x2) + var_18 + (var_18 << 0x2) + var_18 - 0x30) % var_2C;
            rax = (sign_extend_64(rax) + (var_18 << 0x2) + var_18 + (var_18 << 0x2) + var_18 - 0x30) / var_2C;
            var_18 = temp_1;
            var_14 = var_14 + 0x1;
    }
    rax = var_18;
    rbx = stack[2046];
    rsp = rsp + 0x38;
    rbp = stack[2047];
    return rax;
}

int func2(int arg0, int arg1, int arg2) {
    var_48 = arg0;
    var_20 = strcat(arg1, arg2);
    rcx = 0xffffffffffffffff;
    asm { repne scasb al, byte [rdi] };
    *(int16_t *)(var_20 + !rcx + 0xffffffffffffffff) = 0x3038;
    *(int8_t *)(var_20 + !rcx + 0x1) = 0x0;
    var_18 = var_20;
    var_3C = 0x0;
    var_38 = 0x0;
    var_34 = strlen(var_18) >> 0x1;
    while (sign_extend_64(var_38) < strlen(var_18) >> 0x1) {
            rax = *(int8_t *)(var_18 + sign_extend_64(var_38)) & 0xff;
            var_28 = (sign_extend_64(*(int8_t *)(var_18 + sign_extend_32(var_38) + 0x1) & 0xff) - 0x30) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + sign_extend_64(rax) + sign_extend_64(rax) + 0xffffffffffffffa0;
            rax = *(int8_t *)(var_18 + sign_extend_64(var_34)) & 0xff;
            if ((*(int8_t *)(var_48 + sign_extend_64(var_3C)) & 0xff) != (*(int8_t *)("!Y{juRgb&{!okC{z_%BUKvAaEl&uXLT$$sCuKHkbSZ@lcR@%jQ@!cbHSLYpTtD)ddFz)BGSzKo$&DpLpcL)Kn(EnyQ*Mv&U@^khDTAbONFPpIdvahfv!zBSkA@s@EH@BMTvg}}UsPIqe%XvSi!%#mO#jogK(Wb$D#xINLBw%aKYINQsbTH!COwSBiiqgX#E{m(qL{zdC%u&sapLPjY&vqynvNdk%z{X)JvcexNprZf#iKh{!SFRaeRk!Ly%zaatd…" + (((sign_extend_64(var_28) << 0x2) + sign_extend_64(var_28)) * 0x4 + (sign_extend_64(var_28) << 0x2) + sign_extend_64(var_28) << 0x2) + sign_extend_64((sign_extend_64(*(int8_t *)(var_18 + sign_extend_32(var_34) + 0x1) & 0xff) - 0x30) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + sign_extend_64(rax) + sign_extend_64(rax) + 0xffffffffffffffa0)) & 0xff)) {
                    rax = fail(0x1);
            }
            var_3C = var_3C + 0x1;
            var_38 = var_38 + 0x2;
            var_34 = var_34 + 0x2;
    }
    var_38 = 0x0;
    var_34 = strlen(var_18) >> 0x1;
    while (sign_extend_64(var_38) < strlen(var_18) >> 0x1) {
            rax = *(int8_t *)(var_18 + sign_extend_64(var_38)) & 0xff;
            var_30 = (sign_extend_64(*(int8_t *)(var_18 + sign_extend_32(var_38) + 0x1) & 0xff) - 0x30) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + sign_extend_64(rax) + sign_extend_64(rax) + 0xffffffffffffffa0;
            rax = *(int8_t *)(var_18 + sign_extend_64(var_34)) & 0xff;
            var_2C = (sign_extend_64(*(int8_t *)(var_18 + sign_extend_32(var_34) + 0x1) & 0xff) - 0x30) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + (sign_extend_64(rax) + 0xffffffffffffffd0 << 0x2) + sign_extend_64(rax) + sign_extend_64(rax) + 0xffffffffffffffa0;
            rax = 0x151d07eb * var_30 * var_30;
            rax = 0x151d07eb * var_2C * var_2C;
            if ((*(int8_t *)(var_48 + sign_extend_64(var_3C)) & 0xff) != (*(int8_t *)("!Y{juRgb&{!okC{z_%BUKvAaEl&uXLT$$sCuKHkbSZ@lcR@%jQ@!cbHSLYpTtD)ddFz)BGSzKo$&DpLpcL)Kn(EnyQ*Mv&U@^khDTAbONFPpIdvahfv!zBSkA@s@EH@BMTvg}}UsPIqe%XvSi!%#mO#jogK(Wb$D#xINLBw%aKYINQsbTH!COwSBiiqgX#E{m(qL{zdC%u&sapLPjY&vqynvNdk%z{X)JvcexNprZf#iKh{!SFRaeRk!Ly%zaatd…" + (((sign_extend_64(var_30 * var_30 - ((SAR(HIDWORD(0x151d07eb * var_30 * var_30), 0x3)) - (SAR(var_30 * var_30, 0x1f))) * 0x61) << 0x2) + sign_extend_64(var_30 * var_30 - ((SAR(HIDWORD(0x151d07eb * var_30 * var_30), 0x3)) - (SAR(var_30 * var_30, 0x1f))) * 0x61)) * 0x4 + (sign_extend_64(var_30 * var_30 - ((SAR(HIDWORD(0x151d07eb * var_30 * var_30), 0x3)) - (SAR(var_30 * var_30, 0x1f))) * 0x61) << 0x2) + sign_extend_64(var_30 * var_30 - ((SAR(HIDWORD(0x151d07eb * var_30 * var_30), 0x3)) - (SAR(var_30 * var_30, 0x1f))) * 0x61) << 0x2) + sign_extend_64(var_2C * var_2C - ((SAR(HIDWORD(0x151d07eb * var_2C * var_2C), 0x3)) - (SAR(var_2C * var_2C, 0x1f))) * 0x61)) & 0xff)) {
                    rax = fail(0x1);
            }
            var_3C = var_3C + 0x1;
            var_38 = var_38 + 0x2;
            var_34 = var_34 + 0x2;
    }
    rax = puts("Your Skills are really great. Flag is:");
    rax = 0x0;
    rax = printf("pctf{%s}\n", var_48);
    rbx = stack[2046];
    rsp = rsp + 0x68;
    rbp = stack[2047];
    return rax;
}
