static int __init hello_module(void) {
  printk(KERN_INFO "Hello World!\n");
  return 0;
}

static void __exit goodbye_module(void) { printk(KERN_INFO "Adios\n"); }

module_init(hello_module);
module_exit(goodbye_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PEDRO");
MODULE_DESCRIPTION("HELLO WORLD MODULE");
