extern int main();
extern void __module_init();

void _start() {
  __module_init();

  int result = main();

  asm volatile("mov %0, %%edi\n\t"
               "mov $60, %%rax\n\t"
               "syscall\n"
               :
               : "r"(result)
               : "rax", "rdi");
}
