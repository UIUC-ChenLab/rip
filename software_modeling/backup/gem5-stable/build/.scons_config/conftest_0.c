
        asm(".globl _x; _x: .byte 0");
        extern int x;
        int main() { return x; }
        