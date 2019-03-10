; Variables:
;    var_8: -8
;    var_40: -64
;    var_60: -96
;    var_80: -128
;    var_88: -136
;    var_90: -144
;    var_98: -152
;    var_A0: -160
;    var_A4: -164
;    var_A8: -168
;    var_AC: -172
;    var_B0: -176
;    var_B4: -180

int main() {
    var_8 = *0x28;
    rax = 0x0;
    var_AC = 0x14;
    goto loc_103e;

loc_103e:
    rax = var_AC;
    var_AC = rax + 0xffffffffffffffff;
    if (rax != 0x0) goto loc_a53;

loc_1055:
    rax = 0x0;
    rcx = *0x28 ^ *0x28;
    if (rcx != 0x0) {
            rax = __stack_chk_fail();
    }
    return rax;

loc_a53:
    rax = puts(0x10f8); // "############### Secure Secret Keeper ##########"
    rax = 0x0;
    rax = printf("1.Register\n2.Login\n3.Exit\nChoice:");
    rax = 0x0;
    rax = __isoc99_scanf(0x114a, &var_B4);
    if (var_B4 != 0x1) goto loc_c2c; // register

loc_a9a:
    rax = 0x0;
    rax = printf("Enter User_name : ");
    rax = 0x0;
    rax = __isoc99_scanf(0x1160, &var_60);
    if (strcmp(&var_60, "admin") != 0x0) goto loc_aeb;

loc_ada:
    rax = puts(0x1170); // "!!!!!!  User already exist."
    goto loc_103e;

loc_aeb:
    rax = 0x0;
    rax = printf("Enter Password : ");
    rax = 0x0;
    rax = __isoc99_scanf(0x1160, &var_40);
    if ((strlen(&var_60) > 0x13) || (strlen(&var_40) > 0x13)) goto loc_b38;

loc_b4e:
    var_88 = malloc(0x48);
    *(var_88 + 0x8) = malloc(0x14);
    *var_88 = malloc(0x14);
    rax = strcpy(*(var_88 + 0x8), &var_40); // scanf password
    rax = strcpy(*var_88, &var_60); // scanf username
    rax = 0x0;
    rax = printf("User: %s\nPass:%s\n", *var_88, *(var_88 + 0x8));
    *(sign_extend_32(*(int32_t *)count) * 0x8 + list) = var_88;
    *(int32_t *)count = *(int32_t *)count + 0x1;
    rax = puts("**************User Successfully Created*****************\n");
    goto loc_103e;

loc_b38:
    rax = puts("Illegal inputs.");
    rax = exit(0x0);
    return rax;

loc_c2c:
    if (var_B4 != 0x2) goto loc_1033; // login

loc_c3b:
    rax = 0x0;
    rax = printf("Enter User_name : ");
    rax = 0x0;
    rax = __isoc99_scanf(0x1160, &var_80);
    rax = 0x0;
    rax = printf("Enter Password : ");
    rax = 0x0;
    rax = __isoc99_scanf(0x1160, &var_60);
    if ((strlen(&var_80) > 0x13) || (strlen(&var_60) > 0x13)) goto loc_cb1;

loc_cc7:
    var_A8 = 0x0;
    var_A4 = 0x0;
    goto loc_d84;

loc_d84:
    if (var_A4 < *(int32_t *)count) goto loc_ce0; // for-loop increment var_A4 until it reaches index in list

loc_d96:
    if ((var_A8 != 0x0) || (strcmp(&var_80, "admin") != 0x0)) goto loc_e4f;

loc_dbe:
    var_98 = fopen("password.txt", 0x121f); // "password.txt", "r"
    if (var_98 == 0x0) {
            rax = *stderr@@GLIBC_2.2.5;
            rax = fwrite("\nIt doesn't seems to be your account.\n", 0x1, 0x26, rax);
            rax = exit(0x0);
    }
    else {
            rax = fgets(&var_40, 0x32, var_98);
            if (strcmp(&var_40, &var_60) == 0x0) {
                    var_A8 = 0x1;
            }
            rax = exit(0x0);
    }
    return rax;

loc_e4f:
    if (var_A8 == 0x0) goto loc_1025; // goto user does not exist

loc_e5c:
    var_B0 = 0x0;
    rax = 0x0;
    rax = printf("\n\n Welcome %s\n\n", &var_80);
    if (strcmp(&var_80, "admin") != 0x0) goto loc_f21;

loc_e99:
    var_90 = fopen("flag.txt", 0x121f); // "flag.txt", "r"
    if (var_90 == 0x0) {
            rax = *stderr@@GLIBC_2.2.5;
            rax = fwrite("\nflag.txt doesn't exist.\n", 0x1, 0x19, rax);
            rax = exit(0x0);
    }
    else {
            rax = fgets(&var_40, 0x64, var_90);
            rax = 0x0;
            rax = printf("Flag is: %s\n", &var_40);
            rax = exit(0x0);
    }
    return rax;

loc_f21:
    var_B0 = 0x0;
    rax = puts("1.Store your secret info\n2.View the secret\n3.Delete Account\n4.Logout");
    rax = 0x0;
    rax = __isoc99_scanf(0x114a, &var_B0);
    if (var_B0 != 0x1) goto loc_fbe; // Store your secret info

loc_f53:
    rax = puts("Enter your secret info: ");
    rax = 0x0;
    rax = __isoc99_scanf(0x1160, &var_40);
    if (strlen(&var_40) <= 0x32) goto loc_f9f;

loc_f89:
    rax = puts("Invalid input");
    rax = exit(0x0);
    return rax;

loc_f9f:
    rax = strcpy(var_A0 + 0x10, &var_40);
    goto loc_f21;

loc_fbe:
    if (0x0 != 0x2) goto loc_fed; // View the secret

loc_fc9:
    rsi = var_A0 + 0x10;
    rax = 0x0;
    rax = printf(0x1304); // "Info: %s"
    goto loc_f21;

loc_fed:
    if (0x0 == 0x3) {
            *(int8_t *)*var_A0 = 0x0;
            rax = free(*var_A0);
            rax = puts("******** User Successfully Deleted *************\n");
    }
    goto loc_103e;

loc_1025:
    rax = puts(0x1342); //  !!!!!User doesnt exist.
    goto loc_103e;

loc_ce0:
    if ((strcmp(**(sign_extend_32(var_A4) * 0x8 + list), &var_80) != 0x0) || (strcmp(*(*(sign_extend_32(var_A4) * 0x8 + list) + 0x8), &var_60) != 0x0)) goto loc_d7d;

loc_d43:
    rax = puts("Logged in successfully......");
    var_A8 = 0x1;
    var_A0 = *(sign_extend_32(var_A4) * 0x8 + list);
    goto loc_d96;

loc_d7d:
    var_A4 = var_A4 + 0x1;
    goto loc_d84;

loc_cb1:
    rax = puts("Illegal inputs.");
    rax = exit(0x0);
    return rax;

loc_1033:
    rax = exit(0x0);
    return rax;
}