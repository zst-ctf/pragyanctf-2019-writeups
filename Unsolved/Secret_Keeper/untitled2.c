loc_b4e:
    var_88 = malloc(0x48);
    *(var_88 + 0x8) = malloc(0x14);
    *var_88 = malloc(0x14);
    rax = strcpy(*(var_88 + 0x8), &var_40); // scanf password
    rax = strcpy(*var_88, &var_60); // scanf username


list[]

loc_d43:
    rax = puts("Logged in successfully......");
    var_A8 = 0x1;
    var_A0 = *(sign_extend_32(var_A4) * 0x8 + list);
    goto loc_d96;


loc_fc9:
    rsi = var_A0 + 0x10;
    rax = 0x0;
    rax = printf(0x1304); // "Info: %s"
    goto loc_f21;


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

