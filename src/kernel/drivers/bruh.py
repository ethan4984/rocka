bruh = 0
for i in range(100):
    print("#define GPIO_REG_GP (gpioBaseAddr + 0x%x)" % bruh);
    bruh += 4;
